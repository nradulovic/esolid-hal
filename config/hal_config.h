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
 * @brief   	Konfiguracija HAL-a
 * ------------------------------------------------------------------------------------------------
 * @defgroup    hal_cfg HAL configuration
 ****************************************************************************************//** @{ */


#ifndef HAL_CONFIG_H_
#define HAL_CONFIG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/

#define STM32L152RB
#define OPT_HAL_CPU
#define OPT_HAL_INTERRUPT

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
 * @brief       Omogucivanje CPU modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_CPU
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje Interrupt modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_INTERRUPT
#endif

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

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje debug (DBG) modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_DBG
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje TIMER modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_TIMER
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje cyclic redundancy check (CRC) modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_CRC
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
# define OPT_HAL_UART_1
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_2
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_3
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_4
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Podesavanja za Debug (DBG) modul
 * @{ *//*---------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------*//**
 * @brief       Ukljucivanje/iskljucivanje ASSERT makroa
 * @details     Ukoliko je ova opcija:
 *              - definisana - Assert makroi su ukljuceni,
 *              - nedefinisana - Assert makroi su iskljuceni u svim projektima
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_DBG_ASSERT
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Ukljucivanje/iskljucivanje CHECK makroa
 * @details     Ukoliko je ova opcija:
 *              - definisana - Check makroi su ukljuceni,
 *              - nedefinisana - Check makroi su iskljuceni u svim projektima
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_DBG_CHECK
#endif

/*--------------------------------------------------------------------------------------------*//**
 * @brief       Ukljucivanje/iskljucivanje TRACE makroa
 * @details     Ukoliko je ova opcija:
 *              - definisana - Trace makroi su ukljuceni,
 *              - nedefinisana - Trace makroi su iskljuceni u svim projektima
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define OPT_HAL_DBG_TRACE
#endif

/** @} *//*--------------------------------------------------------------------------------------*/

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_config.h
 *************************************************************************************************/
#endif /* HAL_CONFIG_H_ */
