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
#include "compiler.h"
#include "hal_generic.h"

/*===============================================================  DEFINES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Moguce opcije za UART modul
 * @brief       Ove opcije se koriste za popunjavanje definicione strukture
 *              @ref esUartDef.
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
    ES_UART_ERR_OVERRUN,
    ES_UART_ERR_FRAMING,
    ES_UART_ERR_NOISE,
    ES_UART_ERR_PARITY
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

/**@brief       Forward declaration of uart driver structure
 */
typedef struct esUart esUart_T;

/**
 * @brief       Funkcija za opsluzivanje predaje/prijema
 */
typedef size_t (* pUartHandler_T) (uint8_t *, size_t);

/**
 * @brief       Funkcija za opsluzivanje nastalih gresaka
 */
typedef size_t (* pUartErrHandler_T) (esUartError_T);

/**
 * @brief       Definiciona struktura koja konfigurise UART drajver.
 */
struct esUartDef {
/**
 * @brief       Brzina prenosa
 */
    uint32_t            baudrate;

/**
 * @brief       Provera parnosti
 * @details     Moguce vrednosti:
 *              - ES_UART_DATA_7_BITS,
 *              - ES_UART_DATA_8_BITS,
 *              - ES_UART_DATA_9_BITS
 */

    enum esUartParity   parity;
/**
 * @brief       Broj bitova podataka
 * @details     Moguce vrednosti:
 *              - ES_UART_PARITY_NONE,
 *              - ES_UART_PARITY_EVEN,
 *              - ES_UART_PARITY_ODD
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
 *              - Zavisno od porta
 */
	uint8_t             prio;

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

};


/**@brief       Tip definicione strukture
 */
typedef struct esUartDef esUartDef_T;

/*======================================================  GLOBAL VARIABLES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Moguce opcije za UART modul
 * @brief       Ove opcije se koriste za popunjavanje definicione strukture
 *              @ref esUartDef.
 * @{ *//*--------------------------------------------------------------------*/
extern const PORT_C_ROM esUart_T esUartA;
extern const PORT_C_ROM esUart_T esUartB;
extern const PORT_C_ROM esUart_T esUartC;
extern const PORT_C_ROM esUart_T esUartD;
extern const PORT_C_ROM esUart_T esUartE;
extern const PORT_C_ROM esUart_T esUartF;
extern const PORT_C_ROM esUart_T esUartG;
extern const PORT_C_ROM esUart_T esUartH;
/*===================================================  FUNCTION PROTOTYPES  ==*/

/**
 * @brief       Inicijalizacija UART modula i hardvera.
 * @param       uart                    UART koji se konfigurise
 * @param       esUartDef                 pokazivac na definicionu strukturu,
 */
void esUartInit(
    esUart_T        * uart,
    const PORT_C_ROM esUartDef_T * uartDef);

/**
 * @brief       DeInicijalizacija UART modula i hardvera.
 * @param       uart                    UART koji se konfigurise
 * @details     Funkcija postavlja hardver u rezim male potrosnje.
 */
void esUartDeInit(
    esUart_T  *     uart);

/**
 * @brief       Vraca status UART harverskog modula.
 */
esDevStatus_T esUartTxStatus(
    esUart_T *      uart);

void esUartTxChar(
    esUart_T *      uart,
    uint8_t         data);

void esUartTxBegin(
    esUart_T *      uart,
    uint8_t *       buff,
    size_t          buffSize);

size_t esUartTxEnd(
    esUart_T *      uart);

esDevStatus_T esUartRxStatus(
    esUart_T *      uart);

void esUartRxBegin(
    esUart_T *      uart,
    uint8_t *       buff,
    size_t          buffSize);

size_t esUartRxEnd(
    esUart_T *      uart);

/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of hal_uart.h
 ******************************************************************************/
#endif /* HAL_UART_H_ */
