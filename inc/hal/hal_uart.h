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
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/

typedef struct uartDrvState uartDrvState_T;
typedef struct uartDrvDef uartDrvDef_T;

typedef void (* uartCallback_T) (uartDrvDef_T *);

typedef enum esUARTMode {
    UART_TX_ENABLE,
    UART_RX_ENABLE
} esUARTMode_T;

struct esUARTDrvDef {
    uint32_t        baudrate;
    esUARTMode_T    mode;
/**
 * @brief       Funkcija za predaju
 * @details     U zavisnosti od konfiguracije drajvera, ova funkcija se poziva:
 *              - kada je primljen jedan karakter,
 *              - kada je bafer za prijem pun.
 */
    uartCallback_T  pTransmist;
    uartCallback_T  pReceive;
    uartCallback_T  pError;
    uint8_t         * buff;
    size_t          buffSize;
};

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*======================================================================  FUNCTION PROTOTYPES  ==*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       UART driver inicijalizacija
 * @details     Vrsi inicijalizaciju UART hardvera i postavlja ga u neaktivno
 *              stanje.
 *//*--------------------------------------------------------------------------------------------*/
void uartModuleInit(
    void);


/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

/** @endcond *//** @} *//*************************************************************************
 * END of port_detect.h
 *//** @} *//*************************************************************************************/
#endif /* HAL_USART_H_ */
