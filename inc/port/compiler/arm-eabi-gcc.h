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
 * @brief       Interfejs za GCC kompajler, port klasa: common.
 * @addtogroup  port_arm-eabi-gcc
 *********************************************************************//** @{ */

#ifndef ARM_EABI_GCC_H_
#define ARM_EABI_GCC_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  MACRO's  ==*/

#if (__STDC_VERSION < 199901L) && (__GNUC__ >= 2) || defined(__DOXYGEN__)
# define C_FUNC                         __FUNCTION__
#else
# define C_FUNC                         "Unknown"
#endif
#define C_FILE                          __FILE__
#define C_LINE                          __LINE__
#define C_EXT                           __extension__
#define C_PACKED                        __attribute__ ((packed))
#define C_ALIGNED(expr)                 __attribute__ ((aligned (expr)))
#define C_COMPILE_BARRIER()             asm volatile ("" : : : "memory")
#define C_NORETURN                      __attribute__((__noreturn__))
#define C_UNUSED_ARG(type,arg)          __attribute__((__unused__)) type arg
#define C_UNUSED_VAR(type,name)         __attribute__((__unused__)) type name
#define C_USED_VAR(type,name)           __attribute__((__used__)) type name
#define C_INLINE_ALWAYS                 __inline__ __attribute__((__always_inline__))
#define C_INLINE                        __inline__
#define C_NOINLINE                      __attribute__((noinline))
#define C_UNUSED_FUNC                   __attribute__((unused))
#define C_USED_FUNC                     __attribute__((__used__))
#define C_RESTRICT                      __restrict__
#define C_NAKED                         __attribute__((naked))

#define C_CONTAINER_OF(ptr, type, member)                                       \
        (type *)((uint8_t *)(ptr) - offsetof(type, member))

#define C_WEAK_FUNC                     __attribute__((weak))
#define C_ROM
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
 * END of arm-eabi-gcc.h
 ******************************************************************************/
#endif /* ARM_EABI_GCC_H_ */
