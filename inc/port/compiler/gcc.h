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
 * @addtogroup  port_gcc
 *********************************************************************//** @{ */

#ifndef GCC_COMPILER_H_
#define GCC_COMPILER_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
/*===============================================================  MACRO's  ==*/

#if !defined(C_FUNC)
# if (__STDC_VERSION < 199901L) && (__GNUC__ >= 2) || defined(__DOXYGEN__)
#  define C_FUNC                        __FUNCTION__
# endif
#endif

#if !defined(C_FILE)
# define C_FILE                         __FILE__
#endif

#if !defined(C_LINE)
# define C_LINE                         __LINE__
#endif

#if !defined(C_EXT)
# define C_EXT                          __extension__
#endif

#if !defined(C_PACKED)
# define C_PACKED                       __attribute__ ((packed))
#endif

#if !defined(C_ALIGNED)
# define C_ALIGNED(expr)                __attribute__ ((aligned (expr)))
#endif

#if !defined(C_COMPILE_BARRIER)
# define C_COMPILE_BARRIER()            asm volatile ("" : : : "memory")
#endif

#if !defined(C_NORETURN)
# define C_NORETURN                     __attribute__((__noreturn__))
#endif

#if !defined(C_UNUSED_ARG)
# define C_UNUSED_ARG(type,arg)         __attribute__((__unused__)) type arg
#endif

#if !defined(C_UNUSED_VAR)
# define C_UNUSED_VAR(type,name)        __attribute__((__unused__)) type name
#endif

#if !defined(C_USED_VAR)
# define C_USED_VAR(type,name)          __attribute__((__used__)) type name
#endif

#if !defined(C_INLINE_ALWAYS)
# define C_INLINE_ALWAYS                __inline__ __attribute__((__always_inline__))
#endif

#if !defined(C_INLINE)
# define C_INLINE                       __inline__
#endif

#if !defined(C_NOINLINE)
# define C_NOINLINE                     __attribute__((noinline))
#endif

#if !defined(C_UNUSED_FUNC)
# define C_UNUSED_FUNC                  __attribute__((unused))
#endif

#if !defined(C_USED_FUNC)
# define C_USED_FUNC                    __attribute__((__used__))
#endif

#if !defined(C_RESTRICT)
# define C_RESTRICT                     __restrict__
#endif

#if !defined(C_NAKED)
# define C_NAKED                        __attribute__((naked))
#endif

#if !defined(C_PTRCAST)
# define C_PTRCAST(srctype, dsttype, var)                                       \
    C_EXT (((union {srctype src; dsttype dst;} __attribute__ ((__may_alias__)) *)var)->dst)
#endif


/**
 * @brief       Makro za pronalazak pokazivaca na strukturu kada je poznat
 *              pokazivac na jedan clan strukture.
 * @details     U odnosu na klasican makro koji je dostupan u hal_compiler.h
 *              ovaj makro vrsi dodatnu proveru da li je pokazivac na clan
 *              strukture ispravnog tipa.
 */
#if !defined(C_CONTAINER_OF)
#define C_CONTAINER_OF(ptr, type, member)                                       \
        (type *)((uint8_t *)(ptr) - offsetof(type, member))
#endif

#if !defined(C_WEAK_FUNC)
# define C_WEAK_FUNC                    __attribute__((weak))
#endif

/**
 * @brief       Ovaj makro ima svojstva funkcije i zasticen je od bocnih efekata.
 */
#if !defined(ES_ABS)
# define ES_ABS(expr)                                                           \
    C_EXT ({                                                                    \
        typeof(expr) expr_ = (expr);                                            \
        (expr_ < 0) ? -expr_ : expr_;                                           \
    })
#endif

/**
 * @brief       Ovaj makro ima svojstva funkcije i zasticen je od bocnih efekata.
 */
#if !defined(ES_MAX)
# define ES_MAX(expr1, expr2)                                                   \
    C_EXT ({                                                                    \
        typeof(expr1) expr1_ = (expr1);                                         \
        typeof(expr2) expr2_ = (expr2);                                         \
        ((typeof(expr1_))((expr1_ > expr2_) ? expr1_ : expr2_));                \
    })
#endif

/**
 * @brief       Ovaj makro ima svojstva funkcije i zasticen je od bocnih efekata.
 */
#if !defined(ES_MIN)
# define ES_MIN(expr1, expr2)                                                   \
    C_EXT ({                                                                    \
        typeof(expr1) expr1_ = (expr1);                                         \
        typeof(expr2) expr2_ = (expr2);                                         \
        ((typeof(expr1_))((expr1_ < expr2_) ? expr1_ : expr2_));                \
    })
#endif

/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

#if !defined(HAL_STD_TYPES)
# include <stdint.h>
# define HAL_STD_TYPES
#endif

#if !defined(HAL_BOOL_TYPE)
# include <stdbool.h>
# define HAL_BOOL_TYPE
typedef enum boolType {
    FALSE = false,
    TRUE = true
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
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of gcc.h
 ******************************************************************************/
#endif /* GCC_COMPILER_H_ */
