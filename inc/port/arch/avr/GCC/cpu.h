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
 * @author      Dejan Ristic
 * @brief       Interfejs CPU modula za AVR arhitekturu.
 * @addtogroup  port_avr
 *********************************************************************//** @{ */

#ifndef AVR_CPU_H_
#define AVR_CPU_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Atributi za AVR arhitekturu
 * @{ *//*--------------------------------------------------------------------*/
/*
 * Ako koristi iste instrukcije za pristup FLASH i ROM memoriji (citanje)
 * ostavi ovaj define
 */
#define ES_CPU_ATTRIB_LINEAR_ADDR

/*
 * Posto je 8-bitni CPU, poravnjanje je 1 bajt
 */
#define ES_CPU_ATTRIB_ALIGNMENT         1U

/*
 * Broj bitova data-magistrale
 */
#define ES_CPU_NATIVE_BITS              8U
#define ES_CPU_UNATIVE_BITS             8U
typedef int8_t                          native_T;
typedef uint8_t                         unative_T;

/** @} *//*-------------------------------------------------------------------*/
/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Implementacija za AVR arhitekturu
 * @{ *//*--------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS uint_fast8_t esCpuFindLastSet(
    uint32_t value) {

    /*
     * Proguglaj Find Last Set algoritam ili Count Leading Zero. Pogledaj i hal_cpu.h
     */
    uint8_t result;

    __asm volatile ("clz %0, %1" : "=r" (result) : "r" (value) );

    return (31UL - result);
}

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS uint_fast8_t esCpuFindFirstSet(
    uint32_t value) {

    /*
     * Proguglaj Find First Set algoritam ili Count Leading Zero. Pogledaj i hal_cpu.h
     */
    uint_fast8_t clzr;
    int32_t uvalue;

    uvalue = (int32_t)value;
    uvalue = uvalue & (-uvalue);
    __asm volatile ("clz %0, %1" : "=r" (clzr) : "r" (uvalue));

    return (31UL - clzr);
}

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS void esCpuSleep(
    void) {

    /*
     * Postavi CPU u sleep stanje koje ceka na prekid ili stavi obicnu NOP
     * instrukciju
     */

#if defined(NDEBUG)
    __asm volatile ("wfi");
#else
    __asm volatile ("nop");
#endif
}

/*----------------------------------------------------------------------------*/
static C_INLINE_ALWAYS void esCpuStop(
    void) {

    /*
     * Napravi obicnu beskonacnu petlju
     */
    while (TRUE) {

#if defined(NDEBUG)
        esCpuSleep();
#else
        ;
#endif
    }
}

/** @} *//*-------------------------------------------------------------------*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of cpu.h
 ******************************************************************************/
#endif /* AVR_CPU_H_ */
