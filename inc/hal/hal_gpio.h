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
 * @addtogroup  hal_gpio
 * @brief       Kontrola GPIO pinova.
 * @details     GPIO drajver omogucava laku kontrolu i rad sa GPIO pinovima. U
 *              slucaju da korisceni port poseduje mogucnost za prebacivanje
 *              hardvera u rezim male potrosnje, GPIO drajver ce iskoristiti
 *              navedenu osobinu i postavice hardver u rezim male potrosnje
 *              kada se ne koristi.
 * @section     gpio_usage Koriscenje GPIO drajvera
 *              Koriscenje se grubo svodi na tri koraka:
 *              - inicijalizacija (@ref gpio_usage_init)
 *              - pozivi funkcija GPIO modula (@ref gpio_usage_functions)
 *              - deinicijalizacija
 *
 * @subsection  gpio_usage_init Inicijalizacija
 *              Potrebno je najpre instancirati strukturu esGpioDrv_T.
 *              Instaciranje se moze izvrsiti neposredno:
@code
esGpioDrv_T gpioDrajver;
@endcode
 *              ili, upotrebom malloc funkcije:
@code
esGpioDrv_T * pGpioDrajver;

pGpioDrajver = esHmemAlloc(sizeof(esGpioDrv_T));
@endcode
 *              Zatim se formira definiciona struktura. Definiciona struktura
 *              se cuva iskljucivo u ROM/FLASH memoriji. Definiciona struktura
 *              se moze kreirati neposredno:
@code
const C_ROM esGpioDef_T gpioDefinicija = {
    ES_GPIO_MODE_IN,
    ES_GPIO_SPEED_LOW,
    ES_GPIO_OTYPE_PUSHPULL,
    ES_GPIO_ITYPE_PULLNONE
};
@endcode
 *              ili upotrebom makroa:
@code
ES_GPIO_DEFINITION(
    gpioDefinicija,
    ES_GPIO_MODE_IN,
    ES_GPIO_SPEED_LOW,
    ES_GPIO_OTYPE_PUSHPULL,
    ES_GPIO_ITYPE_PULLNONE);
@endcode
 *              Nakon definisanja ove dve strukture init funkcija za port A i
 *              pin 0 se poziva na sledeci nacin:
@code
esGpioInit(
    &gpioDefinicija,
    &gpioDrajver,
    &esGPIOA,
    1U);
@endcode
 *              Pozivom init funkcije se izvrsava inicijalizacija GPIO drajvera
 *              i navedenog hardverskog modula.
 * @subsection  gpio_usage_functions Funkcije GPIO drajvera
 *              GPIO drajver vrsi automatsko aktiviranje/deaktiviranje GPIO
 *              hardverskog modula ukoliko to korisceni HAL port podrzava.
 *              Funkcije automatski azuriraju stanje koriscenih resursa (pinovi
 *              i portovi) i u zavisnosti od stanja hardvera automatski se
 *              postavljaju u rezim minimalne potrosnje kada se GPIO modul ne
 *              koristi.
 *              Naravno, azuriranje stanja GPIO modula unosi dodatni overhead u
 *              radu sa GPIO modulom. U cilju otklanjanja dodatnog overhead-a
 *              napravljene su funkcije i makroi za brz pristup koji postavljaju
 *              odredjene zahteve u pogledu njihovog koriscenja. Pogledati
 *              dokumentaciju za pojedinacne funkcije.
 ****************************************************************************************//** @{ */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/*============================================================================  INCLUDE FILES  ==*/
#include PORT_VARIANT_HEADER(gpio_lld)

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

#define ES_GPIO_DEFINITION(name, mode, speed, outType, inType)                  \
    const C_ROM esGpioDef_T name = {mode, speed, outType, inType}

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Tipovi podataka GPIO drajvera
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura za GPIO port pinove.
 * @details     U ovoj strukturi se opisuje:
 *              - rezim rada pina,
 *              - brzina rada pina,
 *              - izlazni drajver pina,
 *              - ulazni pull-up/pull-down otpori.
 *//*--------------------------------------------------------------------------------------------*/
