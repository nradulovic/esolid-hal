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
 * @brief       Interfejs Hardware Abstraction Layer (HAL) modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_intf
 * @brief       Interfejs Hardware Abstraction Layer (HAL) modula.
 ****************************************************************************************//** @{ */


#ifndef HAL_H_
#define HAL_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "port/port.h"
#include "../config/hal_config.h"
#include "hal_compiler.h"
#include "port/profiles.h"

#if defined(ES_ENABLE_CPU) || defined(__DOXYGEN__)
# include "hal_cpu.h"
#endif

#if defined(ES_ENABLE_INTERRUPT) || defined(__DOXYGEN__)
# include "hal_interrupt.h"
#endif

#if defined(ES_ENABLE_GPIO) || defined(__DOXYGEN__)
# include "hal_gpio.h"
#endif

#if defined(ES_ENABLE_UART) || defined(__DOXYGEN__)
# include "hal_uart.h"
#endif

#if defined(ES_ENABLE_TIMER) || defined(__DOXYGEN__)
# include "hal_timer.h"
#endif

#if defined(ES_ENABLE_CRC) || defined(__DOXYGEN__)
# include "hal_crc.h"
#endif


/*==================================================================================  DEFINES  ==*/
#if defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @name        Konstante dostupnosti HAL modula
 * @{ *//*---------------------------------------------------------------------------------------*/
# define ES_FEATURE_CPU
# define ES_FEATURE_INTERRUPT
# define ES_FEATURE_GPIO
# define ES_FEATURE_UART
# define ES_FEATURE_CRC
# define ES_FEATURE_TIMER
/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione konstante mikroprocesora
 * @{ *//*---------------------------------------------------------------------------------------*/
# define ES_HAL_CPU_NAME
# define ES_HAL_CPU_SERIES
# define ES_HAL_CPU_MANUF
/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione konstante mikrokontrolera
 * @{ *//*---------------------------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME
# define ES_HAL_MCU_SERIES
# define ES_HAL_MCU_MANUF
/** @} *//*--------------------------------------------------------------------------------------*/
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Status hardvera kojeg opsluzuje drajver
 * @details     Jednostavniji hardver obicno ima samo dva stanja:
 *              - stanje neaktivno
 *              - stanje aktivno
 *              Stanje neaktivno je naznaceno ES_DEC_INACTIVE enumeratorom. U
 *              principu, da bi se hardver koristio potrebno je da se hardver
 *              prebaci u aktivno stanje. Aktivno stanje ima dva podstanja,
 *              stanje da je hardver spreman za koriscenje i stanje da je
 *              hardver zauzet. Prvo stanje se oznacava ES_DEV_READY
 *              enumeratorom, dok se drugo stanje oznacava ES_DEC_BUSY
 *              enumeratorom. Dakle, hardver je aktivan ukoliko se nalazi u
 *              nekom od ES_DEV_READY ili ES_DEV_BUSY.
 *              Neki hardverski moduli se pored navedenih stanja mogu naci i u
 *              stanju ES_DEV_ERROR. U ovom stanju se mogu naci bez obzira na
 *              prethodno stanje.
 *//*--------------------------------------------------------------------------------------------*/
enum esDevStatus {
/**
 * @brief       Hardver nije aktiviran.
 * @details     Ovo stanje je karakteristicno kada se hardver ne koristi i
 *              drajver je hardver postavio u rezim male potrosnje.
 */
    ES_DEV_INACTIVE,

/**
 * @brief       Hardver je spreman za koriscenje.
 */
    ES_DEV_READY,

/**
 * @brief       Hardver nije spreman za koriscenje.
 */
    ES_DEV_BUSY,

/**
 * @brief       Hardver je u stanju greske.
 * @details     U zavisnosti od koriscenog hardvera treba da se preduzmu
 *              odredjeni koraci kako bi se greska otklonila/ponistila.
 */
    ES_DEV_ERROR
};

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Definisanje makroa za ulazak/izlazak iz kriticnih sekcija koda za HAL module.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define HAL_CRITICAL_DECL()             ES_CRITICAL_DECL()
#define HAL_CRITICAL_ENTER()            ES_CRITICAL_ENTER(OPT_HAL_INTERRUPT_PRIO)
#define HAL_CRITICAL_EXIT()             ES_CRITICAL_EXIT()
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Status drajvera
 * @see         esDevStatus
 *//*--------------------------------------------------------------------------------------------*/
typedef enum esDevStatus esDevStatus_T;

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizuje sve podmodule HAL sistema
 * @details     Ovu funkciju treba pozvati u toku inicijalizacije sistema i pre
 *              koriscenja bilo koje funkcije iz HAL sistema.
 *//*--------------------------------------------------------------------------------------------*/
void esHalInit(
    void);

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal.h
 *************************************************************************************************/
#endif /* HAL_H_ */
