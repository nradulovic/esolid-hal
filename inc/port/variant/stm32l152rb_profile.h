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
 * @brief       Profil za STM32L152RB mikrokontroler
 * @details     U ovoj datoteci se navode sve periferije datog mikrokontrolera.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l152rb
 * @brief		Profil za STM32L152RB mikrokontroler
 ****************************************************************************************//** @{ */


#ifndef STM32L152RB_PROFILE_H_
#define STM32L152RB_PROFILE_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i periferiji.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_MCU_NAME                 "STM32L152RB"
#define ES_HAL_MCU_FLASH                (131072UL)
#define ES_HAL_MCU_RAM                  (16384UL)
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        GPIO konstante
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_FEATURE_GPIOA
#define ES_HAL_FEATURE_GPIOB
#define ES_HAL_FEATURE_GPIOC
#define ES_HAL_FEATURE_GPIOD
#define ES_HAL_FEATURE_GPIOE
#define ES_HAL_FEATURE_GPIOH
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        Timer konstante
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_FEATURE_TMR2
#define ES_HAL_FEATURE_TMR3
#define ES_HAL_FEATURE_TMR4
#define ES_HAL_FEATURE_TMR6
#define ES_HAL_FEATURE_TMR7
#define ES_HAL_FEATURE_TMR9
#define ES_HAL_FEATURE_TMR10
#define ES_HAL_FEATURE_TMR11
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @name        UART konstante
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_HAL_FEATURE_UART1
#define ES_HAL_FEATURE_UART2
#define ES_HAL_FEATURE_UART3
/** @} *//*--------------------------------------------------------------------------------------*/

/**
 * @brief       Fino podesavanje familije
 */
#define STM32L1XX_MD_

/*==================================================================================  MACRO's  ==*/
/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of stm32l152rb_profile.h
 *************************************************************************************************/
#endif /* STM32L152RB_PROFILE_H_ */
