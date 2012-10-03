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
 * @brief       Profil familije za STM32L1xx seriju.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_stm32l1xx
 ****************************************************************************************//** @{ */


#ifndef STM32L1XX_PROFILE_H_
#define STM32L1XX_PROFILE_H_

/*============================================================================  INCLUDE FILES  ==*/
#if defined(STM32L1XX_MD)
#include "stm32l1xx.h"

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje konstante - familija
 *//*--------------------------------------------------------------------------------------------*/
#define ES_HAL_MCU_FAMILY               "STM32L1xx Medium Density"

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje PORT konstante - familija
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_FAM_STM32L1XX_MD

/*-------------------------------------------------------------------------------------------*//**
 * @name        Konstante mogucnosti HAL modula
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_FEATURE_GPIO
#define ES_HAL_FEATURE_UART
#define ES_HAL_FEATURE_TIMER
#define ES_HAL_FEATURE_CRC
/** @} *//*--------------------------------------------------------------------------------------*/

# if defined(OPT_HAL_GPIO) || defined(__DOXYGEN__)
#  define ES_HAL_ENABLE_GPIO
#  include "port/family/stm32l1xx/gpio_lld.h"
# endif

# if defined(OPT_HAL_UART) || defined(__DOXYGEN__)
#  define ES_HAL_ENABLE_UART
#  include "port/family/stm32l1xx/uart_lld.h"
# endif

# if defined(OPT_HAL_TIMER) || defined(__DOXYGEN__)
#  define ES_HAL_ENABLE_TIMER
#  include "port/family/stm32l1xx/timer_lld.h"
# endif

# if defined(OPT_ENABLE_CRC) || defined(__DOXYGEN__)
#  define ES_HAL_ENABLE_CRC
#  include "port/family/stm32l1xx/crc_lld.h"
# endif
#endif /* STM32L1XX_MD */

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i proizvodjacu.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_MCU_MANUF                "STMicroelectronics"
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of stm32l1xx_profile.h
 *************************************************************************************************/
#endif /* STM32L1XX_PROFILE_H_ */
