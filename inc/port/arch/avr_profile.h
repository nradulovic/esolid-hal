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
 * @author      Dejan Ristic
 * @brief       Profil arhitekture za AVR.
 * @addtogroup  port_avr
 *********************************************************************//** @{ */

#ifndef AVR_PROFILE_H_
#define AVR_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/

#if defined(ES_HAL_ENABLE_CPU)
# if defined(__GNUC__)
#  include "port/arch/avr/GCC/cpu.h"
# endif
#endif

#if defined(ES_HAL_ENABLE_INTERRUPT)
# if defined(__GNUC__)
#  include "port/arch/avr/GCC/interrupt.h"
# endif
#endif

/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        AVR opisne konstante
 * @{ *//*--------------------------------------------------------------------*/
#define ES_HAL_CPU_NAME                 "AVR"
#define ES_HAL_CPU_SERIES               "AVR"
#define ES_HAL_CPU_MANUF                "Atmel"

/** @} *//*-------------------------------------------------------------------*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of avr_profile.h
 ******************************************************************************/
#endif /* AVR_PROFILE_H_ */
