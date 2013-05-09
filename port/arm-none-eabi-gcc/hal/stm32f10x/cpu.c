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
 * @brief       Sistemski drajver za STM32F10x seriju.
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */

/*=========================================================  INCLUDE FILES  ==*/
#include "hal/hal_cpu.h"
#include "stm32f10x_pkg.h"

/*=========================================================  LOCAL DEFINES  ==*/
/*=========================================================  LOCAL MACRO's  ==*/
/*======================================================  LOCAL DATA TYPES  ==*/
/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Maksimalne performanse
 * @details     AHB, APB magistrale su na SYSCLK
 */
static void sysPerfHigh(
    void);

/**
 * @brief       Postavlja SYSCLK na 8MHz
 * @details     AHB, APB magistrale su na SYSCLK
 */
static void sysPerfDef(
    void);

/**
 * @brief       Postavlja najnizi takt za SYSCLK
 * @details     AHB, APB magistrale su na minimumu
 */
static void sysPerfLow(
    void);

/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
static void sysPerfHigh(
    void) {

    uint32_t startUpCntr;
    uint32_t status;

    RCC->CR |= RCC_CR_HSION;                                                    /* Enable HSE                                               */
    startUpCntr = 0UL;

    do {
        status = RCC->CR & RCC_CR_HSIRDY;
        startUpCntr++;
    } while ((0UL == status) && (HSE_STARTUP_TIMEOUT != startUpCntr));

    if (0UL != status) {

#if (24000000UL == PORT_MAX_CPU_FREQ_)

# if defined(STM32F10X_LD) || defined(STM32F10X_LD_VL) ||                       \
    defined(STM32F10X_MD) || defined(STM32F10X_MD_VL)

        if (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
            ES_HWREG_SET(
                RCC->CFGR,
                RCC_CFGR_SW,
                RCC_CFGR_SW_HSI);

            while (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
                ;
            }
        }
        ES_HWREG_SET(
            RCC->CR,
            RCC_CR_HSEON | RCC_CR_PLLON,
            0UL);
        FLASH->ACR &= ~FLASH_ACR_HLFCYA;
        RCC->CFGR &= ~RCC_CFGR_PLLSRC;                                          /* PLL source = HSI/2                                       */
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_PLLMULL,
            RCC_CFGR_PLLMULL6);
        RCC->CR |= RCC_CR_PLLON;

        while (0UL == (RCC->CR & RCC_CR_PLLRDY)) {
            ;
        }
        ES_HWREG_SET(
            RCC->CFGR,
            RCC_CFGR_SW,
            RCC_CFGR_SW_PLL);

        while (RCC_CFGR_SWS_PLL != (RCC->CFGR & RCC_CFGR_SWS)) {
            ;
        }
# elif defined(STM32F10X_HD) || defined(STM32F10X_HD_VL)
# error "NOT IMPLEMENTED"
# else
# error "NOT IMPLEMENTED"
# endif
#else
# error "NOT IMPLEMENTED"
#endif
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK                                            */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV1);
        ES_HWREG_SET(                                                           /* PCLK2 = SYSCLK                                           */
            RCC->CFGR,
            RCC_CFGR_PPRE1,
            RCC_CFGR_PPRE1_DIV1);
        ES_HWREG_SET(                                                           /* PCLK1 = HCLK                                             */
            RCC->CFGR,
            RCC_CFGR_PPRE2,
            RCC_CFGR_PPRE2_DIV1);
    } else {
        /* Greska! HSI nece da se upali. */
    }
}

/*----------------------------------------------------------------------------*/
static void sysPerfDef(
    void) {

    uint32_t startUpCntr;
    uint32_t status;

    RCC->CR |= RCC_CR_HSION;                                                    /* Enable HSE                                               */
    startUpCntr = 0UL;

    do {
        status = RCC->CR & RCC_CR_HSIRDY;
        startUpCntr++;
    } while ((0UL == status) && (HSE_STARTUP_TIMEOUT != startUpCntr));

    if (0UL != status) {

#if defined(STM32F10X_LD) || defined(STM32F10X_LD_VL) ||                        \
    defined(STM32F10X_MD) || defined(STM32F10X_MD_VL)

        if (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
            ES_HWREG_SET(
                RCC->CFGR,
                RCC_CFGR_SW,
                RCC_CFGR_SW_HSI);

            while (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
                ;
            }
        }
        ES_HWREG_SET(
            RCC->CR,
            RCC_CR_HSEON | RCC_CR_PLLON,
            0UL);
        FLASH->ACR &= ~FLASH_ACR_HLFCYA;

#elif defined(STM32F10X_HD) || defined(STM32F10X_HD_VL)
#error "NOT IMPLEMENTED"
#else
#error "NOT IMPLEMENTED"
#endif
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK                                            */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV1);
        ES_HWREG_SET(                                                           /* PCLK2 = SYSCLK                                           */
            RCC->CFGR,
            RCC_CFGR_PPRE1,
            RCC_CFGR_PPRE1_DIV1);
        ES_HWREG_SET(                                                           /* PCLK1 = HCLK                                             */
            RCC->CFGR,
            RCC_CFGR_PPRE2,
            RCC_CFGR_PPRE2_DIV1);
    } else {
        /* Greska! HSI nece da se upali. */
    }
}

