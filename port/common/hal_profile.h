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

#ifndef HAL_PROFILE_H_
#define HAL_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
#include "../config/hal_config.h"

/*============================================================================*
 *
 * Architecture: ARM Cortex-M3
 *
 *============================================================================*/

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 F1 Mainstream
 *----------------------------------------------------------------------------*/
#if defined(STM32F100RB) && !defined(ES_HAL_PROFILE_ENABLED)
# if defined(PORT_ARM_NONE_EABI_GCC_)
#  include "arm-none-eabi-gcc/hal/stm32f10x/stm32f100rb_profile.h"
# endif
#endif

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 L1 Ultra Low Power
 *----------------------------------------------------------------------------*/
#if defined(STM32L152RB) && !defined(ES_HAL_PROFILE_ENABLED)
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
#if defined(STM32F407VG) && !defined(ES_HAL_PROFILE_ENABLED)
# include "port/variant/stm32f407vg_profile.h"
# include "port/family/stm32f4xx_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*============================================================================*
 *
 * Architecture: AVR ATmega
 *
 *============================================================================*/
#if defined(ATMEGA32U2) && !defined(ES_HAL_PROFILE_ENABLED)
# include "port/variant/atmega32u2.h"
# include "port/family/atmega.h"
# include "port/arch/avr_profile.h"
#endif

/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_profile.h
 ******************************************************************************/
#endif /* HAL_PROFILE_H_ */
