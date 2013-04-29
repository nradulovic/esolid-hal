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
 * @brief       Interfejs za kompajler, sadrzi samo opise makroa.
 * @addtogroup  hal_compiler
 *********************************************************************//** @{ */

#ifndef HAL_COMPILER_H_
#define HAL_COMPILER_H_

/*=========================================================  INCLUDE FILES  ==*/

#if defined(__GNUC__)
# include "port/compiler/gcc.h"
#elif defined(__IAR_SYSTEMS_ICC__)
# include "port/compiler/iar.h"
#endif

/*===============================================================  MACRO's  ==*/
#if defined(__DOXYGEN__)
/*------------------------------------------------------------------------*//**
 * @name        Makroi za prosirene opcije C programskog jezika
 * @brief       Ovi makroi definisu interfejs za rad sa naprednim mogucnostima
 *              C kompajlera.
 * @details     Arhitekturna compiler.h datoteka treba da pruzi odgovarajuce
 *              makroe koji ce zameniti ove podrazumevane makroe. Za detalje
 *              oko implementacije navedenih makroa treba konsultovati
 *              compiler.h arhitekturnu datoteku u direktorijumu
 *              common/arhitektura.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Podrska za automatsko popunjavanje imena funkcija u makroima.
 */
# define C_FUNC

/**
 * @brief       Podrska za automatsko popunjavanje imena datoteke koja se
 *              kompajlira
 */
# define C_FILE

/**
 * @brief       Podrska za automatsko popunjavanje reda koda koji se kompajlira.
 */
# define C_LINE

/**
 * @brief       Podrska za C ekstenzije i uklanjanje naivnih upozorenja.
 */
# define C_EXT

/**
 * @brief       Atribut za pakovanje clanova jedne strukture.
 */
# define C_PACKED

/**
 * @brief       Atribut za poravnjanje clanova jedne strukture.
 */
# define C_ALIGNED

/**
 * @brief       Sprecava kompajler optimizator da izvrsi reorganizaciju koda
 *              zbog optimizacije.
 * @details     Koristi se u kriticnim sekcijama koda koji mora da se izvrsi bas
 *              po istom redosledu po kojem je kod i napisan. Pozivanjem ovog
 *              makroa vrsi se sprecavanje optimizatora da rasporedi instrukcije
 *              kako bi izvrsio optimizaciju.
 */
# define C_COMPILE_BARRIER()

/**
 * @brief       Sprecava upozoravanje kompajlera da funkcija ne vraca parametar
 *              iako njena deklaracija govori suprotno.
 */
# define C_NORETURN

/**
 * @brief       Sprecava upozoravanje kompajlera da se argument funkcije ne
 *              koristi.
 */
# define C_UNUSED_ARG(type,arg)

/**
 * @brief       Sprecava upozoravanje kompajlera da se promenljiva ne koristi.
 */
# define C_UNUSED_VAR(type,name)

/**
 * @brief       Uklanja upozorenje da se navedena promenljiva ne koristi.
 */
# define C_USED_VAR(type,name)

/**
 * @brief       Direktiva za inline kompajliranje funkcije.
 * @details     Za razliku od @ref C_INLINE direktive ovu direktivu ce
 *              kompajler bezuslovno izvrsiti.
 */
# define C_INLINE_ALWAYS

/**
 * @brief       Direktiva za inline kompajliranje funkcije.
 * @details     Ova direktiva se moze zanemariti od strane kompajlera. Kompajler
 *              moze odluciti da ne kreira inline funkciju.
 */
# define C_INLINE

/**
 * @brief       Direktiva koja govori da kompajler ne sme da izvrsi inline
 *              kompajliranje ove funkcuje.
 */
# define C_NOINLINE

/**
 * @brief       Sprecava upozorenje kompajlera da se neka funkcija ne koristi.
 */
# define C_UNUSED_FUNC

/**
 * @brief       ISO C99 ekstenzija, ne podrzavaju je svi kompajleri.
 * @details     The restrict keyword is a declaration of intent given by the
 *              programmer to the compiler. It says that for the lifetime of the
 *              pointer, only it or a value directly derived from it (such as
 *              pointer + 1) will be used to access the object to which it
 *              points.
 */
# define C_RESTRICT

/**
 * @brief       Direktiva koja govori kompajleru da kompajlira funkciju bez
 *              ulaznog i izlaznog (prologue/epilogue) koda
 */
# define C_NAKED

/**
 * @brief       Makro za pronalazak pokazivaca na strukturu kada je poznat
 *              pokazivac na jedan clan strukture.
 * @param       ptr                     Pokazivac na clan u nekoj strukturi,
 * @param       type                    tip te strukture,
 * @param       member                  ime clana u toj strukturi.
 * @details     Ovaj makro je zgodan kada imamo pokazivac @c ptr na clan
 *              @c member neke strukture tipa @c type, a potreban je pokazivac
 *              na celu strukturu.
 *              Makro se kompajlira u klasicnu @c load instrukciju, ali sa
 *              potrebnim offsetom (najcesce je negativni broj) za strukturu.
 */
# define C_CONTAINER_OF(ptr, type, member)                                      \
    ((type *)((char *)ptr - offsetof(type, member)))

/**
 * @brief       Deklarisanje funkcije kao slab simbol.
 * @details     Deklarisanje funkcije kao slab simbol omogucuje korisniku da
 *              napise svoju funkciju sa istim imenom koja će potisnuti slabu
 *              funkciju. Na taj nacin korisnik moze da definise svoju funkciju,
 *              a ukoliko ne definise svoju funkciju slaba funkcija se definise
 *              umesto nje.
 *
 *              Ovaj makro je pre svega koristan u definisanju bibliotečkih
 *              funkcija koje mogu biti poništene korisničkim kodom.
 */
# define C_WEAK_FUNC

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Opcije C kompajlera za embedded sisteme
 *              Klasa: common
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Direktiva za smestanje podataka u ROM tip memorije.
 */
# define C_ROM

/**
 * @brief       Modifikator za pristup podataka koji su u ROM memoriji.
 * @details     Mnogi kompajleri nude ne-standardne ekstenzije - direktive za
 *              definisanje i pristup podataka u ROM memoriji.
 */
# define C_ROM_VAR

/**
 * @brief       Deklaracija prekidne rutine
 * @details     Ovaj makro je uveden jer neki kompajleri zahtevaju dodatne
 *              atribute za funkcije kada se deklarise funkcija za prekid.
 */
# define C_INTERRUPT_HANDLER(name)                                              \
    void name (void)

/** @} *//*-------------------------------------------------------------------*/
#endif /* defined(__DOXYGEN__) */
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_compiler.h
 ******************************************************************************/
#endif /* HAL_COMPILER_H_ */
