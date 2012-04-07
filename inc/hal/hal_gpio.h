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
 * @name        Definition group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/

enum esGpioMode {
    ES_GPIO_MODE_IN,
    ES_GPIO_MODE_OUT,
    ES_GPIO_MODE_ANALOG,
    ES_GPIO_MODE_ALTERNATE
};

enum esGpioSpeed {
    ES_GPIO_SPEED_LOW,
    ES_GPIO_SPEED_MEDIUM,
    ES_GPIO_SPEED_HIGH
};

enum esGpioOutType {
    ES_GPIO_OTYPE_PUSHPULL,
    ES_GPIO_OTYPE_OPENDRAIN
};

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
 * @name        Data types group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/

typedef struct gpioDrv esGpioDrv_T;
typedef struct esGpioDef esGpioDef_T;

struct esGpioDef {
    enum esGpioMode mode;
    enum esGpioSpeed speed;
    enum esGpioOutType otype;
    enum esGpioInType itype;
};

/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Variables group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Function group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
void esGpioInit(
    esGpioDrv_T     * aGpio,
    const C_ROM esGpioDef_T * aDefinition,
    uint8_t         aPin);

esDevStatus_T esGpioStatus(
    esGpioDrv_T     * aGpio);

void esGpioDeInit(
    esGpioDrv_T     * aGpio);

void esGpioStart(
    esGpioDrv_T     * aGpio);

void esGpioStop(
    esGpioDrv_T     * aGpio);

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
