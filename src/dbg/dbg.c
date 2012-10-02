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
 * @author      Nenad Radulovic
 * @brief       Implementacija podrske za Debug modul
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  dbg_impl
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#include "dbg/dbg.h"

#if defined(OPT_DBG) || defined(__DOXYGEN__)
/*============================================================================  LOCAL DEFINES  ==*/
/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/

/*-----------------------------------------------------------------------------------------------*/
void esDbgCheckFailed (
    const char          * moduleName,
    const char          * fileName,
    const char          * functionName,
    const char          * expression,
    uint16_t            lineNum) {

    esDbgMessage_T check;

    check.object.name = "DBG_CHECK";
    check.object.desc = "debug macro that validates functions parameters";
    check.object.type = "DBG module macro";
    check.source.module = moduleName;
    check.source.file = fileName;
    check.source.func = functionName;
    check.source.line = lineNum;
    check.text.brief = "Function parameter validation failed";
    check.text.format = "Parameter failed to validate expression: %s";
    check.text.variables = expression;
    check.text.type = ES_DBG_MSG_ERROR;
    check.level = 0U;
    check.timestamp = HAL_SYSTICK_GET_TICK();
    esDbgSendMessage (
        &check);
}

/*-----------------------------------------------------------------------------------------------*/
void esDbgAssertFailed (
    const char          * moduleName,
    const char          * fileName,
    const char          * expression,
    uint16_t            lineNum) {

    esDbgMessage_T assert;

    assert.object.name = "DBG_ASSERT";
    assert.object.desc = "debug macro that is executing internal checks";
    assert.object.type = "DBG module macro";
    assert.source.module = moduleName;
    assert.source.file = fileName;
    assert.source.func = DBG_THIS_FUNC;
    assert.source.line = lineNum;
    assert.text.brief = "Function internal check failed";
    assert.text.format = "Expression failed to validate: %s";
    assert.text.variables = expression;
    assert.text.type = ES_DBG_MSG_ERROR;
    assert.level = 0U;
    assert.timestamp = HAL_SYSTICK_GET_TICK();
    esDbgSendMessage (
        &assert);
}

/*-----------------------------------------------------------------------------------------------*/
void esDbgSendMessage (
    esDbgMessage_T      * message) {

    /**
     * TODO: napisati ovu f-ju
     */
    (void)message;
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#else /* OPT_DBG */
extern char bogusVar;                                                           /* Neki kompajleri ne prihvataju praznu C datoteku. */
#endif


/** @endcond *//** @} *//*************************************************************************
 * END of dbg.c
 *************************************************************************************************/
