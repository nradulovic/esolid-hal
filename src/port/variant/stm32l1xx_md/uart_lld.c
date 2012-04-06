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
 * @addtogroup  stm32l1xx_md_impl
 ****************************************************************************************//** @{ */
/**
 * @defgroup    stm32l1xx_md_uart_impl
 * @brief
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#define VARNT_UART_H_EXT
#include "../src/hal/uart_pkg.h"

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

struct uartDrvExt {
    esUartDrv_T     super;
    USART_TypeDef   * regs;
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
#if defined(OPT_HAL_UART) || defined(__DOXYGEN__)
/*-----------------------------------------------------------------------------------------------*/
void lldUartDrvInit(
    void) {

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
    uart1drv.regs = USART1;
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST;                                       /* Reset GPIO hardvera - aktivno.                           */
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOARST;                                      /* Reset GPIO hardvera - neaktivno.                         */
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOAEN;                                        /* Iskljuci GPIO takt.                                      */
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOALPEN;                                   /* Iskljuci GPIO lowpower takt                              */
    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;                                    /* Reset UART hardvera - aktivno.                           */
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;                                   /* Reset UART hardvera - neaktivno.                         */
    RCC->APB2ENR  &= ~RCC_APB2ENR_USART1EN;                                     /* Iskljuci UART takt.                                      */
    RCC->APB2LPENR &= ~RCC_APB2LPENR_USART1LPEN;                                /* Iskljuci UART low-power takt.                            */
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
    uart2drv.regs = USART2;
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOARST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOAEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOALPEN;
    RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
    RCC->APB1ENR  &= ~RCC_APB1ENR_USART2EN;
    RCC->APB1LPENR &= ~RCC_APB2LPENR_USART2LPEN;
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
    uart3drv.regs = USART3;
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOBRST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOBRST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOBEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOBLPEN;
    RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST;
    RCC->APB1ENR  &= ~RCC_APB1ENR_USART3EN;
    RCC->APB1LPENR &= ~RCC_APB2LPENR_USART3LPEN;
#endif
}

/*-----------------------------------------------------------------------------------------------*/
void lldUartDrvStart(
    esUartDrv_T     * aUart) {

    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
    if (esUART1 == aUart) {
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;                                      /* Ukljuci GPIO takt.                                       */
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;                                   /* Ukljuci UART takt.                                       */

        switch (aUart->drvDef.uartMode) {
            case ES_UART_MODE_RX_ONLY : {
                GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH10;                             /* Ocisti AF polje pin-a.                                   */
                GPIOA->AFR[1] |= (UART1_GPIO_AFIO << UART1_GPIO_AFIO_POS_RX);   /* Postavi potrebnu AF vrednost.                            */
                GPIOA->MODER &= ~GPIO_MODER_MODER10;                            /* Ocisti polje za rezim rada.                              */
                GPIOA->MODER |= GPIO_MODER_MODER10_1;                           /* Postavi AF rezim rada pina.                              */
                GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;                      /* Maksimalna brzina rada.                                  */
                GPIOA->OTYPER &= ~GPIO_OTYPER_OT_10;                            /* Izlaz je u Push-pull rezimu.                             */
                GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR10;                            /* Ne koriste se pull-up/pull-down otpornici.               */
                break;
            }

            case ES_UART_MODE_TX_ONLY : {
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
                HAL_DBG_CHECK(ES_UART_MODE_TX_AND_RX == aUart->drvDef.uartMode);
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
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
    if (esUART2 == aUart) {
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    }
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
    if (esUART2 == aUart) {
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    }
#endif


}

void lldUartDrvStop(
    esUartDrv_T     * aUart) {

}
#endif /* OPT_HAL_UART */
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of uart_lld.c
 *//** @} *//*************************************************************************************/
