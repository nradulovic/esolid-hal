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

/*============================================================================*
 *
 * STM32F10X_LD
 *
 *============================================================================*/
#if defined(STM32F10X_LD)
/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/**
 * @brief       Definisanje konstante - familija
 */
# define ES_HAL_MCU_FAMILY              "STM32F10x Low density devices"

/**
 * @brief       Definisanje PORT konstante - familija
 */
# define PORT_FAM_STM32F10X_LD

# if defined(OPT_HAL_GPIO)
#  error "HAL: GPIO module is not implented for this family."
#  define ES_HAL_ENABLE_GPIO
# endif

# if defined(OPT_HAL_UART)
#  error "HAL: UART module is not implented for this family."
#  define ES_HAL_ENABLE_UART
# endif

# if defined(OPT_HAL_TIMER)
#  error "HAL: TIMER module is not implented for this family."
#  define ES_HAL_ENABLE_TIMER
# endif

# if defined(OPT_ENABLE_CRC)
#  error "HAL: CRC module is not implented for this family."
#  define ES_HAL_ENABLE_CRC
# endif

/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
#endif /* STM32F10X_LD */

/*============================================================================*
 *
 * STM32F10X_LD_VL
 *
 *============================================================================*/
#if defined(STM32F10X_LD_VL)
/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/**
 * @brief       Definisanje konstante - familija
 */
# define ES_HAL_MCU_FAMILY                                                      \
    "STM32F10x Low density Value Line devices"

/**
 * @brief       Definisanje PORT konstante - familija
 */
# define PORT_FAM_STM32F10X_LD_VL

# if defined(OPT_HAL_GPIO)
#  error "HAL: GPIO module is not implented for this family."
#  define ES_HAL_ENABLE_GPIO
# endif

# if defined(OPT_HAL_UART)
#  error "HAL: UART module is not implented for this family."
#  define ES_HAL_ENABLE_UART
# endif

# if defined(OPT_HAL_TIMER)
#  error "HAL: TIMER module is not implented for this family."
#  define ES_HAL_ENABLE_TIMER
# endif

# if defined(OPT_ENABLE_CRC)
#  error "HAL: CRC module is not implented for this family."
#  define ES_HAL_ENABLE_CRC
# endif

/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
#endif /* STM32F10X_LD_VL */

/*============================================================================*
 *
 * STM32F10X_MD_VL
 *
 *============================================================================*/
#if defined(STM32F10X_MD_VL)
/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/**
 * @brief       Definisanje konstante - familija
 */
# define ES_HAL_MCU_FAMILY                                                      \
    "STM32F10x Medium density Value Line devices"

/**
 * @brief       Definisanje PORT konstante - familija
 */
# define PORT_FAM_STM32F10X_MD_VL

# if defined(OPT_HAL_GPIO)
#  define ES_HAL_ENABLE_GPIO
# endif

# if defined(OPT_HAL_UART)
#  error "HAL: UART module is not implented for this family."
#  define ES_HAL_ENABLE_UART
# endif

# if defined(OPT_HAL_TIMER)
#  error "HAL: TIMER module is not implented for this family."
#  define ES_HAL_ENABLE_TIMER
# endif

# if defined(OPT_ENABLE_CRC)
#  error "HAL: CRC module is not implented for this family."
#  define ES_HAL_ENABLE_CRC
# endif

/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
#endif /* STM32F10X_MD_VL */

/*============================================================================*
 *
 * COMMON
 *
 *============================================================================*/
/*=========================================================  INCLUDE FILES  ==*/
#include "port/family/stm32f10x/cmsis/stm32f10x.h"                              /* CMSIS                                                    */

#if defined(ES_HAL_ENABLE_GPIO)
# include "port/family/stm32f10x/gpio_lld.h"
#endif

#if defined(ES_HAL_ENABLE_UART)
# include "port/family/stm32f10x/uart_lld.h"
#endif

#if defined(ES_HAL_ENABLE_TIMER)
# include "port/family/stm32f10x/timer_lld.h"
#endif

#if defined(ES_HAL_ENABLE_CRC)
# include "port/family/stm32f10x/crc_lld.h"
#endif

/*===============================================================  DEFINES  ==*/

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
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32f10x_profile.h
 ******************************************************************************/
#endif /* STM32F10X_PROFILE_H_ */
