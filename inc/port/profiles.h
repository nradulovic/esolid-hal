/*************************************************************************************************
 * This file is part of eSolid
 *
 * Template version: 1.1.15 (20.05.2012)
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
 * @brief       Ucitavanje svih profila
 * @details     Ova datoteka ucitava sve podrzane profile HAL-a.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  module_intf
 ****************************************************************************************//** @{ */


#ifndef PROFILES_H_
#define PROFILES_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*=================================================================================  SETTINGS  ==*/

/*******************************************************************************
 * ST Microelectronics
 *******************************************************************************/
#if defined(STM32L152RB)
# define PORT_FOUND_
# include "port/variant/stm32l152rb_profile.h"
#endif

#if defined(STM32F100C8)
/*----------------------------------------------------------------------------*/
# define PORT_FOUND_
# define ES_HAL_MCU_NAME                "STM32F100C8"
# define ES_HAL_MCU_FLASH               (65536UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/
# include "port/variant/stm32f10x_md_vl/variant_profile.h"
# include "port/family/stm32f10x/family_profile.h"
# include "port/arch/arm_cm3/arch_profile.h"
#endif

#if defined(STM32F100CB)
/*----------------------------------------------------------------------------*/
# define PORT_FOUND_
# define ES_HAL_MCU_NAME                "STM32F100CB"
# define ES_HAL_MCU_FLASH               (131072UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/
# include "port/variant/stm32f10x_md_vl/variant_profile.h"
# include "port/family/stm32f10x/family_profile.h"
# include "port/arch/arm_cm3/arch_profile.h"
#endif

#if defined(STM32F100R8)
/*----------------------------------------------------------------------------*/
# define PORT_FOUND_
# define ES_HAL_MCU_NAME                "STM32F100R8"
# define ES_HAL_MCU_FLASH               (65536UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/
# include "port/variant/stm32f10x_md_vl/variant_profile.h"
# include "port/family/stm32f10x/family_profile.h"
# include "port/arch/arm_cm3/arch_profile.h"
#endif

#if defined(STM32F100RB)
/*----------------------------------------------------------------------------*/
# define PORT_FOUND_
# define ES_HAL_MCU_NAME                "STM32F100RB"
# define ES_HAL_MCU_FLASH               (131072UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/
# include "port/variant/stm32f10x_md_vl/variant_profile.h"
# include "port/family/stm32f10x/family_profile.h"
# include "port/arch/arm_cm3/arch_profile.h"
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if !defined(PORT_FOUND_)
# define ES_HAL_MCU_SERIES              "Unknown MCU series"
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of profiles.h
 *************************************************************************************************/
#endif /* PROFILES_H_ */
