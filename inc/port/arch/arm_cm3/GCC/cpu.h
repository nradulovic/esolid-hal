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
 * @author      Nenad Radulovic
 * @brief       Interfejs CPU modula za ARM Cortex-M3 arhitekturu.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_cpu
 ****************************************************************************************//** @{ */


#ifndef ARCH_CPU_H_
#define ARCH_CPU_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Atributi za ARM Cortex-M3 arhitekturu
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_CPU_ATTRIB_UNITED_ACCESS
#define ES_CPU_ATTRIB_ALIGNMENT         4
#define ES_CPU_NATIVE_BITS              32U
#define ES_CPU_UNATIVE_BITS             32U
typedef int32_t                         native_T;
typedef uint32_t                        unative_T;
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Implementacija za ARM Cortex-M3 arhitekturu
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_CPU_FLS(expr1)                                                      \
    (31 - __builtin_clz(expr1))

#define ES_CPU_FFS(expr1)                                                      \
    ( __builtin_ffs(expr1) - 1)
/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of cpu.h
 *************************************************************************************************/
#endif /* ARCH_CPU_H_ */
