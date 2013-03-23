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
 * @brief       Ucitavanje svih HAL profila
 * @addtogroup  eSolid_port
 *********************************************************************//** @{ */


#ifndef PROFILES_H_
#define PROFILES_H_

/*=========================================================  INCLUDE FILES  ==*/

/*============================================================================*
 *
 * Architecture: ARM Cortex-M3
 *
 *============================================================================*/

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 F1 Mainstream
 *----------------------------------------------------------------------------*/
#if defined(STM32F100RB)
# define                                HAL_PORT_FOUND_
# define                                STM32F10X_MD_VL
# include "port/variant/stm32f100rb_profile.h"
# include "port/family/stm32f10x_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 L1 Ultra Low Power
 *----------------------------------------------------------------------------*/
#if defined(STM32L152RB)
# define                                HAL_PORT_FOUND_
# include "port/variant/stm32l152rb_profile.h"
# include "port/family/stm32l1xx_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*============================================================================*
 *
 * Architecture: ARM Cortex-M4F
 *
 *============================================================================*/

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 F4 Hi-Performance & DSP
 *----------------------------------------------------------------------------*/
#if defined(STM32F407VG)
# define                                HAL_PORT_FOUND_
# include "port/variant/stm32f407vg_profile.h"
# include "port/family/stm32f4xx_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if !defined(HAL_PORT_FOUND_)
# define ES_HAL_MCU_VARIANT             "Unknown MCU series"
# if defined(__GNUC__)
#  warning "HAL Profiles: Cannot determine MCU variant. HAL is disabled."
# else
#  error "HAL Profiles: Cannot determine MCU variant. HAL is disabled."
# endif
#endif

/** @endcond *//** @} *//******************************************************
 * END of profiles.h
 ******************************************************************************/
#endif /* PROFILES_H_ */
