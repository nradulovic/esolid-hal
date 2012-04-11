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
 * @brief       Interfejs/konfiguracija GPIO Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_gpio
 ****************************************************************************************//** @{ */


#ifndef GPIO_LLD_H_
#define GPIO_LLD_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "stm32l1xx.h"

/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Makroi za brz pristup GPIO modulu
 * @brief       Ovim makroima se vrsi najbrzi moguci pristup hardverskim
 *              registrima. Adrese registara se nalaze u RAM memoriji sto
 *              omogucava brzi pristup nego da se vrsi citanje adrese iz spore
 *              FLASH memorije. Ovi makroi koriste opisanu tehniku samo kada se
 *              koristi optimizacija po brzini (OPT_OPTIMIZE_SPEED). Treba
 *              naglasiti da se strukture za GPIO drajver u tom slucaju
 *              povecavaju za 8B (po instanci drajverske strukture).
 *
 *              Ukoliko se ne koristi optimizacija po brzini makroi ce i dalje
 *              raditi, ali sa tom razlikom sto ce se pozivati funkcije
 * @{ *//*---------------------------------------------------------------------------------------*/
#if defined(OPT_OPTIMIZE_SPEED) || defined(__DOXYGEN__)
# define ES_GPIO_FAST_SET(gpio, pins)                                           \
    do {                                                                        \
        gpio->BSRRL = pins;                                                     \
    } while (0)

# define ES_GPIO_FAST_RESET(gpio, pins)                                         \
    do {                                                                        \
        gpio->BSRRH = pins;                                                     \
    } while (0)

#else

# define ES_GPIO_FAST_RESET(gpio, pins)                                         \
    esGpioPinResetFast(gpio, pins)

# define ES_GPIO_FAST_SET(gpio, pins)                                           \
    esGpioPinSetFast(gpio, pins)
#endif
/** @} *//*--------------------------------------------------------------------------------------*/


/*===============================================================================  DATA TYPES  ==*/

struct gpioDrvId;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Drajver struktura
 * @details     Ova struktura opisuje koji je identifikator drajvera, registri i
 *              pinovi koji se koriste. U slucaju da se koristi optimizacija po
 *              brzini, onda se u nju direktno dodavaju adrese registara za brzi
 *              pristup. U tom slucaju moguce je koristi makroe.
 */
struct gpioDrv {
    GPIO_TypeDef        * regs;
    struct gpioDrvId    * drvId;

#if defined(OPT_OPTIMIZE_SPEED)
    __IO uint16_t       * BSRRL;                                                /* BSRR register is split to 2 * 16-bit fields BSRRL */
    __IO uint16_t       * BSRRH;                                                /* BSRR register is split to 2 * 16-bit fields BSRRH */
#endif
    uint16_t            pins;
};

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if defined(OPT_HAL_GPIO)
# if defined(OPT_HAL_GPIO_USE_F)
#  error "HAL->GPIO: This port does not support PORT F."
# endif
# if defined(OPT_HAL_GPIO_USE_G)
#  error "HAL->GPIO: This port does not support PORT G."
# endif
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of gpio_lld.h
 *************************************************************************************************/
#endif /* GPIO_LLD_H_ */
