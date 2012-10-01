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
 * @brief       Interfejs za CPU modul.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_cpu
 ****************************************************************************************//** @{ */

#ifndef HAL_CPU_H_
#define HAL_CPU_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Atributi za CPU
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Operacije za citanje/upis iz ROM memorije su identicne
 *              operacijama za citanje/upis iz RAM memorije.
 * @details		Kada je ovaj atribut definisan onda kada je memorijski prostor
 * 				procesora jedinstven i pristup podacima u RAM i ROM memoriji je
 * 				identičan. Ovaj atribut	moze da se koristi radi selekcije
 * 				optimalnog algoritma u nekoj funkciji. Primera radi, kod
 * 				starijih mikrokontrolera (kao sto je PIC16 i PIC18 serija)
 * 				operacija čitanja podataka iz flash memorije zahteva najpre
 * 				inicijalizaciju tablicnih registara, a citanje podataka se
 * 				obavlja indirektno, preko registra. Navedene operacije zahtevaju
 * 				odredjeno vreme izvrsavanja i cela operacija postaje vrlo
 * 				neefikasna.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define ES_CPU_ATTRIB_UNITED_ACCESS
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Poravnjanje podataka
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define ES_CPU_ATTRIB_ALIGNMENT
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Tip podataka koji odgovara sirini magistrale podataka
 * @brief       Ovi tipovi definisu tipove podataka koji su @b zavisni od
 *              koriscene arhitekture/varijante.
 * @{ *//*---------------------------------------------------------------------------------------*/
#if !defined(ES_CPU_NATIVE_BITS) || defined(__DOXYGEN__)
# define ES_CPU_NATIVE_BITS             8U
typedef int8_t                          native_T;
#endif

#if !defined(ES_CPU_UNATIVE_BITS) || defined(__DOXYGEN__)
# define ES_CPU_UNATIVE_BITS            8U
typedef uint8_t                         unative_T;
#endif
/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Zaustavi procesor
 * @details     Ovaj makro se obicno poziva u slucaju neke katastrofalne greske
 *              i treba zaustaviti dalji rad procesora. Kada se jednom ovaj
 *              makro pokrene on se ne moze prekinuti.
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(ES_CPU_STOP) || defined(__DOXYGEN__)
# define ES_CPU_STOP()                                                         \
    while (1)

#endif

/*-------------------------------------------------------------------------------------------*//**
 * @name        Brza manipulacija sa bitovima
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Find Last set Bit makro
 * @param       expr1                   Broj koji se ispituje.
 * @return      y = log2(expr1)
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define ES_CPU_FLS(expr1)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Find First set Bit makro
 * @param       expr1                   Broj koji se ispituje.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(__DOXYGEN__)
# define ES_CPU_FFS(expr1)
#endif

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Manipulacija SysTick brojaca.
 * @brief       Makroi za rad sa SysTick brojacem.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izbor kloka koji se dovodi SysTick brojacu.
 * @param       clksource               Klok koji se dovodi SysTick modulu.
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(HAL_SYSTICK_CLOCK_CONFIG) || defined(__DOXYGEN__)
# define HAL_SYSTICK_CLOCK_CONFIG(clksource)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Uzimanje trenutne vrednosti broja tick-ova SysTick modula.
 * @return      Trenutna vrednost broja tick-ova u jedinici vremena.
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(HAL_SYSTICK_GET_TICK) || defined(__DOXYGEN__)
# define HAL_SYSTICK_GET_TICK()
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izbor broja tick-ova SysTick modula.
 * @param       tick                	Broj tick-ova koje generise SysTick modul.
 * @return      1 ako nije korektna tick vrednost ili 0 ako jeste.
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(HAL_SYSTICK_CONFIG) || defined(__DOXYGEN__)
# define HAL_SYSTICK_CONFIG(tick)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izvrsi inicijalizaciju SysTick.
 * @param       clksource               Klok koji se dovodi SysTick modulu.
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(HAL_SYSTICK_CLOCK_CONFIG) || defined(__DOXYGEN__)
# define HAL_SYSTICK_CLOCK_CONFIG(clksource)
#endif

/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_cpu.h
 *************************************************************************************************/
#endif /* HAL_CPU_H_ */
