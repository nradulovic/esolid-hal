/*
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
 * ----------------------------------------------------------------------------
 *
 * Project settings:
 * - include paths:
 *      1. ./esolid-hal/inc
 * - source paths:
 *      1. ./esolid-hal, exclude: doc/,src/port,startup/
 *      2. ./esolid-hal/src/port/family/<family name>
 *      3. ./esolid-hal/startup/<compiler>/<arch name>
 * - references
 *      1. CMSIS
 * - exported include paths:
 *      1. ./esolid-hal/inc
 * - exported lib include paths:
 *      1. ./esolid-hal/<profile name>
 *      2. ./esolid-hal/linker-scripts/<compiler>/variant/<variant name>
 * - exported lib:
 *      1. esolid-hal
 *//***********************************************************************//**
 * @file
 * @author      Nenad Radulovic
 * @brief       Interfejs Hardware Abstraction Layer (HAL) modula.
 * @addtogroup  hal_intf
 *********************************************************************//** @{ */

#ifndef HAL_H_
#define HAL_H_

/*=========================================================  INCLUDE FILES  ==*/
#include "../config/hal_config.h"
#include "hal_compiler.h"
#include "hal_generic.h"
#include "port/hal_profiles.h"

#if defined(ES_HAL_ENABLE_CPU)
# include "hal_cpu.h"
#endif

#if defined(ES_HAL_ENABLE_INTERRUPT)
# include "hal_interrupt.h"
#endif

#if defined(ES_HAL_ENABLE_GPIO)
# include "hal_gpio.h"
#endif

#if defined(ES_HAL_ENABLE_UART)
# include "hal_uart.h"
#endif

#if defined(ES_HAL_ENABLE_TIMER)
# include "hal_timer.h"
#endif

#if defined(ES_HAL_ENABLE_CRC)
# include "hal_crc.h"
#endif


/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Vrsi inicijalizaciju eSolid HAL sistema
 */
void esHalInit(
    void);

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal.h
 ******************************************************************************/
#endif /* HAL_H_ */
