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
 * @brief       Profili za STM32F10x MD VL seriju.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_stm32f10x_md_vl
 ****************************************************************************************//** @{ */


#ifndef STM32F10X_MD_VL_H_
#define STM32F10X_MD_VL_H_

#if defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @name        Podrzani portovi STM32F10x MD VL profila
 * @{ *//*---------------------------------------------------------------------------------------*/
# define STM32F100C8
# define STM32F100CB
# define STM32F100R8
# define STM32F100RB
/** @} *//*--------------------------------------------------------------------------------------*/
#endif

#if defined(STM32F100C8)
# define STM32F10X_MD_VL_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME                "STM32F100C8"
# define ES_HAL_MCU_FLASH               (65536UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/

#elif defined(STM32F100CB)
# define STM32F10X_MD_VL_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME                "STM32F100CB"
# define ES_HAL_MCU_FLASH               (131072UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/

#elif defined(STM32F100R8)
# define STM32F10X_MD_VL_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME                "STM32F100R8"
# define ES_HAL_MCU_FLASH               (65536UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/

#elif defined(STM32F100RB)
# define STM32F10X_MD_VL_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME                "STM32F100RB"
# define ES_HAL_MCU_FLASH               (131072UL)
# define ES_HAL_MCU_RAM                 (8192UL)
/*----------------------------------------------------------------------------*/
# define ES_FEATURE_GPIO
# define ES_FEATURE_GPIOA
# define ES_FEATURE_GPIOB
# define ES_FEATURE_GPIOC
# define ES_FEATURE_GPIOD
# define ES_FEATURE_UART
# define ES_FEATURE_TIMER
# define ES_FEATURE_CRC
#endif

#if defined(STM32F10X_MD_VL_)
# define PORT_FOUND_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_SERIES              "Medium density Value Line devices"
#include "port/family/stm32f10x/family_profile.h"
#include "port/arch/arm_cm3/arch_profile.h"
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of stm32f10x_md_vl.h
 *************************************************************************************************/
#endif /* STM32F10X_MD_VL_H_ */
