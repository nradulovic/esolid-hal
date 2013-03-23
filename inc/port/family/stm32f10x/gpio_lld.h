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
 * @brief       Interfejs/konfiguracija GPIO Low Level Driver modula.
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */

#ifndef GPIO_LLD_H_
#define GPIO_LLD_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/

#define EXPAND_AS_GPIO_ENUM(a, b, c)    a,

enum gpioPort {
    GPIO_TABLE(EXPAND_AS_GPIO_ENUM)
    GPIO_LAST_PORT_
};

/*============================================================  DATA TYPES  ==*/

/**
 * @brief       Ime porta koji se koristi
 * @details     Dostupna imena portova zavise od koriscenog mikrokontrolera
 */
typedef enum gpioPort esGpioPort_T;

struct gpioTable {
    GPIO_TypeDef *  reg;
    uint32_t        en;
};

/*======================================================  GLOBAL VARIABLES  ==*/
extern const C_ROM struct gpioTable gpioTable[GPIO_LAST_PORT_];

/*===================================================  FUNCTION PROTOTYPES  ==*/

/*----------------------------------------------------------------------------*/
static C_INLINE void esGpioPinSetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    gpioTable[gpioPort].reg->BSRR = pins;
}

/*----------------------------------------------------------------------------*/
static C_INLINE void esGpioPinResetFast(
    esGpioPort_T    gpioPort,
    uint16_t        pins) {

    gpioTable[gpioPort].reg->BRR = pins;
}

/*----------------------------------------------------------------------------*/
static C_INLINE void esGpioWriteFast(
    esGpioPort_T    gpioPort,
    uint16_t        data) {

    gpioTable[gpioPort].reg->ODR = data;
}

/*----------------------------------------------------------------------------*/
static C_INLINE uint16_t esGpioReadFast(
    esGpioPort_T    gpioPort) {

    return (gpioTable[gpioPort].reg->IDR);
}

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of gpio_lld.h
 ******************************************************************************/
#endif /* GPIO_LLD_H_ */
