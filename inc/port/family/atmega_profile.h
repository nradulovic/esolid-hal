/******************************************************************************
 * This file is part of esolid-hal
 *
 * Template version: 1.1.15 (20.05.2012)
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * esolid-hal is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * esolid-hal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with esolid-hal; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *//***********************************************************************//**
 * @file
 * @author      Dejan Ristic
 * @brief       Profil familije za ATmega seriju.
 * @addtogroup  port_atmega
 *********************************************************************//** @{ */

#ifndef ATMEGA_PROFILE_H_
#define ATMEGA_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  MACRO's  ==*/

#if defined(OPT_HAL_STARTUP)
# define ES_HAL_ENABLE_STARTUP
#endif

#if defined(OPT_HAL_CPU)
# define ES_HAL_ENABLE_CPU
#endif

#if defined(OPT_HAL_INTERRUPT)
# define ES_HAL_ENABLE_INTERRUPT
#endif

/*------------------------------------------------------------------------*//**
 * @name        ATmega opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i proizvodjacu.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Proizvodzac mikrokontrolera
 */
#define ES_HAL_MCU_MANUF                "Atmel"

/**
 * @brief       Familija mikrokontrolera
 */
#define ES_HAL_MCU_FAMILY               "ATmega"

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        STM32F10x konstante mogucnosti
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Port podrzava start-up kod i linker skriptu
 */
#define ES_HAL_FEATURE_STARTUP

/**
 * @brief       Port podrzava CPU
 */
#define ES_HAL_FEATURE_CPU

/**
 * @brief       Port podrzava interrupt
 */
#define ES_HAL_FEATURE_INTERRUPT

/** @} *//*-------------------------------------------------------------------*/
/*============================================================  DATA TYPES  ==*/

#if defined(ES_HAL_ENABLE_INTERRUPT)
/*
 * Ako ATmega nema prioritet prekida ona vrednost ES_PRIO_REALTIME i ostale
 * vrednosti treba da zabrane prekide, ES_PRIO_IDLE treba da omoguci prekide.
 * Ovaj enumerator se koristi za makroe ES_CRITICAL_ENTER/ES_CRITICAL_EXIT
 */
enum esInterruptPrio {
    ES_PRIO_IDLE = 0,
    ES_PRIO_VERY_LOW = 1,
    ES_PRIO_LOW = 1,
    ES_PRIO_BELOW_NORMAL = 1,
    ES_PRIO_NORMAL = 1,
    ES_PRIO_ABOVE_NORMAL = 1,
    ES_PRIO_HIGH = 1,
    ES_PRIO_VERY_HIGH = 1,
    ES_PRIO_REALTIME = 1
};
#endif

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of atmega_profile.h
 ******************************************************************************/
#endif /* ATMEGA_PROFILE_H_ */
