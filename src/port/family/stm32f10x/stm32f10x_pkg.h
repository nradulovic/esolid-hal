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
 * @brief       Selekcija STM32F10x podfamilije
 * @addtogroup  port_stm32f10x
 *********************************************************************//** @{ */

#ifndef STM32F10X_PKG_H_
#define STM32F10X_PKG_H_

/*=========================================================  INCLUDE FILES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        STM32F10x selekcija podfamilije
 * @brief       STM32F10x definise nekoliko podfamilije, stoga je potrebno
 *              izvrsiti selekciju potrebne podfamilije.
 * @{ *//*--------------------------------------------------------------------*/

/*
 * Biramo podfamiliju definisanjem makroa. Medjutim, okruzenje (IDE) mozda vec
 * definise ove makroe i onda moramo da proverimo to kako bi izbegli greske o
 * duplim definicijama.
 */
#if defined(PORT_SUBFAM_STM32F10X_LD_)
# if !defined(STM32F10X_LD)
#  define                               STM32F10X_LD
# endif
#endif

#if defined(PORT_SUBFAM_STM32F10X_MD_)
# if !defined(STM32F10X_MD)
#  define                               STM32F10X_MD
# endif
#endif

#if defined(PORT_SUBFAM_STM32F10X_MD_VL_)
# if !defined(STM32F10X_MD_VL)
#  define                               STM32F10X_MD_VL
# endif
#endif

#if defined(PORT_SUBFAM_STM32F10X_HD_)
# if !defined(STM32F10X_HD)
#  define                               STM32F10X_HD
# endif
#endif

#if defined(PORT_SUBFAM_STM32F10X_HD_VL_)
# if !defined(STM32F10X_HD_VL)
#  define                               STM32F10X_HD_VL
# endif
#endif

#if defined(PORT_SUBFAM_STM32F10X_XL_)
# if !defined(STM32F10X_XL)
#  define                               STM32F10X_XL
# endif
#endif

#if defined(PORT_SUBFAM_STM32F10X_CL_)
# if !defined(STM32F10X_CL)
#  define                               STM32F10X_CL
# endif
#endif

/*
 * Ne prati se sablon datoteke, ali ovo je jedan od boljih nacina realizacije
 */
#include "stm32f10x.h"

/** @} *//*-------------------------------------------------------------------*/
/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/
/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of stm32f10x_pkg.h
 ******************************************************************************/
#endif /* STM32F10X_PKG_H_ */
