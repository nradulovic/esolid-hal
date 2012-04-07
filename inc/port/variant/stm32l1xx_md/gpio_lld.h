/*************************************************************************************************
 * This file is part of eSolid
 *
 * Template version: 1.1.13 (24.03.2012)
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
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Interfejs GPIO Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_gpio
 ****************************************************************************************//** @{ */


#ifndef GPIO_LLD_H_
#define GPIO_LLD_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"

/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef GPIO_LLD_H_VAR
# define GPIO_LLD_H_EXT
#else
# define GPIO_LLD_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Definition group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_GPIO)
# if defined(OPT_HAL_GPIO_USE_A)
#  define esGPIOA                       ((esGpioDrv_T *)&gpioADrv)
# endif

# if defined(OPT_HAL_GPIO_USE_B)
#  define esGPIOB                       ((esGpioDrv_T *)&gpioBDrv)
# endif

# if defined(OPT_HAL_GPIO_USE_C)
#  define esGPIOC                       ((esGpioDrv_T *)&gpioCDrv)
# endif

# if defined(OPT_HAL_GPIO_USE_D)
#  define esGPIOD                       ((esGpioDrv_T *)&gpioDDrv)
# endif

# if defined(OPT_HAL_GPIO_USE_E)
#  define esGPIOE                       ((esGpioDrv_T *)&gpioEDrv)
# endif

    /*Ne postoje portovi F i G */

# if defined(OPT_HAL_GPIO_USE_H)
#  define esGPIOH                       ((esGpioDrv_T *)&gpioHDrv)
# endif
#endif /* OPT_HAL_GPIO */
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Macro group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_A) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOA_DRV(val)                                                \
    (esGPIOA == (val))
#else
#define DBG_VALID_GPIOA_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_B) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOB_DRV(val)                                                \
    (esGPIOB == (val))
#else
#define DBG_VALID_GPIOB_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_C) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOC_DRV(val)                                                \
    (esGPIOC == (val))
#else
#define DBG_VALID_GPIOC_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_D) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOD_DRV(val)                                                \
    (esGPIOD == (val))
#else
#define DBG_VALID_GPIOD_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_E) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOE_DRV(val)                                                \
    (esGPIOE == (val))
#else
#define DBG_VALID_GPIOE_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_H) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOH_DRV(val)                                                \
    (esGPIOH == (val))
#else
#define DBG_VALID_GPIOH_DRV(val)                                                \
    (0U)
#endif

#define GPIO_DRV_LIST(uart)                                                     \
    (DBG_VALID_GPIOA_DRV(uart) ||                                               \
     DBG_VALID_GPIOB_DRV(uart) ||                                               \
     DBG_VALID_GPIOC_DRV(uart) ||                                               \
     DBG_VALID_GPIOD_DRV(uart) ||                                               \
     DBG_VALID_GPIOE_DRV(uart) ||                                               \
     DBG_VALID_GPIOH_DRV(uart))

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
typedef struct gpioDrvExt gpioDrvExt_T;

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Variables group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_GPIO)
# if defined(OPT_HAL_GPIO_USE_A) || defined(__DOXYGEN__)
GPIO_LLD_H_EXT gpioDrvExt_T gpioADrv;
# endif

# if defined(OPT_HAL_GPIO_USE_B) || defined(__DOXYGEN__)
GPIO_LLD_H_EXT gpioDrvExt_T gpioBDrv;
# endif

#if defined(OPT_HAL_GPIO_USE_C) || defined(__DOXYGEN__)
GPIO_LLD_H_EXT gpioDrvExt_T gpioCDrv;
# endif

#if defined(OPT_HAL_GPIO_USE_D) || defined(__DOXYGEN__)
GPIO_LLD_H_EXT gpioDrvExt_T gpioDDrv;
# endif

#if defined(OPT_HAL_GPIO_USE_E) || defined(__DOXYGEN__)
GPIO_LLD_H_EXT gpioDrvExt_T gpioEDrv;
# endif

#if defined(OPT_HAL_GPIO_USE_H) || defined(__DOXYGEN__)
GPIO_LLD_H_EXT gpioDrvExt_T gpioHDrv;
# endif
#endif /* OPT_HAL_GPIO */

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
 * END of gpio_lld.h
 *************************************************************************************************/
#endif /* GPIO_LLD_H_ */
