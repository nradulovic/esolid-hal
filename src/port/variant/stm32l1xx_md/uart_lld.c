/*************************************************************************************************
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
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 * @author      Nenad Radulovic
 * @brief       Implementacija UART Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_uart_impl
 * @brief       UART Low Level Driver modul.
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#define UART_LLD_H_VAR
#include "../src/hal/hal_private.h"

#if defined(STM32L1XX_MD_) && defined(ES_FEATURE_UART) || defined(__DOXYGEN__)
/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_DEFINE_MODULE(UART Low Level Driver);

#define UART1_GPIO_AFIO                 (uint32_t)0x07
#define UART1_GPIO_AFIO_POS_TX          (uint32_t)4U
#define UART1_GPIO_AFIO_POS_RX          (uint32_t)8U
#define UART1_GPIO_PORT                 GPIOA
#define UART1_GPIO_PIN_TX               (uint32_t)9U
#define UART1_GPIO_PIN_RX               (uint32_t)10U
#define GPIO_AFIO_UART2                 (uint32_t)0x07
#define GPIO_AFIO_UART3                 (uint32_t)0x07

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Interni, jedinstveni podaci UART drajvera.
 * @details     Ova struktura se instacira po jednom UART modulu. U njoj se
 *              cuvaju status UART modula.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct uartIntr {
/**
 * @brief       Status predajnika.
 */
    esDevStatus_T       txStatus;

/**
 * @brief       Status prijemnika.
 */
    esDevStatus_T       rxStatus;
};

/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/


void uartDrvHandler(
    esUartDrv_T     * aDriver);

/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
/**
 * @brief       Prekidna rutina za UART1
 */
C_INTERRUPT_HANDLER(USART1_IRQHandler) {

    uartDrvHandler(
        esUART1);
}
#endif

/*-----------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
/**
 * @brief       Prekidna rutina za UART2
 */
C_INTERRUPT_HANDLER(USART2_IRQHandler) {

    uartDrvHandler(
        esUART2);
}
#endif

/*-----------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
/**
 * @brief       Prekidna rutina za UART3
 */
C_INTERRUPT_HANDLER(USART3_IRQHandler) {

    uartDrvHandler(
        esUART3);
}
#endif

/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void lldUartDrvInit(
    void) {

#if defined(OPT_HAL_UART)
# if defined(OPT_HAL_UART_USE_1)
    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;                                    /* Reset UART hardvera - aktivno.                           */
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;                                   /* Reset UART hardvera - neaktivno.                         */
    RCC->APB2ENR  &= ~RCC_APB2ENR_USART1EN;                                     /* Iskljuci UART takt.                                      */
    RCC->APB2LPENR &= ~RCC_APB2LPENR_USART1LPEN;                                /* Iskljuci UART low-power takt.                            */
# endif

# if defined(OPT_HAL_UART_USE_2)
    RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
    RCC->APB1ENR  &= ~RCC_APB1ENR_USART2EN;
    /*
     RCC->APB1LPENR &= ~RCC_APB2LPENR_USART;
     */
# endif

# if defined(OPT_HAL_UART_USE_3)
    RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST;
    RCC->APB1ENR  &= ~RCC_APB1ENR_USART3EN;
    /*
    RCC->APB1LPENR &= ~RCC_APB2LPENR_USART3LPEN;
    */
# endif
#endif /* OPT_HAL_UART */
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartStatus(
    esUartDrv_T     * uart) {

    HAL_DBG_CHECK(NULL != uart);                                                /* Provera par: da li je uart inicijalizovan?               */
    HAL_DBG_CHECK(UART_DRVID_LIST(uart->drvId));                                /* Provera par: da li je drvId validan?                     */

}

/*-----------------------------------------------------------------------------------------------*/
void lldUartDrvStart(
    esUartDrv_T     * aUart) {

#if defined(OPT_HAL_UART)
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

# if defined(OPT_HAL_UART_USE_1)
    if (esUART1 == aUart) {
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;                                      /* Ukljuci GPIO takt.                                       */
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;                                   /* Ukljuci UART takt.                                       */

        switch (aUart->drvDef.mode) {
            case ES_UART_MODE_RX : {
                GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH10;                             /* Ocisti AF polje pin-a.                                   */
                GPIOA->AFR[1] |= (UART1_GPIO_AFIO << UART1_GPIO_AFIO_POS_RX);   /* Postavi potrebnu AF vrednost.                            */
                GPIOA->MODER &= ~GPIO_MODER_MODER10;                            /* Ocisti polje za rezim rada.                              */
                GPIOA->MODER |= GPIO_MODER_MODER10_1;                           /* Postavi AF rezim rada pina.                              */
                GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;                      /* Maksimalna brzina rada.                                  */
                GPIOA->OTYPER &= ~GPIO_OTYPER_OT_10;                            /* Izlaz je u Push-pull rezimu.                             */
                GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR10;                            /* Ne koriste se pull-up/pull-down otpornici.               */
                break;
            }

            case ES_UART_MODE_TX : {
                GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH9;
                GPIOA->AFR[1] |= (UART1_GPIO_AFIO << UART1_GPIO_AFIO_POS_TX);
                GPIOA->MODER &= ~GPIO_MODER_MODER9;
                GPIOA->MODER |= GPIO_MODER_MODER9_1;
                GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;
                GPIOA->OTYPER &= ~GPIO_OTYPER_OT_9;
                GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR9;
                break;
            }

            default : {
                HAL_DBG_CHECK(ES_UART_MODE_TX_AND_RX == aUart->drvDef.mode);
                GPIOA->AFR[1] &= ~(GPIO_AFRH_AFRH9 | GPIO_AFRH_AFRH10);
                GPIOA->AFR[1] |= ((UART1_GPIO_AFIO << UART1_GPIO_AFIO_POS_TX) | (UART1_GPIO_AFIO << UART1_GPIO_AFIO_POS_RX));
                GPIOA->MODER &= ~(GPIO_MODER_MODER9 | GPIO_MODER_MODER10);
                GPIOA->MODER |= (GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1);
                GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9 | GPIO_OSPEEDER_OSPEEDR10);
                GPIOA->OSPEEDR &= ~(GPIO_OTYPER_OT_9 | GPIO_OTYPER_OT_10);
                GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR9 | GPIO_PUPDR_PUPDR10);
                break;
            }
        }
    }
