/*************************************************************************************************
 * This file is part of esolid-haldsm
 *
 * Template version: 1.1.13 (24.03.2012)
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * esolid-haldsm is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * esolid-haldsm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with esolid-haldsm; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *************************************************************************************************/


/*********************************************************************************************//**
 * @file
 * @author  	nenad
 * @brief       Interface of uart_pkg.
 * @details     Detailed description
 * @note        Notes
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  module_intf
 ****************************************************************************************//** @{ */


#ifndef UART_PKG_H_
#define UART_PKG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef UART_PKG_H_VAR
# define UART_PKG_H_EXT
#else
# define UART_PKG_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Macro group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Variables group
 * @brief       brief description
 * @{ *//*---------------------------------------------------------------------------------------*/
/** @} *//*--------------------------------------------------------------------------------------*/

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Privatne API funkcije
 * @brief       Ovde se nalaze funkcije koje se interno pozivaju iskljucivo od
 *              strane HAL-a.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       UART modul inicijalizacija
 * @details     Vrsi inicijalizaciju UART modula i postavlja ga u neaktivno
 *              stanje.
 *//*--------------------------------------------------------------------------------------------*/
void uartModuleInit(
    void);

/** @} *//*--------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Portabilne API funkcije
 * @brief       Implementacija ovih funkcija se menja u zavisnosti od koriscenog
 *              porta.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       UART driver inicijalizacija
 * @details     Vrsi inicijalizaciju/reset UART hardvera i postavlja ga u
 *              neaktivno stanje.
 *//*--------------------------------------------------------------------------------------------*/
void lldUartDrvInit(
    void);

void lldUartDrvStart(
    esUartDrv_T     * aUart);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of uart_pkg.h
 *************************************************************************************************/
#endif /* UART_PKG_H_ */
