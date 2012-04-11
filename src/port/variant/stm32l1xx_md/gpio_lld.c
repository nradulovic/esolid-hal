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
 * @addtogroup  stm32l1xx_md_impl
 ****************************************************************************************//** @{ */
/**
 * @defgroup    stm32l1xx_md_gpio_impl
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
/*-------------------------------------------------------------------------------------------*//**
 * @name        Makroi za proveru paramatera
 * @brief       Koriste se iskljucivo za proveru predatih parametara.
 * @details     Ukoliko je pretprocesorom iskljucen neki port onda se nece ni
 *              vrsiti provera parametara sa tim vrednostima.
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_A) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOA_DRV(val)                                                \
    (&esGPIOA == (val))
#else
#define DBG_VALID_GPIOA_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_B) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOB_DRV(val)                                                \
    (&esGPIOB == (val))
#else
#define DBG_VALID_GPIOB_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_C) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOC_DRV(val)                                                \
    (&esGPIOC == (val))
#else
#define DBG_VALID_GPIOC_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_D) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOD_DRV(val)                                                \
    (&esGPIOD == (val))
#else
#define DBG_VALID_GPIOD_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_E) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOE_DRV(val)                                                \
    (&esGPIOE == (val))
#else
#define DBG_VALID_GPIOE_DRV(val)                                                \
    (0U)
#endif

#if defined(OPT_HAL_GPIO) && defined(OPT_HAL_GPIO_USE_H) || defined(__DOXYGEN__)
#define DBG_VALID_GPIOH_DRV(val)                                                \
    (&esGPIOH == (val))
#else
#define DBG_VALID_GPIOH_DRV(val)                                                \
    (0U)
#endif

#define GPIO_DRVID_LIST(gpio)                                                     \
    (DBG_VALID_GPIOA_DRV(gpio) ||                                               \
     DBG_VALID_GPIOB_DRV(gpio) ||                                               \
     DBG_VALID_GPIOC_DRV(gpio) ||                                               \
     DBG_VALID_GPIOD_DRV(gpio) ||                                               \
     DBG_VALID_GPIOE_DRV(gpio) ||                                               \
     DBG_VALID_GPIOH_DRV(gpio))

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  LOCAL DATA TYPES  ==*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Interni, jedinstveni podaci GPIO drajvera.
 * @details     Ova struktura se instacira po jednom portu. U njoj se cuvaju
 *              koji pinovi se koriste, a koji se ne koriste.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct gpioIntr {
/**
 * @brief       Svaki bit ove promenljive je dodeljen jednom pinu.
 * @details     Ukoliko je bit postavljen, onda se pin koristi.
 */
    uint16_t        usedPins;
} gpioIntr_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Indentifikaciona struktura GPIO drajvera
 * @details     Ova struktura sadrzi sve neophodne podatke koji su potrebni za
 *              rad sa jednim portom, na primer: lokacije registara GPIO modula,
 *              lokacije i bitovi za RCC modul i sve ostalo sto je potrebno da
 *              se konfigurise da GPIO modul radi. Glavni zadatak ove strukture
 *              je da se spreci potreba da sam korisnik pali i podesava taktne
 *              signale i ostale peripetije sa AHB/APB magistralama.
 *//*--------------------------------------------------------------------------------------------*/
