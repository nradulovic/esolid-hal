/******************************************************************************
 * This file is part of eSolid
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * eSolid is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * eSolid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with eSolid; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *//***********************************************************************//**
 * @file
 * @author      Nenad Radulovic
 * @brief       Sistemski drajver za STM32L1xx seriju.
 * @addtogroup  port_stm32l1xx
 *********************************************************************//** @{ */

/*=========================================================  INCLUDE FILES  ==*/
#include "hal/hal.h"
#include "stm32l1xx_pkg.h"

/*=========================================================  LOCAL DEFINES  ==*/
/*=========================================================  LOCAL MACRO's  ==*/
/*======================================================  LOCAL DATA TYPES  ==*/
/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/

static void sysPerfSetHigh(
    void);

static void sysPerfSetMedium(
    void);

static void sysPerfSetDefault(
    void);

/*=======================================================  LOCAL VARIABLES  ==*/

/**
 * @brief       Trenutni sistemski profil
 */
static esSysPerf_T sysPerfProfile;

/*======================================================  GLOBAL VARIABLES  ==*/
/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/

/**
 * @brief       Postavlja takt oscilator na najvecu mogucu vrednost
 * @par         Bocni efekti:
 *              - ukljucuje 64-bit pristup flash memoriji
 *              - ukljucuje prefetch buffer
 *              - HCLK = SYSCLK
 *              - ukljucuje/iskljucuje PWR interfejs
 *              - ukljucuje PLL
 *              - iskljucuje MSI
 */
static void sysPerfSetHigh(
    void) {

    uint16_t startUpCntr;
    uint32_t status;

    RCC->CR |= RCC_CR_HSION;                                                    /* Enable HSI                                               */
    startUpCntr = 0U;

    do {
        status = RCC->CR & RCC_CR_HSIRDY;
        ++startUpCntr;
    } while ((0UL == status) && (HSI_STARTUP_TIMEOUT != startUpCntr));          /* Wait until HSI is ready                                  */

    if (0UL != status) {

/*
 * Postavljanje takt oscilatora na HSI: radjeno po RM0038 (doc id 15965, rev 4),
 * Increasing the CPU frequency (in the same voltage range)
 */
        FLASH->ACR |= FLASH_ACR_ACC64;                                          /* Enable 64-bit access                                     */

        if (0UL == (FLASH->ACR & FLASH_ACR_ACC64)) {
            /* Greska! 64bit access nece */
        }
        FLASH->ACR |= FLASH_ACR_LATENCY;                                        /* Flash 1 wait state                                       */

        if (0UL == (FLASH->ACR & FLASH_ACR_LATENCY)) {
            /* Greska! Nece 1WS */
        }
        FLASH->ACR |= FLASH_ACR_PRFTEN;                                         /* Enable Prefetch Buffer                                   */

/*
 * Podesavanja regulatora napajanja: radjeno po RM0038 (doc id 15965, rev 4),
 * Table 8. Performance versus Vcore range, red: High
 */
        RCC->APB1ENR |= RCC_APB1ENR_PWREN;                                      /* Enable the PWR interface clock                           */
        ES_HWREG_SET(                                                           /* Select the Voltage Range 1 (1.8V)                        */
            PWR->CR,
            PWR_CR_VOS,
            PWR_CR_VOS_0);

        while (0UL != (PWR->CSR & PWR_CSR_VOSF)) {                              /* Wait Until the Voltage Regulator is ready                */
            ;
        }
        RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;                                     /* Disable the PWR interface clock                          */
        ES_HWREG_SET(                                                           /* PLL configuration                                        */
            RCC->CFGR,
            RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL | RCC_CFGR_PLLDIV,
            RCC_CFGR_PLLSRC_HSI | RCC_CFGR_PLLMUL4 | RCC_CFGR_PLLDIV2);         /* PLLCLK = (HSI * 4) / 2 = 32MHz                           */
        RCC->CR |= RCC_CR_PLLON;                                                /* Enable PLL                                               */

        while (0UL != (RCC->CR & RCC_CR_PLLRDY)) {                              /* Wait till PLL is ready                                   */
            ;
        }
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_SW,
            RCC_CFGR_SW_PLL);                                                   /* Select PLL as system clock source                        */

        while (RCC_CFGR_SWS_PLL != (RCC->CFGR & RCC_CFGR_SWS)) {                /* Wait till PLL is used as system clock source             */
            ;
        }
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK                                            */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV1);
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PPRE1,
            RCC_CFGR_PPRE1_DIV1);
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PPRE2,
            RCC_CFGR_PPRE2_DIV1);
        RCC->CR &= ~RCC_CR_MSION;                                               /* Switch off MSI clock generator                           */
        RCC->CR &= ~RCC_CR_HSEON;
        sysPerfProfile = ES_SYS_PERF_HIGH;
    } else {
        /* Greska! Nije hteo HSI da se upali. */
    }
}