# endif /* OPT_HAL_UART_USE_1 */

# if defined(OPT_HAL_UART_USE_2)
    if (esUART2 == aUart) {
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    }
# endif /* OPT_HAL_UART_USE_2 */

# if defined(OPT_HAL_UART_USE_3)
    if (esUART2 == aUart) {
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    }
# endif /* OPT_HAL_UART_USE_3 */
#else /* OPT_HAL_UART */
    (void)aUart;
#endif /* !OPT_HAL_UART */
}

/*-----------------------------------------------------------------------------------------------*/
void esUartInit(
    const C_ROM esUartId_T * uartId,
    const C_ROM esUartDef_T * uartDef,
    esUartDrv_T     * uart) {

    HAL_DBG_CHECK((const C_ROM esUartId_T *)0U != uartId);                      /* Provera par: da li je uartId inicijalizovan?             */
    HAL_DBG_CHECK((const C_ROM esUartDef_T *)0U != uartDef);                    /* Provera par: da li je uartDef inicijalizovan?            */
    HAL_DBG_CHECK(NULL != uart);                                                /* Provera par: da li je uart inicijalizovan?               */
    HAL_DBG_CHECK(UART_DRVID_LIST(uartId));                                     /* Provera par: da li je uartId validan?                    */
    HAL_DBG_CHECK(
        (ES_UART_DATA_7_BITS == uartDef->dataBits) ||
        (ES_UART_DATA_8_BITS == uartDef->dataBits) ||
        (ES_UART_DATA_9_BITS == uartDef->dataBits));                            /* Provera par: da li je dataBits validan enumerator?       */
    HAL_DBG_CHECK(
        (ES_UART_STOP_HALF_BIT == uartDef->stopBits) ||
        (ES_UART_STOP_ONE_AND_HALF_BIT == uartDef->stopBits) ||
        (ES_UART_STOP_ONE_BIT == uartDef->stopBits) ||
        (ES_UART_STOP_TWO_BITS == uartDef->stopBits));                          /* Provera par: da li je stopBits validan enumerator?       */
    HAL_DBG_CHECK(
        (ES_UART_MODE_RX == uartDef->mode) ||
        (ES_UART_MODE_TX == uartDef->mode) ||
        (ES_UART_MODE_TX_AND_RX == uartDef->mode));                             /* Provera par: da li je mode validan enumerator?           */

}



/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#else /* STM32F10X_MD_VL_ && ES_FEATURE_GPIO */
extern char bogusVar;                                                           /* Neki kompajleri ne prihvataju praznu C datoteku. */
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of uart_lld.c
 *//**********************************************************************************************/
