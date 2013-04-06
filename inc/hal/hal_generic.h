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
 * @brief       Zajednicka svojstva HAL modula
 * @addtogroup  hal_intf
 *********************************************************************//** @{ */

#ifndef HAL_GENERIC_H_
#define HAL_GENERIC_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
#if defined(__DOXYGEN__)
/*------------------------------------------------------------------------*//**
 * @name        Konstante mogucnosti HAL modula
 * @details     Ovi makroi govore da za datu funkcionalnost postoje HAL moduli.
 *              Ukoliko je makro definisan onda HAL podrzava datu funkcionalnost.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       HAL podrzava CPU
 */
# define ES_HAL_FEATURE_CPU

/**
 * @brief       HAL podrzava interrupt kontroler
 */
# define ES_HAL_FEATURE_INTERRUPT

/**
 * @brief       HAL podrzava GPIO
 */
# define ES_HAL_FEATURE_GPIO

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Konstante dostupnosti HAL modula
 * @details     Ove konstante govore da za datu funkcionalnost postoje HAL
 *              moduli i da su oni aktivni. Ukoliko je makro definisan onda
 *              je modul i omogucen.
 * @{ *//*--------------------------------------------------------------------*/

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

/*===============================================================  MACRO's  ==*/

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

/**
 * @brief       Moguci nivoi perfomansi procesora
 */
typedef enum esSysSpeed {
/**
 * @brief       Najniza brzina rada mikrokontrolera
 */
    ES_SYS_SPEED_LOW,

/**
 * @brief       Srednja brzina rada mikrokontrolera
 */
    ES_SYS_SPEED_MEDIUM,

/**
 * @brief       Najveca brzina rada mikrokontrolera
 */
    ES_SYS_SPEED_HIGH
} esSysSpeed_T;

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

#if (OPT_HAL_STARTUP != 1U)
/**
 * @brief       Vrsi inicijalizaciju eSolid sistema
 * @details     Poziva se samo kada se ne koristi podrazumevani HAL start-up kod.
 *              U tom slučaju, korisnik mora da explicitno pozove ovu funkciju
 *              pre pozivanja bilo koje funkcije iz eSolid sistema.
 */
void esSysInit(
    void);
#endif

/**
 * @brief       Postavlja zeljeni nivo perfomansi mikrokontrolera
 * @param       speed                   Nivo brzine rada procesora
 *  @arg        @ref ES_SYS_SPEED_LOW
 *  @arg        @ref ES_SYS_SPEED_MEDIUM
 *  @arg        @ref ES_SYS_SPEED_HIGH
 */
void esSysSpeedSet(
    esSysSpeed_T    speed);

/**
 * @brief       Vraca u kojem nivou perfomansi se nalazi mikrokontroler
 * @return      Nivo brzine u kojem se nalazi procesor, magistrale i brzina
 *              periferije
 *  @retval     ES_SYS_PERF_DEFAULT
 *  @retval     ES_SYS_SPEED_MEDIUM
 *  @retval     ES_SYS_SPEED_HIGH
 */
esSysSpeed_T esSysSpeedGet(
    void);

/**
 * @brief       Vraca vrednost taktne frekvencije jezgra
 * @return      Vrednost taktne frekvencije u Hz.
 */
uint32_t esSysCoreClockGet(
    void);

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_generic.h
 ******************************************************************************/
#endif /* HAL_GENERIC_H_ */
