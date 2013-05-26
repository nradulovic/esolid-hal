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
#include "hal.h"
#include "common/int_profile.h"

#if !defined(ES_HAL_FEATURE_INTERRUPT)
# error "HAL: hal_int.h does not support your current port"
#endif

/*===============================================================  MACRO's  ==*/

#if defined(__DOXYGEN__)

/**
 * @brief       Predefinisani prioriteti izvrsavanja koda
 * @details     Enumerator esHandlePrio definise moguce nivoe koje HAL definise
 *              za upotrebu. Ukoliko MCU definise manji broj nivoa nego sto je
 *              ovde definisano onda ce se nekoliko nivoa preklapati kako bi se
 *              osiguralo postojanje svih nivoa.
 *
 *              Svaki kod koji se izvrsava ima odredjeni nivo prioriteta.
 *              Podrazumevani nivo izvrsavanja je @ref ES_PRIO_IDLE. Koriscenjem
 *              makroa @ref ES_CRITICAL_ENTER i @ref ES_CRITICAL_EXIT moguce je
 *              podici prioritet koda. Podizanjem prioriteta koda moguce je
 *              zabraniti samo odredjene prekide ciji su prekidi manji ili
 *              jednaki prioritetu tekuce izvrsavanog koda.
 */
enum esInterruptPrio {
/**
 * @brief       Najnizi prioritet prekidne rutine ili koda koji se izvrsava
 */
    ES_PRIO_IDLE = 0,
    ES_PRIO_VERY_LOW = 32,
    ES_PRIO_LOW = 64,
    ES_PRIO_BELOW_NORMAL = 96,
    ES_PRIO_NORMAL = 128,
    ES_PRIO_ABOVE_NORMAL = 160,
    ES_PRIO_HIGH = 192,
    ES_PRIO_VERY_HIGH = 224,

/**
 * @brief       Najvisi prioritet prekidne rutine ili koda koji se izvrsava
 * @details     Ovaj nivo je jednak insturkcijama koje zabranjuju globalni
 *              prekid.
 */
    ES_PRIO_REALTIME = 255
};

/*------------------------------------------------------------------------*//**
 * @name        Ulazak i izlazak iz kriticnih sekcija koda
 * @brief       Kriticne sekcije koda su zasticene od prekida ciji su prioriteti
 *              manji ili jednaki od prioriteta tekuce izvrsavanog koda.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Deklaracija promenljive u kojoj se cuva trenutnu masku
 *              prioriteta tekuceg koda.
 * @details     Ovaj makro se koristi u kombinaciji sa makroima za ulazak i
 *              izlazak iz kriticnih sekcija koda.
 */
# define ES_CRITICAL_DECL()

/**
 * @brief       Ulazak u kriticni deo koda, postavlja se najvisi dozvoljeni
 *              prioritet za eSolid
 * @param       prio                    Prioritet kriticne sekcije koda.
 *  @arg        0 - 255                 postavljanje maske.
 */
# define ES_CRITICAL_ENTER(prio)

/**
 * @brief       Izlazak iz kriticnog dela koda, vraca se prethodni prioritet.
 */
# define ES_CRITICAL_EXIT()

/** @} *//*-------------------------------------------------------------------*/
#endif /* defined(__DOXYGEN__) */
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
/*------------------------------------------------------------------------*//**
 * @name        Maskiranje prioriteta prekidnih rutina
 * @brief       Ove funkcije se koriste za manipulaciju sa globalnom maskom
 *              prioriteta prekidnih rutina.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Postavlja masku prioriteta
 * @param       prio                    Nova maska prioriteta.
 *  @arg        0                       iskljucivanje maske,
 *  @arg        1 - 255                 postavljanje maske.
 * @details     Ovom funkcijom se postavlja granica prioriteta iznad koje mogu
 *              da se dese prekidi. Najnizi prioritet prekida je 0, a najvisi
 *              prioritet je 255. Maksimalni prioritet koji se moze podesiti
 *              je 255 i postavljanje maske na 255 efektivno onemogucuje sve
 *              prekide. Maska sa vrednoscu 0 je rezervisana za iskljucivanje
 *              maske. Podrazumevano, maska je 0, sto znaci da su prekidi svih
 *              prioriteta omoguceni.
 */
void esIntPrioMaskSet(
    uint32_t        prio);

/**
 * @brief       Dobavlja trenutnu masku prioriteta prekidnih rutina.
 * @return      Trenutna maska prioriteta.
 *  @retval     0                       maska je iskljucena,
 *  @retval     1 - 255                 vrednost maske.
 */
esIntPrioReg_T esIntPrioMaskGet(
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
