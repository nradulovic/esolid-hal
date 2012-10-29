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
 * @brief       Makroi za nivoe dogadjaja koji se unose u dnevnik
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  log_intf
 * @brief		Makroi za nivoe dogadjaja koji se unose u dnevnik
 ****************************************************************************************//** @{ */


#ifndef HAL_LOG_LEVELS_H_
#define HAL_LOG_LEVELS_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Nivo obelezavanja dogadjaja u dnevnik
 * @details     Aplikacija moze da ima nekoliko nivoa obelezavanja u dnevnik u
 *              zavisnosti od znacaja/ozbiljnosti dogadjaja. Postoje sledeci
 *              predefinisani nivoi znacaja dogadjaja.
 *
 *              Aplikacija moze da odluci koji nivoi znacaja dogadjaja ce se
 *              ubacivati u dnevnik. Na primer, ukoliko izvorni kod poseduje
 *              sve navedene nivoe znacaja, a zeljeni nivo je postavljen na
 *              nivo ES_LOG_LEVEL_WARN, onda se u dnevniku pojavljuju samo
 *              poruke sa nivoom jednakim ili vecim od nivoa ES_LOG_LEVEL_WARN.
 *              Poruke sa nizim nivoom se za vreme kompajliranja pretvaraju u
 *              prazne makroe.
 * @{ *//*---------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Kriticne greske koje dovode do toga da se aplikacija zaustavi.
 *//*--------------------------------------------------------------------------------------------*/
#define ES_LOG_LEVEL_FATAL              5U

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Greske za vreme izvrsavanja aplikacije, ali aplikacija moze da
 *              nastavi sa izvrsavanjem.
 *//*--------------------------------------------------------------------------------------------*/
#define ES_LOG_LEVEL_ERROR              4U

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upozorenja
 *//*--------------------------------------------------------------------------------------------*/
#define ES_LOG_LEVEL_WARN               3U

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Informativne poruke
 *//*--------------------------------------------------------------------------------------------*/
#define ES_LOG_LEVEL_INFO               2U

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Debug poruke
 *//*--------------------------------------------------------------------------------------------*/
#define ES_LOG_LEVEL_DEBUG              1U

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Poruke sa finim detaljima
 *//*--------------------------------------------------------------------------------------------*/
#define ES_LOG_LEVEL_TRACE              0U

/** @} *//*--------------------------------------------------------------------------------------*/
/*==================================================================================  MACRO's  ==*/
/*===============================================================================  DATA TYPES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of hal_log_levels.h
 *************************************************************************************************/
#endif /* HAL_LOG_LEVELS_H_ */