struct gpioDrvId {
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

C_INLINE_ALWAYS uint32_t translateSpeed_(
    enum esGpioSpeed speed);

C_INLINE_ALWAYS void pinRegInsertI_(
    esGpioDrvId_T       * gpioId,
    uint16_t            pins);

C_INLINE_ALWAYS bool_T pinRegIsEmptyI_(
    esGpioDrvId_T       * gpioId);

C_INLINE_ALWAYS void pinRegRemoveI_(
    esGpioDrvId_T       * gpioId,
    uint16_t            pins);

C_INLINE void gpioStart_(
    esGpioDrv_T     * gpio);

C_INLINE void gpioStop_(
    esGpioDrv_T     * gpio);

/*==========================================================================  LOCAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Interni, jedinstveni podaci GPIO drajvera po portu.
 * @details     Struktura se instacira jedna za svaki port. U njima se cuvaju
 *              koji se pinovi koriste/ne koriste.
 *//*--------------------------------------------------------------------------------------------*/
static struct gpioIntr gpioAIntr;
static struct gpioIntr gpioBIntr;
static struct gpioIntr gpioCIntr;
static struct gpioIntr gpioDIntr;
static struct gpioIntr gpioEIntr;
static struct gpioIntr gpioHIntr;
/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikacione strukture GPIO portova.
 *//*--------------------------------------------------------------------------------------------*/
const C_ROM struct gpioDrvId esGPIOA = {
    GPIOA,
    &gpioAintr,
    1U
};

const C_ROM struct gpioDrvId esGPIOB = {
    GPIOB,
    &gpioBintr,
    2U
};

const C_ROM struct gpioDrvId esGPIOC = {
    GPIOC,
    &gpioCintr,
    3U
};

const C_ROM struct gpioDrvId esGPIOD = {
    GPIOD,
    &gpioDintr,
    4U
};

const C_ROM struct gpioDrvId esGPIOE = {
    GPIOE,
    &gpioEintr,
    5U
};

const C_ROM struct gpioDrvId esGPIOH = {
    GPIOH,
    &gpioHintr,
    6U
};
/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS uint32_t translateSpeed_ (
    enum esGpioSpeed speed) {

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
C_INLINE_ALWAYS void pinRegInsertI_(
    esGpioDrvId_T       * gpioId,
    uint16_t            pins) {

    gpioId->intr->usedPins |= pins;
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS bool_T pinRegIsEmptyI_(
    esGpioDrvId_T       * gpioId) {

    if ((uint16_t)0U != gpioId->intr->usedPins) {

        return (FALSE);
    } else {

        return (TRUE);
    }
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE_ALWAYS void pinRegRemoveI_(
    esGpioDrvId_T       * gpioId,
    uint16_t            pins) {

    gpioId->intr->usedPins &= ~pins;
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE void gpioStart_(
    esGpioDrv_T     * gpio) {

    HAL_CRITICAL_DECL();

    HAL_CRITICAL_ENTER();
    pinRegInsertI_(
        gpio->drvId,
        gpio->pins);                                                            /* Registruj da se pinovi koriste.                          */
    HAL_CRITICAL_EXIT();
    RCC->AHBENR |= ((uint32_t)1U << gpio->drvId->rccPos);                       /* Omoguci takt za port periferiju.                         */
}

/*-----------------------------------------------------------------------------------------------*/
C_INLINE void gpioStop_(
    esGpioDrv_T     * gpio) {

    HAL_CRITICAL_DECL();

    HAL_CRITICAL_ENTER();
    pinRegRemoveI_(
        gpio->drvId,
        gpio->pins);

    if (TRUE == pinRegIsEmptyI_(gpio->drvId)) {
        RCC->AHBENR &= ~((uint32_t)1U << gpio->drvId->rccPos);                  /* Onemoguci takt za port periferiju.                       */
    }
    HAL_CRITICAL_EXIT();
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

/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void esGpioInit(
    const C_ROM esGpioDef_T * definition,
    esGpioDrv_T     * gpio,
    const C_ROM esGpioDrvId_T * gpioId,
    uint16_t        pins) {

    uint16_t pinPos;
    uint16_t pos;

    HAL_DBG_CHECK((const C_ROM esGpioDef_T *)0U != definition);                 /* Provera par: mora da se preda definiciona struktura.     */
    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpioId));                                     /* Provera par: da li je drvId ispravan?                    */
    HAL_DBG_CHECK((uint16_t)0U != pins);                                        /* Provera par: mora da se izabere barem jedan pin.         */
    HAL_DBG_CHECK(
        (ES_GPIO_MODE_IN == definition->mode) ||
        (ES_GPIO_MODE_OUT == definition->mode));                                /* Provera par: da li mode enumerator?                      */
    HAL_DBG_CHECK(
        (ES_GPIO_OTYPE_OPENDRAIN == definition->otype) ||
        (ES_GPIO_OTYPE_PUSHPULL == definition->otype));
    HAL_DBG_CHECK(
        (ES_GPIO_ITYPE_PULLDOWN == definition->itype) ||
        (ES_GPIO_ITYPE_PULLNONE == definition->itype) ||
        (ES_GPIO_ITYPE_PULLUP == definition->itype));                           /* Provera par: da li je inType enumerator?                 */
    HAL_DBG_CHECK(
        (ES_GPIO_SPEED_HIGH == definition->speed) ||
        (ES_GPIO_SPEED_MEDIUM == definition->speed) ||
        (ES_GPIO_SPEED_LOW == definition->speed));                              /* Provera par: da li speed enumerator?                     */
    gpio->drvId = (struct gpioDrvId *)gpioId;
    gpio->regs = gpioId->regs;
    gpio->pins = pins;

#if defined(OPT_OPTIMIZE_SPEED)
    gpio->BSRRH = &(gpioId->regs->BSRRH);
    gpio->BSRRL = &(gpioId->regs->BSRRL);
#endif
    RCC->AHBENR |= ((uint32_t)1U << gpioId->rccPos);                            /* Omoguci takt za port periferiju.                         */

    for (pinPos = 0x00; pinPos < 0x10; pinPos++) {
        pos = (uint32_t)1U << pinPos;

        if ((uint16_t)0U != (pins & pos)) {
            gpio->regs->MODER &= (uint32_t)0x03 << (pinPos * 2U);
            gpio->regs->MODER |= ((uint32_t)definition->mode) << (pinPos * 2U);
            gpio->regs->OSPEEDR &= (uint32_t)0x03 << (pinPos * 2U);
            gpio->regs->OSPEEDR |= translateSpeed_(definition->speed) << (pinPos * 2U);
            gpio->regs->OTYPER &= (uint32_t)0x01 << pinPos;
            gpio->regs->OTYPER |= ((uint32_t)definition->otype) << pinPos;
            gpio->regs->PUPDR &= (uint32_t)0x03 << (pinPos * 2U);
            gpio->regs->PUPDR |= ((uint32_t)definition->itype) << (pinPos * 2U);
        }
    }
    RCC->AHBENR &= ~((uint32_t)1U << gpioId->rccPos);                           /* Onemoguci takt za port periferiju.                       */
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
        gpio);
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioDeInit(
    esGpioDrv_T     * gpio) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpio->drvId = (struct gpioDrvId *)0U;
    gpio->regs = (GPIO_TypeDef *)0U;
    gpio->pins = (uint16_t)0U;

#if defined(OPT_OPTIMIZE_SPEED)
    gpio->BSRRH = (__IO uint16_t *)0U;
    gpio->BSRRL = (__IO uint16_t *)0U;
#endif
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinSetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */

#if defined(OPT_OPTIMIZE_SPEED)
    gpio->BSRRL = pins;
#else
    gpio->regs->BSRRL = pins;
#endif
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinResetFast(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */

#if defined(OPT_OPTIMIZE_SPEED)
    gpio->BSRRH = pins;
#else
    gpio->regs->BSRRH = pins;
#endif
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinSet(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);

#if defined(OPT_OPTIMIZE_SPEED)
    gpio->BSRRL = pins;
#else
    gpio->regs->BSRRL = pins;
#endif
    gpioStop_(
        gpio);
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioPinReset(
    esGpioDrv_T     * gpio,
    uint16_t        pins) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);

#if defined(OPT_OPTIMIZE_SPEED)
    gpio->BSRRH = pins;
#else
    gpio->regs->BSRRH = pins;
#endif
    gpioStop_(
        gpio);
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioWrite(
    esGpioDrv_T     * gpio,
    uint16_t        data) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpioStart_(
        gpio);
    gpio->regs->ODR = data;
    gpioStop_(
        gpio);
}

/*-----------------------------------------------------------------------------------------------*/
void esGpioFastWrite(
    esGpioDrv_T     * gpio,
    uint16_t        data) {

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    gpio->regs->ODR = data;
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esGpioStatus(
    esGpioDrv_T     * gpio) {

    uint32_t rccState;

    HAL_DBG_CHECK(NULL != gpio);                                                /* Provera par: da li je gpio definisan?                    */
    HAL_DBG_CHECK(GPIO_DRVID_LIST(gpio->drvId));                                /* Provera par: da li je drvId ispravan?                    */
    rccState = RCC->AHBENR & ((uint32_t)0x01 << (gpio->drvId->rccPos));

    if ((uint32_t)0U != rccState) {

        return (ES_DEV_ACTIVE);
    } else {

        return (ES_DEV_INACTIVE);
    }
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of gpio_lld.c
 *//** @} *//*************************************************************************************/
