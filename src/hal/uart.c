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
#include "hal_private.h"

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
/*-----------------------------------------------------------------------------------------------*/
void uartModuleInit(void) {

#if defined(OPT_HAL_UART)
# if defined(OPT_HAL_UART_USE_1)
    esUART1->drvDef = NULL;
    esUART1->txStatus = ES_DEV_INACTIVE;
    esUART1->rxStatus = ES_DEV_INACTIVE;
# endif

# if defined(OPT_HAL_UART_USE_2)
    esUART2->drvDef = NULL;
    esUART2->txStatus = ES_DEV_INACTIVE;
    esUART2->rxStatus = ES_DEV_INACTIVE;
# endif

# if defined(OPT_HAL_UART_USE_3)
    esUART3->drvDef = NULL;
    esUART3->txStatus = ES_DEV_INACTIVE;
    esUART3->rxStatus = ES_DEV_INACTIVE;
# endif
    lldUartDrvInit();
#endif /* OPT_HAL_UART */
}

/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));

    esDevStatus_T status;

    if (NULL == aUart->drvDef) {
        status = ES_DEV_INACTIVE;
    } else {
        status = ES_DEV_ACTIVE;
    }

    return (status);
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartRxStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));

    return (aUart->rxStatus);
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esUartTxStatus(
    esUartDrv_T     * aUart) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));

    return (aUart->txStatus);
}

/*-----------------------------------------------------------------------------------------------*/
void esUartInit(
    esUartDrv_T     * aUart,
    const C_ROM esUartDrvDef_T  * aDefinition) {

    HAL_DBG_CHECK(UART_DRV_LIST(aUart));
    HAL_DBG_CHECK((const C_ROM esUartDrvDef_T *)0U != aDefinition);
    aUart->drvDef = aDefinition;
    aUart->txStatus = ES_DEV_INACTIVE;
    aUart->rxStatus = ES_DEV_INACTIVE;
    lldUartDrvStart(
        aUart);
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of uart.c
 *************************************************************************************************/
