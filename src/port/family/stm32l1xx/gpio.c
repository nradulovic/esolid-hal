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
 * @brief       GPIO drajver za STM32F10x seriju.
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */
                                                                                                  
/*=========================================================  INCLUDE FILES  ==*/
#include "../src/hal/hal_private.h"

#if defined(ES_HAL_ENABLE_GPIO)
#include "stm32l1xx_pkg.h"

/*===============================================================  DEFINES  ==*/
/*=========================================================  LOCAL MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        STM32L1xx pomocni makroi za formiranje GPIO tabele
 * @{ *//*--------------------------------------------------------------------*/
#define EXPAND_AS_GPIO(a, b, c)         {b, c},

/** @} *//*-------------------------------------------------------------------*/
/*======================================================  LOCAL DATA TYPES  ==*/

/**
 * @brief       Struktura GPIO identifikatora
 */
struct gpioTable {
/**
 * @brief       Registri hw
 */
    GPIO_TypeDef *  reg;

/**
 * @brief       Bit za omogucavanje takta
 */
    uint32_t        en;
};

/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/

/**
 * @brief       Tabela svih GPIO portova
 */
static const C_ROM struct gpioTable gpioTable [GPIO_LAST_PORT_] = {
    GPIO_TABLE_(EXPAND_AS_GPIO)
};

/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*===================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/

void gpioInit(
    void) {

    uint8_t cnt;

    for (cnt = 0; cnt < GPIO_LAST_PORT_; cnt++) {
        RCC->AHBRSTR |= gpioTable[cnt].en;
        RCC->AHBRSTR &= ~gpioTable[cnt].en;
    }
}

/*====================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
void esGpioInit(
    esGpioPort_T    gpioPort,
    const C_ROM esGpioDef_T * gpioDef,
    uint16_t        pins) {

    uint32_t cntr;
    uint32_t mask;

    mask = 0UL;

    for (cntr = 0UL; cntr < 16; cntr++) {

        if (pins & (0x01UL << cntr)) {
            mask |= 0x03UL << (2UL * cntr);
        }
    }
    RCC->AHBENR |= gpioTable[gpioPort].en;

    if (gpioDef->mode == ES_GPIO_MODE_OUT) {
        ES_HWREG_SET(
            gpioTable[gpioPort].reg->MODER,
            mask,
            0x55555555UL & mask);
    } else {
        ES_HWREG_SET(
            gpioTable[gpioPort].reg->MODER,
            mask,
            0UL);
    }

    switch (gpioDef->itype) {
        case ES_GPIO_ITYPE_PULLNONE : {
            ES_HWREG_SET(
                gpioTable[gpioPort].reg->PUPDR,
                mask,
                0UL);
            break;
        }

        case ES_GPIO_ITYPE_PULLUP : {
            ES_HWREG_SET(
                gpioTable[gpioPort].reg->PUPDR,
                mask,
                0x55555555UL & mask);
            break;
        }

        default : {
            ES_HWREG_SET(
                gpioTable[gpioPort].reg->PUPDR,
                mask,
                0xAAAAAAAAUL & mask);
            break;
        }
    }

    switch (gpioDef->speed) {
        case ES_GPIO_SPEED_HIGH : {
            ES_HWREG_SET(
                gpioTable[gpioPort].reg->OSPEEDR,
                mask,
                0xFFFFFFFFUL & mask);
            break;
        }

        case ES_GPIO_SPEED_MEDIUM : {
            ES_HWREG_SET(
                gpioTable[gpioPort].reg->OSPEEDR,
                mask,
                0xAAAAAAAAUL & mask);
            break;
        }

        default : {
            ES_HWREG_SET(
                gpioTable[gpioPort].reg->OSPEEDR,
                mask,
                0UL);
            break;
        }
    }

    if (gpioDef->otype == ES_GPIO_OTYPE_OPENDRAIN) {
        gpioTable[gpioPort].reg->OTYPER |= pins;
    } else {
        gpioTable[gpioPort].reg->OTYPER &= ~pins;
    }
    RCC->AHBENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioDeInit(
    esGpioPort_T    gpioPort) {

    RCC->APB2RSTR |= gpioTable[gpioPort].en;
    RCC->APB2RSTR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
esDevStatus_T esGpioStatus(
    esGpioPort_T    gpioPort) {

    esDevStatus_T ans;

    if (RCC->AHBENR & gpioTable[gpioPort].en) {
        ans = ES_HAL_DEV_READY;
    } else {
        ans = ES_HAL_DEV_INACTIVE;
    }

    return (ans);
}

/*----------------------------------------------------------------------------*/
void esGpioPinSet(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    RCC->AHBENR |= gpioTable[gpioPort].en;
    esGpioPinSetFast(
        gpioPort,
        pins);
    RCC->AHBENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioPinReset(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    RCC->AHBENR |= gpioTable[gpioPort].en;
    esGpioPinResetFast(
        gpioPort,
        pins);
    RCC->AHBENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioWrite(
    esGpioPort_T    gpioPort,
    uint16_t        data) {

    RCC->AHBENR |= gpioTable[gpioPort].en;
    esGpioWriteFast(
        gpioPort,
        data);
    RCC->AHBENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
uint16_t esGpioRead(
    esGpioPort_T    gpioPort) {

    uint16_t data;

    RCC->AHBENR |= gpioTable[gpioPort].en;
    data = esGpioReadFast(
        gpioPort);
    RCC->AHBENR &= ~gpioTable[gpioPort].en;

    return (data);
}

/*----------------------------------------------------------------------------*/
void esGpioStart(
    esGpioPort_T    gpioPort) {

    RCC->AHBENR |= gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioStop(
    esGpioPort_T    gpioPort) {

    RCC->AHBENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioPinSetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    gpioTable[gpioPort].reg->BSRRL = pins;
}

/*----------------------------------------------------------------------------*/
void esGpioPinResetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    gpioTable[gpioPort].reg->BSRRH = pins;
}

/*----------------------------------------------------------------------------*/
void esGpioWriteFast(
    esGpioPort_T    gpioPort,
    uint16_t        data) {

    gpioTable[gpioPort].reg->ODR = data;
}

/*----------------------------------------------------------------------------*/
uint16_t esGpioReadFast(
    esGpioPort_T    gpioPort) {

    return (gpioTable[gpioPort].reg->IDR);
}

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#else /* ES_HAL_ENABLE_GPIO */
extern C_UNUSED_VAR(uint8_t, emptyVariable);
#endif /* !ES_HAL_ENABLE_GPIO */

/** @endcond *//** @} *//******************************************************
 * END of gpio.c
 ******************************************************************************/
