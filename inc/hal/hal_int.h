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
 * @author      Nenad Radulovic
 * @brief       Interfejs za rad sa prekidima.
 * @addtogroup  hal_int_intf
 *********************************************************************//** @{ */

#ifndef HAL_INT_H_
#define HAL_INT_H_

/*=========================================================  INCLUDE FILES  ==*/
#include "compiler.h"
#include "hal_generic.h"

/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Kontrola glavnog prekida
 * @brief       Funkcije za omogucavanje/onemogucavanje svih prekida u sistemu.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Omoguci prekide
 * @details     Omoguci globalni prekid
 */
void esIntEnable(
    void);

/**
 * @brief       Onemoguci prekide
 * @details     Onemoguci globalni prekid
 */
void esIntDisable(
    void);

/** @} *//*-------------------------------------------------------------------*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_int.h
 ******************************************************************************/
#endif /* HAL_INT_H_ */
