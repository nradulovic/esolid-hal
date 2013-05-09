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
 * @brief       Profil familije za STM32F10x seriju.
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */

#ifndef STM32F10X_PROFILE_H_
#define STM32F10X_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  MACRO's  ==*/

/**
 * @brief       Naglasi da se INT modul koristi
 */
#define ES_HAL_INT_ENABLED

/*============================================================  DATA TYPES  ==*/

enum esInterruptPrio {
    ES_PRIO_IDLE = 0,
    ES_PRIO_VERY_LOW = 255,
    ES_PRIO_LOW = 254,
    ES_PRIO_BELOW_NORMAL = 192,
    ES_PRIO_NORMAL = 128,
    ES_PRIO_ABOVE_NORMAL = 64,
    ES_PRIO_HIGH = 32,
    ES_PRIO_VERY_HIGH = 2,
    ES_PRIO_REALTIME = 0x20
};

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32f10x_profile.h
 ******************************************************************************/
#endif /* STM32F10X_PROFILE_H_ */
