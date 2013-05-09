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
 * @brief       Interfejs Hardware Abstraction Layer (HAL) modula.
 * @addtogroup  hal_intf
 *********************************************************************//** @{ */

#ifndef HAL_H_
#define HAL_H_

/*=========================================================  INCLUDE FILES  ==*/
#include "hal_compiler.h"
#include "common/hal_profile.h"

#if !defined(ES_HAL_PROFILE_ENABLED)
# error "HAL: HAL does not support your current port"
#endif

/*===============================================================  MACRO's  ==*/
#if defined(__DOXYGEN__)
/*------------------------------------------------------------------------*//**
 * @name        Konstante mogucnosti HAL modula
 * @details     Ovi makroi govore da za datu funkcionalnost postoje HAL moduli.
 *              Ukoliko je makro definisan onda HAL podrzava datu funkcionalnost.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       HAL podrzava start-up kod i linker skriptu
 */
# define ES_HAL_FEATURE_STARTUP

/**
 * @brief       HAL podrzava CPU
 */
# define ES_HAL_FEATURE_CPU

/**
 * @brief       HAL podrzava interrupt kontroler
 */
# define ES_HAL_FEATURE_INTERRUPT

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Identifikacione i opisne konstante mikrokontrolera
 * @details     Konstantne niske (string) koje identifikuju mikrokontroler
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Ime mikrokontrolera
 * @details     Konstantna niska mikrokontrolera, na primer: "STM32F100RB"
 */
# define ES_HAL_MCU_NAME

/**
 * @brief       Familija mikrokontrolera
 * @details     Konstantna niska familije mikrokontrolera, na primer: "STM32F10x"
 */
# define ES_HAL_MCU_FAMILY

/**
 * @brief       Proizvodzac mikrokontrolera
 * @details     Konstantna niska imena proizvodzaca, na primer: "ST Microelectronics"
 */
# define ES_HAL_MCU_MANUF

/**
 * @brief       Velicina FLASH (programske) memorije u bajtovima
 * @details     Tip podatka je unsigned long, odnosno, uint32_t. Na primer:
 *              32768UL
 */
# define ES_HAL_MCU_FLASH

/**
 * @brief       Velicina RAM memorije u bajtovima
 * @details     Vraca velicinu RAM memorije u bajtovima. Ukoliko embedded sistem
 *              poseduje vise RAM memorija, vraca se velicina RAM memorije za
 *              cuvanje programskih podataka.
 */
# define ES_HAL_MCU_RAM

/** @} *//*-------------------------------------------------------------------*/
#endif /* __DOXYGEN__ */

/*------------------------------------------------------------------------*//**
 * @name        Makroi opste namene - Extended Support
 * @details     Ovde su dostupni makroi za:
 *              - rad sa stringovima i konkatenacija
 *              - jednostavne aritmeticke operacije
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Izracunavanje dimenzije elementa jedno-dimenzionalnog niza
 *              @a expr.
 * @param       string                  Niz
 * @mseffect
 */
#define ES_DIMENSION(string)                                                    \
    (sizeof(string) / sizeof(string[0]))

/**
 * @brief       Vrsi deljenje dva broja i zaokruzuje rezultat.
 * @param       expr1                   deljenik
 * @param       expr2                   delitelj
 * @note        Pozeljno je da @a expr2 bude konstanta, inace, generisace se dva
 *              deljenja.
 * @mseffect
 * @par         Primer:
 * @include     es_div_round.c
 *
 * @par         Izlaz:
 *
 *              @code
 *              Deljenje 28 / 5 = 5
 *              Zaokruzeno: 6
 *              @endcode
 */
#define ES_DIV_ROUND(numerator, denominator)                                    \
    (((numerator) + ((denominator) / 2U)) / (denominator))

/**
 * @brief       Vrsi deljenje dva broja sa zaokruzivanjem broja navise.
 * @param       expr1                   deljenik
 * @param       expr2                   delitelj
 * @note        Pozeljno je da @a expr2 bude konstanta, inace, generisace se
 *              jedno oduzimanje i jedno deljenje.
 * @mseffect
 * @par         Primer:
 * @include     es_div_roundup.c
 *
 * @par         Izlaz:
 *
 *              @code
 *              Deljenje 27 / 5 = 5
 *              Zaokruzeno: 6
 *              @endcode
 */
