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
 * @brief       Interfejs port sistema.
 * ------------------------------------------------------------------------------------------------
 * @defgroup    port_intf eSolid port interface
 * @brief       Interfejs port sistema.
 ****************************************************************************************//** @{ */


#ifndef PORT_H_
#define PORT_H_


/*============================================================================  INCLUDE FILES  ==*/
#include "port/port_detect.h"

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Port konstanta koja se koristi prilikom ispitavanja mogucnosti
 *              port sistema.
 * @details     Ova promenljiva pokazuje da je dati atribut podrzan.
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_TRUE                       1

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Port konstanta koja se koristi prilikom ispitivanja mogucnosti
 *              port sistema.
 * @details     Ova promenljiva pokazuje da dati atribut nije podrzan.
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_FALSE                      2

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Pomocni makroi za ispravan rad port sistema
 * @note        Svi pomocni makroi su namenjeni iskljucivo za internu upotrebu
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Koristi se u makrou PORT_CONCAT().
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_ICONCAT(expr1, expr2)      expr1 ## expr2

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Objedinjuje argumente u jedan niz.
 * @param       expr1                   Prvi argument koji se spaja
 * @param       expr2                   Drugi argumenr koji se spaja
 * @return      expression = expr1 + expr2
 * @details     Nakon poziva PORT_CONCAT(var, 123) dobija se var123.
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_CONCAT(expr1, expr2)       PORT_ICONCAT(expr1, expr2)

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Neposredno (Immediate) pretvaranje izraza u niz karaktera.
 * @param       expr                    Prvi argument koji se spaja
 * @return      "expr"
 * @details     Nakon poziva E_STRING(E_CONCAT(Ne, sa)) dobija se
 *              "E_CONCAT(Ne, sa)".
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_ISTRING(expr)              #expr

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Pretvaranje izraza u niz karaktera.
 * @param       expr                    Argument koji treba da se pretvori u niz
 *                                      karaktera.
 * @return      "expr"
 * @details     Nakon poziva E_STRING(E_CONCAT(Ne, sa)) dobija se "Nesa".
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_STRING(expr)                PORT_ISTRING(expr)

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Makroi interfejsa za port sistem.
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vraca putanju za Common klasu port sistema.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(PORT_CMN) || defined(__DOXYGEN__)
# define PORT_CMN_HEADER(common_module)                                         \
    PORT_STRING(port/common/PORT_CMN/common_module.h)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vraca putanju za Arch klasu port sistema.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(PORT_ARCH) || defined(__DOXYGEN__)
# define PORT_ARCH_HEADER(arch_module)                                          \
    PORT_STRING(port/arch/PORT_ARCH/arch_module.h)
#else
# error "PORT_ARCH is not defined. Please define it according to the used architecture."
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vraca putanju za Varian klasu port sistema.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(PORT_VARIANT) || defined(__DOXYGEN__)
# define PORT_VARIANT_HEADER(variant_module)                                    \
    PORT_STRING(port/variant/PORT_VARIANT/variant_module.h)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vraca putanju za Platform klasu port sistema.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(PORT_PLATFORM) || defined(__DOXYGEN__)
# define PORT_PLATFORM_HEADER(platform_module)                                  \
    PORT_STRING(port/platform/PORT_PLATFORM/platform_module.h)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vraca putanju ka kompajlerskom poddirektorijumu.
 *//*--------------------------------------------------------------------------------------------*/
#define PORT_COMPILER_HEADER(module)                                            \
    PORT_STRING(PORT_CMN/module.h)

/** @} *//*--------------------------------------------------------------------------------------*/

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
 * END of port.h
 *************************************************************************************************/
#endif /* PORT_H_ */
