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
 * @author      Nenad Radulovic
 * @brief       Implementacija GPIO Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_gpio_impl
 * @brief       GPIO Low Level Driver modul.
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#define GPIO_LLD_H_VAR
#include "../src/hal/hal_private.h"

/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_DEFINE_MODULE(GPIO Low Level Driver);

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Interni, jedinstveni podaci GPIO drajvera.
 * @details     Ova struktura se instacira po jednom portu. U njoj se cuvaju
 *              koji pinovi se koriste, a koji se ne koriste.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct gpioIntr {
/**
 * @brief       Registar koriscenih pinova.
 * @details     Ukoliko je bit postavljen, onda je pin registrovan i mozda se
 *              koristi.
 */
    uint16_t        registry;

/**
 * @brief       Bitmapa aktivnih pinova.
 * @details     Svaki bit odgovara jednom pinu. Ukoliko je bit postavljen, onda
 *              se pin upravo koristi.
 */
    uint16_t        active;
} gpioIntr_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Indentifikaciona struktura GPIO drajvera
 * @details     Ova struktura sadrzi sve neophodne podatke koji su potrebni za
 *              rad sa jednim portom, na primer: lokacije registara GPIO modula,
 *              lokacije i bitovi za RCC modul i sve ostalo sto je potrebno da
 *              se konfigurise da GPIO modul radi. Glavni zadatak ove strukture
 *              je da:
 *              - ukljuci i podesi odgovarajuce taktne signale i
 *              - ukljuci kontrolere AHB/APB magistrala.
 *//*--------------------------------------------------------------------------------------------*/
struct gpioId {
/**
 * @brief       Pokazivac na GPIO registre
 */
    GPIO_TypeDef    * regs;

/**
 * @brief       Pokazivac na interne, jedinstvene podatke GPIO porta.
 */
    gpioIntr_T      * intr;

/**
 * @brief       Redni broj porta koji se koristi prilikom konfiguracije RCC modula.
 */
    uint8_t         rccPos;
};

/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Lokalne funkcije
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Prevod korisnickih argumenata u oblik povoljan za hardverske
 *              registre.
 * @param       speed                   Korisnicki argument.
 * @return      Broj koji treba upisati u registar.
 *//*--------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS uint32_t translateSpeed_(
    enum esGpioSpeed speed);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Ukljucivanje (omogucivanje rada) GPIO modula
 * @param       gpio                    Pokazivac na identifikacionu strukturu
 *                                      porta koji treba da se ukljuci.
 *//*--------------------------------------------------------------------------------------------*/
C_INLINE void gpioStart_(
    esGpioDrv_T         * gpio);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Iskljucivanje (onemogucivanje rada) GPIO modula
 * @param       gpio                    Pokazivac na identifikacionu strukturu
 *                                      porta koji treba da se iskljuci.
 *//*--------------------------------------------------------------------------------------------*/
C_INLINE void gpioStop_(
    esGpioDrv_T         * gpio);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Konfigurise vise pinova
 * @param       gpioDef                 Pokazivac na definicionu strukturu,
 * @param       gpio                    pokazivac na upravljacku strukturu,
 * @param       pins                    pinovi koji treba da se konfigurisu.
 *//*--------------------------------------------------------------------------------------------*/
static void pinConfig(
    const C_ROM esGpioDef_T * gpioDef,
    esGpioDrv_T     * gpio,
    uint16_t        pins);

/** @} *//*--------------------------------------------------------------------------------------*/

/*==========================================================================  LOCAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Interni, jedinstveni podaci GPIO drajvera za svaki port.
 * @brief       Struktura se instacira jedna za svaki port. U njima se cuvaju
 *              koji se pinovi koriste/ne koriste.
 * @{ *//*---------------------------------------------------------------------------------------*/
