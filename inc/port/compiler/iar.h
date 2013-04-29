/******************************************************************************
 * This file is part of esolid-hal
 *
 * Template version: 1.1.18 (10.03.2013)
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * esolid-hal is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * esolid-hal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with esolid-hal; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *//***********************************************************************//**
 * @file
 * @author  	Nenad Radulović
 * @brief       Interfejs za IAR kompajler, port klasa: common.
 * @addtogroup  port_iar
 *********************************************************************//** @{ */

#ifndef IAR_COMMON_H_
#define IAR_COMMON_H_

/*=========================================================  INCLUDE FILES  ==*/

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

/*===============================================================  MACRO's  ==*/

#define C_FUNC
#define C_FILE
#define C_LINE
#define C_EXT
#define C_PACKED                        __packed
#define C_ALIGNED(expr)
#define C_COMPILE_BARRIER()
#define C_NORETURN                      __noreturn
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

#define C_WEAK_FUNC                     __weak
#define C_ROM
#define C_ROM_VAR
#define C_INTERRUPT_HANDLER(name)       name

/*------------------------------------------------------  C++ extern begin  --*/
#if defined(__cplusplus)
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

typedef enum boolType {
    FALSE = 0UL,
    TRUE = 1UL
} bool_T;

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*--------------------------------------------------------  C++ extern end  --*/
#if defined(__cplusplus)
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of iar.h
 ******************************************************************************/
#endif /* IAR_COMMON_H_ */
