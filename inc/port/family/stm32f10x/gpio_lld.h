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
 *//******************************************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Interfejs/konfiguracija GPIO Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_gpio_impl
 ****************************************************************************************//** @{ */


#ifndef GPIO_LLD_H_
#define GPIO_LLD_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
#if defined(OPT_OPTIMIZE_SPEED)
# define ES_GPIO_FAST_SET(gpio, pins)                                           \
    do {                                                                        \
        gpio->BSRRL = pins;                                                     \
    } while (0)

# define ES_GPIO_FAST_RESET(gpio, pins)                                         \
    do {                                                                        \
        gpio->BSRRH = pins;                                                     \
    } while (0)

#endif

/*===============================================================================  DATA TYPES  ==*/
struct gpioId;
struct gpioIntr;
struct gpioDef;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upravljacka struktura
 * @details     Ova struktura opisuje koji je identifikator drajvera, registri i
 *              pinovi koji se koriste. U slucaju da se koristi optimizacija po
 *              brzini, onda se u nju direktno dodavaju adrese registara za brzi
 *              pristup. U tom slucaju moguce je koristi makroe.
 *//*--------------------------------------------------------------------------------------------*/
struct gpioDrv {
/**
 * @brief       Pokazivac na identifikacionu strukturu
 */
    struct gpioId       * drvId;

/*
 * GPIO drajver nema potrebu da poseduje direktan pokazivac na internu strukturu.
 * Internoj strukturi se pristupa preko ID strukture.
 */
#if 0
/**
 * @brief       Pokazivac na internu strukturu
 */
    struct gpioIntr     * drvIntr;
#endif

/*
 * GPIO drajver nema potrebu da poseduje pokazivac na definicionu strukturu.
 */
#if 0
/**
 * @brief       Pokazivac na definicionu strukturu
 */
    struct gpioDef      * drvDef;
#endif

/**
 * @brief       Pokazivac na registre hardvera
 */
    volatile GPIO_TypeDef * regs;

/**
 * @brief       Pinovi porta koji se koriste od strane ove upravljacke strukture.
 */
    uint16_t            pins;
};

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if defined(ES_ENABLE_GPIO)
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