struct gpioDef {
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
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Struktura za identifikaciju hardvera GPIO modula
 * @details     Preko ove strukture GPIO drajver se spaja sa zeljenim GPIO
 *              modulom. Ove strukture su definisane interno i njima se ne
 *              pristupa direktno od strane korisnika vec se samo koriste kao
 *              argument funkcije za inicijalizaciju.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct gpioDrvId esGpioDrvId_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Drajver struktura GPIO modula
 * @details     Struktura se koristi za cuvanje informacija koji GPIO modul se
 *              koristi, status GPIO modula i za brzi pristup registrima. Da bi
 *              se GPIO drajver koristio mora da se najpre ova struktura
 *              instancira.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct gpioDrv esGpioDrv_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura GPIO drajvera
 * @details     Struktura se koristi da se na lak nacin funkciji za
 *              inicijalizaciju preda opis GPIO pinova. Jedna definiciona
 *              struktura se moze koristi za inicijalizaciju vise pinova.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct gpioDef esGpioDef_T;

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione strukture GPIO modula
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
 * @param       gpioId                  Identifikaciona struktura. Ova
 *                                      struktura je definisana od strane HAL-a
 *                                      i korisnik samo navodi ime strukture.
 *                                      Tako struktura esGPIOA opisuje PORT A,
 *                                      esGPIOB opisuje PORT B i tako dalje.
 *                                      Ove strukture se nalaze u ROM memoriji.
 * @param       pins                    Maska pinova koji se konfigurisu.
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

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Deinicijalizacija GPIO modula
 * @param       gpio                    Pokazivac na drajver strukturu.
 * @details     Funkcija se poziva kada je potrebno da se prekine sa radom sa
 *              GPIO drajverom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioDeInit(
    esGpioDrv_T     * gpio);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Status GPIO drajvera.
 * @param       gpio                    Pokazivac na drajver strukturu.
 * @return      U zavisnosti od stanja drajvera funkcija vraca:
 *              - ES_DEV_INACTIVE - hardver je neaktivan i u stanju
 *              male potrosnje. Da bi se hardver koristio treba da se prebaci u
 *              aktivno stanje.
 *              - ES_DEV_READY - Hardver je vec u aktivnom stanju i spreman je
 *              za koriscenje.
 *              GPIO drajver ne podrzava ostala stanja drajvera navedena u
 *              @ref esDevStatus.
 *//*--------------------------------------------------------------------------------------------*/
esDevStatus_T esGpioStatus(
    esGpioDrv_T     * gpio);

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije za normalan pristup GPIO hardveru
 * @brief       Funkcije omogucavaju koriscenje rezima male potrosnje i
 *              solidnu brzinu rada.
 * @details     Funkcije automatski azuriraju stanje koriscenih resursa (pinovi
 *              i portovi) i u zavisnosti od stanja hardvera automatski se
 *              postavljaju u rezim minimalne potrosnje.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Postavlja pinove na logicku jedinicu.
 * @param       gpio                    Pokazivac na drajver strukturu,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku jedinicu.
 *              Funkcija automatski vrsi aktiviranje/deaktiviranje GPIO modula.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioPinSet(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Postavlja pinove na logicku nulu.
 * @param       gpio                    Pokazivac na drajver strukturu,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku nulu.
 *              Funkcija automatski vrsi aktiviranje/deaktiviranje GPIO modula.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioPinReset(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upisuje podatak na pinove porta.
 * @param       gpio                    Pokazivac na drajver strukturu,
 * @param       data                    podatak koji treba upisati.
 *              Funkcija automatski vrsi aktiviranje/deaktiviranje GPIO modula.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Pocetak rada sa GPIO portom.
 * @param       gpio                    Pokazivac na drajver strukturu.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioStart(
    esGpioDrv_T     * gpio);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Zaustavljanje rada sa GPIO portom.
 * @param       gpio                    Pokazivac na drajver strukturu.
 * @pre         Drajver treba da bude inicijalizovan esGpioInit() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioStop(
    esGpioDrv_T     * gpio);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Postavlja pinove na logicku jedinicu.
 * @param       gpio                    Pokazivac na drajver strukturu,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku jedinicu.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioPinSetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Postavlja pinove na logicku nulu.
 * @param       gpio                    Pokazivac na drajver strukturu,
 * @param       pins                    maska pinova koji treba da se postave na
 *                                      logicku nulu.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
void esGpioPinResetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upisuje podatak na pinove porta.
 * @param       gpio                    Pokazivac na drajver strukturu,
 * @param       data                    podatak koji treba upisati.
 * @pre         Drajver treba da bude aktiviran esGpioStart() funkcijom.
 *//*--------------------------------------------------------------------------------------------*/
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