static volatile struct gpioIntr gpioAIntr;
static volatile struct gpioIntr gpioBIntr;
static volatile struct gpioIntr gpioCIntr;
static volatile struct gpioIntr gpioDIntr;
static volatile struct gpioIntr gpioEIntr;
static volatile struct gpioIntr gpioHIntr;
/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione strukture GPIO portova.
 * @{ *//*---------------------------------------------------------------------------------------*/
const C_ROM struct gpioId esGPIOA = {
    GPIOA,
    &gpioAintr,
    1U
};

const C_ROM struct gpioId esGPIOB = {
    GPIOB,
    &gpioBintr,
    2U
};

const C_ROM struct gpioId esGPIOC = {
    GPIOC,
    &gpioCintr,
    3U
};

const C_ROM struct gpioId esGPIOD = {
    GPIOD,
    &gpioDintr,
    4U
};

const C_ROM struct gpioId esGPIOE = {
    GPIOE,
    &gpioEintr,
    5U
};

const C_ROM struct gpioId esGPIOH = {
    GPIOH,
    &gpioHintr,
    6U
};
/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS uint32_t translateSpeed_ (
    enum esGpioSpeed    speed) {

    switch (speed) {

        case ES_GPIO_SPEED_HIGH : {

            return ((uint32_t)0x03);
            break;
        }

        default : {                                                             /* Najverovatniji slucaj da je brzina HIGH.                 */

            return ((uint32_t)speed);
        }
    }
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS void gpioStartI_(
    esGpioDrv_T     * gpio) {

    gpio->drvId->intr->active |= pins;                                          /* Oznaci da su pinovi aktivni.                             */
    RCC->AHBENR |= ((uint32_t)1U << gpio->drvId->rccPos);                       /* Omoguci takt za port periferiju.                         */
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS void gpioStopI_(
    esGpioDrv_T     * gpio) {

    gpio->drvId->intr->active &= ~pins;                                         /* Oznaci da pinovi vise nisu aktivni.                      */

    if ((uint16_t)0U == gpio->drvId->intr->active) {
        RCC->AHBENR &= ~((uint32_t)1U << gpio->drvId->rccPos);                  /* Onemoguci takt za port periferiju.                       */
    }
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE void gpioStart_(
    esGpioDrv_T     * gpio) {

    HAL_CRITICAL_DECL();

    HAL_CRITICAL_ENTER();
    gpioStartI_(
        gpio);
    HAL_CRITICAL_EXIT();
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE void gpioStop_(
    esGpioDrv_T     * gpio) {

    HAL_CRITICAL_DECL();

    HAL_CRITICAL_ENTER();
    gpioStopI_(
        gpio);
    HAL_CRITICAL_EXIT();
}

/*-----------------------------------------------------------------------------------------------*/
static void pinConfig(
    const C_ROM esGpioDef_T * gpioDef,
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    uint16_t pinPos;
    uint16_t pos;

    for (pinPos = 0x00; pinPos < 0x10; pinPos++) {
        pos = (uint32_t)1U << pinPos;

        if ((uint16_t)0U != (pins & pos)) {
            gpio->regs->MODER &= (uint32_t)0x03 << (pinPos * 2U);
            gpio->regs->MODER |= ((uint32_t)gpioDef->mode) << (pinPos * 2U);
            gpio->regs->OSPEEDR &= (uint32_t)0x03 << (pinPos * 2U);
            gpio->regs->OSPEEDR |= translateSpeed_(gpioDef->speed) << (pinPos * 2U);
            gpio->regs->OTYPER &= (uint32_t)0x01 << pinPos;
            gpio->regs->OTYPER |= ((uint32_t)gpioDef->otype) << pinPos;
            gpio->regs->PUPDR &= (uint32_t)0x03 << (pinPos * 2U);
            gpio->regs->PUPDR |= ((uint32_t)gpioDef->itype) << (pinPos * 2U);
        }
    }
}

/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void lldGpioDrvInit(
    void) {

#if defined(OPT_HAL_GPIO)
# if defined(OPT_HAL_GPIO_USE_A)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOARST;                                       /* Reset GPIO hardvera - aktivno.                           */
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOARST;                                      /* Reset GPIO hardvera - neaktivno.                         */
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOAEN;                                        /* Iskljuci GPIO takt.                                      */
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOALPEN;                                   /* Iskljuci GPIO lowpower takt                              */
# endif

# if defined(OPT_HAL_GPIO_USE_B)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOBRST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOBRST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOBEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOBLPEN;
# endif

# if defined(OPT_HAL_GPIO_USE_C)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOCRST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOCRST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOCEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOCLPEN;
# endif

# if defined(OPT_HAL_GPIO_USE_D)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIODRST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIODRST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIODEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIODLPEN;
# endif

# if defined(OPT_HAL_GPIO_USE_E)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOERST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOERST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOEEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOELPEN;
# endif

# if defined(OPT_HAL_GPIO_USE_H)
    RCC->AHBRSTR |= RCC_AHBRSTR_GPIOHRST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_GPIOHRST;
    RCC->AHBENR  &= ~RCC_AHBENR_GPIOHEN;
    RCC->AHBLPENR &= ~RCC_AHBLPENR_GPIOHLPEN;
# endif
#endif
}

void lldGpioStart(
    esGpioId_T          * gpioId,
    uint16_t            pins);

void lldGpioStop(
    esGpioId_T          * gpioId,
    uint16_t            pins);

void lldGpioQuery(
    esGpioId_T          * gpioId,
    uint8_t             pin);

/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void esGpioInit(
    const C_ROM esGpioId_T * gpioId,
    const C_ROM esGpioDef_T * gpioDef,
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK((const C_ROM esGpioDef_T *)0U != gpioDef);                    /* Provera par: mora da se preda definiciona struktura.     */
    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpioId));                                     /* Provera par: da li je drvId ispravan?                    */
    HAL_DBG_CHECK((uint16_t)0U != pins);                                        /* Provera par: mora da se izabere barem jedan pin.         */
    HAL_DBG_CHECK(
        (ES_GPIO_MODE_IN == gpioDef->mode) ||
        (ES_GPIO_MODE_OUT == gpioDef->mode));                                   /* Provera par: da li mode enumerator?                      */
    HAL_DBG_CHECK(
        (ES_GPIO_OTYPE_OPENDRAIN == gpioDef->otype) ||
        (ES_GPIO_OTYPE_PUSHPULL == gpioDef->otype));
    HAL_DBG_CHECK(
        (ES_GPIO_ITYPE_PULLDOWN == gpioDef->itype) ||
        (ES_GPIO_ITYPE_PULLNONE == gpioDef->itype) ||
        (ES_GPIO_ITYPE_PULLUP == gpioDef->itype));                              /* Provera par: da li je inType enumerator?                 */
    HAL_DBG_CHECK(
        (ES_GPIO_SPEED_HIGH == gpioDef->speed) ||
        (ES_GPIO_SPEED_MEDIUM == gpioDef->speed) ||
        (ES_GPIO_SPEED_LOW == gpioDef->speed));                                 /* Provera par: da li speed enumerator?                     */
    HAL_ASSERT((uint16_t)0U == (gpioId->intr->registry & pins));                /* Provera: pinovi koji se inicijalizuju ne smeju da budu   */
                                                                                /* registrovani od strane drugog drajvera.                  */
    gpio->drvId = (struct gpioId *)gpioId;
    gpio->regs = gpioId->regs;
    RCC->AHBENR |= ((uint32_t)1U << gpioId->rccPos);                            /* Omoguci takt za port periferiju.                         */
    pinConfig(
        gpioDef,
        gpio,
        pins);
    RCC->AHBENR &= ~((uint32_t)1U << gpioId->rccPos);                           /* Onemoguci takt za port periferiju.                       */
    gpioId->intr->registry |= pins;                                             /* Registruj da se pinovi koriste.                          */
    gpio->pins = pins;                                                          /* Prijavi u upravljacku strukturu da se pinovi koriste.    */
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioReInit(
    const C_ROM esGpioDef_T * gpioDef,
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK((const C_ROM esGpioDef_T *)0U != gpioDef);                    /* Provera par: mora da se preda definiciona struktura.     */
    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    HAL_DBG_CHECK((uint16_t)0U != pins);                                        /* Provera par: mora da se izabere barem jedan pin.         */
    HAL_ASSERT((uint16_t)0U == ((gpio->drvId->intr->registry & ~gpio->pins) & pins)); /* Provera: pinovi koji se reinicijalizuju ne smeju da*/
                                                                                /* budu korisceni od strane drugog drajvera.                */
    RCC->AHBENR |= ((uint32_t)1U << gpio->drvId->rccPos);                       /* Omoguci takt za port periferiju.                         */
    pinConfig(
        gpioDef,
        gpio,
        pins);
    RCC->AHBENR &= ~((uint32_t)1U << gpio->drvId->rccPos);                      /* Onemoguci takt za port periferiju.                       */
    gpio->drvId->intr->registry |= pins;                                        /* Registruj da se pinovi koriste.                          */
    gpio->pins |= pins;                                                         /* Prijavi u upravljacku strukturu da se pinovi koriste.    */
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioDeInit(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    HAL_DBG_CHECK((uint16_t)0U != pins);                                        /* Provera par: mora barem jedan pin da se deinicijalizuje. */
    HAL_DBG_CHECK((uint16_t)0U != (pins & ~gpio->pins));                        /* Provera par: pins mora da bude podskup gpio->pins.       */
    gpioStop_(
        gpio);                                                                  /* Pokusaj da ugasis hardver.                               */
    gpio->pins &= ~pins;                                                        /* Odjavi iz upravljacke strukture koriscene pinove.        */
    gpio->drvId->intr->registry &= ~pins;                                       /* Odjavi iz registra koriscene pinove.                     */

    if ((uint16_t)0U == gpio->pins) {                                           /* Da li se koristi jos neki pin u upravljackoj strukturi?  */
        gpio->drvId = (struct gpioId *)0U;                                      /* Ne koristi se => brisi sve.                              */
        gpio->regs = (GPIO_TypeDef *)0U;
        gpio->pins = (uint16_t)0U;
    }
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioStart(
    esGpioDrv_T     * gpio) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioStop(
    esGpioDrv_T     * gpio) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStop_(
        gpio);                                                                  /* Pokusaj da ugasis hardver.                               */
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinSetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpio->regs->BSRRL = pins & gpio->pins;
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinResetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpio->regs->BSRRH = pins & gpio->pins;
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinSet(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);
    gpio->regs->BSRRL = pins & gpio->pins;
    gpioStop_(
        gpio);                                                                  /* Pokusaj da ugasis hardver.                               */
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinReset(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);
    gpio->regs->BSRRH = pins & gpio->pins;
    gpioStop_(
        gpio);                                                                  /* Pokusaj da ugasis hardver.                               */
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioWrite(
    esGpioDrv_T     * gpio,
    uint16_t        data) {

    HAL_CRITICAL_DECL();
    uint16_t tmpData;
    uint16_t tmpPort;

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    tmpData = data & gpio->pins;
    HAL_CRITICAL_ENTER();
    gpioStartI_(
        gpio);
    tmpPort = gpio->regs->ODR & ~gpio->pins;
    gpio->regs->ODR = tmpPort | tmpData;
    gpioStopI_(
        gpio);
    HAL_CRITICAL_EXIT();
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioWriteFast(
    esGpioDrv_T     * gpio,
    uint16_t        data) {

    HAL_CRITICAL_DECL();
    uint16_t tmpData;
    uint16_t tmpPort;

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    tmpData = data & gpio->pins;
    HAL_CRITICAL_ENTER();
    tmpPort = gpio->regs->ODR & ~gpio->pins;
    gpio->regs->ODR = tmpPort | tmpData;
    HAL_CRITICAL_EXIT();
}

/*-----------------------------------------------------------------------------------------------*/
uint16_t esGpioRead(
    esGpioDrv_T     * gpio) {

    uint16_t data;

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);
    data = gpio->regs->IDR & gpio->pins;
    gpioStop_(
        gpio);

    return (data);
}

/*-----------------------------------------------------------------------------------------------*/
uint16_t esGpioReadFast(
    esGpioDrv_T     * gpio) {

    uint16_t data;

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    data = gpio->regs->IDR & gpio->pins;

    return (data);
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esGpioStatus(
    esGpioDrv_T     * gpio) {

    uint32_t rccState;

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    rccState = RCC->AHBENR & ((uint32_t)0x01 << (gpio->drvId->rccPos));

    if ((uint32_t)0U != rccState) {

        return (ES_DEV_READY);
    } else {

        return (ES_DEV_INACTIVE);
    }
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of gpio_lld.c
 *//**********************************************************************************************/
