/*************************************************************************************************
 * This file is part of esolid-haldsm
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * esolid-haldsm is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * esolid-haldsm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with esolid-haldsm; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 * @author  	nenad
 * @brief       Interface of hal_private.
 * @details     Detailed description
 * @note        Notes
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  module_intf
 ****************************************************************************************//** @{ */


#ifndef HAL_PRIVATE_H_
#define HAL_PRIVATE_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "hal/hal.h"
#if defined(ES_ENABLE_GPIO) || defined(__DOXYGEN__)
# include "gpio_pkg.h"
#endif
#if defined(ES_ENABLE_UART) || defined(__DOXYGEN__)
#include "uart_pkg.h"
#endif
#if defined(ES_ENABLE_TIMER) || defined(__DOXYGEN__)
#include "timer_pkg.h"
#endif

/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef HAL_PRIVATE_H_VAR
# define HAL_PRIVATE_H_EXT
#else
# define HAL_PRIVATE_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Definition group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Macro group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Data types group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Variables group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Function group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_private.h
 *************************************************************************************************/
#endif /* HAL_PRIVATE_H_ */
