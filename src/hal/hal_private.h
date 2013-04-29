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
 * @brief       Privatna sekcija HAL-a
 * @addtogroup  hal_impl
 *********************************************************************//** @{ */

#ifndef HAL_PRIVATE_H_
#define HAL_PRIVATE_H_

/*=========================================================  INCLUDE FILES  ==*/
#include "hal/hal.h"
#include "sys_pkg.h"
#include "uart_pkg.h"
#include "timer_pkg.h"
#include "crc_pkg.h"

/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Inicijalizuje sve podmodule HAL sistema
 * @details     Ovu funkciju treba pozvati u toku inicijalizacije sistema i pre
 *              koriscenja bilo koje funkcije iz HAL sistema.
 * @notapi
 */
void halInit(
    void);

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_private.h
 ******************************************************************************/
#endif /* HAL_PRIVATE_H_ */
