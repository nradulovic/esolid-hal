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
 * @brief       Profil za STM32L152RB mikrokontroler
 * @addtogroup  port_stm32l152rb
 *********************************************************************//** @{ */

#ifndef STM32L152RB_PROFILE_H_
#define STM32L152RB_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        STM32L152RB opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i periferiji.
 * @{ *//*--------------------------------------------------------------------*/
#define ES_HAL_MCU_NAME                 "STM32L152RB"
#define ES_HAL_MCU_FLASH                131072UL
#define ES_HAL_MCU_RAM                  16384UL

/** @} *//*-------------------------------------------------------------------*/

/**
 * @brief       Tabela GPIO portova
 * @notapi
 */
#define GPIO_TABLE_(ENTRY)                                                      \
    ENTRY(ES_GPIOA, GPIOA, RCC_AHBENR_GPIOAEN)                                  \
    ENTRY(ES_GPIOB, GPIOB, RCC_AHBENR_GPIOBEN)                                  \
    ENTRY(ES_GPIOC, GPIOC, RCC_AHBENR_GPIOCEN)                                  \
    ENTRY(ES_GPIOD, GPIOD, RCC_AHBENR_GPIODEN)                                  \
    ENTRY(ES_GPIOE, GPIOE, RCC_AHBENR_GPIOEEN)                                  \
    ENTRY(ES_GPIOH, GPIOH, RCC_AHBENR_GPIOHEN)

/**
 * @brief       Definisanje podfamilije
 * @notapi
 */
#define PORT_SUBFAM_STM32L1XX_MD_

/**
 * @brief       Definisanje maksimalne frekvencije taktnog signala
 * @notapi
 */
#define PORT_MAX_CPU_FREQ_              32000000UL

/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32l152rb_profile.h
 ******************************************************************************/
#endif /* STM32L152RB_PROFILE_H_ */
