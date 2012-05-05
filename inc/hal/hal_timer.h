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
 * @brief       Interfejs za Timer modul.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_timer
 * @brief		Upravljanje tajmerima
 ****************************************************************************************//** @{ */


#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_

/*============================================================================  INCLUDE FILES  ==*/
#include PORT_VARIANT_HEADER(timer_lld)

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Rezim rada Timer drajvera
 *//*--------------------------------------------------------------------------------------------*/
enum esTimerMode {
/**
 * @brief       Timer modul se ukljucuje samo jedanput.
 */
    ES_TIMER_MODE_ONCE,

/**
 * @brief       Timer se ukljucuje periodicno.
 */
    ES_TIMER_MODE_PERIODIC
};

/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Pomocni makro za definisanje Timer drajvera
 * @param       name                    Ime upravljacke strukture GPIO drajvera,
 * @param       mode                    rezim rada Timer drajvera,
 *  @arg        ES_TIMER_MODE_ONCE
 *  @arg        ES_TIMER_MODE_PERIODIC
 * @param       microseconds            interval tajmera,
 * @param       pHandler                prekidna rutina,
 * @param       pHandlerArg             argumenti prekidne rutine,
 * @param       prio                    prioritet prekidne rutine.
 * @see esTimerMode
 * @see esHandlerPrio
 *//*--------------------------------------------------------------------------------------------*/
#define ES_GPIO_DEFINITION(name, mode, microseconds, pHandler, pHandlerArg, prio) \
    const C_ROM esTimerDef_T name = {name, mode, microseconds, pHandler, pHandlerArg, prio}

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif
  
/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Tipovi podataka Timer modula
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Prekidna rutina za tajmere
 * @details     Funkcija se predaje jedan argument, @c void * koji pokazuje na
 *              zeljene korisnicke podatke.
 *//*--------------------------------------------------------------------------------------------*/
typedef void (* pTimerHandler_T) (void *);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura za Timer drajver
 * @details     U ovoj strukturi se opisuje:
 *              - rezim rada tajmera,
 *              - interval tajmera,
 *              - prekidna funkcija,
 *              - argumenti prekidne funkcije.
 *//*--------------------------------------------------------------------------------------------*/
struct tmrDef {
/**
 * @brief       Rezim rada tajmera
 * @details     Moguce vrednosti:
 *              - ES_TIMER_MODE_ONCE - Timer modul se ukljucuje samo jedanput.
 *              Nakon isteka zadatog intervala poziva se pHandler funkcija.
 *              - ES_TIMER_MODE_PERIODIC - Timer modul je stalno ukljucen,
 *              tajmer odbrojava sa periodom navedenom u microseconds
 *              promenljivoj. Funkcija pHandler se poziva nakon isteka svake
 *              periode.
 */
    enum esTimerMode  mode;

/**
 * @brief       Interval tajmera u mikrosekundama
 */
    uint32_t        microseconds;

/**
 * @brief       Prekidna rutina koja opsluzuje tajmer
 */
    pTimerHandler_T pHandler;

/**
 * @brief       Argument koji se predaje prekidnoj rutini
 */
    void            * pHandlerArg;

/**
 * @brief       Prioritet prekidne rutine
 */
    enum esHandlerPrio prio;
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura Timer modula.
 * @details     Preko ove strukture Timer drajver se spaja sa zeljenim Timer
 *              modulom. Ove strukture su definisane interno i njima se ne
 *              pristupa direktno od strane korisnika vec se samo koriste kao
 *              argument funkcije za inicijalizaciju.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct tmrId esTimerId_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upravljacka struktura Timer drajvera.
 * @details     Struktura se koristi za cuvanje informacija koji Timer modul se
 *              koristi, status Timer modula i za brz pristup registrima. Da bi
 *              se Timer drajver koristio mora da se najpre ova struktura
 *              instancira.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct tmrDrv esTimerDrv_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura Timer drajvera.
 * @details     Struktura se koristi da se na lak nacin funkciji za
 *              inicijalizaciju preda opis Timer modula. Jedna definiciona
 *              struktura se moze koristi za inicijalizaciju vise tajmera.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct tmrDef esTimerDef_T;

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione strukture Timer modula
 * @brief       Koriste se prilikom inicijalizacije Timer modula
 * @details     Prilikom inicijalizacije dovoljno je navesti ime zeljenog Timer
 *              modula.
 * @see         esTimerInit()
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_TIMER) || defined(__DOXYGEN__)
# if defined(OPT_HAL_TIMER_USE_1) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura za Timer modul 1.
 *//*--------------------------------------------------------------------------------------------*/
extern const C_ROM struct tmrId esTimer1;
# endif

# if defined(OPT_HAL_TIMER_USE_2) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura za Timer modul 2.
 *//*--------------------------------------------------------------------------------------------*/
extern const C_ROM struct tmrId esTimer2;
# endif

# if defined(OPT_HAL_TIMER_USE_3) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura za Timer modul 3.
 *//*--------------------------------------------------------------------------------------------*/
extern const C_ROM struct tmrId esTimer3;
# endif
#endif /* OPT_HAL_TIMER */
/** @} *//*--------------------------------------------------------------------------------------*/

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Opste funkcije za rad sa tajmerima
 * @brief       Inicijalizacija, deinicijalizacija i status Timer modula.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizacija Timer drajvera
 * @param       timerId                 Identifikaciona struktura.
 * @param       timerDef                Definiciona struktura.
 * @param       timer                   Upravljacka struktura.
 * @note        Ova funkcija se mora pozvati pre koriscenja bilo koje funkcije
 *              u ovom modulu.
 *//*--------------------------------------------------------------------------------------------*/
void esTimerInit(
    const C_ROM esTimerId_T * timerId,
    const C_ROM esTimerDef_T * timerDef,
    esTimerDrv_T    * timer);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Deinicijalizacija Timer drajvera
 * @param       timer                   Pokazivac na upravljacku strukturu.
 * @details     Funkcija se poziva kada je potrebno da se prekine sa radom sa
 *              Timer drajverom.
 *//*--------------------------------------------------------------------------------------------*/
void esTimerDeInit(
    esTimerDrv_T    * timer);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Status Timer drajvera.
 * @param       timer                   Pokazivac na upravljacku strukturu.
 * @return      U zavisnosti od stanja drajvera funkcija vraca:
 *              - ES_DEV_INACTIVE - hardver je neaktivan i u stanju
 *              male potrosnje. Da bi se hardver koristio treba da se prebaci u
 *              aktivno stanje.
 *              - ES_DEV_BUSY - hardver se upravo koristi.
 *              Timer drajver ne podrzava ostala stanja drajvera navedena u
 *              @ref esDevStatus.
 *//*--------------------------------------------------------------------------------------------*/
esDevStatus_T esTimerStatus(
    esTimerDrv_T    * timer);

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije za standardni pristup Timer hardveru
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Ukljucuje odbrojanje tajmera
 * @param       timer                   Upravljacka struktura drajvera.
 * @return      Trenutna vrednost brojaca.
 *//*--------------------------------------------------------------------------------------------*/
uint32_t esTimerStart(
    esTimerDrv_T    * timer);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Zaustavlja brojanje tajmera.
 * @param       timer                   Upravljacka struktura drajvera.
 * @return      Trenutna vrednost brojaca.
 *//*--------------------------------------------------------------------------------------------*/
uint32_t esTimerStop(
    esTimerDrv_T    * timer);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_timer.h
 *************************************************************************************************/
#endif /* HAL_TIMER_H_ */