/**
 * @brief       Postavlja takt oscilator na najvecu mogucu vrednost
 * @par         Bocni efekti:
 *              - ukljucuje 64-bit pristup flash memoriji
 *              - ukljucuje prefetch buffer
 *              - HCLK = SYSCLK
 *              - ukljucuje/iskljucuje PWR interfejs
 *              - iskljucuje PLL
 *              - iskljucuje MSI
 */
static void sysPerfSetMedium(
    void) {

    uint32_t startUpCntr;
    uint32_t status;

    RCC->CR |= RCC_CR_HSION;                                                    /* Enable HSI                                               */
    startUpCntr = 0U;

    do {
        status = RCC->CR & RCC_CR_HSIRDY;
        ++startUpCntr;
    } while ((0UL == status) && (HSI_STARTUP_TIMEOUT != startUpCntr));          /* Wait until HSI is ready                                  */

    if (0UL != status) {

/*
 * Postavljanje takt oscilatora na HSI: radjeno po RM0038 (doc id 15965, rev 4),
 * Increasing the CPU frequency (in the same voltage range)
 */
        FLASH->ACR |= FLASH_ACR_ACC64;                                          /* Enable 64-bit access                                     */

        if (0UL == (FLASH->ACR & FLASH_ACR_ACC64)) {
            /* Greska! 64bit access nece */
        }
        FLASH->ACR |= FLASH_ACR_LATENCY;                                        /* Flash 1 wait state                                       */

        if (0UL == (FLASH->ACR & FLASH_ACR_LATENCY)) {
            /* Greska! Nece 1WS */
        }
        FLASH->ACR |= FLASH_ACR_PRFTEN;                                         /* Enable Prefetch Buffer                                   */

/*
 * Podesavanja regulatora napajanja: radjeno po RM0038 (doc id 15965, rev 4),
 * Table 8. Performance versus Vcore range, red: High
 */
        RCC->APB1ENR |= RCC_APB1ENR_PWREN;                                      /* Enable the PWR APB1 Clock                                */
        ES_HWREG_SET(                                                           /* Select the Voltage Range 1 (1.8V)                        */
            PWR->CR,
            PWR_CR_VOS,
            PWR_CR_VOS_0);

        while (0UL != (PWR->CSR & PWR_CSR_VOSF)) {                              /* Wait Until the Voltage Regulator is ready                */
            ;
        }
        RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;                                     /* Disable the PWR interface clock                          */
        ES_HWREG_SET(                                                           /* Select HSI as system clock source                        */
            RCC->CFGR,
            RCC_CFGR_SW,
            RCC_CFGR_SW_HSI);

        while (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {                /* Wait till HSI is used as system clock source             */
            ;
        }
        RCC->APB1ENR |= RCC_APB1ENR_PWREN;                                      /* Enable the PWR APB1 Clock                                */
        ES_HWREG_SET(                                                           /* Select the Voltage Range 2 (1.5V)                        */
            PWR->CR,
            PWR_CR_VOS,
            PWR_CR_VOS_1);

        while (0UL != (PWR->CSR & PWR_CSR_VOSF)) {                              /* Wait Until the Voltage Regulator is ready                */
            ;
        }
        RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;                                     /* Disable the PWR interface clock                          */
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK                                            */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV1);
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PPRE1,
            RCC_CFGR_PPRE1_DIV1);
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PPRE2,
            RCC_CFGR_PPRE2_DIV1);
        RCC->CR &= ~RCC_CR_PLLON;                                               /* Switch off PLL                                           */
        RCC->CR &= ~RCC_CR_MSION;                                               /* Switch off HSI clock generator                           */
        RCC->CR &= ~RCC_CR_HSEON;
        sysPerfProfile = ES_SYS_PERF_MEDIUM;
    } else {
        /* Greska! Nece MSI da se ukljuci */
    }
}

/**
 * @brief       Postavlja takt oscilator na najvecu mogucu vrednost
 * @par         Bocni efekti:
 *              - iskljucuje 64-bit pristup flash memoriji
 *              - iskljucuje prefetch buffer
 *              - HCLK = SYSCLK
 *              - ukljucuje/iskljucuje PWR interfejs
 *              - iskljucuje PLL
 *              - iskljucuje HSI
 */
