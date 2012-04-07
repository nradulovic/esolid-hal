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
 * @brief       Interfejs za UART modul.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_intf
 ****************************************************************************************//** @{ */


#ifndef HAL_USART_H_
#define HAL_USART_H_


/*============================================================================  INCLUDE FILES  ==*/
#include PORT_VARIANT_HEADER(uart_lld)

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Rezimi rada UART drajvera
 *//*--------------------------------------------------------------------------------------------*/
enum esUartMode {
    ES_UART_MODE_TX_AND_RX,
    ES_UART_MODE_TX_ONLY,
    ES_UART_MODE_RX_ONLY,
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Moguce greske koje UART drajver detektuje
 *//*--------------------------------------------------------------------------------------------*/
enum esUartError {
    ES_UART_ERR_OVERRUN,
    ES_UART_ERR_FRAMING,
    ES_UART_ERR_NOISE,
    ES_UART_ERR_PARITY,
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Moguci izbor parnosti.
 *//*--------------------------------------------------------------------------------------------*/
enum esUartParity {
    ES_UART_PARITY_NONE,
    ES_UART_PARITY_EVEN,
    ES_UART_PARITY_ODD
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Moguci izbor stop bitova.
 *//*--------------------------------------------------------------------------------------------*/
enum esUartStopBit {
    ES_UART_STOP_HALF_BIT,
    ES_UART_STOP_ONE_BIT,
    ES_UART_STOP_ONE_AND_HALF_BIT,
    ES_UART_STOP_TWO_BITS
};

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
typedef enum esUartError esUartError_T;
typedef void (* esUartHandler_T) (uint8_t *, size_t);
typedef void (* esUartErrHandler_T) (esUartError_T);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura koja konfigurise UART drajver.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esUartDrvDef {
/**
 * @brief       Brzina prenosa
 */
    uint32_t        baudrate;

/**
 * @brief       Broj bitova podataka
 */
    uint8_t         dataBits;

/**
 * @brief       Broj stop bitova
 */
    enum esUartStopBit stopBits;

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

/**
 * @brief       Funkcija za resavanje gresaka
 * @details     Ova funkcija se poziva ukoliko je detektovana neka od gresaka.
 */
    esUartErrHandler_T  pErrorHandler;
} esUartDrvDef_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Kontrolna struktura drajvera
 * @details     Ova struktura se instacira za svaki drajver koji se koristi.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esUartDrv {
    uartDrvIntr_T       driver;
    esUartDrvDef_T  * drvDef;
    esDevStatus_T   txStatus;
    esDevStatus_T   rxStatus;
} esUartDrv_T;

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizacija UART modula i hardvera.
 * @param       aInstance               Pokazivac na strukturu UART drajvera,
 * @param       aDefinition             definiciona struktura za drajver,
 * @param       aUartId                 identifikator UART hardverskog modula.
 *//*--------------------------------------------------------------------------------------------*/
void esUartInit(
    esUartDrv_T     * aInstance,
    const esUartDrvDef_T  * aDefinition,
    esUartHwId_T    * aUartId);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       DeInicijalizacija UART modula i hardvera.
 * @param       aUart                   Pokazivac na strukturu UART drajvera.
 * @details     Funkcija postavlja hardver u rezim male potrosnje.
 *//*--------------------------------------------------------------------------------------------*/
void esUartDeInit(
    esUartDrv_T     * aInstance);

esDevStatus_T esUartStatus(
    esUartDrv_T     * aInstance);

esDevStatus_T esUartTxStatus(
    esUartDrv_T     * aInstance);

void esUartTxChar(
    esUartDrv_T     * aInstance,
    uint8_t         aData);

void esUartTxBegin(
    esUartDrv_T     * aInstance,
    uint8_t         * aBuffer,
    size_t          aSize);

size_t esUartTxEnd(
    esUartDrv_T     * aInstance);

esDevStatus_T esUartRxStatus(
    esUartDrv_T     * aInstance);

uint8_t esUartRxChar(
    esUartDrv_T     * aInstance);

void esUartRxBegin(
    esUartDrv_T     * aInstance,
    uint8_t         * aBuffer,
    size_t          aSize);

size_t esUartRxEnd(
    esUartDrv_T     * aInstance);

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of port_detect.h
 *************************************************************************************************/
#endif /* HAL_USART_H_ */
