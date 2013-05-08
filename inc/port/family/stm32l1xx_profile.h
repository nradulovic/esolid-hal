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
 * @author  	Nenad Radulovic
 * @brief       Profil familije za STM32L1xx seriju.
 * @addtogroup  port_stm32l1xx
 *********************************************************************//** @{ */

#ifndef STM32L1XX_PROFILE_H_
#define STM32L1XX_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

#if defined(OPT_HAL_STARTUP)
# define ES_HAL_ENABLE_STARTUP
#endif

#if defined(OPT_HAL_CPU)
# define ES_HAL_ENABLE_CPU
#endif

#if defined(OPT_HAL_INTERRUPT)
# define ES_HAL_ENABLE_INTERRUPT
#endif

#if defined(OPT_HAL_GPIO)
# define ES_HAL_ENABLE_GPIO
#endif

/*------------------------------------------------------------------------*//**
 * @name        STM32L1xx opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i proizvodjacu.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Proizvodzac mikrokontrolera
 */
#define ES_HAL_MCU_MANUF                "STMicroelectronics"

/**
 * @brief       Familija mikrokontrolera
 */
#define ES_HAL_MCU_FAMILY               "STM32L1xx device"

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        STM32L1xx konstante mogucnosti
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Port podrzava start-up kod i linker skriptu
 */
#define ES_HAL_FEATURE_STARTUP

/**
 * @brief       Port podrzava GPIO
 */
#define ES_HAL_FEATURE_GPIO

/**
 * @brief       Port podrzava CPU
 */
#define ES_HAL_FEATURE_CPU

/**
 * @brief       Port podrzava interrupt
 */
#define ES_HAL_FEATURE_INTERRUPT

/** @} *//*-------------------------------------------------------------------*/

/** @} *//*-------------------------------------------------------------------*/
/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        STM32L1xx pomocni makroi za formiranje tabela hardvera
 * @{ *//*--------------------------------------------------------------------*/
#define EXPAND_AS_GPIO_ENUM(a, b, c)    a,

/** @} *//*-------------------------------------------------------------------*/
/*============================================================  DATA TYPES  ==*/

#if defined(ES_HAL_ENABLE_INTERRUPT)
enum esInterruptPrio {
    ES_PRIO_IDLE = 0,
    ES_PRIO_VERY_LOW = 255,
    ES_PRIO_LOW = 254,
    ES_PRIO_BELOW_NORMAL = 192,
    ES_PRIO_NORMAL = 128,
    ES_PRIO_ABOVE_NORMAL = 64,
    ES_PRIO_HIGH = 32,
    ES_PRIO_VERY_HIGH = 2,
    ES_PRIO_REALTIME = 0x20
};
#endif

#if defined(ES_HAL_ENABLE_GPIO)
typedef enum esGpioPort {
    GPIO_TABLE_(EXPAND_AS_GPIO_ENUM)
    GPIO_LAST_PORT_
} esGpioPort_T;
#endif

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32l1xx_profile.h
 ******************************************************************************/
#endif /* STM32L1XX_PROFILE_H_ */
