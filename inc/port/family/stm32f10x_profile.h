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
 * @brief       Profil familije za STM32F10x seriju.
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */


#ifndef STM32F10X_PROFILE_H_
#define STM32F10X_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

#if defined(PORT_SUBFAM_STM32F10X_LD_)

/**
 * @brief       Definisanje konstante - familija
 */
# define ES_HAL_MCU_FAMILY              "STM32F10x Low density devices"

#endif /* STM32F10X_LD */

#if defined(PORT_SUBFAM_STM32F10X_LD_VL_)

/**
 * @brief       Definisanje konstante - familija
 */
# define ES_HAL_MCU_FAMILY                                                      \
    "STM32F10x Low density Value Line devices"

#endif /* STM32F10X_LD_VL */

#if defined(PORT_SUBFAM_STM32F10X_MD_VL_)

/**
 * @brief       Definisanje konstante - familija
 */
# define ES_HAL_MCU_FAMILY                                                      \
    "STM32F10x Medium density Value Line devices"

#endif /* STM32F10X_MD_VL */

#if defined(OPT_HAL_GPIO)
# define ES_HAL_ENABLE_GPIO
#endif

#if defined(OPT_HAL_UART)
# define ES_HAL_ENABLE_UART
#endif

#if defined(OPT_HAL_TIMER)
# define ES_HAL_ENABLE_TIMER
#endif

#if defined(OPT_ENABLE_CRC)
# define ES_HAL_ENABLE_CRC
#endif

/*------------------------------------------------------------------------*//**
 * @name        Opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i proizvodjacu.
 * @{ *//*--------------------------------------------------------------------*/
#define ES_HAL_MCU_MANUF                "STMicroelectronics"

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Konstante mogucnosti HAL modula
 * @{ *//*--------------------------------------------------------------------*/
#define ES_HAL_FEATURE_GPIO
#define ES_HAL_FEATURE_UART
#define ES_HAL_FEATURE_TIMER
#define ES_HAL_FEATURE_CRC

/** @} *//*-------------------------------------------------------------------*/
/*===============================================================  MACRO's  ==*/

#define EXPAND_AS_GPIO_ENUM(a, b, c)    a,
#define EXPAND_AS_UART_ENUM(a, b, c)    a,
#define EXPAND_AS_TIMER_ENUM(a, b, c)   a,

/*============================================================  DATA TYPES  ==*/

#if defined(ES_HAL_ENABLE_GPIO)

/**
 * @brief       Ime Gpio porta koji se koristi
 * @details     Dostupna imena portova zavise od koriscenog mikrokontrolera
 */
typedef enum esGpioPort {
    GPIO_TABLE(EXPAND_AS_GPIO_ENUM)
    GPIO_LAST_PORT_
} esGpioPort_T;
#endif

#if defined(ES_HAL_ENABLE_UART)

/**
 * @brief       Ime Uart porta koji se koristi
 * @details     Dostupna imena portova zavise od koriscenog mikrokontrolera
 */
typedef enum esUartPort {
    UART_TABLE(EXPAND_AS_UART_ENUM)
    UART_LAST_PORT_
} esUartPort_T;
#endif

#if defined(ES_HAL_ENABLE_TIMER)

/**
 * @brief       Ime Timera koji se koristi
 * @details     Dostupna imena portova zavise od koriscenog mikrokontrolera
 */
typedef enum esTimer {
    TIMER_TABLE(EXPAND_AS_TIMER_ENUM)
    TIMER_LAST_
} esTimer_T;
#endif

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32f10x_profile.h
 ******************************************************************************/
#endif /* STM32F10X_PROFILE_H_ */
