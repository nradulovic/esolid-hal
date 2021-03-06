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
 * @author      Nenad Radulovic
 * @brief       Interfejs za UART modul.
 * @addtogroup  hal_uart_intf
 *********************************************************************//** @{ */

#ifndef HAL_USART_H_
#define HAL_USART_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Moguce opcije za UART modul
 * @brief       Ove opcije se koriste za popunjavanje definicione strukture
 *              @ref uartDef.
 * @{ *//*--------------------------------------------------------------------*/

/**
 * @brief       Rezimi rada UART drajvera
 */
enum esUartMode {
    ES_UART_MODE_TX,
    ES_UART_MODE_RX,
    ES_UART_MODE_TX_AND_RX
};

/**
 * @brief       Moguci izbor parnosti.
 */
enum esUartParity {
    ES_UART_PARITY_NONE,
    ES_UART_PARITY_EVEN,
    ES_UART_PARITY_ODD
};

/**
 * @brief       Moguci izbor broja bitova podataka.
 */
enum esUartDataBits {
    ES_UART_DATA_7_BITS,
    ES_UART_DATA_8_BITS,
    ES_UART_DATA_9_BITS
};

/**
 * @brief       Moguci izbor stop bitova.
 */
enum esUartStopBit {
    ES_UART_STOP_HALF_BIT,
    ES_UART_STOP_ONE_BIT,
    ES_UART_STOP_ONE_AND_HALF_BIT,
    ES_UART_STOP_TWO_BITS
};

/** @} *//*-------------------------------------------------------------------*/

/**
 * @brief       Moguce greske koje UART drajver moze da detektuje
 */
enum esUartError {
    ES_UART_ERR_OVERRUN,//!< ES_UART_ERR_OVERRUN
    ES_UART_ERR_FRAMING,//!< ES_UART_ERR_FRAMING
    ES_UART_ERR_NOISE,  //!< ES_UART_ERR_NOISE
    ES_UART_ERR_PARITY, //!< ES_UART_ERR_PARITY
};

/*===============================================================  MACRO's  ==*/
/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

/**
 * @brief       Moguce greske koje UART drajver detektuje
 */
typedef enum esUartError esUartError_T;

/**
 * @brief       Funkcija za opsluzivanje predaje/prijema
 */
typedef void (* pUartHandler_T) (uint8_t *, size_t);

/**
 * @brief       Funkcija za opsluzivanje nastalih gresaka
 */
typedef void (* pUartErrHandler_T) (esUartError_T);

/**
 * @brief       Definiciona struktura koja konfigurise UART drajver.
 */
typedef struct uartDef {
/**
 * @brief       Brzina prenosa
 */
    uint32_t            baudrate;

/**
 * @brief       Broj bitova podataka
 * @details     Moguce vrednosti:
 *              - ES_UART_DATA_7_BITS,
 *              - ES_UART_DATA_8_BITS,
 *              - ES_UART_DATA_9_BITS
 */
    enum esUartDataBits dataBits;

/**
 * @brief       Broj stop bitova
 * @details     Moguce vrednosti:
 *              - ES_UART_STOP_HALF_BIT,
 *              - ES_UART_STOP_ONE_BIT,
 *              - ES_UART_STOP_ONE_AND_HALF_BIT,
 *              - ES_UART_STOP_TWO_BITS
 */
    enum esUartStopBit  stopBits;

/**
 * @brief       Rezim rada UART-a.
 * @details     Postoje tri rezima rada:
 *              - ES_UART_TX_AND_RX - koristi se ceo UART modul,
 *              - ES_UART_TX_ONLY - koristi se samo predajna sekcija UART-a
 *              - ES_UART_RX_ONLY - koristi se samo prijemna sekcija UART-a
 */
    enum esUartMode     mode;

/**
 * @brief       Prioritet funkcija za prijem/predaju/resavanje gresaka.
 * @details     Sve funkcije se izvrsavaju u prekidnoj rutini koja poseduje
 *              @c prio prioritet.
 *
 *              Moguce vrednosti:
 *              - ES_PRIO_IDLE,
 *              - ES_PRIO_VERY_LOW,
 *              - ES_PRIO_LOW,
 *              - ES_PRIO_BELOW_NORMAL,
 *              - ES_PRIO_NORMAL,
 *              - ES_PRIO_ABOVE_NORMAL,
 *              - ES_PRIO_HIGH,
 *              - ES_PRIO_VERY_HIGH,
 *              - ES_PRIO_REALTIME
 */
    enum esHandlerPrio  prio;

/**
 * @brief       Funkcija za predaju
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je predat jedan karakter,
 *              - kada je bafer za slanje prazan.
 */
    pUartHandler_T      pTxHandler;

/**
 * @brief       Funkcija za prijem
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je primljen jedan karakter,
 *              - kada je bafer za prijem pun.
 */
    pUartHandler_T      pRxHandler;

/**
 * @brief       Funkcija za resavanje gresaka
 * @details     Ova funkcija se poziva ukoliko je detektovana neka od gresaka.
 */
    pUartErrHandler_T   pErrorHandler;
} esUartDef_T;

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Inicijalizacija UART modula i hardvera.
 * @param       uart                    UART koji se konfigurise
 * @param       uartDef                 pokazivac na definicionu strukturu,
 */
void esUartInit(
    esUart_T        uart
    const C_ROM esUartDef_T * uartDef);

/**
 * @brief       DeInicijalizacija UART modula i hardvera.
 * @param       uart                    UART koji se konfigurise
 * @details     Funkcija postavlja hardver u rezim male potrosnje.
 */
void esUartDeInit(
    esUart_T        uart);

/**
 * @brief       Vraca status UART harverskog modula.
 */
esDevStatus_T esUartStatus(
    esUart_T        uart);

esDevStatus_T esUartStatus(
    esUartDrv_T     * uart);

void esUartTxChar(
    esUartDrv_T     * aUart,
    uint8_t         aData);

void esUartTxBegin(
    esUartDrv_T     * aUart,
    uint8_t         * aBuffer,
    size_t          aSize);

size_t esUartTxEnd(
    esUartDrv_T     * aUart);

esDevStatus_T esUartRxStatus(
    esUartDrv_T     * aUart);

void esUartRxBegin(
    esUartDrv_T     * aUart,
    uint8_t         * aBuffer,
    size_t          aSize);

size_t esUartRxEnd(
    esUartDrv_T     * aUart);

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_uart.h
 ******************************************************************************/
#endif /* HAL_UART_H_ */
