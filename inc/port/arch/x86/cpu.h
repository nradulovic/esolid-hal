/*************************************************************************************************
 * This file is part of eSolid
 *
 * Copyright (C) 2011 - Nenad Radulovic
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
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 *
 * @author      nesa
 *
 * @brief       Interfejs CPU modula za Intel x86 arhitekturu, port klasa:
 *              arhitektura.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * @addtogroup  hal_cpu
 *
 ****************************************************************************************//** @{ */

#ifndef ARCH_HAL_CPU_H_
#define ARCH_HAL_CPU_H_


/*************************************************************************************************
 * INCLUDE FILES
 *************************************************************************************************/

/*-----------------------------------------------------------------------------------------------*
 * Module dependencies
 *-----------------------------------------------------------------------------------------------*/
#include PORT_VARIANT_HEADER(hal/cpu)

/*-----------------------------------------------------------------------------------------------*
 * Module configuration and adapter
 *-----------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------*
 * EXTERNS
 *-----------------------------------------------------------------------------------*//** @cond */

#ifdef ARCH_HAL_CPU_H_VAR
#define ARCH_HAL_CPU_H_EXT
#else
#define ARCH_HAL_CPU_H_EXT extern
#endif


/** @endcond*//***********************************************************************************
 * DEFINES
 *************************************************************************************************/


/*************************************************************************************************
 * MACRO's
 *************************************************************************************************/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Implementacija za Intel x86 arhitekturu
 * @{ *//*---------------------------------------------------------------------------------------*/

#if !defined(ES_CPU_FLS) || defined(__DOXYGEN__)
# define ES_CPU_FLS(expr1)                                                     \
    (31 - __builtin_clz(expr1))
#endif

#if !defined(ES_CPU_FFS) || defined(__DOXYGEN__)
# define ES_CPU_FFS(expr1)                                                     \
    ( __builtin_ffs(expr1) - 1)
#endif

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Atributi za Intel x86 arhitekturu
 * @{ *//*---------------------------------------------------------------------------------------*/

#define ES_CPU_ATTRIB_UNITED_ACCESS       PORT_TRUE

/** @} *//*--------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------*
 * C/C++ #ifdef - open
 *-----------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************
 * DATA TYPES
 *************************************************************************************************/


/*************************************************************************************************
 * GLOBAL VARIABLES
 *************************************************************************************************/


/*************************************************************************************************
 * FUNCTION PROTOTYPES
 *************************************************************************************************/


/*-----------------------------------------------------------------------------------------------*
 * C/C++ #endif - close
 *-----------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


/*************************************************************************************************
 * CONFIGURATION ERRORS
 *************************************************************************************//** @cond */


/** @endcond *//** @} *//*************************************************************************
 * END of HEADER FILE
 *************************************************************************************************/
#endif /* ARCH_HAL_CPU_H_ */
