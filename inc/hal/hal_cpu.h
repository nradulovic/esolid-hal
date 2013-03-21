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
 * @brief       Interfejs za CPU modul.
 * @addtogroup  hal_cpu
 *********************************************************************//** @{ */

#ifndef HAL_CPU_H_
#define HAL_CPU_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Atributi za CPU
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Operacije za citanje/upis iz ROM memorije su identicne
 *              operacijama za citanje/upis iz RAM memorije.
 * @details		Kada je ovaj atribut definisan onda kada je memorijski prostor
 * 				procesora jedinstven, odnosno, linearan i pristup podacima u RAM
 * 				i ROM memoriji je identican. Ovaj atribut moze da se koristi
 * 				radi selekcije optimalnog algoritma u nekoj funkciji.
 *
 * 				Primera radi, kod starijih mikrokontrolera (kao sto je PIC16 i
 * 				PIC18 serija) operacija citanja podataka iz FLASH memorije
 * 				zahteva najpre inicijalizaciju tablicnih registara i citanje
 * 				podataka se	obavlja indirektno, preko registra. Navedene
 * 				operacije zahtevaju odredjeno vreme izvrsavanja i ceo proces je
 * 				vrlo neefikasan.
 *
 * 				Ukoliko je makro:
 * 				- definisan - CPU ima linearan adresni prostor
 * 				- nedefinisan - CPU ima odvojene adresne prostore za podatke i
 * 				program
 */
#if defined(__DOXYGEN__)
# define ES_CPU_ATTRIB_LINEAR_ADDR
#endif

/**
 * @brief       Pokazuje da li CPU podrzava pristup podacima koji nisu
 *              poravnani
 *
 *              Ukoliko je makro:
 *              - definisan - CPU podrzava pristup podacima koji ne moraju da
 *                  budu poravnani
 *              - nedefinisan - CPU ne podrzava neporavnani pristup
 */
#if defined(__DOXYGEN__)
# define ES_CPU_ATTRIB_UNALIGNED_ACCESS
#endif

/**
 * @brief       Poravnjanje podataka (alignement)
 */
#if defined(__DOXYGEN__)
# define ES_CPU_ATTRIB_ALIGNMENT
#endif

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Tip podataka koji odgovara sirini magistrale podataka
 * @brief       Ovi tipovi definisu tipove podataka koji su @b zavisni od
 *              koriscene arhitekture/varijante.
 * @{ *//*--------------------------------------------------------------------*/
#if !defined(ES_CPU_NATIVE_BITS) || defined(__DOXYGEN__)
# define ES_CPU_NATIVE_BITS
#endif

#if !defined(ES_CPU_UNATIVE_BITS) || defined(__DOXYGEN__)
# define ES_CPU_UNATIVE_BITS
#endif

/** @} *//*-------------------------------------------------------------------*/
/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Manipulacija SysTick brojaca.
 * @brief       Makroi za rad sa SysTick brojacem.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Izbor kloka koji se dovodi SysTick brojacu.
 * @param       clksource               Klok koji se dovodi SysTick modulu.
 */
#if !defined(HAL_SYSTICK_CLOCK_CONFIG) || defined(__DOXYGEN__)
# define HAL_SYSTICK_CLOCK_CONFIG(clksource)
#endif

/**
 * @brief       Uzimanje trenutne vrednosti broja tick-ova SysTick modula.
 * @return      Trenutna vrednost broja tick-ova u jedinici vremena.
 */
#if !defined(HAL_SYSTICK_GET_TICK) || defined(__DOXYGEN__)
# define HAL_SYSTICK_GET_TICK()             0U
#endif

/**
 * @brief       Izbor broja tick-ova SysTick modula.
 * @param       tick                	Broj tick-ova koje generise SysTick modul.
 * @return      1 ako nije korektna tick vrednost ili 0 ako jeste.
 */
#if !defined(HAL_SYSTICK_CONFIG) || defined(__DOXYGEN__)
# define HAL_SYSTICK_CONFIG(tick)
#endif

/**
 * @brief       Izvrsi inicijalizaciju SysTick.
 * @param       clksource               Klok koji se dovodi SysTick modulu.
 */
#if !defined(HAL_SYSTICK_CLOCK_CONFIG) || defined(__DOXYGEN__)
# define HAL_SYSTICK_CLOCK_CONFIG(clksource)
#endif

/** @} *//*-------------------------------------------------------------------*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Zaustavi procesor
 * @details     Poziva se kada treba zaustaviti dalji rad procesora.
 * @note        Kada se kompajlira @c release verzija koda funkcija postavlja
 *              procesor u stanje @c sleep.
 * @inline
 */
#if defined(__DOXYGEN__)
C_INLINE_ALWAYS void esCpuStop(
    void);
#endif

/**
 * @brief       Prebaci rezim rada u stanje uspavano
 * @details     Ovaj makroi prepacuje mikrokontroler u stanje najmanje potrosnje.
 *              Periferija koja generise dogadjaje mora da nastavi da radi. U
 *              slucaju da mikrokontroler ne podrzava rad periferije dok je CPU
 *              u uspavanom rezimu funkcija nece postaviti MCU u stanje male
 *              potrosnje.
 * @note        Kada se kompajlira @c debug verzija koda funkcija ne postavlja
 *              procesor u stanje @c sleep jer obicno @c sleep stanja procesora
 *              gase i vezu sa debagerom. Zbog toga se funkcija kompajlira u
 *              NOP instrukciju i omogucava nesmetano debagiranje.
 * @inline
 */
#if defined(__DOXYGEN__)
C_INLINE_ALWAYS void esCpuSleep(
    void);
#endif

/**
 * @brief       Find Last set Bit
 * @param       value                   Broj koji se ispituje.
 * @return      y = log2(expr1)
 * @pre         value != 0
 * @details     Primer 1: parametar @c value ima vrednost sa binarnom
 *              reprezentacijom: 110. Funkcija u ovom slucaju vraca vrednost 2.
 *              Primer 2: parameter @c value ima vrednost sa binarnom
 *              reprezentacijom: 101001. Funkcija u ovom slucaju vraca vrednost
 *              5.
 * @inline
 */
#if defined(__DOXYGEN__)
C_INLINE_ALWAYS uint_fast8_t esCpuFindLastSet(
    uint32_t value);
#endif

/**
 * @brief       Find First set Bit
 * @param       value                   Broj koji se ispituje.
 * @return      Vraca poziciju zadnjeg bita koji je setovan u @c value.
 * @inline
 */
#if defined(__DOXYGEN__)
C_INLINE_ALWAYS uint_fast8_t esCpuFindFirstSet(
    uint32_t value);
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_cpu.h
 ******************************************************************************/
#endif /* HAL_CPU_H_ */
