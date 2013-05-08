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
#include "../config/hal_config.h"
#include "hal_compiler.h"
#include "port/profiles.h"

#if defined(ES_HAL_ENABLE_CPU)
# include "hal_cpu.h"
#endif

#if defined(ES_HAL_ENABLE_INTERRUPT)
# include "hal_interrupt.h"
#endif

#if defined(ES_HAL_ENABLE_UART)
# include "hal_uart.h"
#endif

#if defined(ES_HAL_ENABLE_TIMER)
# include "hal_timer.h"
#endif

#if defined(ES_HAL_ENABLE_CRC)
# include "hal_crc.h"
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
 * @name        Konstante dostupnosti HAL modula
 * @details     Ove konstante govore da za datu funkcionalnost postoje HAL
 *              moduli i da su oni aktivni. Ukoliko je makro definisan onda
 *              je modul i omogucen.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       HAL podrzava start-up kod i linker skriptu i omoguceno je
 *              njegovo koriscenje
 * @details     Koriscenje se kontrolise opcijom @ref OPT_HAL_STARTUP
 */
# define ES_HAL_ENABLE_STARTUP

/**
 * @brief       HAL podrzava CPU i omoguceno je njegovo koriscenje
 * @details     Koriscenje se kontrolise opcijom @ref OPT_HAL_CPU
 */
# define ES_HAL_ENABLE_CPU

/**
 * @brief       HAL podrzava interrupt kontroler i omoguceno je njegovo
 *              koriscenje
 * @details     Koriscenje se kontrolise opcijom @ref OPT_HAL_INTERRUPT
 */
# define ES_HAL_ENABLE_INTERRUPT

/**
 * @brief       HAL podrzava GPIO i omoguceno je njegovo koriscenje
 * @details     Koriscenje se kontrolise opcijom @ref OPT_HAL_GPIO
 */
# define ES_HAL_ENABLE_GPIO

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
 *
 */
#define ES_HWREG_SET(reg, mask, val)                                            \
    do {                                                                        \
        unative_T tmp;                                                          \
        tmp = (unative_T)(reg);                                                 \
        tmp &= ~((unative_T)mask);                                              \
        tmp |= (unative_T)(val);                                                \
        reg = tmp;                                                              \
    } while (0U)

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
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

#if !defined(ES_HAL_ENABLE_STARTUP)
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
