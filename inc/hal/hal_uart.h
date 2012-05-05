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
 * @addtogroup  hal_uart
 * @brief       Upravljanje UART hardverskog modula.
 ****************************************************************************************//** @{ */


#ifndef HAL_USART_H_
#define HAL_USART_H_


/*============================================================================  INCLUDE FILES  ==*/
#include PORT_VARIANT_HEADER(uart_lld)

/*==================================================================================  DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Moguce opcije za UART modul
 * @brief       Ove opcije se koriste za popunjavanje definicione strukture
 *              @ref uartDef.
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Rezimi rada UART drajvera
 *//*--------------------------------------------------------------------------------------------*/
enum esUartMode {
    ES_UART_MODE_TX,
    ES_UART_MODE_RX,
    ES_UART_MODE_TX_AND_RX
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
 * @brief       Moguci izbor broja bitova podataka.
 *//*--------------------------------------------------------------------------------------------*/
enum esUartDataBits {
    ES_UART_DATA_7_BITS,
    ES_UART_DATA_8_BITS,
    ES_UART_DATA_9_BITS
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

/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Moguce greske koje UART drajver detektuje
 *//*--------------------------------------------------------------------------------------------*/
enum esUartError {
    ES_UART_ERR_OVERRUN,
    ES_UART_ERR_FRAMING,
    ES_UART_ERR_NOISE,
    ES_UART_ERR_PARITY,
};

/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Moguce greske koje UART drajver detektuje
 *//*--------------------------------------------------------------------------------------------*/
typedef enum esUartError esUartError_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Funkcija za opsluzivanje predaje/prijema
 *//*--------------------------------------------------------------------------------------------*/
typedef void (* pUartHandler_T) (uint8_t *, size_t);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Funkcija za opsluzivanje nastalih gresaka
 *//*--------------------------------------------------------------------------------------------*/
typedef void (* pUartErrHandler_T) (esUartError_T);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura koja konfigurise UART drajver.
 *//*--------------------------------------------------------------------------------------------*/
struct uartDef {
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
 * @details
 */
    enum esUartStopBit  stopBits;

/**
 * @brief       Rezim rada UART-a.
 * @details     Postoje tri rezima rada:
 *              - ES_UART_TX_AND_RX - koristi se ceo UART modul,
 *              - ES_UART_TX_ONLY - koristi se samo predajna sekcija UART-a
 *              - ES_UART_RX_ONLY - koristi se samo prijemna sekcija UART-a
 */
    enum esUartMode     uartMode;

/**
 * @brief       Funkcija za predaju
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je predat jedan karakter,
 *              - kada je bafer za slanje prazan.
 */
    pUartHandler_T     pTxHandler;

/**
 * @brief       Funkcija za prijem
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je primljen jedan karakter,
 *              - kada je bafer za prijem pun.
 */
    pUartHandler_T     pRxHandler;

/**
 * @brief       Funkcija za resavanje gresaka
 * @details     Ova funkcija se poziva ukoliko je detektovana neka od gresaka.
 */
    pUartErrHandler_T  pErrorHandler;
};

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura UART drajvera.
 * @details     Preko ove strukture UART drajver se spaja sa zeljenim UART
 *              modulom. Ove strukture su definisane interno i njima se ne
 *              pristupa direktno od strane korisnika vec se samo koriste kao
 *              argument funkcije za inicijalizaciju.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct uartId esUartId_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Upravljacka struktura UART drajvera
 * @details     Struktura se koristi za cuvanje informacija koji UART modul se
 *              koristi, status UART modula i za brz pristup registrima. Da bi
 *              se UART drajver koristio mora da se najpre ova struktura
 *              instancira.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct uartDrv esUartDrv_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definiciona struktura UART drajvera.
 * @details     Struktura se koristi da se na lak nacin funkciji za
 *              inicijalizaciju preda opis UART drajvera. Jedna definiciona
 *              struktura se moze koristi za inicijalizaciju vise UART modula.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct uartDef esUartDef_T;

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione strukture UART modula
 * @brief       Koriste se prilikom inicijalizacije UART hardverskog modula
 * @details     Prilikom inicijalizacije dovoljno je navesti ime zeljenog UART
 *              hardverskog modula.
 * @see         esUartInit()
 * @{ *//*---------------------------------------------------------------------------------------*/

#if defined(OPT_HAL_UART) || defined(__DOXYGEN__)
# if defined(OPT_HAL_UART_USE_1) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura za UART 1.
 *//*--------------------------------------------------------------------------------------------*/
extern const C_ROM struct uartId esUART1;
# endif

# if defined(OPT_HAL_UART_USE_2) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura za UART 2.
 *//*--------------------------------------------------------------------------------------------*/
extern const C_ROM struct uartId esUART2;
# endif

# if defined(OPT_HAL_UART_USE_3) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Identifikaciona struktura za UART 3.
 *//*--------------------------------------------------------------------------------------------*/
extern const C_ROM struct uartId esUART3;
# endif
#endif /* OPT_HAL_UART */

/** @} *//*--------------------------------------------------------------------------------------*/

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Inicijalizacija UART modula i hardvera.
 * @param       uartId                  Pokazivac na identifikacionu strukturu,
 * @param       uartDef                 pokazivac na definicionu strukturu,
 * @param       uart                    pokazivac na upravljacku struktura.
 *//*--------------------------------------------------------------------------------------------*/
void esUartInit(
    const C_ROM esUartId_T * uartId,
    const C_ROM esUartDef_T * uartDef,
    esUartDrv_T     * uart);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       DeInicijalizacija UART modula i hardvera.
 * @param       aUart                   Pokazivac na strukturu UART drajvera.
 * @details     Funkcija postavlja hardver u rezim male potrosnje.
 *//*--------------------------------------------------------------------------------------------*/
void esUartDeInit(
    esUartDrv_T     * uart);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vraca status UART harverskog modula.
 *//*--------------------------------------------------------------------------------------------*/
esDevStatus_T esUartStatus(
    esUartDrv_T     * uart);

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

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if !defined(OPT_HAL_GPIO) && defined(OPT_HAL_UART)
# error "HAL=>UART: You must enable OPT_HAL_GPIO option to manage the UART pins."
#else
# if defined(OPT_HAL_UART)
#  if defined(OPT_HAL_UART_USE_1)
#   if !defined(OPT_HAL_GPIO_USE_A)
#    error "HAL=>UART: You must enable OPT_HAL_GPIO_USE_A option to manage UART1 pins"
#   endif
#  endif
#  if defined(OPT_HAL_UART_USE_2)
#   if !defined(OPT_HAL_GPIO_USE_A)
#    error "HAL=>UART: You must enable OPT_HAL_GPIO_USE_A option to manage UART2 pins"
#   endif
#  endif
#  if defined(OPT_HAL_UART_USE_3)
#   if !defined(OPT_HAL_GPIO_USE_A)
#    error "HAL=>UART: You must enable OPT_HAL_GPIO_USE_B option to manage UART3 pins"
#   endif
#  endif
#  if defined(OPT_HAL_UART_USE_4)
#   error "HAL=>UART: This port does not support OPT_HAL_UART_USE_4"
#  endif
# endif
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of port_detect.h
 *************************************************************************************************/
#endif /* HAL_USART_H_ */
