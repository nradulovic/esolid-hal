/*************************************************************************************************
 * This file is part of eSolid
 *
 * Copyright (C) 2011 - Nenad Radulovic
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
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 *
 * @author      nesa
 *
 * @brief       Interfejs za UART modul STM32L1xx Medium Density serija, port
 *              klasa: varijanta.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * @addtogroup  hal_usart
 *
 ****************************************************************************************//** @{ */


#ifndef VARNT_UART_H_
#define VARNT_UART_H_


/*************************************************************************************************
 * INCLUDE FILES
 *************************************************************************************************/

#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_usart.h"

/*-----------------------------------------------------------------------------------------------*
 * Module dependencies
 *-----------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------*
 * Module configuration and adapter
 *-----------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------*
 * EXTERNS
 *-----------------------------------------------------------------------------------*//** @cond */


#ifdef VARNT_UART_H_VAR
#define VARNT_UART_H_EXT
#else
#define VARNT_UART_H_EXT extern
#endif


/** @endcond*//***********************************************************************************
 * DEFINES
 *************************************************************************************************/


/*************************************************************************************************
 * MACRO's
 *************************************************************************************************/

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
#define esUART1                                                                 \
    ((esUartDrv_T *)&uart1drv)

#define DBG_VALID_UART1_DRV(val)                                                \
    (esUART1 == (val))
#else
#define DBG_VALID_UART1_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
#define esUART2                                                                 \
    ((esUartDrv_T *)&uart2drv)

#define DBG_VALID_UART2_DRV(val)                                                \
    (esUART2 == (val))
#else
#define DBG_VALID_UART2_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
#define esUART3                                                                 \
    ((esUartDrv_T *)&uart3drv)

#define DBG_VALID_UART3_DRV(val)                                                \
    (esUART3 == (val))
#else
#define DBG_VALID_UART3_DRV(val)                                                \
    (0U)
#endif


/*-----------------------------------------------------------------------------------------------*
 * C/C++ #ifdef - open
 *-----------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************
 * DATA TYPES
 *************************************************************************************************/

typedef struct uartDrvExt uartDrvExt_T;

/*************************************************************************************************
 * GLOBAL VARIABLES
 *************************************************************************************************/

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
VARNT_UART_H_EXT uartDrvExt_T uart1drv;
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
VARNT_UART_H_EXT uartDrvExt_T esUart2drv;
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
VARNT_UART_H_EXT uartDrvExt_T esUart3drv;
#endif


/*************************************************************************************************
 * FUNCTION PROTOTYPES
 *************************************************************************************************/


/*-----------------------------------------------------------------------------------------------*
 * C/C++ #endif - close
 *-----------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


/*************************************************************************************************
 * CONFIGURATION ERRORS
 *************************************************************************************//** @cond */


/** @endcond *//** @} *//*************************************************************************
 * END of usart.h
 *************************************************************************************************/
#endif /* VARNT_UART_H_ */
