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
 * @brief       Interfejs za GPIO modul.
 * @addtogroup  hal_gpio_intf
 *********************************************************************//** @{ */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/*=========================================================  INCLUDE FILES  ==*/
#include "hal.h"
#include "common/gpio_profile.h"

#if !defined(ES_HAL_GPIO_ENABLED)
# error "HAL: hal_gpio.h does not support your current port"
#endif

/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Moguce opcije za GPIO port pinove
 * @brief       Ove opcije se koriste za popunjavanje definicione strukture
 *              @ref gpioDef.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Rezim rada GPIO port pina
 */
enum esGpioMode {
/**
 * @brief       Pin je ulaz
 */
    ES_GPIO_MODE_IN,

/**
 * @brief       Pin je izlaz
 */
    ES_GPIO_MODE_OUT
};

/**
 * @brief       Brzina rada GPIO pinova.
 * @note        Ova podesavanja ne podrzavaju svi portovi.
 */
enum esGpioSpeed {
/**
 * @brief       Minimalna brzina rada GPIO porta
 * @details     Tacna vrednost zavisi od trenutnog PORT-a.
 */
    ES_GPIO_SPEED_LOW,

/**
 * @brief       Srednja brzina rada.
 * @details     Jednaka je maksimalnoj i minimalnoj brzini rada GPIO porta.
 *              Tacna vrednost zavisi od trenutnog PORT-a.
 */
    ES_GPIO_SPEED_MEDIUM,

/**
 * @brief       Maksimalna brzina rada
 * @details     Tacna vrednost zavisi od trenutnog PORT-a.
 */
    ES_GPIO_SPEED_HIGH
};

/**
 * @brief       Rezim rada izlaznog drajvera pina
 */
enum esGpioOutType {
/**
 * @brief       Izlazni pin radi u push-pull rezimu
 */
    ES_GPIO_OTYPE_PUSHPULL,

/**
 * @brief       Ukljucen je samo jedna polovina izlaznog drajvera.
 * @details     Ukoliko hardver podrzava odabir gornje ili donje polovine onda
 *              se selekcija moze vrsiti preko @ref esGpioInType.
 */
    ES_GPIO_OTYPE_OPENDRAIN
};

/**
 * @brief       Konfiguracija pull-up ili pull-down otpornika
 */
enum esGpioInType {
/**
 * @brief       Ne koriste se pull-up/pull-down otpori
 */
    ES_GPIO_ITYPE_PULLNONE,

/**
 * @brief       Koristi se pull-up
 */
    ES_GPIO_ITYPE_PULLUP,

/**
 * @brief       Koristi se pull-down
 */
    ES_GPIO_ITYPE_PULLDOWN
};

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

/**
 * @brief       Definiciona struktura za GPIO port pinove.
 * @details     U ovoj strukturi se opisuje:
 *              - rezim rada pina,
 *              - brzina rada pina,
 *              - izlazni drajver pina,
 *              - ulazni pull-up/pull-down otpori.
 */
typedef struct esGpioDef {
/**
 * @brief       Rezim rada pina/pinova
 * @details     Specificira rezim rada pinova.
 * @par         Moguce vrednosti:
 *              - @ref ES_GPIO_MODE_IN
 *              - @ref ES_GPIO_MODE_OUT
 */
    enum esGpioMode mode;

/**
 * @brief       Brzina rada pina/pinova
 * @details     Specificira brzinu rada GPIO porta.
 * @par         Moguce vrednosti:
 *              - @ref ES_GPIO_SPEED_LOW
 *              - @ref ES_GPIO_SPEED_MEDIUM
 *              - @ref ES_GPIO_SPEED_HIGH
 */
    enum esGpioSpeed speed;

/**
 * @brief       Rezim rada izlaznog drajvera
 * @details     Specificira izlazni rezim rada pinova.
 * @par         Moguce vrednosti:
 *              - @ref ES_GPIO_OTYPE_PUSHPULL
 *              - @ref ES_GPIO_OTYPE_OPENDRAIN
 */
    enum esGpioOutType otype;

/**
 * @brief       Pull-up/pull-down otpori
 * @details     Specificira da li se koriste pull-up/push-down otpori.
 * @par         Moguce vrednosti:
 *              - @ref ES_GPIO_ITYPE_PULLNONE
 *              - @ref ES_GPIO_ITYPE_PULLUP
 *              - @ref ES_GPIO_ITYPE_PULLDOWN
 */
    enum esGpioInType itype;
} esGpioDef_T;

#if defined(__DOXYGEN__)
/**
 * @brief       Ime Gpio porta koji se koristi
 * @details     Dostupna imena portova zavise od koriscenog mikrokontrolera
 */
typedef enum esGpio {
/**
 * @brief       Identifikatora porta A
 */
    ES_GPIOA,

/**
 * @brief       Identifikatora porta B
 */
    ES_GPIOB,

/**
 * @brief       Identifikatora porta C
 */
    ES_GPIOC,

/**
 * @brief       Identifikatora porta D
 */
    ES_GPIOD,

/**
 * @brief       Identifikatora porta E
 */
    ES_GPIOE,

/**
 * @brief       Identifikatora porta F
 */
    ES_GPIOF,

/**
 * @brief       Identifikatora porta G
 */
    ES_GPIOG,

/**
 * @brief       Identifikatora porta H
 */
    ES_GPIOH,
} esGpio_T;
#endif

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Opste funkcije za rad sa GPIO modulom.
 * @brief       Inicijalizacija, deinicijalizacija i status GPIO modula.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Inicijalizacija GPIO drajvera
 * @param       gpioPort                GPIO port koji se inicijalizuje
 *  @arg        ES_GPIOA
 *  @arg        ES_GPIOB
 *  @arg        ES_GPIOC
 *  @arg        ES_GPIOD
 *  @arg        ES_GPIOE
 *  @arg        ES_GPIOF
 *  @arg        ES_GPIOG
 *  @arg        ES_GPIOH
 * @param       gpioDef                 Pokazivac na definicionu strukturu.
 * @param       pins                    Maska pinova koji se konfigurisu.
 * @details     Vrsi inicijalizaciju GPIO porta sa definicionom strukturom
 *              @c gpioDef.
 */
