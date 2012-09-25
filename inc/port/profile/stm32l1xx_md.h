/*************************************************************************************************
 * This file is part of esolid-haldsm
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * esolid-haldsm is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * esolid-haldsm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with esolid-haldsm; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *//******************************************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Profili za STM32L1xx MD seriju.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_stm32l1xx_md
 ****************************************************************************************//** @{ */


#ifndef STM32L1XX_MD_H_
#define STM32L1XX_MD_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*=================================================================================  SETTINGS  ==*/

#if defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @name        Podrzani portovi STM32L1xx MD profila
 * @{ *//*---------------------------------------------------------------------------------------*/
# define STM32L152RB
/** @} *//*--------------------------------------------------------------------------------------*/
#endif

#if defined(STM32L152RB)
# define STM32L1XX_MD_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME                "STM32L152RB"
# define ES_HAL_MCU_FLASH               (131072UL)
# define ES_HAL_MCU_RAM                 (16384UL)
#endif

#if defined(STM32L1XX_MD_)
# define PORT_FOUND_
/*----------------------------------------------------------------------------*/
# define ES_HAL_MCU_SERIES              "Ultra-low-power Medium Density devices"
# define ES_FEATURE_CPU
# define ES_FEATURE_INTERRUPT

# if defined(OPT_HAL_CPU)
#  define ES_ENABLE_CPU
# endif

# if defined(OPT_HAL_INTERRUPT)
#  define ES_ENABLE_INTERRUPT
# endif

# include "port/family/stm32l1xx/family_profile.h"
# include "port/arch/arm_cm3/arch_profile.h"
#endif
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of stm32l1xx_md.h
 *************************************************************************************************/
#endif /* STM32L1XX_MD_H_ */
