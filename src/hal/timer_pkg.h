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
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Implementacija Timer Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_timer_impl
 ****************************************************************************************//** @{ */


#ifndef TIMER_PKG_H_
#define TIMER_PKG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Makroi za proveru paramatera
 * @brief       Koriste se iskljucivo za proveru predatih parametara.
 * @details     Ukoliko je pretprocesorom iskljucen neki port onda se nece ni
 *              vrsiti provera parametara sa tim vrednostima.
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(ES_ENABLE_TIMER) && defined(OPT_HAL_TIMER_USE_1) || defined(__DOXYGEN__)
#define DBG_VALID_TIMER1_DRV(val)                                               \
    (&esTimer1 == (val))
#else
#define DBG_VALID_TIMER1_DRV(val)                                               \
    (0U)
#endif

#if defined(ES_ENABLE_TIMER) && defined(OPT_HAL_TIMER_USE_2) || defined(__DOXYGEN__)
#define DBG_VALID_TIMER2_DRV(val)                                               \
    (&esTimer2 == (val))
#else
#define DBG_VALID_TIMER2_DRV(val)                                               \
    (0U)
#endif

#if defined(ES_ENABLE_TIMER) && defined(OPT_HAL_TIMER_USE_3) || defined(__DOXYGEN__)
#define DBG_VALID_TIMER3_DRV(val)                                               \
    (&esTimer3 == (val))
#else
#define DBG_VALID_TIMER3_DRV(val)                                               \
    (0U)
#endif

#define TIMER_DRVID_LIST(gpio)                                                  \
    (DBG_VALID_TIMER1_DRV(gpio) ||                                              \
     DBG_VALID_TIMER2_DRV(gpio) ||                                              \
     DBG_VALID_TIMER3_DRV(gpio))

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
 * @brief       Inicijalizacije Timer drajver modula
 * @details     Ova funkcija se poziva automatski u toku inicijalizacije HAL
 *              paketa.
 *//*--------------------------------------------------------------------------------------------*/
void lldTimerDrvInit(
    void);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of timer_pkg.h
 *************************************************************************************************/
#endif /* TIMER_PKG_H_ */
