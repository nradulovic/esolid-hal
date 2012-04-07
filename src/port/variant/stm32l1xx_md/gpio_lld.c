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
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/

void gpioDrvHandler(
    esGpioDrv_T     * aDriver);

/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

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

void lldGpioPinFunction(ES_HWREGS_T * aGpio, uint16_t);

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of gpio_lld.c
 *//** @} *//*************************************************************************************/
