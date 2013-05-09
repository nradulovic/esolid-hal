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
 * @brief       Interfejs Interrupt modula za ARM Cortex-M3 arhitekturu.
 * @addtogroup  port_arm_cm3
 *********************************************************************//** @{ */

#ifndef CM3_INT_H_
#define CM3_INT_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Implementacija za ARM Cortex-M3 arhitekturu
 * @{ *//*--------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS void esIntEnable(
    void) {

    __asm volatile ("cpsie i");
}

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS void esIntDisable(
    void) {

    __asm volatile ("cpsid i");
}

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS void esIntPrioMaskSet(
    uint32_t        prio) {

    __asm volatile ("msr basepri, %0" : : "r" (prio) );
}

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS uint32_t esIntPrioMaskGet(
    void) {

    uint32_t prio;

    __asm volatile ("mrs %0, basepri_max" : "=r" (prio) );

    return(prio);
}

/** @} *//*-------------------------------------------------------------------*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of cm3_int.h
 ******************************************************************************/
#endif /* CM3_INT_H_ */
