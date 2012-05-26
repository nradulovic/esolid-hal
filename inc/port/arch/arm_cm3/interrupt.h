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
 * @brief       Interfejs Interrupt modula za ARM Cortex-M3 arhitekturu.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  intr_intf
 ****************************************************************************************//** @{ */


#ifndef ARCH_INTERRUPT_H_
#define ARCH_INTERRUPT_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Implementacija za ARM Cortex-M3 arhitekturu
 * @brief       Preferiraju se asembler komande za implementaciju makroa.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define INT_PRIO_MASK_GET_()                                                    \
    C_EXT ({                                                                    \
        register uint32_t reg;                                                  \
        __asm volatile (                                                        \
            "mrs %0, basepri"                                                   \
            : "=r"(reg) :: "memory", "cc");                                     \
        reg;                                                                    \
    })

#define INT_PRIO_MASK_SET_(prio)                                                \
    do {                                                                        \
        register uint32_t reg = (prio);                                         \
        __asm volatile (                                                        \
            "msr basepri, %0"                                                   \
            :: "r"(reg) : "memory", "cc");                                      \
    } while (0)

#define ES_INT_ENABLE()                                                         \
    __asm volatile ("cpsie i")

#define ES_INT_DISABLE()                                                        \
    __asm volatile ("cpsid i")

#define ES_INT_PRIO_MASK_SET(prio)                                              \
    do {                                                                        \
        if (0U == prio) {                                                       \
            INT_PRIO_MASK_SET_(0U);                                             \
        } else {                                                                \
            INT_PRIO_MASK_SET_((uint8_t)((uint16_t)256U - (uint16_t)(prio));    \
        }                                                                       \
    } while (0)

#define ES_INT_PRIO_MASK_GET()                                                  \
    C_EXT ({                                                                    \
        uint32_t mask;                                                          \
        if (0U != mask) {                                                       \
            mask = (uint32_t)256U - mask;                                       \
        }                                                                       \
        mask;                                                                   \
    })

#define ES_CRITICAL_DECL()													    \
	uint32_t irqLock_

#define ES_CRITICAL_ENTER(prio)						    					\
    do {                                                                        \
        irqLock_ = INT_PRIO_MASK_GET_();                                        \
        ES_INT_PRIO_MASK_SET(prio);                                            \
    } while (0)

#define ES_CRITICAL_EXIT()													    \
    do {                                                                        \
        __asm volatile (                                                        \
            "msr basepri, %0"                                                   \
            :: "r"(irqLock_) : "memory", "cc");                                 \
    } while (0)
/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of interrupt.h
 *************************************************************************************************/
#endif /* ARCH_INTERRUPT_H_ */
