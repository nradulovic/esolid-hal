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
 * @brief       Profil arhitekture za ARM Cortex-M3.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_arm_cm3
 ****************************************************************************************//** @{ */


#ifndef ARM_CM3_HAL_H_
#define ARM_CM3_HAL_H_

/*============================================================================  INCLUDE FILES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Konstante mogucnosti HAL modula
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_FEATURE_CPU
#define ES_HAL_FEATURE_INTERRUPT
/** @} *//*--------------------------------------------------------------------------------------*/

#if defined(OPT_HAL_CPU)
# define ES_HAL_ENABLE_CPU
# if defined(__GNUC__)
#  include "port/arch/arm_cm3/GCC/cpu.h"
# elif defined(__IAR_SYSTEMS_ICC__)
#  include "port/arch/arm_cm3/IAR/cpu.h"
# endif
#endif

#if defined(OPT_HAL_INTERRUPT)
# define ES_HAL_ENABLE_INTERRUPT
# if defined(__GNUC__)
#  include "port/arch/arm_cm3/GCC/interrupt.h"
# elif defined(__IAR_SYSTEMS_ICC__)
#  include "port/arch/arm_cm3/IAR/interrupt.h"
# endif
#endif

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikroprocesoru i proizvodjacu.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_CPU_NAME                 "Cortex-M3"
#define ES_HAL_CPU_SERIES               "ARMv7-M"
#define ES_HAL_CPU_MANUF                "ARM"
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje PORT konstante - arhitektura
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_ARCH_ARM_CM3

/*==================================================================================  MACRO's  ==*/
/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of arm_cm3_hal.h
 *************************************************************************************************/
#endif /* ARM_CM3_HAL_H_ */