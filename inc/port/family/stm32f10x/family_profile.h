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
 * @brief       Profil familije za STM32F10x seriju.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_stm32f10x
 ****************************************************************************************//** @{ */


#ifndef FAMILY_PROFILE_H_
#define FAMILY_PROFILE_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione konstante
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_MCU_NAME                                                         \
    "STM32F10x"

#define ES_HAL_MCU_SERIES                                                       \
    "Low & medium-density value line"

#define ES_HAL_MCU_MANUF                                                        \
    "STMicroelectronics"

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Konstante dostupnosti
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_GPIO)
# define ES_FEATURE_GPIO
# include "port/family/stm32f10x/gpio_lld.h"
#endif

#if defined(OPT_HAL_UART)
# define ES_FEATURE_UART
# include "port/family/stm32f10x/uart_lld.h"
#endif

#if defined(OPT_HAL_TIMER)
# define ES_FEATURE_TIMER
# include "port/family/stm32f10x/timer_lld.h"
#endif

#if defined(OPT_HAL_CRC)
# define ES_FEATURE_CRC
# include "port/family/stm32f10x/crc_lld.h"
#endif

/** @} *//*--------------------------------------------------------------------------------------*/
/*==================================================================================  MACRO's  ==*/
/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of family_profile.h
 *************************************************************************************************/
#endif /* FAMILY_PROFILE_H_ */