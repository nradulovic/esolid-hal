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
 * @brief       Konfiguracija HAL-a
 * @addtogroup  hal_cfg
 *********************************************************************//** @{ */

#ifndef HAL_CONFIG_H_
#define HAL_CONFIG_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/* #define STM32L152RB */
#define STM32F100RB

/*==============================================================  SETTINGS  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Podesavanja HAL-a
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Podesavanje brzine rada sistema
 * @details     Postoje tri nivoa brzine rada sistema:
 *              - @ref ES_SYS_SPEED_LOW Minimalna brzina rada, najveca usteda
 *                                      energije
 *              - @ref ES_SYS_SPEED_MEDIUM Srednja brzina rada
 *              - @ref ES_SYS_SPEED_HIGH Maksimalna brzina rada, najmanja usteda
 *                                      energije.
 *
 *              Vrsi postavljanje performansi sistema prema datom profilu.
 *              Funkcije ukljucuju potrebne takt oscilatore, PLL kola,
 *              preskalere, regulatore napajanja i kontrolere magistrala kako bi
 *              se izabrani profil aktivirao.
 *              Podrazumevano podesavanje: ES_SYS_SPEED_LOW
 */
#if !defined(OPT_HAL_SYS_SPEED)
# define OPT_HAL_SYS_SPEED              ES_SYS_SPEED_LOW
#endif

/** @} *//*-------------------------------------------------------------------*/
/*------------------------------------------------------------------------*//**
 * @name        Podesavanja kompajlera
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Ukoliko je ovaj makro definisan HAL nece definisati BOOLean
 *              tipove podataka: TRUE i FALSE
 */
#if defined(__DOXYGEN__)
# define HAL_BOOL_TYPE
#endif

/** @} *//*-------------------------------------------------------------------*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_config.h
 ******************************************************************************/
#endif /* HAL_CONFIG_H_ */
