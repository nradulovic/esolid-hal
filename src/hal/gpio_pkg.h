/*************************************************************************************************
 * This file is part of esolid-haldsm
 *
 * Template version: 1.1.13 (24.03.2012)
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
 * @author  	Nenad Radulovic
 * @brief       Implementacija GPIO Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_gpio_impl
 ****************************************************************************************//** @{ */


#ifndef GPIO_PKG_H_
#define GPIO_PKG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Makroi za proveru paramatera
 * @brief       Koriste se iskljucivo za proveru predatih parametara.
 * @details     Ukoliko je pretprocesorom iskljucen neki port onda se nece ni
 *              vrsiti provera parametara sa tim vrednostima.
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_A) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOA_DRV(val)                                                \
    (&esGPIOA == (val))
#else
#define DBG_VALID_GPIOA_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_B) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOB_DRV(val)                                                \
    (&esGPIOB == (val))
#else
#define DBG_VALID_GPIOB_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_C) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOC_DRV(val)                                                \
    (&esGPIOC == (val))
#else
#define DBG_VALID_GPIOC_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_D) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOD_DRV(val)                                                \
    (&esGPIOD == (val))
#else
#define DBG_VALID_GPIOD_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_E) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOE_DRV(val)                                                \
    (&esGPIOE == (val))
#else
#define DBG_VALID_GPIOE_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_H) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOH_DRV(val)                                                \
    (&esGPIOH == (val))
#else
#define DBG_VALID_GPIOH_DRV(val)                                                \
    (0U)
#endif

#define GPIO_DRVID_LIST(gpio)                                                     \
    (DBG_VALID_GPIOA_DRV(gpio) ||                                               \
     DBG_VALID_GPIOB_DRV(gpio) ||                                               \
     DBG_VALID_GPIOC_DRV(gpio) ||                                               \
     DBG_VALID_GPIOD_DRV(gpio) ||                                               \
     DBG_VALID_GPIOE_DRV(gpio) ||                                               \
     DBG_VALID_GPIOH_DRV(gpio))

/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Globalne, privatne funkcije
 * @brief       Ove funkcije definise port
 * @details     Funkcije koje pripadaju ovoj grupi nisu namenjene da ih korisnik
 *              direktno poziva vec se koriste od strane samog HAL sistema.
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizacije GPIO drajver modula
 * @details     Ova funkcija se poziva automatski u toku inicijalizacije HAL
 *              paketa.
 *//*--------------------------------------------------------------------------------------------*/
void lldGpioDrvInit(
    void);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of gpio_pkg.h
 *************************************************************************************************/
#endif /* GPIO_PKG_H_ */
