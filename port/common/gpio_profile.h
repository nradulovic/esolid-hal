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
 * @brief       Ucitavanje svih CPU profila
 * @addtogroup  eSolid_port_cpu
 *********************************************************************//** @{ */

#ifndef GPIO_PROFILE_H_
#define GPIO_PROFILE_H_

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
#if defined(STM32F100RB) && !defined(ES_HAL_GPIO_ENABLED)
# if defined(PORT_ARM_NONE_EABI_GCC_)
#  include "arm-none-eabi-gcc/hal/stm32f10x/stm32f10x_gpio.h"
# endif
#endif

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 L1 Ultra Low Power
 *----------------------------------------------------------------------------*/
#if defined(STM32L152RB) && !defined(ES_HAL_GPIO_ENABLED)
# if defined(PORT_ARM_NONE_EABI_GCC_)
#  include "arm-none-eabi-gcc/hal/arch/cm3/cm3_cpu.h"
# endif
#endif

/*============================================================================*
 *
 * Architecture: ARM Cortex-M4F
 *
 *============================================================================*/

/*----------------------------------------------------------------------------*
 * STMicroelectronics - STM32 F4 Hi-Performance & DSP
 *----------------------------------------------------------------------------*/
#if defined(STM32F407VG) && !defined(ES_HAL_GPIO_ENABLED)
# if defined(PORT_ARM_NONE_EABI_GCC_)
#  include "arm-none-eabi-gcc/hal/arch/cm3/cm3_cpu.h"
# endif
#endif

/*============================================================================*
 *
 * Architecture: AVR ATmega
 *
 *============================================================================*/
#if defined(ATMEGA32U2) && !defined(ES_HAL_GPIO_ENABLED)
# if defined(PORT_AVR_GCC_)
#  include "avr-gcc/hal/arch/avr/avr_cpu.h"
# endif
#endif

/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of gpio_profile.h
 ******************************************************************************/
#endif /* GPIO_PROFILE_H_ */
