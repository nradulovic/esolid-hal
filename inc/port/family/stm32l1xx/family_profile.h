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


#ifndef FAMILY_PROFILE_H_
#define FAMILY_PROFILE_H_

/*============================================================================  INCLUDE FILES  ==*/

#if defined(ES_ENABLE_GPIO) || defined(__DOXYGEN__)
# include "port/family/stm32f10x/gpio_lld.h"
#endif

#if defined(ES_ENABLE_UART) || defined(__DOXYGEN__)
# include "port/family/stm32f10x/uart_lld.h"
#endif

#if defined(ES_ENABLE_TIMER) || defined(__DOXYGEN__)
# include "port/family/stm32f10x/timer_lld.h"
#endif

#if defined(ES_ENABLE_CRC) || defined(__DOXYGEN__)
# include "port/family/stm32f10x/crc_lld.h"
#endif

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione konstante
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_MCU_FAMILY                                                       \
    "STM32L1xx"

#define ES_HAL_MCU_MANUF                                                        \
    "STMicroelectronics"

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