static void sysPerfSetDefault(
    void) {

    uint32_t startUpCntr;
    uint32_t status;

    RCC->CR |= RCC_CR_MSION;                                                    /* Enable MSI                                               */
    startUpCntr = 0UL;

    do {                                                                        /* Wait untill MSI is ready and if Time out is reached exit */
        status = RCC->CR & RCC_CR_MSIRDY;
        ++startUpCntr;
    } while((0UL == status) && (HSI_STARTUP_TIMEOUT != startUpCntr));

    if (0UL != status) {
        ES_HWREG_SET(                                                           /* Set MSI clock range to 2MHz                              */
            RCC->ICSCR,
            RCC_ICSCR_MSIRANGE,
            RCC_ICSCR_MSIRANGE_5);
        ES_HWREG_SET(                                                           /* Select MSI as system clock source                        */
            RCC->CFGR,
            RCC_CFGR_SW,
            RCC_CFGR_SW_MSI);

        while (RCC_CFGR_SWS_MSI != (RCC->CFGR & RCC_CFGR_SWS)) {                /* Wait till MSI is used as system clock source             */
            ;
        }
        FLASH->ACR &= ~FLASH_ACR_PRFTEN;                                        /* Disable Prefetch Buffer                                  */
        FLASH->ACR &= ~FLASH_ACR_LATENCY;                                       /* Flash 0 wait state                                       */
        FLASH->ACR &= ~FLASH_ACR_ACC64;                                         /* Disable 64-bit access                                    */
        RCC->APB1ENR |= RCC_APB1ENR_PWREN;                                      /* Enable the PWR interface clock                           */
        PWR->CR |= PWR_CR_VOS;                                                  /* Select the Voltage Range 3 (1.2V)                        */

        while (0UL != (PWR->CSR & PWR_CSR_VOSF)) {                              /* Wait Until the Voltage Regulator is ready                */
            ;
        }
        RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;                                     /* Disable the PWR interface clock                          */
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK                                            */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV1);
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PPRE1,
            RCC_CFGR_PPRE1_DIV1);
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PPRE2,
            RCC_CFGR_PPRE2_DIV1);
        RCC->CR &= ~RCC_CR_PLLON;                                               /* Switch off PLL                                           */
        RCC->CR &= ~RCC_CR_HSION;                                               /* Switch off HSI clock generator                           */
        RCC->CR &= ~RCC_CR_HSEON;
        sysPerfProfile = ES_SYS_PERF_DEFAULT;
    } else {
        /* Greska! Nece MSI da se ukljuci */
    }
}

/*===================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*====================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
void esSysPerfSet(
    esSysPerf_T    speed) {

    switch (speed) {
        case ES_SYS_PERF_HIGH : {
            sysPerfSetHigh();
            break;
        }

        case ES_SYS_PERF_MEDIUM : {
            sysPerfSetMedium();
            break;
        }

        default : {
            sysPerfSetDefault();
            break;
        }
    }
}

/*----------------------------------------------------------------------------*/
esSysPerf_T esSysPerfGet(
    void) {

    return (sysPerfProfile);
}

/*----------------------------------------------------------------------------*/
uint32_t esSysCoreClockGet(
    void) {

    uint32_t clk;

    switch (RCC->CFGR & RCC_CFGR_SWS) {
        case RCC_CFGR_SWS_HSI : {
            clk = 16000000UL;
            break;
        }

        case RCC_CFGR_SWS_MSI : {

            switch (RCC->ICSCR & RCC_ICSCR_MSIRANGE) {
                case RCC_ICSCR_MSIRANGE_0 : {
                    clk = 65535UL;
                    break;
                }

                case RCC_ICSCR_MSIRANGE_1 : {
                    clk = 131072UL;
                    break;
                }

                case RCC_ICSCR_MSIRANGE_2 : {
                    clk = 262144UL;
                    break;
                }

                case RCC_ICSCR_MSIRANGE_3 : {
                    clk = 524288UL;
                    break;
                }

                case RCC_ICSCR_MSIRANGE_4 : {
                    clk = 1048576UL;
                    break;
                }

                case RCC_ICSCR_MSIRANGE_5 : {
                    clk = 2097152UL;
                    break;
                }

                default : {
                    clk = 4194304UL;
                    break;
                }
            }
            break;
        }

        case RCC_CFGR_SWS_PLL : {

            if (RCC_CFGR_PLLSRC_HSI == (RCC->CFGR & RCC_CFGR_PLLSRC)) {
                const C_ROM uint32_t mulTable [9] = {
                    3UL,
                    4UL,
                    6UL,
                    8UL,
                    12UL,
                    16UL,
                    24UL,
                    32UL,
                    48UL
                };
                uint32_t mul;
                uint32_t div;

                mul = mulTable[(RCC->CFGR & RCC_CFGR_PLLMUL) >> 18UL];
                div = ((RCC->CFGR & RCC_CFGR_PLLDIV) >> 22UL) + 1UL;
                clk = (16000000UL * mul) / div;
            } else {
                clk = 0UL;
            }
            break;
        }

        default : {
            clk = 0UL;
            break;
        }
    }

    if (0UL != clk) {
        uint32_t div;

        div = RCC->CFGR & RCC_CFGR_HPRE;

        if (div & 0x08UL) {
            div = 2UL << (div & ~0x08UL);
            clk = clk / div;
        }
    }

    return (clk);
}

/*----------------------------------------------------------------------------*/
void sysInit(
    void) {

    RCC->CIR = 0UL;                                                             /* Disable all interrupts                                   */
    sysPerfSetDefault();
}

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of sys.c
 ******************************************************************************/
