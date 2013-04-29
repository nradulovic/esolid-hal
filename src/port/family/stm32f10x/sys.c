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
 * @brief       Sistemski drajver za STM32F10x seriju.
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */

/*=========================================================  INCLUDE FILES  ==*/
#include "hal/hal.h"
#include "stm32f10x_pkg.h"

/*=========================================================  LOCAL DEFINES  ==*/
/*=========================================================  LOCAL MACRO's  ==*/
/*======================================================  LOCAL DATA TYPES  ==*/
/*=============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*=======================================================  LOCAL VARIABLES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*============================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*===================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*====================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*----------------------------------------------------------------------------*/
uint32_t esSysCoreClockGet(
    void) {

    uint32_t clk;
    uint32_t div;

    switch (RCC->CFGR & RCC_CFGR_SWS) {
        case RCC_CFGR_SWS_HSI : {
            clk = 16000000UL;
            break;
        }

        case RCC_CFGR_SWS_PLL : {
            uint32_t mul;

            if (RCC_CFGR_PLLSRC_PREDIV1 == (RCC->CFGR & RCC_CFGR_PLLSRC)) {
                clk = 1000000UL / (1 << (RCC->CFGR2 & RCC_CFGR2_PREDIV1));
            } else {
                clk = 4000000UL;
            }
            mul = ((RCC->CFGR & RCC_CFGR_PLLMULL) >> 18UL) + 2UL;
            clk *= mul;
            break;
        }

        default : {
            clk = 1000000UL;
            break;
        }
    }
    div = (RCC->CFGR & RCC_CFGR_HPRE) >> 4UL;

    if (div & 0x08UL) {
        div = 2UL << (div & ~0x08UL);
        clk = clk / div;
    }

    return (clk);
}

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of sys.c
 ******************************************************************************/
