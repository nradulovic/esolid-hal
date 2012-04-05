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
    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;                                    /* Reset hardvera - aktivno.                                */
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;                                   /* Reset hardvera - neaktivno.                              */
    RCC->APB2ENR  &= ~RCC_APB2ENR_USART1EN;                                     /* Iskljuci takt.                                           */
    RCC->APB2LPENR &= ~RCC_APB2LPENR_USART1LPEN;                                /* Iskljuci low-power takt.                                 */
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
    uart2drv.regs = USART2;
    RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
    RCC->APB1ENR  &= ~RCC_APB1ENR_USART2EN;
    RCC->APB1LPENR &= ~RCC_APB2LPENR_USART2LPEN;
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
    uart3drv.regs = USART3;
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
    GPIO_InitTypeDef GPIO_InitStructure;

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
    if (esUART1 == aUart) {
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    }
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
    if (esUART2 == aUart) {
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    }
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
    if (esUART2 == aUart) {
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    }
#endif


}

#endif /* OPT_HAL_UART */
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of uart_lld.c
 *//** @} *//*************************************************************************************/
