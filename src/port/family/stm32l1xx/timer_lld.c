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
 * @brief       Implementacija Timer Low Level Driver modula.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  stm32l1xx_md_timer_impl
 * @brief       Timer Low Level Driver modul.
 ****************************************************************************************//** @{ */

/*============================================================================  INCLUDE FILES  ==*/
#define TIMER_LLD_H_VAR
#include "../src/hal/hal_private.h"

#if defined(STM32L1XX_MD_) && defined(ES_ENABLE_TIMER) || defined(__DOXYGEN__)
/*============================================================================  LOCAL DEFINES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Local debug define macro.
 *//*--------------------------------------------------------------------------------------------*/
DBG_DEFINE_MODULE(Timer Low Level Driver);

/*============================================================================  LOCAL MACRO's  ==*/
/*=========================================================================  LOCAL DATA TYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Interni, jedinstveni podaci Timer drajvera.
 * @details     Ova struktura se instacira po jednom tajmeru.
 *//*--------------------------------------------------------------------------------------------*/
typedef struct tmrIntr {
/**
 * @brief       Status Timer drajvera
 */
    esDevStatus_T       status;
} tmrIntr_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Indentifikaciona struktura Timer drajvera
 * @details     Ova struktura sadrzi sve neophodne podatke koji su potrebni za
 *              rad sa jednim tajmerom. Glavni zadatak ove strukture
 *              je da:
 *              - ukljuci i podesi odgovarajuce taktne signale i
 *              - ukljuci kontrolere AHB/APB magistrala.
 *//*--------------------------------------------------------------------------------------------*/
struct tmrId {
/**
 * @brief       Pokazivac na registre hardvera
 */
    TIM_TypeDef         * regs;

/**
 * @brief       Pokazivac na internu strukturu
 */
    struct tmrIntr      * drvIntr;
};

/*================================================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*==========================================================================  LOCAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Interni, jedinstveni podaci Timer drajvera za svaki tajmer.
 * @brief       Struktura se instacira jedna za svaki tajmer.
 * @{ *//*---------------------------------------------------------------------------------------*/
static struct tmrIntr tmr2Intr;
static struct tmrIntr tmr3Intr;
/** @} *//*--------------------------------------------------------------------------------------*/

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Identifikacione strukture Timer modula.
 * @{ *//*---------------------------------------------------------------------------------------*/
const C_ROM struct tmrId esTimer2 = {
    TIM2,
    &tmr2intr,
};

const C_ROM struct tmrId esTimer3 = {
    TIM3,
    &tmr3intr,
};
/** @} *//*--------------------------------------------------------------------------------------*/

/*===============================================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*======================================================  GLOBAL PRIVATE FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void lldTimerDrvInit(
    void) {

#if defined(OPT_HAL_TIMER)
# if defined(OPT_HAL_TIMER_USE_2)

# endif

# if defined(OPT_HAL_TIMER_USE_3)

# endif
#endif /* OPT_HAL_TIMER */
}

/*=======================================================  GLOBAL PUBLIC FUNCTION DEFINITIONS  ==*/
/*-----------------------------------------------------------------------------------------------*/
void esTimerInit(
    const C_ROM esTimerId_T * timerId,
    const C_ROM esTimerDef_T * timerDef,
    esTimerDrv_T    * timer) {

    HAL_DBG_CHECK((const C_ROM esTimerDef_T *)0U != timerDef);                  /* Provera par: mora da se preda definiciona struktura.     */
    HAL_DBG_CHECK(NULL != timer);                                               /* Provera par: da li je timer definisan?                   */
    HAL_DBG_CHECK(TIMER_DRVID_LIST(timerId));                                   /* Provera par: da li je drvId ispravan?                    */
    HAL_DBG_CHECK(
        (ES_TIMER_MODE_ONCE == timerDef->mode) ||
        (ES_TIMER_MODE_PERIODIC == timerDef->mode));                            /* Provera par: da li mode enumerator?                      */

}

/*-----------------------------------------------------------------------------------------------*/
void esTimerDeInit(
    esTimerDrv_T    * timer) {

    HAL_DBG_CHECK(NULL != timer);                                               /* Provera par: da li je timer definisan?                   */
    HAL_DBG_CHECK(TIMER_DRVID_LIST(timer->drvId));                              /* Provera par: da li je drvId ispravan?                    */
}

/*-----------------------------------------------------------------------------------------------*/
esDevStatus_T esTimerStatus(
    esTimerDrv_T    * timer) {

    HAL_DBG_CHECK(NULL != timer);                                               /* Provera par: da li je timer definisan?                   */
    HAL_DBG_CHECK(TIMER_DRVID_LIST(timer->drvId));                              /* Provera par: da li je drvId ispravan?                    */

    return (ES_DEV_BUSY);
}

/*-----------------------------------------------------------------------------------------------*/
uint32_t esTimerStart(
    esTimerDrv_T    * timer) {

    HAL_DBG_CHECK(NULL != timer);                                               /* Provera par: da li je timer definisan?                   */
    HAL_DBG_CHECK(TIMER_DRVID_LIST(timer->drvId));                              /* Provera par: da li je drvId ispravan?                    */

    return (0U);
}

/*-----------------------------------------------------------------------------------------------*/
uint32_t esTimerStop(
    esTimerDrv_T    * timer) {

    HAL_DBG_CHECK(NULL != timer);                                               /* Provera par: da li je timer definisan?                   */
    HAL_DBG_CHECK(TIMER_DRVID_LIST(timer->drvId));                              /* Provera par: da li je drvId ispravan?                    */

    return (0U);
}

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#else /* STM32F10X_MD_VL_ && ES_ENABLE_TIMER */
extern char bogusVar;                                                           /* Neki kompajleri ne prihvataju praznu C datoteku. */
#endif

/** @endcond *//** @} *//*************************************************************************
 * END of timer_lld.c
 *************************************************************************************************/
