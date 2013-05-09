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
 * @brief       Profil za STM32F100RB mikrokontroler
 * @addtogroup  port_stm32f100rb
 *********************************************************************//** @{ */

#ifndef STM32F100RB_PROFILE_H_
#define STM32F100RB_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        STM32F100RB opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i periferiji.
 * @{ *//*--------------------------------------------------------------------*/

#define ES_HAL_MCU_NAME                 "STM32F100RB"
#define ES_HAL_MCU_FLASH                131072UL
#define ES_HAL_MCU_RAM                  8192UL
#define ES_HAL_MCU_MANUF                "STMicroelectronics"
#define ES_HAL_MCU_FAMILY               "STM32F10x device"

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        STM32F10x konstante mogucnosti
 * @{ *//*--------------------------------------------------------------------*/

#define ES_HAL_FEATURE_STARTUP
#define ES_HAL_FEATURE_CPU
#define ES_HAL_FEATURE_INTERRUPT
#define ES_HAL_FEATURE_GPIO

/** @} *//*-------------------------------------------------------------------*/

/**
 * @brief       Naglasi da se koristi profil
 */
#define ES_HAL_PROFILE_ENABLED

/**
 * @brief       Tabela GPIO portova
 * @notapi
 */
#define GPIO_TABLE_(ENTRY)                                                      \
    ENTRY(ES_GPIOA, GPIOA, RCC_APB2ENR_IOPAEN)                                  \
    ENTRY(ES_GPIOB, GPIOB, RCC_APB2ENR_IOPBEN)                                  \
    ENTRY(ES_GPIOC, GPIOC, RCC_APB2ENR_IOPCEN)                                  \
    ENTRY(ES_GPIOD, GPIOD, RCC_APB2ENR_IOPDEN)                                  \
    ENTRY(ES_GPIOE, GPIOE, RCC_APB2ENR_IOPEEN)

/**
 * @brief       Definisanje podfamilije
 * @notapi
 */
# define PORT_SUBFAM_STM32F10X_MD_VL_

/**
 * @brief       Definisanje maksimalne frekvencije taktnog signala
 * @notapi
 */
#define PORT_MAX_CPU_FREQ_              24000000UL

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32f100rb_profile.h
 ******************************************************************************/
#endif /* STM32F100RB_PROFILE_H_ */
