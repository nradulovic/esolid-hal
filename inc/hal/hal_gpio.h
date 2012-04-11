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
 * @author  	Nenad Radulovic
 * @brief       Interfejs za GPIO modul.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_intf
 ****************************************************************************************//** @{ */
/**
 * @defgroup    hal_gpio GPIO modul
 * @brief       Rad sa GPIO modulom
 ****************************************************************************************//** @{ */


#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/*============================================================================  INCLUDE FILES  ==*/
# include PORT_VARIANT_HEADER(gpio_lld)

/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef GPIO_H_VAR
# define GPIO_H_EXT
#else
# define GPIO_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Moguce opcije za GPIO port pinove
 * @brief       Ove opcije se koriste za popunjavanje definicione strukture
 *              @ref gpioDef.
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Rezim rada GPIO port pina
 *//*--------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Brzina rada GPIO pinova.
 * @note        Ova podesavanja ne podrzavaju svi portovi.
 *//*--------------------------------------------------------------------------------------------*/
enum esGpioSpeed {
    ES_GPIO_SPEED_LOW,
    ES_GPIO_SPEED_MEDIUM,
    ES_GPIO_SPEED_HIGH
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Rezim rada izlaznog drajver pina
 *//*--------------------------------------------------------------------------------------------*/
enum esGpioOutType {
    ES_GPIO_OTYPE_PUSHPULL,
    ES_GPIO_OTYPE_OPENDRAIN
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Konfiguracija pull-up ili pull-down otpornika
 *//*--------------------------------------------------------------------------------------------*/
enum esGpioInType {
    ES_GPIO_ITYPE_PULLNONE,
    ES_GPIO_ITYPE_PULLUP,
    ES_GPIO_ITYPE_PULLDOWN
};

/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Macro group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Definiciona struktura za GPIO port pinove.
 * @details     U ovoj strukturi se opisuje:
 *              - rezim rada pina,
 *              - brzina rada pina,
 *              - izlazni drajver pina,
 *              - ulazni pull-up/pull-down otpori.
 * @{ *//*---------------------------------------------------------------------------------------*/

struct gpioDef {
    enum esGpioMode mode;
    enum esGpioSpeed speed;
    enum esGpioOutType otype;
    enum esGpioInType itype;
};

typedef struct gpioDrvId esGpioDrvId_T;
typedef struct gpioDrv esGpioDrv_T;
typedef struct gpioDef esGpioDef_T;

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione strukture GPIO portova
 * @brief       Koriste se prilikom inicijalizacije GPIO porta
 * @details     Prilikom inicijalizacije dovoljno je navesti ime zeljenog GPIO
 *              porta.
 * @see         esGpioInit()
 * @{ *//*---------------------------------------------------------------------------------------*/

#if defined(OPT_HAL_GPIO)
# if defined(OPT_HAL_GPIO_USE_A)
extern const C_ROM struct gpioDrvId esGPIOA;
# endif

# if defined(OPT_HAL_GPIO_USE_B)
extern const C_ROM struct gpioDrvId esGPIOB;
# endif

# if defined(OPT_HAL_GPIO_USE_C)
extern const C_ROM struct gpioDrvId esGPIOC;
# endif

# if defined(OPT_HAL_GPIO_USE_D)
extern const C_ROM struct gpioDrvId esGPIOD;
# endif

# if defined(OPT_HAL_GPIO_USE_E)
extern const C_ROM struct gpioDrvId esGPIOE;
# endif

# if defined(OPT_HAL_GPIO_USE_F)
extern const C_ROM struct gpioDrvId esGPIOF;
# endif

# if defined(OPT_HAL_GPIO_USE_G)
extern const C_ROM struct gpioDrvId esGPIOG;
# endif

# if defined(OPT_HAL_GPIO_USE_H)
extern const C_ROM struct gpioDrvId esGPIOH;
# endif
#endif /* OPT_HAL_GPIO */

/** @} *//*--------------------------------------------------------------------------------------*/

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Opste funkcije za rad sa GPIO modulom.
 * @brief       Inicijalizacija, deinicijalizacija i status GPIO modula.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizacija GPIO drajvera
 * @param       definition              Pokazivac na strukturu definicije. Ova
 *                                      struktura se nalazi u ROM memoriji.
 * @param       gpio                    Pokazivac na drajver strukturu. Ona je
 *                                      zavisna od koriscenog porta. Nalazi se u
 *                                      RAM memoriji i intezivno se koristi
 *                                      prilikom brzih (@c fast funkcije)
 *                                      pristupa.
 * @param       gpioId                  Identifikaciona struktura. Ovu strukturu
 *                                      definise sam port i korisnik samo navodi
 *                                      imena strukture. Tako struktura esGPIOA
 *                                      opisuje PORT A, esGPIOB opisuje PORT B
 *                                      i tako dalje. Ove strukture se nalaze u
 *                                      ROM memoriji.
 * @param       pins                    Pinovi koji se konfigurisu. Ovo je bit
 *                                      maska pinova koji se konfigurisu kako je
 *                                      opisano u definition strukturi.
 * @details     Vrsi inicijalizaciju drajver strukture @c gpio sa definicionom
 *              strukturom @c definition. Zeljeni GPIO port se specificira
 *              @c gpioId parametrom, a pinovi @c pins parametrom.
 *
 *              Nakon inicijalizacije, hardveru se obraca iskljucivo preko
 *              pokazivaca na portabilnu struktur @ref esGpioDrv_T.
 * @note        Ova funkcija se mora pozvati pre koriscenja bilo koje funkcije
 *              u ovom modulu.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioInit(
    const C_ROM esGpioDef_T * definition,
    esGpioDrv_T     * gpio,
    const C_ROM esGpioDrvId_T * gpioId,
    uint16_t        pins);

esDevStatus_T esGpioStatus(
    esGpioDrv_T     * gpio);

void esGpioDeInit(
    esGpioDrv_T     * gpio);

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije za normalan pristup GPIO hardveru
 * @brief       Funkcije omogucavaju koriscenje rezima male potrosnje i solidnu
 *              brzinu rada.
 * @details     Funkcije automatski azuriraju stanje koriscenih resursa (pinovi
 *              i portovi) i u zavisnosti od stanja hardvera automatski se
 *              postavljaju u rezim minimalne potrosnje.
 *              Naravno, azuriranje stanja unosi dodatni overhead u radu sa
 *              GPIO modulom. U tu svrhu napravljene su funkcije i makroi za
 *              brzi pristup koje postavljaju odredjene zahteve u pogledu
 *              njihovog koriscenja. Pogledati dokumentaciju za pojedinacne
 *              funkcije.
 * @{ *//*---------------------------------------------------------------------------------------*/
void esGpioPinSet(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

void esGpioPinReset(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

void esGpioWrite(
    esGpioDrv_T     * gpio,
    uint16_t        data);

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije za brz pristup GPIO hardveru
 * @brief       Funkcije onemogucavaju koriscenje rezima male potrosnje, ali
 *              pruzaju vecu brzinu.
 * @details     Pre koriscenja brzih funkcija ili makroi potrebno je najpre
 *              pozvati esGpioStart() funkciju kojom se GPIO modul prebacuje iz
 *              rezima male potrosnje u radni rezim. Nakon poziva navedene
 *              funkcije GPIO se moze slobodno kontrolisati. Ukoliko postoji
 *              nekoliko korisnika istog GPIO porta i pokusa da ga postavi u
 *              rezim male potrosnje njemu ce biti odbijena akcija. Sve dok svi
 *              korisnici GPIO porta ne prestanu sa radom nad GPIO portom
 *              hardver se nece postaviti u rezim male potrosnje.
 *
 *              Kada se zavrsi sa radom nad GPIO portom, poziva se funkcija
 *              esGpioStop() koja obavestava drajver da je korisnik zavrsio sa
 *              koriscenjem GPIO porta. Ukoliko ne postoji vise ni jedan
 *              korisnik datog porta onda se hardver postavlja u rezim male
 *              potrosnje.
 * @{ *//*---------------------------------------------------------------------------------------*/

void esGpioStart(
    esGpioDrv_T     * gpio);

void esGpioStop(
    esGpioDrv_T     * gpio);

void esGpioPinSetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

void esGpioPinResetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

void esGpioWriteFast(
    esGpioDrv_T     * gpio,
    uint16_t        data);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_gpio.h
 *************************************************************************************************/
#endif /* HAL_GPIO_H_ */
