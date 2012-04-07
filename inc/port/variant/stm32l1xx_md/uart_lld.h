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
 * @author  	Nenad Radulovic
 * @brief       Interfejs UART Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_uart
 ****************************************************************************************//** @{ */


#ifndef UART_LLD_H_
#define UART_LLD_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_usart.h"

/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef UART_LLD_H_VAR
# define UART_LLD_H_EXT
#else
# define UART_LLD_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Definition group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_UART)
# if defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
#  define esUART1                       ((esUartDrv_T *)&uart1drv)
# endif

# if defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
#  define esUART2                       ((esUartDrv_T *)&uart2drv)
# endif

# if defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
#  define esUART3                       ((esUartDrv_T *)&uart3drv)
# endif
#endif /* OPT_HAL_UART */
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Macro group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
#define DBG_VALID_UART1_DRV(val)                                                \
    (esUART1 == (val))
#else
#define DBG_VALID_UART1_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
#define DBG_VALID_UART2_DRV(val)                                                \
    (esUART2 == (val))
#else
#define DBG_VALID_UART2_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
#define DBG_VALID_UART3_DRV(val)                                                \
    (esUART3 == (val))
#else
#define DBG_VALID_UART3_DRV(val)                                                \
    (0U)
#endif

#define UART_DRV_LIST(uart)                                                     \
    (DBG_VALID_UART1_DRV(uart) ||                                               \
     DBG_VALID_UART2_DRV(uart) ||                                               \
     DBG_VALID_UART3_DRV(uart))

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Data types group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
typedef struct uartDrvIntr {
    USART_TypeDef   * regs;
} uartDrvIntr_T;

typedef struct esUartId {
    USART_TypeDef   * regs;
    uint8_t         number;
} esUartHwId_T;

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Function group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if !defined(OPT_HAL_GPIO) && defined(OPT_HAL_UART)
# error "HAL=>UART: You must enable OPT_HAL_GPIO option to manage the UART pins."
#else
# if defined(OPT_HAL_UART)
#  if defined(OPT_HAL_UART_USE_1)
#   if !defined(OPT_HAL_GPIO_USE_A)
#    error "HAL=>UART: You must enable OPT_HAL_GPIO_USE_A option to manage UART1 pins"
#   endif
#  endif
#  if defined(OPT_HAL_UART_USE_2)
#   if !defined(OPT_HAL_GPIO_USE_A)
#    error "HAL=>UART: You must enable OPT_HAL_GPIO_USE_A option to manage UART2 pins"
#   endif
#  endif
#  if defined(OPT_HAL_UART_USE_3)
#   if !defined(OPT_HAL_GPIO_USE_A)
#    error "HAL=>UART: You must enable OPT_HAL_GPIO_USE_B option to manage UART3 pins"
#   endif
#  endif
#  if defined(OPT_HAL_UART_USE_4)
#   error "HAL=>UART: This port does not support OPT_HAL_UART_USE_4"
#  endif
# endif
#endif


/** @endcond *//** @} *//*************************************************************************
 * END of uart_lld.h
 *************************************************************************************************/
#endif /* UART_LLD_H_ */