#define ES_DIV_ROUNDUP(numerator, denominator)                                  \
    (((numerator) + (denominator) - 1U) / (denominator))

/**
 * @brief       Vraca vecu vrednost od ponudjenih vrednosti @a expr1 i @a expr2
 */
#define ES_MAX(expr1, expr2)                                                    \
    ((expr1 > expr2) ? expr1 : expr2))

/**
 * @brief       Vraca manju vrednost od ponudjenih vrednosti @a expr1 i @a expr2
 */
#define ES_MIN(expr1, expr2)                                                    \
    ((expr1 < expr2) ? expr1 : expr2))

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Makroi za bit manipulaciju - Extended Support
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Vrsi poravnjanje @a num promenjive sa granicama specificarane
 *              u @a align
 * @param       num                     Promenjiva koju treba poravnati,
 * @param       align                   granica poravnanja.
 * @details     Primer:
 *              @a expr1 ima binarnu vrednost: 10010101 = 149
 *              @a expr2 ima binarnu vrednost: 00000100 = 4
 *              Dobija se 152.
 * @mseffect
 */
#define ES_ALIGN(num, align)                                                    \
    ((num) & ~((align) - 1U))

/**
 * @brief       Vrsi poravnjanje @a num promenjive sa granicama specificarane
 *              u @a align
 * @param       num                     Promenjiva koju treba poravnati,
 * @param       align                   granica poravnanja.
 * @details     Primer:
 *              @a expr1 ima binarnu vrednost: 10010101 = 149
 *              @a expr2 ima binarnu vrednost: 00000100 = 4
 *              Dobija se 152.
 * @mseffect
 */
#define ES_ALIGN_UP(num, align)                                                 \
    (((num) + (align) - 1U) & ~((align) - 1U))

/**
 * @brief       Da li je @c expr jednak nekom stepenu dvojke?
 * @details     Makro vraca TRUE kada je vrednost @c expr izraza jednaka nekom
 *              stepenu dvojke, inace, vraca FALSE.
 * @mseffect
 */
#define ES_IS_POW2(num)                                                         \
    (!((num) & ((num) - 1)))

/**
 * @brief       Izracunava log2 za vreme kompajliranja za uint8_t
 * @mseffect
 */
#define ES_UINT8_LOG2(x)                                                        \
    ((x) < 2 ? 0 :                                                              \
     ((x) < 4 ? 1 :                                                             \
      ((x) < 8 ? 2 :                                                            \
       ((x) < 16 ? 3 :                                                          \
        ((x) < 32 ? 4 :                                                         \
         ((x) < 64 ? 5 :                                                        \
          ((x) < 128 ? 6 : 7)))))))

/**
 * @brief       Kreira masku za MSB bit koji odgovara tipu @c type
 * @param       type                    Tip podataka za koji se trazi MSB.
 * @return      Odgovarajuca binarna maska za MSB.
 */
#define ES_MASK_MSB(type)                                                       \
    (1UL << ((sizeof(type) * 8U) - 1U))

/**
 * @brief       Postavlja MSB bit na jedan, "1".
 * @param       var                     Promenljiva kojoj se postavlja MSB bit
 *                                      na jedan.
 * @mseffect
 */
#define ES_SET_MSB(var)                                                         \
    do {                                                                        \
        var |= ES_MASK_MSB(var);                                                \
    } while (0)

/**
 * @brief       Postavlja MSB bit na nulu, "0".
 * @param       var                     Promenljiva kojoj se postavlja MSB bit
 *                                      na nulu.
 * @mseffect
 */
#define ES_CLR_MSB(var)                                                         \
    do {                                                                        \
        var &= ~ES_MASK_MSB(var);                                               \
    } while (0)

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

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

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

#if !defined(ES_HAL_FEATURE_STARTUP)
/**
 * @brief       Vrsi inicijalizaciju eSolid HAL sistema
 * @details     Poziva se samo kada se ne koristi podrazumevani HAL start-up kod.
 *              U slučaju kada se ne koristi HAL start-up kod korisnik mora da
 *              explicitno pozove ovu funkciju pre pozivanja bilo koje funkcije
 *              iz eSolid sistema.
 */
void esHalInit(
    void);
#endif

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal.h
 ******************************************************************************/
#endif /* HAL_H_ */
