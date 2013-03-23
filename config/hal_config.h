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
 * @brief       Konfiguracija HAL-a
 * @addtogroup  hal_cfg
 *********************************************************************//** @{ */

#ifndef HAL_CONFIG_H_
#define HAL_CONFIG_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/* #define STM32L152RB */
#define STM32F100RB
#define OPT_HAL_CPU
#define OPT_HAL_INTERRUPT
#define OPT_HAL_GPIO

/*==============================================================  SETTINGS  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Omogucivanje pojedinacnih modula
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Omogucivanje CPU modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_CPU
#endif

/**
 * @brief       Omogucivanje Interrupt modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_INTERRUPT
#endif

/**
 * @brief       Omogucivanje GPIO modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_GPIO
#endif

/**
 * @brief       Omogucivanje UART modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_UART
#endif

/**
 * @brief       Omogucivanje TIMER modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_TIMER
#endif

/**
 * @brief       Omogucivanje cyclic redundancy check (CRC) modula
 * @details     Ukoliko je podesavanje:
 *              - definisano - modul je omogucen,
 *              - nedefinisano - moduj je onemogucen.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_CRC
#endif

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Podesavanja za UART modul
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_1
#endif

/**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_2
#endif

/**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_3
#endif

/**
 * @brief       Omogucivanje pojedinih UART modula
 * @pre         Mora da bude definisana promenljiva @ref OPT_HAL_UART.
 */
#if defined(__DOXYGEN__)
# define OPT_HAL_UART_4
#endif

/** @} *//*-------------------------------------------------------------------*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_config.h
 ******************************************************************************/
#endif /* HAL_CONFIG_H_ */
