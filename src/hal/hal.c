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
 * @author      Nenad Radulovic
 * @brief       Implementacija osnovnih HAL funkcija.
 * @addtogroup  hal_impl
 *********************************************************************//** @{ */

/*=========================================================  INCLUDE FILES  ==*/
#include "hal_private.h"

/*=========================================================  LOCAL DEFINES  ==*/
/*=========================================================  LOCAL MACRO's  ==*/
/*======================================================  LOCAL DATA TYPES  ==*/
/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/

#if (OPT_HAL_STARTUP != 1U)
C_WEAK_FUNC void kernelInit(
    void);
#endif

/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/

#if (OPT_HAL_STARTUP != 1U)
C_WEAK_FUNC void kernelInit(
    void) {

    return;
}
#endif

/*===================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
void halInit(
    void) {

    sysInit();

#if defined(ES_HAL_ENABLE_GPIO)
    gpioInit();
#endif

#if defined(ES_HAL_ENABLE_UART)
    lldUartDrvInit();
#endif

#if defined(ES_HAL_ENABLE_TIMER)
    lldTimerDrvInit();
#endif

#if defined(ES_HAL_ENABLE_CRC)
    lldCrcDrvInit();
#endif
}

/*====================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
#if (OPT_HAL_STARTUP != 1U)
void esSysInit (void) {
    halInit();
    kernelInit();
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal.c
 ******************************************************************************/
