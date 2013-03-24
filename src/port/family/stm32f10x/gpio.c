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
#define GPIO_LLD_VAR
#include "../src/hal/hal_private.h"

#if defined(ES_HAL_ENABLE_GPIO)
#include "stm32f10x_pkg.h"

/*===============================================================  DEFINES  ==*/
/*=========================================================  LOCAL MACRO's  ==*/

#define EXPAND_AS_GPIO(a, b, c)         {b, c},

/*======================================================  LOCAL DATA TYPES  ==*/

struct gpioTable {
    GPIO_TypeDef *  reg;
    uint32_t        en;
};

/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/

const C_ROM struct gpioTable gpioTable [GPIO_LAST_PORT_] = {
    GPIO_TABLE(EXPAND_AS_GPIO)
};

/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*===================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/

void gpioInit(
    void) {

    uint8_t cnt;

    for (cnt = 0; cnt < GPIO_LAST_PORT_; cnt++) {
        RCC->APB2RSTR |= gpioTable[cnt].en;
        RCC->APB2RSTR &= ~gpioTable[cnt].en;
    }
}

/*====================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

/*----------------------------------------------------------------------------*/
void esGpioInit(
    esGpioPort_T    gpioPort,
    const C_ROM esGpioDef_T * gpioDef,
    uint16_t        pins) {

    uint32_t pin;
    uint32_t tmp;

    RCC->APB2ENR |= gpioTable[gpioPort].en;

    if (ES_GPIO_MODE_IN == gpioDef->mode) {
        tmp = 0x00UL;                                                           /* mode == input                                            */

        if (ES_GPIO_ITYPE_PULLNONE == gpioDef->itype) {
            tmp |= 0x04UL;                                                      /* cnf == floating input                                    */
        } else {
            tmp |= 0x08UL;                                                      /* cnf == pull-up/pull-down                                 */
        }
    } else {

        switch (gpioDef->speed) {
            case ES_GPIO_SPEED_HIGH : {
                tmp = 0x03UL;
                break;
            }

            case ES_GPIO_SPEED_MEDIUM : {
                tmp = 0x02UL;
                break;
            }

            default : {
                tmp = 0x01UL;
                break;
            }
        }

        if (ES_GPIO_OTYPE_OPENDRAIN == gpioDef->otype) {
            tmp |= 0x04UL;
        }
    }

    if (pins & 0x00FF) {

        for (pin = 0UL; pin < 8UL; pin++) {

            if (pins & ES_BV32(pin)) {
                gpioTable[gpioPort].reg->CRL &= ~(0x0FUL << (pin * 4UL));
                gpioTable[gpioPort].reg->CRL |= (tmp << (pin * 4UL));

                if (ES_GPIO_ITYPE_PULLDOWN == gpioDef->itype) {
                    gpioTable[gpioPort].reg->BRR = ES_BV32(pin);
                } else if (ES_GPIO_ITYPE_PULLUP == gpioDef->itype) {
                    gpioTable[gpioPort].reg->BSRR = ES_BV32(pin);
                }
            }
        }
    }

    if (pins & 0xFF00) {

        for (pin = 0UL; pin < 8UL; pin++) {

            if (pins & ES_BV32(pin + 8UL)) {
                gpioTable[gpioPort].reg->CRH &= ~(0x0FUL << (pin * 4UL));
                gpioTable[gpioPort].reg->CRH |= (tmp << (pin * 4UL));

                if (ES_GPIO_ITYPE_PULLDOWN == gpioDef->itype) {
                    gpioTable[gpioPort].reg->BRR = ES_BV32(pin + 8UL);
                } else if (ES_GPIO_ITYPE_PULLUP == gpioDef->itype) {
                    gpioTable[gpioPort].reg->BSRR = ES_BV32(pin + 8UL);
                }
            }
        }
    }
    RCC->APB2ENR &= ~gpioTable[gpioPort].en;
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

    if (RCC->APB2ENR & gpioTable[gpioPort].en) {
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

    RCC->APB2ENR |= gpioTable[gpioPort].en;
    esGpioPinSetFast(
        gpioPort,
        pins);
    RCC->APB2ENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioPinReset(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    RCC->APB2ENR |= gpioTable[gpioPort].en;
    esGpioPinResetFast(
        gpioPort,
        pins);
    RCC->APB2ENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioWrite(
    esGpioPort_T    gpioPort,
    uint16_t        data) {

    RCC->APB2ENR |= gpioTable[gpioPort].en;
    esGpioWriteFast(
        gpioPort,
        data);
    RCC->APB2ENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
uint16_t esGpioRead(
    esGpioPort_T    gpioPort) {

    uint16_t data;

    RCC->APB2ENR |= gpioTable[gpioPort].en;
    data = esGpioReadFast(
        gpioPort);
    RCC->APB2ENR &= ~gpioTable[gpioPort].en;

    return (data);
}

/*----------------------------------------------------------------------------*/
void esGpioStart(
    esGpioPort_T    gpioPort) {

    RCC->APB2ENR |= gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioStop(
    esGpioPort_T    gpioPort) {

    RCC->APB2ENR &= ~gpioTable[gpioPort].en;
}

/*----------------------------------------------------------------------------*/
void esGpioPinSetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    gpioTable[gpioPort].reg->BSRR = pins;
}

/*----------------------------------------------------------------------------*/
void esGpioPinResetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    gpioTable[gpioPort].reg->BRR = pins;
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