void esGpioInit(
    esGpioPort_T    gpioPort,
    const C_ROM esGpioDef_T * gpioDef,
    uint16_t        pins);

/**
 * @brief       Deinicijalizacija GPIO modula
 * @param       gpioPort                GPIO port koji se deinicijalizuje
 * @details     Funkcija se poziva kada je potrebno da se prekine sa radom sa
 *              GPIO drajverom.
 */
void esGpioDeInit(
    esGpioPort_T    gpioPort);

/**
 * @brief       Status GPIO drajvera.
 * @param       gpioPort                    GPIO port ciji se status trazi
 * @return      U zavisnosti od stanja drajvera funkcija vraca:
 *  @retval     ES_DEV_INACTIVE - hardver je neaktivan i u stanju male
 *              potrosnje. Da bi se hardver koristio treba da se prebaci u
 *              aktivno stanje.
 *  @retval     ES_DEV_READY - Hardver je vec u aktivnom stanju i spreman je
 *              za koriscenje.
 */
esDevStatus_T esGpioStatus(
    esGpioPort_T    gpioPort);

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Funkcije za standardni pristup GPIO hardveru
 * @brief       Funkcije omogucavaju koriscenje rezima male potrosnje i
 *              solidnu brzinu rada.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Postavlja pinove na logicku jedinicu.
 * @param       gpioPort                GPIO port,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku jedinicu.
 *              Funkcija automatski vrsi aktiviranje/deaktiviranje GPIO modula.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 */
void esGpioPinSet(
    esGpioPort_T    gpioPort,
    uint16_t        pins);

/**
 * @brief       Postavlja pinove na logicku nulu.
 * @param       gpioPort                GPIO port,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku nulu.
 *              Funkcija automatski vrsi aktiviranje/deaktiviranje GPIO modula.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 */
void esGpioPinReset(
    esGpioPort_T    gpioPort,
    uint16_t        pins);

/**
 * @brief       Upisuje podatak na pinove porta.
 * @param       gpioPort                GPIO port,
 * @param       data                    podatak koji treba upisati.
 *              Funkcija automatski vrsi aktiviranje/deaktiviranje GPIO modula.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 */
void esGpioWrite(
    esGpioPort_T    gpioPort,
    uint16_t        data);

/**
 * @brief       Dobavlja podatak sa specificiranog porta.
 * @param       gpioPort                GPIO port,
 * @return      Stanje na pinovima specificiranog porta.
 */
uint16_t esGpioRead(
    esGpioPort_T    gpioPort);

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Funkcije za brz pristup GPIO hardveru
 * @brief       Funkcije onemogucavaju koriscenje rezima male potrosnje, ali
 *              pruzaju vecu brzinu.
 * @details     Pre koriscenja brzih funkcija ili potrebno je najpre pozvati
 *              esGpioStart() funkciju kojom se GPIO modul prebacuje iz rezima
 *              male potrosnje u radni rezim. To odgovara prelasku stanja
 *              drajvera iz stanja @ref ES_DEV_INACTIVE u stanje
 *              @ref ES_DEV_READY. Nakon poziva navedene funkcije GPIO se moze
 *              slobodno upravljati.
 *
 *              Kada se zavrsi sa radom nad GPIO portom, poziva se funkcija
 *              esGpioStop() koja obavestava drajver da je korisnik zavrsio sa
 *              koriscenjem GPIO porta i port se postavlja u rezim male
 *              potrosnje.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Pocetak rada sa GPIO portom.
 * @param       gpioPort                GPIO port koji se aktivira
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 */
void esGpioStart(
    esGpioPort_T    gpioPort);

/**
 * @brief       Zaustavljanje rada sa GPIO portom.
 * @param       gpioPort                GPIO port,
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 */
void esGpioStop(
    esGpioPort_T    gpioPort);

/**
 * @brief       Postavlja pinove na logicku jedinicu.
 * @param       gpioPort                GPIO port,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku jedinicu.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 * @note        Funkcija nece promeniti vrednosti onih pinova koji nisu
 *              obuhvaceni upravljackom strukturom.
 */
void esGpioPinSetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins);

/**
 * @brief       Postavlja pinove na logicku nulu.
 * @param       gpioPort                GPIO port,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku nulu.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 */
void esGpioPinResetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins);

/**
 * @brief       Upisuje podatak na pinove porta.
 * @param       gpioPort                GPIO port,
 * @param       data                    podatak koji treba upisati.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 */
void esGpioWriteFast(
    esGpioPort_T    gpioPort,
    uint16_t        data);

/**
 * @brief       Dobavlja podatak sa specificiranog porta.
 * @param       gpioPort                GPIO port,
 * @return      Stanje na pinovima specificiranog porta.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 */
uint16_t esGpioReadFast(
    esGpioPort_T    gpioPort);

/** @} *//*-------------------------------------------------------------------*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_gpio.h
 ******************************************************************************/
#endif /* HAL_GPIO_H_ */
