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
 * @addtogroup  hal_cpu_intf
 *********************************************************************//** @{ */

#ifndef HAL_CPU_H_
#define HAL_CPU_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  MACRO's  ==*/
#if defined(__DOXYGEN__)
/*------------------------------------------------------------------------*//**
 * @name        Identifikacione i opisne konstante mikroprocesora
 * @details     Konstantne niske (string) koje identifikuju mikroprocesor
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Ime procesora
 * @details     Konstantna niska imena procesora, na primer: "Cortex-M3"
 */
# define ES_HAL_CPU_NAME

/**
 * @brief       Serija procesora
 * @details     Konstantna niska imena familije procesora, na primer: "ARMv7-M"
 */
# define ES_HAL_CPU_SERIES

/**
 * @brief       Proizvodzac procesora
 * @details     Konstantna niska proizvodzaca procesora, na primer: "ARM"
 */
# define ES_HAL_CPU_MANUF

/** @} *//*-------------------------------------------------------------------*/
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
# define ES_CPU_ATTRIB_LINEAR_ADDR

/**
 * @brief       Pokazuje da li CPU podrzava pristup podacima koji nisu
 *              poravnani
 *
 *              Ukoliko je makro:
 *              - definisan - CPU podrzava pristup podacima koji ne moraju da
 *                  budu poravnani
 *              - nedefinisan - CPU ne podrzava neporavnani pristup
 */
# define ES_CPU_ATTRIB_UNALIGNED_ACCESS

/**
 * @brief       Poravnjanje podataka (alignement)
 */
# define ES_CPU_ATTRIB_ALIGNMENT

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Tip podataka koji odgovara sirini magistrale podataka
 * @brief       Ovi tipovi definisu tipove podataka koji su @b zavisni od
 *              koriscene arhitekture/varijante.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Broj bitova u oznacenom podatku koji ima sirinu data magistrale
 *              procesora
 */
# define ES_CPU_NATIVE_BITS

/**
 * @brief       Broj bitova u neoznacenom podatku koji ima sirinu data
 *              magistrale procesora
 */
# define ES_CPU_UNATIVE_BITS

/** @} *//*-------------------------------------------------------------------*/
#endif /* defined(__DOXYGEN__) */
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Dobavlja trenutnu brzinu rada mikroprocesora
 * @details     Funkcija smatra da je vrednost frekvencije eksternih oscilatora
 *              tacno 1MHz. Tako da je korisnik duzan da izvrsi potrebno
 *              skaliranje frekvencije na pravu vrednost. Recimo da funkcija
 *              vrati vrednost 2.000.000 Hz, a korisnik je prikljucio kvarz za
 *              8MHz. Faktor skaliranja je 8MHz/1MHz = 8 sto znaci da izlazna
 *              vrednost treba da se pomnozi sa 8 i dobijamo da mikroprocesor
 *              radi na 16.000.000 Hz, odnosno, 16MHz.
 * @return      Vrednost taktne frekvencije mikroprocesora u Hz kada se koristi
 *              interni oscilator, a kada se koristi eksterni oscilator vraca
 *              vrednost Hz po 1MHz.
 */
uint32_t esCpuSpeedGet(
    void);

/**
 * @brief       Zaustavlja procesor
 * @details     Poziva se kada treba zaustaviti dalji rad procesora.
 * @note        Kada se kompajlira @c release verzija koda funkcija postavlja
 *              procesor u stanje @c sleep.
 */
void esCpuStop(
    void);

/**
 * @brief       Prebacuje rezim rada CPU-a u stanje uspavano
 * @details     Ovaj makroi prepacuje mikrokontroler u stanje najmanje potrosnje.
 *              Periferija koja generise dogadjaje mora da nastavi da radi. U
 *              slucaju da mikrokontroler ne podrzava rad periferije dok je CPU
 *              u uspavanom rezimu funkcija nece postaviti MCU u stanje male
 *              potrosnje.
 * @note        Kada se kompajlira @c debug verzija koda funkcija ne postavlja
 *              procesor u stanje @c sleep jer obicno @c sleep stanja procesora
 *              gase i vezu sa debagerom. Zbog toga se funkcija kompajlira u
 *              NOP instrukciju i omogucava nesmetano debagiranje.
 */
void esCpuSleep(
    void);

/*------------------------------------------------------------------------*//**
 * @name        Logicke i aritmeticke operacije
 * @{ *//*--------------------------------------------------------------------*/

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
 */
uint_fast8_t esCpuFindLastSet(
    uint32_t        value);

/**
 * @brief       Find First set Bit
 * @param       value                   Broj koji se ispituje.
 * @return      Vraca poziciju zadnjeg bita koji je setovan u @c value.
 */
uint_fast8_t esCpuFindFirstSet(
    uint32_t        value);

/** @} *//*-------------------------------------------------------------------*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_cpu.h
 ******************************************************************************/
#endif /* HAL_CPU_H_ */
