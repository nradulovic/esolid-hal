/*************************************************************************************************
 * This file is part of eSolid
 *
 * Template version: 1.1.15 (20.05.2012)
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
 * @brief       Ucitavanje svih HAL profila
 * @details     Ova datoteka ucitava sve podrzane profile HAL-a.
 * ------------------------------------------------------------------------------------------------
 * @defgroup    port_intf eSolid port interface
 * @brief       Interfejs port sistema.
 * @section     port_doc Portovanje sistema
 * U racunarstvu, portovanje je proces prilagodjavanja softvera, tako da
 * izvrsni program moze biti kreiran za racunarsko okruzenje koje se razlikuje
 * onog za koje je bio prvobitno projektovan (npr. razlicit procesor,
 * operativni sistem, druge biblioteke).
 *
 * Softver je prenosiv kada je trosak portovanja na novu platformu manji od
 * cene pisanja celokupnog softvera.
 *
 * Rec "port" potice od latinske reci @c portare, sto znaci "prenesti".
 *
 * @section     port_levels Port Arhitektura, Varijanta i Platforma
 *
 * Port je organizovan u cetiri nivoa:
 * - Port Arhitektura vrsi apstrakciju osnovne procesorske arhitekture i
 * obuhvata objekte kao sto su opsluzivanje prekida, prebacivanje konteksta,
 * start-up sekvencu i slicno. Klasican predstavnik Port Arhitekture je ARM
 * Cortex-M3 arhitektura. Ovaj port opisuje registre procesora, prekidni
 * kontroler i debug hardver koji je karakteristican za @b svaki mikrokontroler
 * sa ARM Cortex-M3 jezgrom.
 * - Port Familija pokriva opste osobine procesora kao sto su kes memorija,
 * MMU, DMA i FPU. Port Familija je, takodje, zaduzen za memorijske i prekidne
 * kontrolere na samom cipu. a obuhvata tajmere, I/O registre i druge module
 * hardvera na mikrokontroleru.
 * - Port Varijanta predstavlja najprecizniji opis jednog mikrokontrolera jer se
 * u ovom port nivou opisuje koji GPIO portovi postoje, koliko UART, SPI i I2C
 * modula ima u datom kucistu, iznos FLASH i RAM memorije i slicno. Obicno se za
 * arhitekturne varijacije implementacija nalazi u Port Familija, a Port
 * Varijanta pruza samo odgovarajuce pretprocesorske konfiguracione promenljive.
 * - Port Platforma vrsi apstrakciju i opisuje osobine platforme koja se koristi.
 * Pod platformom se podrazumeva mikrokontroler sa dodatnim hardverom. Obicno su
 * to neki oblici razvojnih ploca. Port Platforma u tom slucaju pruza dodatnu
 * abstrakciju hardvera tako da se, na primer, umesto porta navede ime LED diode
 * koja treba da se aktivira.
 *
 * Granice izmedju ova cetiri nivoa nisu uvek jasno definisane, sa obzirom da se
 * funkcionalnost menja izmedju ovih nivoa od port-a do port-a. Uopsteno
 * gledano svaki port se sastoji od modula koji su definisani u nekoliko nivoa.
 ****************************************************************************************//** @{ */


#ifndef PROFILES_H_
#define PROFILES_H_

/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/
/*=================================================================================  SETTINGS  ==*/

/*===============================================================================================*
 * Architecture: ARM Cortex-M3
 *===============================================================================================*/

/*-----------------------------------------------------------------------------------------------*
 * STMicroelectronics - STM32 F1 Mainstream
 *-----------------------------------------------------------------------------------------------*/
#if defined(STM32F100RB)
# define PORT_FOUND_
# include "port/variant/stm32f100rb_profile.h"
# include "port/family/stm32f10x_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*-----------------------------------------------------------------------------------------------*
 * STMicroelectronics - STM32 L1 Ultra Low Power
 *-----------------------------------------------------------------------------------------------*/
#if defined(STM32L152RB)
# define PORT_FOUND_
# include "port/variant/stm32l152rb_profile.h"
# include "port/family/stm32l1xx_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*===============================================================================================*
 * Architecture: ARM Cortex-M4F
 *===============================================================================================*/

/*-----------------------------------------------------------------------------------------------*
 * STMicroelectronics - STM32 F4 Hi-Performance & DSP
 *-----------------------------------------------------------------------------------------------*/
#if defined(STM32F407VG)
# define PORT_FOUND_
# include "port/variant/stm32f407vg_profile.h"
# include "port/family/stm32f4xx_profile.h"
# include "port/arch/arm_cm3_profile.h"
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if !defined(PORT_FOUND_)
# define ES_HAL_MCU_VARIANT             "Unknown MCU series"
# if defined(__GNUC__)
#  warning "HAL Profiles: Cannot determine MCU variant. HAL will be disabled."
# endif
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of profiles.h
 *************************************************************************************************/
#endif /* PROFILES_H_ */
