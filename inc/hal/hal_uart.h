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
 * @author      Dejan Ristic
 * @brief       Interfejs za UART modul.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_intf
 ****************************************************************************************//** @{ */
/**
 * @defgroup    hal_uart UART modul
 * @brief       Rad sa UART modulom
 ****************************************************************************************//** @{ */


#ifndef HAL_USART_H_
#define HAL_USART_H_


/*============================================================================  INCLUDE FILES  ==*/
/*==================================================================================  DEFINES  ==*/

enum esUartMode {
    ES_UART_MODE_TX_AND_RX,
    ES_UART_MODE_TX_ONLY,
    ES_UART_MODE_RX_ONLY,
};

typedef enum esUartError {
    ES_UART_ERR_OVERRUN,
    ES_UART_ERR_FRAMING,
    ES_UART_ERR_NOISE,
    ES_UART_ERR_PARITY,
} esUartError_T;

enum esUartParity {
    ES_UART_PARITY_NONE,
    ES_UART_PARITY_EVEN,
    ES_UART_PARITY_ODD
};

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/

typedef struct uartDrv esUartDrv_T;
typedef struct esUartDrvDef esUartDrvDef_T;

typedef enum esUartStatus {
    ES_UART_INACTIVE,
    ES_UART_ACTIVE,
    ES_UART_READY,
    ES_UART_BUSY,
    ES_UART_ERROR
} esUartStatus_T;

typedef void (* esUartHandler_T) (esUartDrv_T *);
typedef void (* esUartErrHandler_T) (esUartError_T);

struct esUartDrvDef {
    uint32_t        baudrate;
    uint8_t         dataBits;
    uint8_t         stopBits;
/**
 * @brief       Rezim rada UART-a.
 * @details     Postoje tri rezima rada:
 *              - ES_UART_TX_AND_RX - koristi se ceo UART modul,
 *              - ES_UART_TX_ONLY - koristi se samo predajna sekcija UART-a
 *              - ES_UART_RX_ONLY - koristi se samo prijemna sekcija UART-a
 */
    enum esUartMode uartMode;

/**
 * @brief       Funkcija za predaju
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je predat jedan karakter,
 *              - kada je bafer za slanje prazan.
 */
    esUartHandler_T  pTxHandler;

/**
 * @brief       Funkcija za prijem
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je primljen jedan karakter,
 *              - kada je bafer za prijem pun.
 */
    esUartHandler_T  pRxHandler;
    esUartErrHandler_T  pErrorHandler;
};

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/

void esUartStart(
    esUartDrv_T     * aUart,
    const esUartDrvDef_T  * aDefinition);

void esUartStop(
    esUartDrv_T     * aUart);

esUartStatus_T esUartStatus(
    esUartDrv_T     * aUart);

esUartStatus_T esUartTxStatus(
    esUartDrv_T     * aUart);

void esUartTxChar(
    esUartDrv_T     * aUart,
    uint8_t         aData);

void esUartTxBegin(
    esUartDrv_T     * aUart,
    uint8_t         * aBuffer,
    size_t          aSize);

size_t esUartTxEnd(
    esUartDrv_T     * aUart);

esUartStatus_T esUartRxStatus(
    esUartDrv_T     * aUart);

uint8_t esUartRxChar(
    esUartDrv_T     * aUart);

void esUartRxBegin(
    esUartDrv_T     * aUart,
    uint8_t         * aBuffer,
    size_t          aSize);

size_t esUartRxEnd(
    esUartDrv_T     * aUart);

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of port_detect.h
 *//** @} *//*************************************************************************************/
#endif /* HAL_USART_H_ */
