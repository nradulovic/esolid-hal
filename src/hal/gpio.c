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
 * @brief       Implementacija GPIO modula
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  gpio_impl
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#include "hal_private.h"

/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_DEFINE_MODULE(gpio);

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/

void gpioModuleInit (
    void) {

#if defined(OPT_HAL_GPIO)
# if defined(OPT_HAL_GPIO_USE_A)
    esGPIOA->drvDef = (esGpioDef_T *)0U;
    esGPIOA->state = ES_DEV_INACTIVE;
    esGPIOA->users = (uint16_t)0U;
# endif

# if defined(OPT_HAL_GPIO_USE_B)
    esGPIOB->drvDef = (esGpioDef_T *)0U;
    esGPIOB->state = ES_DEV_INACTIVE;
    esGPIOB->users = (uint16_t)0U;
# endif

# if defined(OPT_HAL_GPIO_USE_C)
    esGPIOC->drvDef = (esGpioDef_T *)0U;
    esGPIOC->state = ES_DEV_INACTIVE;
    esGPIOC->users = (uint16_t)0U;
# endif

# if defined(OPT_HAL_GPIO_USE_D)
    esGPIOD->drvDef = (esGpioDef_T *)0U;
    esGPIOD->state = ES_DEV_INACTIVE;
    esGPIOD->users = (uint16_t)0U;
# endif

# if defined(OPT_HAL_GPIO_USE_E)
    esGPIOE->drvDef = (esGpioDef_T *)0U;
    esGPIOE->state = ES_DEV_INACTIVE;
    esGPIOE->users = (uint16_t)0U;
# endif

# if defined(OPT_HAL_GPIO_USE_H)
    esGPIOH->drvDef = (esGpioDef_T *)0U;
    esGPIOH->state = ES_DEV_INACTIVE;
    esGPIOH->users = (uint16_t)0U;
# endif
    lldGpioDrvInit();
#endif /* OPT_HAL_GPIO */
}

void gpioDrvStart(
    esGpioDrv_T * aGpio) {

    if ((uint16_t)0U == aGpio->users) {

    }

#if defined(OPT_HAL_GPIO)
#else /* OPT_HAL_GPIO */
    (void)aGpio;
#endif /* !OPT_HAL_GPIO */
}
/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of gpio.c
 *************************************************************************************************/
