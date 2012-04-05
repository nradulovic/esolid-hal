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
#include "../src/hal/uart_pkg.h"

/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_DEFINE_MODULE(UART Low Level Driver);

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
/**
 * @brief       Prekidna rutina za UART1
 */
C_INTERRUPT_HANDLER(USART1_IRQHandler) {

}
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
/**
 * @brief       Prekidna rutina za UART2
 */
C_INTERRUPT_HANDLER(USART2_IRQHandler) {

}
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
/**
 * @brief       Prekidna rutina za UART3
 */
C_INTERRUPT_HANDLER(USART3_IRQHandler) {

}
#endif

/*==============================================================  GLOBAL FUNCTION DEFINITIONS  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of uart_lld.c
 *//** @} *//*************************************************************************************/
