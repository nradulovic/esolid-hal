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
 * @brief       Implementacija UART modula
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_uart_impl
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#include "hal_private.h"

#if defined(ES_ENABLE_UART) || defined(__DOXYGEN__)
/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_DEFINE_MODULE(HAL UART module);

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRVID_LIST(aUart));

    esDevStatus_T status;

    if (NULL == aUart->drvDef) {
        status = ES_DEV_INACTIVE;
    } else {
        status = ES_DEV_READY;
    }

    return (status);
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartRxStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRVID_LIST(aUart));

    return (aUart->rxStatus);
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartTxStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRVID_LIST(aUart));

    return (aUart->txStatus);
}

/*-----------------------------------------------------------------------------------------------*/
void esUartInit(
    const C_ROM esUartId_T * uartId,
    const C_ROM esUartDef_T * uartDef,
    esUartDrv_T     * uart) {

    HAL_DBG_CHECK(UART_DRVID_LIST(uart));
    HAL_DBG_CHECK((const C_ROM esUartDef_T *)0U != uartDef);
    aUart->drvDef = aDefinition;
    aUart->txStatus = ES_DEV_INACTIVE;
    aUart->rxStatus = ES_DEV_INACTIVE;
    lldUartDrvStart(
        aUart);
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#else /* ES_ENABLE_UART */
extern char bogusVar;                                                           /* Neki kompajleri ne prihvataju praznu C datoteku. */
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of uart.c
 *************************************************************************************************/
