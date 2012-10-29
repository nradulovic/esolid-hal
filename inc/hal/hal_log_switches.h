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
 * @brief       Prekidaci za vodjenje dnevnika
 * @details     Ova datoteka se ukljucuje nakon navodjenja opcija za modul dnevnika
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  log_intf
 * @brief		Prekidaci za vodjenje dnevnika
 * @details     Ova datoteka se ukljucuje nakon navodjenja opcija za modul dnevnika
 ****************************************************************************************//** @{ */


#ifndef HAL_LOG_SWITCHES_H_
#define HAL_LOG_SWITCHES_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje trenutnog nivoa za vodjenje dnevnika
 * @details     Korisnik treba da definise ovu konstantu na zeljeni nivo
 *              vodjenja dnevnika pre ukljucivanja hal_log_switches.h datoteke.
 *              Na primer, sledeci kod ukljucuje samo makroe sa prioritetom
 *              @ref ES_LOG_LEVEL_WARN ili vecim:
 @code
 #define OPT_LOG_LEVEL               ES_LOG_LEVEL_WARN
 #include "hal/hal_log_switches.h"
 @endcode
 * @note        Ukoliko konstanta nije definisana, vodjenje dnevnika nije
 *              ukljuceno za dati modul.
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(OPT_LOG_LEVEL) || !defined(OPT_HAL_LOG) || defined(__DOXYGEN__)
# define OPT_LOG_LEVEL                  6U
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje imena modula.
 * @details     Korisnik treba da definise ovu preprocesorsku konstantu sa
 *              imenom modula. Na primer, ukoliko se dnevnik koristi u modulu
 *              koji se zove Memory management korisnik treba da napise sledece
 *              pre ukljucivanja hal_log_switches.h datoteke:
 @code
 #define OPT_HAL_LOG_MODULE_NAME        "Memory management"
 #include "hal/hal_log_switches.h"
 @endcode
 * @note        Ukoliko konstanta nije definisana automatski se definise
 *              konstanta sa sadrzajem "Unknown module".
 *//*--------------------------------------------------------------------------------------------*/
#if !defined(OPT_LOG_MODULE_NAME) || defined(__DOXYGEN__)
# define LOG_MODULE_NAME                "Unknown module"
#else
# define LOG_MODULE_NAME                OPT_LOG_MODULE_NAME
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje imena datoteke.
 * @details     Makro vrsi definisanje imena datoteke za koriscenje od strane
 *              funkcija dnevnika. Dovoljno je da korisnik navede makro u
 *              sekciji DEFINES izvorne datoteke. Makro vrsi instaciranje
 *              znakovne konstante sa imenom datoteke u kojoj se makro poziva.
 * @note        Ovaj makro se postavlja iskljucivo unutar datoteke izvornog koda.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) && (OPT_LOG_LEVEL <= ES_LOG_LEVEL_FATAL) || defined(__DOXYGEN__)
# define ES_LOG_DEFINE_FILE(name)                                               \
    C_UNUSED_VAR(static const C_ROM char * const C_ROM_VAR, LOG_THIS_FILE) = ES_ISTRING(name);
#else
# define ES_LOG_DEFINE_FILE()                                                   \
    extern C_UNUSED_VAR(uint8_t, unusedDefineModule)
#endif

