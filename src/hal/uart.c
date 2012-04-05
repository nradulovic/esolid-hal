/*************************************************************************************************
 * This file is part of eSolid
 *
 * Template version: 1.1.10 (24.03.2012)
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
 * @addtogroup  uart_impl
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#include "uart_pkg.h"

/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
DBG_DEFINE_MODULE(regs);

#define UART_DRV_LIST(uart)                                                     \
    (DBG_VALID_UART1_DRV(uart) ||                                               \
     DBG_VALID_UART2_DRV(uart) ||                                               \
     DBG_VALID_UART3_DRV(uart))

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void uartModuleInit(void) {

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
    esUART1->drvDef = (esUartDrvDef_T *)0U;
    esUART1->txStatus = ES_UART_INACTIVE;
    esUART1->rxStatus = ES_UART_INACTIVE;
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
    esUART2->drvDef = (esUartDrvDef_T *)0U;
    esUART2->txStatus = ES_UART_INACTIVE;
    esUART2->rxStatus = ES_UART_INACTIVE;
#endif

#if defined(OPT_HAL_UART) && defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
    esUART3->drvDef = (esUartDrvDef_T *)0U;
    esUART3->txStatus = ES_UART_INACTIVE;
    esUART3->rxStatus = ES_UART_INACTIVE;
#endif
    lldUartDrvInit();
}

/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
esUartStatus_T esUartStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));

    esUartStatus_T status;

    if ((esUartDrvDef_T *)0U == aUart->drvDef) {
        status = ES_UART_INACTIVE;
    } else {
        status = ES_UART_ACTIVE;
    }

    return (status);
}

/*-----------------------------------------------------------------------------------------------*/
esUartStatus_T esUartRxStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));

    return (aUart->rxStatus);
}

/*-----------------------------------------------------------------------------------------------*/
esUartStatus_T esUartTxStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));

    return (aUart->txStatus);
}

/*-----------------------------------------------------------------------------------------------*/
void esUartStart(
    esUartDrv_T     * aUart,
    const C_ROM esUartDrvDef_T  * aDefinition) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));
    HAL_DBG_CHECK((const C_ROM esUartDrvDef_T *)0U != aDefinition);
    aUart->drvDef = aDefinition;
    aUart->txStatus = ES_UART_INACTIVE;
    aUart->rxStatus = ES_UART_INACTIVE;
    lldUartDrvStart(
        aUart);
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of regs.c
 *************************************************************************************************/
