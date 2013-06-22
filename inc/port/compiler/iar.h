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
/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/

#if !defined(C_FUNC)
# define C_FUNC
#endif

#if !defined(C_FILE)
# define C_FILE
#endif

#if !defined(C_LINE)
# define C_LINE
#endif

#if !defined(C_EXT)
# define C_EXT
#endif

#if !defined(C_PACKED)
# define C_PACKED                       __packed
#endif

#if !defined(C_ALIGNED)
# define C_ALIGNED(expr)
#endif

#if !defined(C_COMPILE_BARRIER)
# define C_COMPILE_BARRIER()
#endif

#if !defined(C_NORETURN)
# define C_NORETURN                     __noreturn
#endif

#if !defined(C_UNUSED_ARG)
# define C_UNUSED_ARG(type,arg)
#endif

#if !defined(C_UNUSED_VAR)
# define C_UNUSED_VAR(type,name)
#endif

#if !defined(C_USED_VAR)
# define C_USED_VAR(type,name)
#endif

#if !defined(C_INLINE_ALWAYS)
# define C_INLINE_ALWAYS
#endif

#if !defined(C_INLINE)
# define C_INLINE
#endif

#if !defined(C_NOINLINE)
# define C_NOINLINE
#endif

#if !defined(C_UNUSED_FUNC)
# define C_UNUSED_FUNC
#endif

#if !defined(C_USED_FUNC)
# define C_USED_FUNC
#endif

#if !defined(C_RESTRICT)
# define C_RESTRICT
#endif

#if !defined(C_NAKED)
# define C_NAKED
#endif

#if !defined(C_PTRCAST)
# define C_PTRCAST(srctype, dsttype, var)
#endif

#if !defined(C_CONTAINER_OF)
#define C_CONTAINER_OF(ptr, type, member)
#endif

#if !defined(C_WEAK_FUNC)
# define C_WEAK_FUNC                    __weak
#endif

#if !defined(ES_ABS)
# define ES_ABS(expr)
#endif

#if !defined(ES_MAX)
# define ES_MAX(expr1, expr2)
#endif

#if !defined(ES_MIN)
# define ES_MIN(expr1, expr2)
#endif

/*------------------------------------------------------  C++ extern begin  --*/
#if defined(__cplusplus)
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

#if !defined(HAL_STD_TYPES)
# include <stdint.h>
# define HAL_STD_TYPES
#endif

#if !defined(HAL_BOOL_TYPE)
# define HAL_BOOL_TYPE
typedef enum boolType {
    FALSE = 0UL,
    TRUE = 1UL
} bool_T;
#endif

#if !defined(HAL_FAST_TYPES)
# include <stdint.h>
#define HAL_FAST_TYPES
#endif

#if !defined(HAL_DEF_TYPES)
# include <stddef.h>
# define HAL_DEF_TYPES
#endif

#if !defined(HAL_VARARG_SUPP)
# include <stdarg.h>
# define HAL_VARARG_SUPP
#endif

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