#if (OPT_LOG_LEVEL <= ES_LOG_LEVEL_FATAL)
# if defined(ES_HAL_FEATURE_VARIADIC_MACRO)
#  define ES_LOG_FATAL(fmt, ...)                                                \
    esLogAdvMessage(                                                            \
        LOG_THIS_MODULE,                                                        \
        LOG_THIS_FILE,                                                          \
        C_FUNC,                                                                 \
        OPT_HAL_LOG_TIMESTAMP,                                                  \
        ES_LOG_LEVEL_FATAL,                                                     \
        fmt,                                                                    \
        ## __VA_ARGS__)
# else /* ES_HAL_FEATURE_VARIADIC_MACRO */
/**
 * @todo    Napisati f-ju koja automatski popunjava level i poziva esLogAdvMessage
 */
#  define ES_LOG_FATAL                                                          \
    esLogFatal
# endif /* !ES_HAL_FEATURE_VARIADIC_MACRO */
#else /* OPT_LOG_LEVEL <= ES_LOG_LEVEL_FATAL */
# define ES_LOG_FATAL
#endif /* !OPT_LOG_LEVEL <= ES_LOG_LEVEL_FATAL */

#if (OPT_LOG_LEVEL <= ES_LOG_LEVEL_ERROR)
# if defined(ES_HAL_FEATURE_VARIADIC_MACRO)
#  define ES_LOG_ERROR(fmt, ...)                                                \
    esLogAdvMessage(                                                            \
        LOG_THIS_MODULE,                                                        \
        LOG_THIS_FILE,                                                          \
        C_FUNC,                                                                 \
        OPT_HAL_LOG_TIMESTAMP,                                                  \
        ES_LOG_LEVEL_ERROR,                                                     \
        fmt,                                                                    \
        ## __VA_ARGS__)
# else /* ES_HAL_FEATURE_VARIADIC_MACRO */
/**
 * @todo    Napisati f-ju koja automatski popunjava level i poziva esLogAdvMessage
 */
#  define ES_LOG_ERROR                                                          \
    esLogError
# endif /* !ES_HAL_FEATURE_VARIADIC_MACRO */
#else
# define ES_LOG_ERROR
#endif /* !OPT_LOG_LEVEL <= ES_LOG_LEVEL_ERROR */

#if (OPT_LOG_LEVEL <= ES_LOG_LEVEL_WARN)
# if defined(ES_HAL_FEATURE_VARIADIC_MACRO)
#  define ES_LOG_WARN(fmt, ...)                                                 \
    esLogAdvMessage(                                                            \
        LOG_THIS_MODULE,                                                        \
        LOG_THIS_FILE,                                                          \
        C_FUNC,                                                                 \
        OPT_HAL_LOG_TIMESTAMP,                                                  \
        ES_LOG_LEVEL_WARN,                                                      \
        fmt,                                                                    \
        ## __VA_ARGS__)
# else /* ES_HAL_FEATURE_VARIADIC_MACRO */
/**
 * @todo    Napisati f-ju koja automatski popunjava level i poziva esLogAdvMessage
 */
#  define ES_LOG_WARN                                                           \
    esLogWarn
# endif /* !ES_HAL_FEATURE_VARIADIC_MACRO */
#else
# define ES_LOG_WARN
#endif /* OPT_LOG_LEVEL <= ES_LOG_LEVEL_WARN */

#if (OPT_LOG_LEVEL <= ES_LOG_LEVEL_INFO)
# if defined(ES_HAL_FEATURE_VARIADIC_MACRO)
#  define ES_LOG_INFO(fmt, ...)                                                 \
    esLogAdvMessage(                                                            \
        LOG_THIS_MODULE,                                                        \
        LOG_THIS_FILE,                                                          \
        C_FUNC,                                                                 \
        OPT_HAL_LOG_TIMESTAMP,                                                  \
        ES_LOG_LEVEL_INFO,                                                      \
        fmt,                                                                    \
        ## __VA_ARGS__)
# else /* ES_HAL_FEATURE_VARIADIC_MACRO */
/**
 * @todo    Napisati f-ju koja automatski popunjava level i poziva esLogAdvMessage
 */
#  define ES_LOG_INFO                                                           \
    esLogInfo
# endif /* !ES_HAL_FEATURE_VARIADIC_MACRO */
#else
# define ES_LOG_INFO
#endif /* OPT_LOG_LEVEL <= ES_LOG_LEVEL_INFO */

#if (OPT_LOG_LEVEL <= ES_LOG_LEVEL_DEBUG)
# if defined(ES_HAL_FEATURE_VARIADIC_MACRO)
#  define ES_LOG_DEBUG(fmt, ...)                                                \
    esLogAdvMessage(                                                            \
        LOG_THIS_MODULE,                                                        \
        LOG_THIS_FILE,                                                          \
        C_FUNC,                                                                 \
        OPT_HAL_LOG_TIMESTAMP,                                                  \
        ES_LOG_LEVEL_DEBUG,                                                     \
        fmt,                                                                    \
        ## __VA_ARGS__)
# else /* ES_HAL_FEATURE_VARIADIC_MACRO */
/**
 * @todo    Napisati f-ju koja automatski popunjava level i poziva esLogAdvMessage
 */
#  define ES_LOG_DEBUG                                                          \
    esLogDebug
# endif /* !ES_HAL_FEATURE_VARIADIC_MACRO */
#else
# define ES_LOG_DEBUG
#endif /* OPT_LOG_LEVEL <= ES_LOG_LEVEL_DEBUG */

#if (OPT_LOG_LEVEL <= ES_LOG_LEVEL_TRACE)
# if defined(ES_HAL_FEATURE_VARIADIC_MACRO)
#  define ES_LOG_TRACE(fmt, ...)                                                \
    esLogAdvMessage(                                                            \
        LOG_THIS_MODULE,                                                        \
        LOG_THIS_FILE,                                                          \
        C_FUNC,                                                                 \
        OPT_HAL_LOG_TIMESTAMP,                                                  \
        ES_LOG_LEVEL_TRACE,                                                     \
        fmt,                                                                    \
        ## __VA_ARGS__)
# else /* ES_HAL_FEATURE_VARIADIC_MACRO */
/**
 * @todo    Napisati f-ju koja automatski popunjava level i poziva esLogAdvMessage
 */
#  define ES_LOG_TRACE                                                          \
    esLogTrace
# endif /* !ES_HAL_FEATURE_VARIADIC_MACRO */
#else
# define ES_LOG_TRACE
#endif /* OPT_LOG_LEVEL <= ES_LOG_LEVEL_TRACE */



/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
#if defined(OPT_HAL_LOG) && (OPT_LOG_LEVEL <= ES_LOG_LEVEL_FATAL)
static const C_ROM char * const C_ROM_VAR LOG_THIS_MODULE = LOG_MODULE_NAME;
#endif

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_log_switches.h
 *************************************************************************************************/
#endif /* HAL_LOG_SWITCHES_H_ */
