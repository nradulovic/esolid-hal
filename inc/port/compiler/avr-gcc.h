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
 * @author      Nenad Radulović
 * @brief       Interfejs za AVR-GCC kompajler, port klasa: common.
 * @addtogroup  port_avr_gcc
 *********************************************************************//** @{ */

#ifndef GCC_COMPILER_H_
#define GCC_COMPILER_H_

/*=========================================================  INCLUDE FILES  ==*/

#include <avr/pgmspace.h>

/*===============================================================  MACRO's  ==*/

#if (__STDC_VERSION < 199901L) && (__GNUC__ >= 2) || defined(__DOXYGEN__)
# define C_FUNC                         __FUNCTION__
#else
# define C_FUNC                         "Unknown"
#endif
#define C_FILE
#define C_LINE
#define C_EXT
#define C_PACKED
#define C_ALIGNED(expr)
#define C_COMPILE_BARRIER()
#define C_NORETURN
#define C_UNUSED_ARG(type,arg)
#define C_UNUSED_VAR(type,name)
#define C_USED_VAR(type,name)
#define C_INLINE_ALWAYS
#define C_INLINE
#define C_NOINLINE
#define C_UNUSED_FUNC
#define C_USED_FUNC
#define C_RESTRICT
#define C_NAKED

#define C_CONTAINER_OF(ptr, type, member)                                       \
        (type *)((uint8_t *)(ptr) - offsetof(type, member))

#define C_WEAK_FUNC
#define C_ROM                           __ATTR_PROGMEM__
#define C_ROM_VAR
#define C_INTERRUPT_HANDLER(name)       name

/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

typedef enum boolType {
    FALSE = 0U,
    TRUE = 1U
} bool_T;

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of gcc.h
 ******************************************************************************/
#endif /* GCC_COMPILER_H_ */
