/*************************************************************************************************
 * This file is part of eSolid
 *
 * Template version: 1.1.13 (24.03.2012)
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
 *//******************************************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Implementacija UART Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_uart_impl
 ****************************************************************************************//** @{ */


#ifndef UART_PKG_H_
#define UART_PKG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef UART_PKG_H_VAR
# define UART_PKG_H_EXT
#else
# define UART_PKG_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Macro group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(ES_ENABLE_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
#define DBG_VALID_UART1_DRV(val)                                                \
    (esUART1 == (val))
#else
#define DBG_VALID_UART1_DRV(val)                                                \
    (0U)
#endif

#if defined(ES_ENABLE_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
#define DBG_VALID_UART2_DRV(val)                                                \
    (esUART2 == (val))
#else
#define DBG_VALID_UART2_DRV(val)                                                \
    (0U)
#endif

#if defined(ES_ENABLE_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
#define DBG_VALID_UART3_DRV(val)                                                \
    (esUART3 == (val))
#else
#define DBG_VALID_UART3_DRV(val)                                                \
    (0U)
#endif

#define UART_DRVID_LIST(uart)                                                   \
    (DBG_VALID_UART1_DRV(uart) ||                                               \
     DBG_VALID_UART2_DRV(uart) ||                                               \
     DBG_VALID_UART3_DRV(uart))
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Globalne, privatne funkcije
 * @brief       Ove funkcije definise port
 * @details     Funkcije koje pripadaju ovoj grupi nisu namenjene da ih korisnik
 *              direktno poziva vec se koriste od strane samog HAL sistema.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizacije UART drajver modula
 * @details     Ova funkcija se poziva automatski u toku inicijalizacije HAL
 *              paketa.
 *//*--------------------------------------------------------------------------------------------*/
void lldUartDrvInit(
    void);

void lldUartDrvStart(
    esUartDrv_T     * aUart);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of uart_pkg.h
 *************************************************************************************************/
#endif /* UART_PKG_H_ */
