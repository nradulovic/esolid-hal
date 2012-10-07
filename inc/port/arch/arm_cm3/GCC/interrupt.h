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
 * @brief       Preferiraju se asembler komande ili intrisic funkcije za
 *              implementaciju makroa.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_INT_ENABLE()                                                         \
    __enable_irq()

#define ES_INT_DISABLE()                                                        \
    __disable_irq()

#define ES_INT_PRIO_MASK_SET(prio)                                              \
    __set_BASEPRI(prio)

#define ES_INT_PRIO_MASK_GET()                                                  \
    __get_BASEPRI()

#define ES_CRITICAL_DECL()													    \
	uint32_t irqLock_

#define ES_CRITICAL_ENTER(prio)						    					    \
    do {                                                                        \
        irqLock_ = __get_BASEPRI();                                             \
        __set_BASEPRI(prio);                                                    \
    } while (0)

#define ES_CRITICAL_EXIT()													    \
    __set_BASEPRI(irqLock_)

/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Predefinisani prioriteti prekidnih rutina
 *//*--------------------------------------------------------------------------------------------*/
enum esHandlerPrio {
    ES_PRIO_IDLE = 0,
    ES_PRIO_VERY_LOW = 255,
    ES_PRIO_LOW = 254,
    ES_PRIO_BELOW_NORMAL = 192,
    ES_PRIO_NORMAL = 128,
    ES_PRIO_ABOVE_NORMAL = 64,
    ES_PRIO_HIGH = 32,
    ES_PRIO_VERY_HIGH = 2,
    ES_PRIO_REALTIME = 1
};

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of interrupt.h
 *************************************************************************************************/
#endif /* ARCH_INTERRUPT_H_ */
