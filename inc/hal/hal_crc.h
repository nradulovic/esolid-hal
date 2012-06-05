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
 * @author  	Nenad Radulovic
 * @brief       Interfejs za CRC modul
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_crc
 * @brief		Izracunavanje CRC (Cyclic Redundancy Check) koda za detekciju gresaka
 ****************************************************************************************//** @{ */


#ifndef HAL_CRC_H_
#define HAL_CRC_H_

/*
 * NOTE: Svojstvo odredjuje hardverski profil varijante.
 */
#if defined(ES_FEATURE_CRC) || defined(__DOXYGEN__)
/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Tipovi podataka za CRC drajver
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura CRC drajvera
 * @details     Sledeca struktura cuva kontekst za izvrsavanje CRC algoritma.
 *              Sva polja strukture su parametri kojima se konfigurise algoritam.
 *//*--------------------------------------------------------------------------------------------*/
struct crcDef {
/**
 * @brief       Polinom CRC algoritma
 * @details     Ovom promenljivom se iskazuje polinom CRC algoritma. Zadnji bit
 *              polinoma se izostavlja. Na primer, ako je polinom 10110, onda
 *              treba navesti 06. Vazan aspekt ovog parametra je da predstavlja
 *              nereflektovan polinom.
 */
    uint32_t    poly;

/**
 * @brief       Sirina polinoma CRC algoritma
 * @details     Ova vrednost treba da je za 1-bit manja od stvarne sirine
 *              polinoma.
 */
    uint32_t    polyWidth;

/**
 * @brief       Ovaj parametar odredjuje pocetnu vrednost registra kada pocinje
 *              algoritam.
 */
    uint32_t    initData;

/**
 * @brief       Ova vrednost se XOR-uje sa vrednoscu iz povratnog registra.
 */
    uint32_t    xorOut;

/**
 * @brief       Reflektovanje ulaznog podatka.
 * @details     Ovo je boolean parametar. Ako je vrednost FALSE, ulazni bajtovi
 *              se obradjuju, gde se 7 bit tretira kao MSB, a bit 0 LSB. Ako
 *              ovaj parametar ima vrednost TRUE, svaki bajt se reflektuje pre
 *              obrade.
 */
    bool_T      refIn;

/**
 * @brief       Reflektovanje izlaznog podatka.
 * @details     Ovo je boolean parametar. Ako je podesen na vrednost FALSE,
 *              konacna vrednost u povratnom registru se direktno prosledjuje
 *              XOR out fazi, u suprotnom, ako ovaj parametar ima vrednost TRUE,
 *              konacna vrednost povratnog registra se prvo reflektuje.
 */
    bool_T      refOut;
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upravljacka struktura CRC drajvera.
 * @details     Struktura se koristi za cuvanje informacija koji CRC algoritam
 *              se koristi, status CRC modula i radni prostor za algoritam. Da
 *              bi se CRC drajver koristio mora da se najpre ova struktura
 *              instancira.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct crcDrv esCrcDrv_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura CRC drajvera.
 * @details     Struktura se koristi da se na lak nacin funkciji za
 *              inicijalizaciju preda opis CRC algoritma. Jedna definiciona
 *              struktura se moze koristi za inicijalizaciju vise drajvera.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct crcDef esCrcDef_T;
/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije za generisanje 16-bitnog i 32-bitnog CRC koda
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Generise 16-bitni CRC kod za ulazni blok @c pDataBlk.
 * @param       pDataBlk                Ulazni blok podataka,
 * @param       blkSize                 velicina bloka podataka.
 * @return      CRC kod za predati blok podataka.
 *//*--------------------------------------------------------------------------------------------*/
uint16_t esCrc16(
    uint8_t             * pDataBlk,
    size_t              blkSize);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Generise 16-bitni CRC kod za ulazni blok @c pDataBlk, sa
 *              inicijalnom vrednoscu @c initCrc.
 * @param       pDataBlk                Ulazni blok podataka,
 * @param       blkSize                 velicina bloka podataka,
 * @param       initCrc                 inicijalna vrednost CRC koda. Koristi se
 *                                      u slucaju kada je potrebno generisati
 *                                      CRC kod za nekoliko sukcesivnih blokova
 *                                      podataka.
 * @return      CRC kod za predati blok podataka.
 *//*--------------------------------------------------------------------------------------------*/
uint16_t esCrcPartial16(
    uint8_t             * pDataBlk,
    size_t              blkSize,
    uint16_t            initCrc);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Generise 32-bitni CRC kod za ulazni blok @c pDataBlk.
 * @param       pDataBlk                Ulazni blok podataka,
 * @param       blkSize                 velicina bloka podataka.
 * @return      CRC kod za predati blok podataka.
 *//*--------------------------------------------------------------------------------------------*/
uint32_t esCrc32(
    uint8_t             * pDataBlk,
    size_t              blkSize);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_crc.h
 *************************************************************************************************/
#endif /* ES_FEATURE_CRC */
#endif /* HAL_CRC_H_ */
