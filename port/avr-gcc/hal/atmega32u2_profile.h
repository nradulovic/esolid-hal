/******************************************************************************
 * This file is part of esolid-hal
 *
 * Template version: 1.1.15 (20.05.2012)
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
 * @author  	Dejan Ristic
 * @brief       Profil za ATmega32u2 mikrokontroler
 * @addtogroup  port_atmega32u2
 *********************************************************************//** @{ */

#ifndef ATMEGA32U2_PROFILE_H_
#define ATMEGA32U2_PROFILE_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------------------------*//**
 * @name        ATmega32u2 opisne konstante
 * @brief       Ovde se nalaze konstante koje daju vise informacija o
 *              mikrokontroleru i periferiji.
 * @{ *//*--------------------------------------------------------------------*/
#define ES_HAL_MCU_NAME                 "ATmega32u2"
#define ES_HAL_MCU_FLASH                32768UL
#define ES_HAL_MCU_RAM                  1024UL

/** @} *//*-------------------------------------------------------------------*/

/**
 * @brief       Definisanje podfamilije
 * @notapi
 */
/*
 * Ovaj define sam koristo da odredim podfamiliju kod STM32. Mozda kod Atmela
 * nije potreban
 */
# define                                PORT_SUBFAM_ATMEGA

/**
 * @brief       Definisanje maksimalne frekvencije taktnog signala
 * @notapi
 */
/*
 * Ovaj define sam koristio za start-up kod. Mozda kod ATmega nije potreban
 */
#define PORT_MAX_CPU_FREQ_              16000000UL

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of atmega32u2_profile.h
 ******************************************************************************/
#endif /* ATMEGA32U2_PROFILE_H_ */
