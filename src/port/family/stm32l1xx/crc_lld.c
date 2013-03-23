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
 * @brief       Implementacija CRC Low Level Driver modula.
 * @addtogroup  port_stm32l1xx
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#define CRC_LLD_H_VAR
#include "../src/hal/hal_private.h"

#if defined(STM32L1XX_MD_) && defined(ES_ENABLE_CRC) || defined(__DOXYGEN__)
/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_DEFINE_MODULE(HAL crc modul);

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*=========================================================================  GLOBAL VARIABLES  ==*/
/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void lldCrcDrvInit(
    void) {

    RCC->AHBRSTR |= RCC_AHBRSTR_CRCRST;
    RCC->AHBRSTR &= ~RCC_AHBRSTR_CRCRST;
    CRC->CR |= CRC_CR_RESET;
    RCC->AHBENR &= ~RCC_AHBENR_CRCEN;
}

/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
uint32_t esCrc32(
    uint8_t             * pDataBlk,
    size_t              blkSize) {

    size_t cntr;
    size_t cnt;
    volatile uint32_t data;
    uint32_t * pWord;

    HAL_DBG_CHECK(NULL != pDataBlk);                                            /* Provera par: da li je pDataBlk validan?                  */
    HAL_DBG_CHECK((size_t)0U != blkSize);                                       /* Provera par: blok podataka ne sme da bude prazan.        */
    RCC->AHBENR |= RCC_AHBENR_CRCEN;
    CRC->CR |= CRC_CR_RESET;
    pWord = (uint32_t *)pDataBlk;
    cnt = blkSize >> 2U;

    if ((size_t)0U != cnt) {

        for (cntr = (size_t)0U; cntr < cnt; cntr++) {
            CRC->DR = *pWord++;
        }
    }
    cnt = blkSize & (size_t)3U;

    if ((size_t)0U != cnt) {

        if ((size_t)1U == cnt) {
            CRC->DR = *((uint8_t *)pWord);
        } else if ((size_t)2U == cnt) {
            CRC->DR = *((uint16_t *)pWord);
        } else {
            CRC->DR = *pWord & (uint32_t)(0x00FFFFFF);
        }
    }
    data = CRC->DR;
    RCC->AHBENR &= ~RCC_AHBENR_CRCEN;

    return (data);
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#else /* STM32F10X_MD_VL_ && ES_ENABLE_CRC */
extern char bogusVar;                                                           /* Neki kompajleri ne prihvataju praznu C datoteku. */
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of crc_lld.c
 *************************************************************************************************/
