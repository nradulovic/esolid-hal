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
 * @author  	Nenad Radulovic
 * @brief       Interfejs za GPIO modul.
 * @addtogroup  hal_gpio_intf
 *********************************************************************//** @{ */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

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
    ES_GPIO_MODE_OUT,
};

/**
 * @brief       Brzina rada GPIO pinova.
 * @note        Ova podesavanja ne podrzavaju svi portovi.
 */
enum esGpioSpeed {
    ES_GPIO_SPEED_LOW,
    ES_GPIO_SPEED_MEDIUM,
    ES_GPIO_SPEED_HIGH
};

/**
 * @brief       Rezim rada izlaznog drajvera pina
 */
enum esGpioOutType {
    ES_GPIO_OTYPE_PUSHPULL,
    ES_GPIO_OTYPE_OPENDRAIN
};

/**
 * @brief       Konfiguracija pull-up ili pull-down otpornika
 */
enum esGpioInType {
    ES_GPIO_ITYPE_PULLNONE,
    ES_GPIO_ITYPE_PULLUP,
    ES_GPIO_ITYPE_PULLDOWN
};

/** @} *//*-------------------------------------------------------------------*/
/*===============================================================  MACRO's  ==*/
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
 * @details     Moguce vrednosti:
 *              - ES_GPIO_MODE_IN
 *              - ES_GPIO_MODE_OUT
 */
    enum esGpioMode mode;

/**
 * @brief       Brzina rada pina/pinova
 * @details     Moguce vrednosti:
 *              - ES_GPIO_SPEED_LOW
 *              - ES_GPIO_SPEED_MEDIUM
 *              - ES_GPIO_SPEED_HIGH
 */
    enum esGpioSpeed speed;

/**
 * @brief       Rezim rada izlaznog drajvera
 * @details     Moguce vrednosti:
 *              - ES_GPIO_OTYPE_PUSHPULL
 *              - ES_GPIO_OTYPE_OPENDRAIN
 */
    enum esGpioOutType otype;

/**
 * @brief       Pull-up/pull-down otpori
 * @details     Moguce vrednosti:
 *              - ES_GPIO_ITYPE_PULLNONE
 *              - ES_GPIO_ITYPE_PULLUP
 *              - ES_GPIO_ITYPE_PULLDOWN
 */
    enum esGpioInType itype;
} esGpioDef_T;

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Opste funkcije za rad sa GPIO modulom.
 * @brief       Inicijalizacija, deinicijalizacija i status GPIO modula.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Inicijalizacija GPIO drajvera
 * @param       gpioPort                GPIO port koji se inicijalizuje
 * @param       gpioDef                 Pokazivac na definicionu strukturu. Ova
 *                                      struktura se nalazi u ROM memoriji.
 * @param       pins                    Maska pinova koji se konfigurisu.
 * @details     Vrsi inicijalizaciju GPIO porta sa definicionom strukturom
 *              @c gpioDefinition.
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
