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
 * @brief       Autodetekcija kompajlera i ostalih aspekata port sistema.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  port_intf
 ****************************************************************************************//** @{ */
/**
 * @defgroup    port_detection Autodetekcija porta
 * @brief       Detekcija kompajlera, arhitekture, varijante i platforme
 * @details     Ovaj modul vrsi automatsku detekciju kompajlera. Time se
 *              definise common klasa port sistema. Zatim se vrsi ispitivanje
 *              korisnickih definisanih preprocesorskih promenljivih kako bi se
 *              odredile i ostale klase port sistema.
 *
 *              Pored autodetekcije, svaka klasa port sistema se moze definisati
 *              i rucno od strane korisnika.
 ****************************************************************************************//** @{ */


#ifndef PORT_DETECT_H_
#define PORT_DETECT_H_


/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Podrzani portovi klase platforme.
 * @brief       Konstante koje prepoznaje port sistem za konfiguraciju platforme.
 * @{ *//*---------------------------------------------------------------------------------------*/

#define _STM32L_DISCOVERY_              1

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Podrzani portovi klase varijante.
 * @brief       Konstante koje prepoznaje port sistem za konfiguraciju varijante.
 * @{ *//*---------------------------------------------------------------------------------------*/

#define _STM32L1XX_MD_                  201
#define _STM32F10X_LD_VL_               202
#define _LINUX_X86_						203
#define _LINUX_X86_X64_					204
#define _WIN_X86_						205
#define _WIN_X86_X64_					206
#define _STM32F10X_MD_VL_               207

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Podrzani portovi klase familije.
 * @brief       Konstante koje prepoznaje port sistem za konfiguraciju
 *              familije.
 * @{ *//*---------------------------------------------------------------------------------------*/

#define _STM32F10X_                     301
#define _STM32L1XX_                     302

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Podrzani portovi klase arhitekture.
 * @brief       Konstante koje prepoznaje port sistem za konfiguraciju
 *              arhitekture.
 * @{ *//*---------------------------------------------------------------------------------------*/

#define _ARM_CM3_                       401
#define _X86_COMPAT_					402

/** @} *//*--------------------------------------------------------------------------------------*/

/*==================================================================================  MACRO's  ==*/
/*-----------------------------------------------------------------------------------------------*
 *              Definisanje platforme i odredjivanje varijante
 *-----------------------------------------------------------------------------------------------*/
#if defined(OPT_PORT_PLATFORM)

# if (OPT_PORT_PLATFORM == _STM32L_DISCOVERY_)
#  define PORT_PLATFORM                 STM32L_DISCOVERY
#  define OPT_PORT_VARIANT              _STM32L1XX_MD_

# else
#  error "Can not resolve port platform class, please check OPT_PORT_PLATFORM option."
# endif

#endif

/*-----------------------------------------------------------------------------------------------*
 *              Definisanje varijante i odredjivanje arhitekture
 *-----------------------------------------------------------------------------------------------*/
#if defined(OPT_PORT_VARIANT)

# if (OPT_PORT_VARIANT == _STM32L1XX_MD_)
#  define PORT_VARIANT                  stm32l1xx_md
#  define OPT_PORT_FAMILY               _STM32L1XX_

# elif (OPT_PORT_VARIANT == _STM32F10X_LD_VL_)
#  define PORT_VARIANT                  stm32f10x_ld_vl
#  define OPT_PORT_FAMILY               _STM32F10X_

# elif (OPT_PORT_VARIANT == _STM32F10X_MD_VL_)
#  define PORT_VARIANT                  stm32f10x_md_vl
#  define OPT_PORT_FAMILY               _STM32F10X_

# elif (OPT_PORT_VARIANT == _LINUX_X86_)
#  define PORT_VARIANT					linux_x86
#  define OPT_PORT_ARCH					_X86_COMPAT_

# elif (OPT_PORT_VARIANT == _LINUX_X86_X64_)
#  define PORT_VARIANT					linux_x86_x64
#  define OPT_PORT_ARCH					_X86_COMPAT_

# else
#  error "Can not resolve port variant class, please check OPT_PORT_VARIANT option."
# endif
#else
# error "OPT_PORT_VARIANT not defined. Please, define OPT_PORT_VARIANT or OPT_PORT_PLATFORM option."
#endif

/*-----------------------------------------------------------------------------------------------*
 *              Definisanje familije
 *-----------------------------------------------------------------------------------------------*/
#if defined(OPT_PORT_FAMILY)

# if (OPT_PORT_FAMILY == _STM32L1XX_)
#  define PORT_FAMILY                   stm32l1xx
#  define OPT_PORT_ARCH                 _ARM_CM3_

# elif (OPT_PORT_FAMILY == _STM32F10X_)
#  define PORT_FAMILY                   stm32f10x
#  define OPT_PORT_ARCH                 _ARM_CM3_

# else
#  error "Can not resolve port family class, please check OPT_PORT_FAMILY option."
# endif
#else
# error "OPT_PORT_FAMILY not defined. Please, define OPT_PORT_FAMILY or OPT_PORT_PLATFORM option."
#endif

/*-----------------------------------------------------------------------------------------------*
 *              Definisanje arhitekture
 *-----------------------------------------------------------------------------------------------*/
#if defined(OPT_PORT_ARCH)

# if (OPT_PORT_ARCH == _ARM_CM3_)
#  define PORT_ARCH                     arm_cm3

# elif (OPT_PORT_ARCH == _X86_COMPAT_)
#  define PORT_ARCH						x86

# else
#  error "Can not resolve port architecture class, please check OPT_PORT_ARCH option."
# endif
#else
# error "OPT_PORT_ARCH not defined. Please, define OPT_PORT_ARCH, OPT_PORT_VARIANT or OPT_PORT_PLATFORM option."
#endif

/*-----------------------------------------------------------------------------------------------*
 *              Odredjivanje kompajlera
 *-----------------------------------------------------------------------------------------------*/

#if defined(OPT_PORT_CMN)
# if (OPT_PORT_CMN == _GCC_)
#  define PORT_CMN                      GCC
# endif
#else
# if defined(__GNUC__)
#  define PORT_CMN                      GCC
# elif defined(__IAR_SYSTEMS_ICC) || defined(__IAR_SYSTEMS_ICC__)
#  define PORT_CMN                      IAR
# endif
#endif

#if !defined(PORT_CMN)
# error "Can not resolve port common class, please specify in OPT_PORT_CMN option."
#endif

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/


/** @endcond *//** @} *//*************************************************************************
 * END of port_detect.h
 *//** @} *//*************************************************************************************/
#endif /* PORT_DETECT_H_ */
