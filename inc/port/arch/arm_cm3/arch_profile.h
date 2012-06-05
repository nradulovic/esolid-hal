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


#ifndef ARCH_PROFILE_H_
#define ARCH_PROFILE_H_

/*============================================================================  INCLUDE FILES  ==*/
#include PORT_CMN_DEPENDENT(cpu)
#include PORT_CMN_DEPENDENT(interrupt)

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Konstante svojstva za ARM Cortex-M3
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_FEATURE_CPU
#define ES_FEATURE_INTERRUPT
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione konstante za ARM Cortex-M3
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_CPU_NAME                 "Cortex-M3"
#define ES_HAL_CPU_SERIES               "ARMv7-M"
#define ES_HAL_CPU_MANUF                "ARM"
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of arch_profile.h
 *************************************************************************************************/
#endif /* ARCH_PROFILE_H_ */
