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
 *//******************************************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief   	Konfiguracija HAL-a.
 * ------------------------------------------------------------------------------------------------
 * @defgroup	hal_cfg HAL configuration
 ****************************************************************************************//** @{ */


#ifndef HAL_CFG_H_
#define HAL_CFG_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "hal_config.h"

/*==================================================================================  DEFINES  ==*/
/*=================================================================================  SETTINGS  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Maksimalni prioritet koji eSolid HAL koristi.
 * @details     Ova opcija ogranicava maksimalni prioritet izvrsavanja eSolid
 *              HAL kriticnih sekcija. Ovo omogucava da se koriste odredjeni
 *              prekidi u sistemu i u toku izvrsenja kriticnih sekcija koda.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_INTERRUPT_PRIO
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @name        Omogucivanje pojedinacnih modula
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje GPIO modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_GPIO
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje UART modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Podesavanja za UART modul
 * @{ *//*---------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_USE_1
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_USE_2
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_USE_3
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_USE_4
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Debug podrska
 * @brief       Makroi za debug podrsku. Pogledati @ref dbg_intf.
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_DBG_HAL) || defined(__DOXYGEN__)
# define HAL_ASSERT                     DBG_ASSERT
# define HAL_ASSERT_ALWAYS              DBG_ASSERT_ALWAYS
# define HAL_COMPILE_ASSERT             DBG_COMPILE_ASSERT
# define HAL_DBG_DECL                   DBG_DECL
# define HAL_DBG_DEFINE_MODULE          DBG_DEFINE_MODULE
# define HAL_DBG_ENTRY                  DBG_ENTRY
# define HAL_DBG_EXIT                   DBG_EXIT
# define HAL_DBG_MACRO                  DBG_MACRO
# define HAL_DBG_CHECK                  DBG_CHECK
#else
# define HAL_ASSERT(expr)               DBG_EMPTY_MACRO()
# define HAL_ASSERT_ALWAYS(expr)        DBG_EMPTY_MACRO()
# define HAL_COMPILE_ASSERT(expr)       DBG_EMPTY_DECL()
# define HAL_DBG_DECL(expr)             DBG_EMPTY_DECL()
# define HAL_DBG_DEFINE_MODULE(expr)    DBG_EMPTY_DECL()
# define HAL_DBG_ENTRY()                DBG_EMPTY_MACRO()
# define HAL_DBG_EXIT()                 DBG_EMPTY_MACRO()
# define HAL_DBG_MACRO(expr)            DBG_EMPTY_MACRO()
# define HAL_DBG_CHECK(expr)            DBG_EMPTY_MACRO()
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/


/** @endcond *//** @} *//*************************************************************************
 * END of hal_cfg.h
 *************************************************************************************************/
#endif /* HAL_CFG_H_ */