/*----------------------------------------------------------------------------*/
static void sysPerfLow(
    void) {

    uint32_t startUpCntr;
    uint32_t status;

    RCC->CR |= RCC_CR_HSION;                                                    /* Enable HSE                                               */
    startUpCntr = 0UL;

    do {
        status = RCC->CR & RCC_CR_HSIRDY;
        startUpCntr++;
    } while ((0UL == status) && (HSE_STARTUP_TIMEOUT != startUpCntr));

    if (0UL != status) {

#if defined(STM32F10X_LD) || defined(STM32F10X_LD_VL) ||                        \
    defined(STM32F10X_MD) || defined(STM32F10X_MD_VL)

        if (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
            ES_HWREG_SET(
                RCC->CFGR,
                RCC_CFGR_SW,
                RCC_CFGR_SW_HSI);

            while (RCC_CFGR_SWS_HSI != (RCC->CFGR & RCC_CFGR_SWS)) {
                ;
            }
        }
        ES_HWREG_SET(
            RCC->CR,
            RCC_CR_HSEON | RCC_CR_PLLON,
            0UL);
        FLASH->ACR &= ~FLASH_ACR_HLFCYA;

#elif defined(STM32F10X_HD) || defined(STM32F10X_HD_VL)
#error "NOT IMPLEMENTED"
#else
#error "NOT IMPLEMENTED"
#endif
#if defined(NDEBUG)
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK / 512                                      */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV512);
#else
        ES_HWREG_SET(                                                           /* HCLK = SYSCLK / 1                                        */
            RCC->CFGR,
            RCC_CFGR_HPRE,
            RCC_CFGR_HPRE_DIV1);
#endif
        ES_HWREG_SET(                                                           /* PCLK2 = HCLK / 16                                        */
            RCC->CFGR,
            RCC_CFGR_PPRE1,
            RCC_CFGR_PPRE1_DIV16);
        ES_HWREG_SET(                                                           /* PCLK1 = HCLK / 16                                        */
            RCC->CFGR,
            RCC_CFGR_PPRE2,
            RCC_CFGR_PPRE2_DIV16);
    } else {
        /* Greska! HSI nece da se upali. */
    }
}

/*===================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*====================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
void esSysPerfSet(
    esSysPerf_T    speed) {

    switch (speed) {

        case ES_SYS_PERF_HIGH : {
            sysPerfHigh();
            break;
        }

        case ES_SYS_PERF_LOW : {
            sysPerfLow();
            break;
        }

        default : {
            sysPerfDef();
            break;
        }
    }
}

/*----------------------------------------------------------------------------*/
uint32_t esSysCoreClockGet(
    void) {

    uint32_t clk;
    uint32_t div;

    switch (RCC->CFGR & RCC_CFGR_SWS) {
        case RCC_CFGR_SWS_HSI : {
            clk = 16000000UL;
            break;
        }

        case RCC_CFGR_SWS_PLL : {
            uint32_t mul;

            if (RCC_CFGR_PLLSRC_PREDIV1 == (RCC->CFGR & RCC_CFGR_PLLSRC)) {
                clk = 1000000UL / (1 << (RCC->CFGR2 & RCC_CFGR2_PREDIV1));
            } else {
                clk = 4000000UL;
            }
            mul = ((RCC->CFGR & RCC_CFGR_PLLMULL) >> 18UL) + 2UL;
            clk *= mul;
            break;
        }

        default : {
            clk = 1000000UL;
            break;
        }
    }
    div = (RCC->CFGR & RCC_CFGR_HPRE) >> 4UL;

    if (div & 0x08UL) {
        div = 2UL << (div & ~0x08UL);
        clk = clk / div;
    }

    return (clk);
}

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of cpu.c
 ******************************************************************************/
