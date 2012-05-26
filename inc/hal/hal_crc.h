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
 * @brief       Interfejs za CRC modul
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_crc
 * @brief		Izracunavanje CRC (Cyclic Redundancy Check) koda za detekciju gresaka
 ****************************************************************************************//** @{ */


#ifndef HAL_CRC_H_
#define HAL_CRC_H_

/*
 * NOTE: Svojstvo odredjuje hardverski profil varijante.
 */
#if defined(ES_FEATURE_CRC) || defined(__DOXYGEN__)
/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije za generisanje 16-bitniog CRC koda
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Generise 16-bitni CRC kod za ulazni blok @c dataBlk, sa
 *              inicijalnom vrednoscu @c initCrc.
 * @param       dataBlk                 Ulazni blok podataka,
 * @param       blkSize                 velicina bloka podataka,
 * @param       initCrc                 inicijalna vrednost CRC koda. Koristi se
 *                                      u slucaju kada je potrebno generisati
 *                                      CRC kod za nekoliko sukcesivnih blokova
 *                                      podataka. U suprotnom ova vrednost treba
 *                                      da je jednaka nuli.
 * @return      CRC kod za predati blok podataka.
 *//*--------------------------------------------------------------------------------------------*/
uint16_t esCrc16(
    uint8_t             * dataBlk,
    size_t              blkSize,
    uint16_t            initCrc);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_crc.h
 *************************************************************************************************/
#endif /* ES_FEATURE_CRC */
#endif /* HAL_CRC_H_ */
