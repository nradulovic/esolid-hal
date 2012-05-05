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
 * @author      Nenad Radulovic
 * @brief       Interfejs Hardware Abstraction Layer (HAL) modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_intf
 * @brief       Interfejs Hardware Abstraction Layer (HAL) modula.
 * @section     hal_intro Hardware Abstraction Layer
 * U ovom odeljku je predstavljena specifikacija Hardware Abstraction Layer
 * (HAL) modula. HAL vrsi apstrakciju procesorske arhitekture i/ili platforme
 * na nivo dovoljan da sistem koji koristi eSolid pakete bude prebaceno (port)
 * na tu platformu.
 *
 * @section     hal_principles Osnovna nacela
 * HAL implementacija je vodjena sledecim osnovnim nacelima:
 * - HAL je implementiran u C-u i asembleru.
 * - Interfejs je pisan pomocu C makroa. Ovo omogucava da se interfejs
 * implementira kao C funkcija, asembler ili poziv na eksterne C ili asembler
 * funkcije. Time se postize odabir najefikasnije implementacije bez promene
 * interfejsa.
 * - HAL pruza jednostavan, portabilan interfejs za manipulaciju sa hardverom
 * sirokog spektra. Programeru se uvek ostavlja mogucnost da se HAL zaobidje i
 * vrsi direktan pristup hardveru. Ovakav nacin rada nije preporucljiv jer se
 * smanjuje portabilnost koda.
 *
 * @section     hal_interface HAL interfejs
 * HAL interfejs je podeljen u nekoliko celina gde svaka celina opsluzuje jedan
 * hardverski modul. Jedna celina cini drajver datog hardverskog modula. Svaki
 * drajver ima interfejs koji je kreiran u skladu sa odredjenim smernicama.
 *
 * Opsta struktura podataka drajvera je sledeca:
 * - nepromenljivi, privatni podaci,
 * - nepromenljivi, javni podaci,
 * - promenljivi, privatni podaci,
 * - promenljivi, javni podaci.
 *
 * <b>Nepromenljivi, privatni podaci</b> se koriste za identifikaciju
 * hardverskog modula. Tako, na primer, postoje esGPIOA, esGPIOB, esUART0,
 * esUART1, esUART2 struktrure koje se koriste prilikom pozivanja
 * inicijalizacione funkcije. Atribut @c "nepromenljivi" kazuje da su podaci
 * smesteni u ROM/FLASH memoriji, a atribut @c "privatni" se koristi jer
 * korisnik nema dojam o strukturi podataka. Ova struktura se krace zove
 * <b> identifikaciona struktura </b>.
 *
 * <b>Nepromenljivi, javni podaci</b> se koriste za definisanje rada drajver
 * modula. U ovu strukturu podataka korisnik upisuje zeljene atribute drajver
 * modula. Prilikom inicijalizacije drajver se konfigurise prema definiciji koja
 * je navedena u strukturi. Ova struktura se nalazi u ROM/FLASH memoriji i
 * naziva se <b> definiciona struktura </b>.
 *
 * <b>Promenljivi, privatni podaci</b> su smesteni u RAM memoriju, cuvaju stanje
 * drajvera i ostale podatke o hardveru. Korisnik nema direktan pristup ovim
 * podacima, osim preko definisanog interfejsa.
 *
 * <b>Promenljivi, javni podaci</b> se, takodje, cuvaju u RAM memoriju,
 * struktura je poznata korisniku i moze da izvrsi pristup njima. U ovu
 * strukturu se cuva barem identifikator hardverskog modula koji se upotrebljava.
 * Ova struktura se naziva <b> upravljacka struktura </b>.
 *
 * U zavisnosti od implementacije, ne mora svaki drajver da poseduje sve
 * pomenute strukture podataka, ali svaki drajver mora minimalno da ima
 * identifikacione strukture koje se koriste prilikom inicijalizacije.
 *
 * @subsection  hal_interface_init Inicijalizacija drajvera
 * Inicijalizacija se u opstem slucaju vrsi u nekoliko koraka:
 * 1. Instaciranje struktrure promenljivih javnih podataka, odnosno, upravljacke
 *    strukture podataka,
 * 2. instaciranje strukture nepromenljivih, javnih podataka, odnosno,
 *    definicione strukture,
 * 3. poziva se funkcija za inicijalizaciju kojoj se predaje:
 *    - identifikaciona struktura,
 *    - definiciona struktura podataka i
 *    - upravljacka struktura.
 * Instanca strukture promenljivih, javnih podataka se koristi kao identifikator
 * drajvera za hardver koji se koriste za sve druge funkcije.
 *
 * @subsection  hal_interface_usage Upotreba drajvera
 * Nakon inicijalizacije mogu se pozivati funkcije drajvera. Svim funkcija se
 * predaje instanca strukture promenljivih, javnih podataka kako bi funkcija
 * znala sa kojim hardverskim modulom se radi.
 *
 * @subsection  hal_interface_deinit Zavrsetak rada sa drajverom
 * Za prestanak rada sa drajverom dovoljno je pozvati DeInit funkciju koja ce
 * izvrsiti prebacivanje hardvera u rezim male potrosnje, ukoliko to podrzava.
 *
 * @section     hal_structure Struktura HAL
 * HAL se sastoji iz tri klasa. U sledecoj tabeli prikazani su kratki opisi
 * klasa:
<table>
<tr>
    <td><b>HAL klasa</b></td>
    <td><b>Opis</b></td>
    <td><b>Funkcija</b></td>
</tr>

<tr>
    <td>Arhitektura HAL</td>
    <td>Funkcionalnost koja je vezana za jednu arhitekturu procesora u kombinaciji sa izabranim kompajlerom. Deo funkcionalnosti moze biti redefinisana u Varijant HAL.</td>
    <td>Debug funkcionalnost specificna za arhitekturu, definicije vektora prekida i izuzetaka i njihovih rutina, makroi konteksta, sistemska inicijalizacija</td>
</tr>
<tr>
    <td>Varijanta HAL</td>
    <td>Neke procesorske arhitekture dolaze u nekoliko varijanti, na primer MIPS dolazi u 32 i 64 bita, a neki procesori imaju i dodatne module.</td>
    <td>Varijanta HAL prosiruje funkcionalnost Arhitektura HAL-a, konfiguracione opcije, drajveri za dodatne module.</td>
</tr>
    <tr>
    <td>Platforma HAL</td>
    <td>Sadrzi funkcionalnost i konfiguracione opcije vezane za platformu.</td>
    <td>Prva inicijalizacija hardvera, specifikacija memorijske strukture, konfiguracione opcije (brzina procesora, opcije kompajlera), debug IO funkcije.</td>
</tr>
</table>
 ****************************************************************************************//** @{ */


#ifndef HAL_H_
#define HAL_H_


/*============================================================================  INCLUDE FILES  ==*/
#include "cfg/hal_cfg.h"
#include "hal_compiler.h"
#include "hal_cpu.h"
#include "hal_interrupt.h"
#include "hal_gpio.h"
#include "hal_uart.h"
#include "hal_timer.h"
#include "hal_crc.h"
#include "hal_support.h"


/*==================================================================================  DEFINES  ==*/
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
