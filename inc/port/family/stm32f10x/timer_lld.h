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
 * @author  	Nenad Radulovic
 * @brief       Interfejs/konfiguracija Timer Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_timer_impl
 ****************************************************************************************//** @{ */


#ifndef TIMER_LLD_H_
#define TIMER_LLD_H_

/*============================================================================  INCLUDE FILES  ==*/
#include "stm32l1xx.h"

/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
struct tmrId;
struct tmrIntr;
struct tmrDef;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upravljacka struktura
 * @details     Ova struktura opisuje koji je identifikator drajvera,
 *              definicionu strukturu i registre.
 *//*--------------------------------------------------------------------------------------------*/
struct tmrDrv {
/**
 * @brief       Pokazivac na identifikacionu strukturu
 */
    struct tmrId        * drvId;

/**
 * @brief       Pokazivac na internu strukturu
 */
    struct tmrIntr      * drvIntr;

/**
 * @brief       Pokazivac na definicionu strukturu
 */
    struct tmrDef       * drvDef;

/**
 * @brief       Pokazivac na registre hardvera
 */
    TIM_TypeDef         * regs;
};

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if defined(ES_ENABLE_TIMER)
# if defined(OPT_HAL_TIMER_USE_1)
#  error "HAL->TIMER: This port does not support Timer 1."
# endif
# if defined(OPT_HAL_TIMER_USE_5)
#  error "HAL->TIMER: This port does not support Timer 5."
# endif
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of timer_lld.h
 *************************************************************************************************/
#endif /* TIMER_LLD_H_ */
