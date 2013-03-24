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
 * @brief       Zajednicka svojstva HAL modula
 * @addtogroup  hal_intf
 *********************************************************************//** @{ */

#ifndef HAL_GENERIC_H_
#define HAL_GENERIC_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
#if defined(__DOXYGEN__)
/*------------------------------------------------------------------------*//**
 * @name        Konstante mogucnosti HAL modula
 * @details     Ove konstante govore da za datu funkcionalnost postoje HAL
 *              moduli.
 * @{ *//*--------------------------------------------------------------------*/
# define ES_HAL_FEATURE_CPU
# define ES_HAL_FEATURE_INTERRUPT
# define ES_HAL_FEATURE_GPIO
# define ES_HAL_FEATURE_UART
# define ES_HAL_FEATURE_CRC
# define ES_HAL_FEATURE_TIMER

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Konstante dostupnosti HAL modula
 * @details     Ove konstante govore da za datu funkcionalnost postoje HAL
 *              moduli i da su oni aktivni.
 * @{ *//*--------------------------------------------------------------------*/
# define ES_HAL_ENABLE_CPU
# define ES_HAL_ENABLE_INTERRUPT
# define ES_HAL_ENABLE_GPIO
# define ES_HAL_ENABLE_UART
# define ES_HAL_ENABLE_CRC
# define ES_HAL_ENABLE_TIMER

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Identifikacione i opisne konstante mikroprocesora
 * @{ *//*--------------------------------------------------------------------*/
# define ES_HAL_CPU_NAME
# define ES_HAL_CPU_FAMILY
# define ES_HAL_CPU_MANUF

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Identifikacione i opisne konstante mikrokontrolera
 * @{ *//*--------------------------------------------------------------------*/
# define ES_HAL_MCU_NAME
# define ES_HAL_MCU_FAMILY
# define ES_HAL_MCU_MANUF
# define ES_HAL_MCU_FLASH
# define ES_HAL_MCU_RAM

/** @} *//*-------------------------------------------------------------------*/
#endif /* __DOXYGEN__ */

/**
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
 */
typedef enum esDevStatus {
/**
 * @brief       Hardver nije aktiviran.
 * @details     Ovo stanje je karakteristicno kada se hardver ne koristi i
 *              drajver je hardver postavio u rezim male potrosnje.
 */
    ES_HAL_DEV_INACTIVE,

/**
 * @brief       Hardver je spreman za koriscenje.
 */
    ES_HAL_DEV_READY,

/**
 * @brief       Hardver nije spreman za koriscenje.
 */
    ES_HAL_DEV_BUSY,

/**
 * @brief       Hardver je u stanju greske.
 * @details     U zavisnosti od koriscenog hardvera treba da se preduzmu
 *              odredjeni koraci kako bi se greska otklonila/ponistila.
 */
    ES_HAL_DEV_ERROR
} esDevStatus_T;

/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_generic.h
 ******************************************************************************/
#endif /* HAL_GENERIC_H_ */
