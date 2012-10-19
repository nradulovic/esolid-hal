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
 * @author  	Nenad Radulovic
 * @brief       Interfejs modula za podrsku debagiranja.
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_dbg
 * @brief		Interfejs modula za podrsku debagiranja.
 ****************************************************************************************//** @{ */


#ifndef HAL_DBG_H_
#define HAL_DBG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef HAL_DBG_H_VAR
# define HAL_DBG_H_EXT
#else
# define HAL_DBG_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Makroi bez dejstva
 * @brief       Ovi makroi se koriste kao zamena za neaktivne debug makroe.
 * @details     Njihova uloga je da sprece upozorenja za vreme kompajliranja.
 * @{ *//*---------------------------------------------------------------------------------------*/
#define ES_DBG_EMPTY_DECL()                                                     \
    extern C_UNUSED_VAR(uint8_t, ES_CONCAT(dbgVar, __LINE__))

#define ES_DBG_EMPTY_MACRO()                (void)0

/** @} *//*--------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje imena modula.
 * @param       moduleName              Ime modula koji se definise.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) || defined(__DOXYGEN__)
# define ES_DBG_DEFINE_MODULE(moduleName)                                       \
    static const C_ROM char * const C_ROM_VAR DBG_THIS_FILE = __FILE__;         \
    static const C_ROM char * const C_ROM_VAR DBG_THIS_MODULE = ES_STRING(moduleName)
#else
# define ES_DBG_DEFINE_MODULE(moduleName)                                       \
    extern C_UNUSED_VAR(uint8_t, unusedDefineModule)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vrsi proveru da li su argumenti predati funkciji ispravni
 * @mseffect
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) && defined(OPT_HAL_ES_DBG_CHECK) || defined(__DOXYGEN__)
# if defined(__GNUC__)
#  define ES_DBG_CHECK(expr)                                                    \
    ((expr) ? (void)0 : esDbgCheckFailed(DBG_THIS_MODULE, DBG_THIS_FILE, __func__, ES_STRING(expr), (uint16_t)__LINE__))
# else
static const C_ROM char * const C_ROM_VAR DBG_THIS_FUNC = "Unknown function";
#  define ES_DBG_CHECK(expr)                                                    \
    ((expr) ? (void)0 : esDbgCheckFailed(DBG_THIS_MODULE, DBG_THIS_FILE, DBG_THIS_FUNC, ES_STRING(expr), (uint16_t)__LINE__))
# endif
#else
# define ES_DBG_CHECK(expr)                (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izvrsava akcije ASSERT makroa.
 * @param       expr                    Izraz/uslov koji treba da bude istinit.
 * @details     Ukoliko uslov @c expr nije istinit poziva se @c extern funkcija
 *              @c dbgAssertFailed koja stampa mesto nastanka greske.
 * @mseffect
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) && defined(OPT_HAL_ES_DBG_ASSERT) || defined(__DOXYGEN__)
# define ES_DBG_ASSERT(expr)                                                    \
    ((expr) ? (void)0 : esDbgAssertFailed(HAL_DBG_THIS_MODULE, HAL_DBG_THIS_FILE, ES_STRING(expr), (uint16_t)__LINE__))
#else
# define ES_DBG_ASSERT(expr)               (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Assert makro koji bezuslovno prikazuje gresku.
 * @param       msg                     Poruka o gresci koja se ispisuje
 *                                      korisniku.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) && defined(OPT_HAL_ES_DBG_ASSERT) || defined(__DOXYGEN__)
# define ES_DBG_ASSERT_ALWAYS(msg)                                              \
    esDbgAssertFailed(DBG_THIS_MODULE, DBG_THIS_FILE, ES_STRING(msg), (uint16_t)__LINE__)
#else
# define ES_DBG_ASSERT_ALWAYS(msg)         (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Makro koji se izvrsava za vreme kompajliranja.
 * @param       expr                    Izraz/uslov koji treba da prodje
 *                                      ispitivanje.
 * @details     Ovaj makro se najcesce postavlja u delovima koda koji su poznati
 *              za vreme kompajliranja.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) && defined(OPT_HAL_ES_DBG_ASSERT) || defined(__DOXYGEN__)
# define ES_DBG_ASSERT_COMPILE(expr)                                            \
    extern char ES_CONCAT(compileAssert, __LINE__) [(expr) ? 1 : -1]
#else
# define ES_DBG_ASSERT_COMPILE(expr)                                            \
    extern C_UNUSED_VAR(uint8_t, ES_CONCAT(dbgVar, __LINE__))
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izvrsavanje debug @c expr koda.
 * @details     Ovaj makro izvrsava @c expr kod samo kada je Debug modul ukljucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) || defined(__DOXYGEN__)
# define ES_DBG_MACRO(expr)                                                     \
    expr
#else
# define ES_DBG_MACRO(expr)                                                     \
    (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izvrsavanje debug @c expr koda.
 * @details     Ovaj makro izvrsava @c expr kod samo kada je Debug modul ukljucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_DBG) && defined(OPT_HAL_DBG_TRACE) || defined(__DOXYGEN__)
# define ES_DBG_TRACE(filterBitMask, format, ...)                               \
    if (0U != ((filterBitMask) & filterBitMap)) {                               \
        esDbgTrace(format, __VA_ARGS__);                                        \
    }
#else
# define ES_DBG_TRACE(filterBitMask, format, ...)                               \
    (void)0
#endif

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
#if defined(OPT_HAL_DBG) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Tipovi debug poruka
 *//*--------------------------------------------------------------------------------------------*/
typedef enum esDbgMsgType {
/**
 * @brief       Poruka je izvestaj o gresci
 */
    ES_DBG_MSG_ERROR,

/**
 * @brief       Poruka je informativnog karaktera
 */
    ES_DBG_MSG_INFO,

/**
 * @brief       Poruka upozorenja o mogucem problemu
 */
    ES_DBG_MSG_WARNING
} esDbgMsgType_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Opis objekta generatora poruke
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esDbgObject {
    const char C_ROM * C_ROM_VAR name;
    const char C_ROM * C_ROM_VAR type;
    const char C_ROM * C_ROM_VAR desc;
} esDbgObject_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Opis izvornog mesta gde se objekat nalazi
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esDbgSource {
    const char C_ROM * C_ROM_VAR module;
    const char C_ROM * C_ROM_VAR file;
    const char C_ROM * C_ROM_VAR func;
    int16_t line;
} esDbgSource_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Tekst koji saopštava objekat
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esDbgText {
/**
 * @brief       Kratak opis poruke
 */
    const char C_ROM * C_ROM_VAR brief;

/**
 * @brief       Detaljan tekst poruke zajedno sa znakovima za formatiranje
 */
    const char C_ROM * C_ROM_VAR format;

/**
 * @brief       Promenljive koje treba da se odstampaju.
 */
    const char       * variables;

/**
 * @brief       Tip poruke. Pogledati @ref esDbgMsgType_T.
 */
    esDbgMsgType_T   type;
} esDbgText_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Struktura jedne debug poruke
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esDbgMessage {
/**
 * @brief       Objekat koji je kreirao poruku
 */
    esDbgObject_T object;

/**
 * @brief       Izvorno mesto poruke
 */
    esDbgSource_T source;

/**
 * @brief       Text poruke
 */
    esDbgText_T   text;

/**
 * @brief       Brojac vremena nastanka poruke
 */
    uint16_t      timestamp;
} esDbgMessage_T;

/*=========================================================================  GLOBAL VARIABLES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Bit mapa ukljucenih Trace filtera
 * @details     Svaki bit ove promenljive predstavlja filter za jedan tip
 *              informacija.
 *//*--------------------------------------------------------------------------------------------*/
HAL_DBG_H_EXT uint32_t filterBitMap;

/*======================================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @name        Funkcije javnog interfejsa
 * @{ *//*---------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Prikazuje obavestenje o nevazecem argumentu funkcije
 * @param       moduleName              Ime modula gde je nastala greska,
 * @param       fileName                ime datoteke u modulu,
 * @param       functionName            ime funkcije,
 * @param       expression              greska koja je nastala,
 * @param       lineNum                 redni broj linije koda u datoteci.
 * @details     Ova funkcija dobija sve potrebne parametre od strane makroa kako
 *              bi se prijavila neka interna greska. Svi pokazivaci pokazuju na
 *              tekst u ASCII formatu koji treba da se posalje na Debug monitor.
 *//*--------------------------------------------------------------------------------------------*/
void esDbgCheckFailed (
    const char          * moduleName,
    const char          * fileName,
    const char          * functionName,
    const char          * expression,
    uint16_t            lineNum);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Prikazuje obavestenje o nastaloj internoj gresci.
 * @param       moduleName              Ime modula gde je nastala greska,
 * @param       fileName                ime datoteke u modulu,
 * @param       expression              greska koja je nastala,
 * @param       lineNum                 redni broj linije koda u datoteci.
 * @details     Ova funkcija dobija sve potrebne parametre od strane makroa kako
 *              bi se prijavila neka interna greska. Svi pokazivaci pokazuju na
 *              tekst u ASCII formatu koji treba da se posalje na Debug monitor.
 *//*--------------------------------------------------------------------------------------------*/
void esDbgAssertFailed (
    const char          * moduleName,
    const char          * fileName,
    const char          * expression,
    uint16_t            lineNum);

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Ispisuje debug poruku
 * @param       message                 Struktura debug poruke.
 * @details     Ova funkciju uzima informacije u poruci i stavlja ih u
 *              odgovarajuce bafere. Kada se red cekanja popuni, vrsi se slanje
 *              svih poruka.
 *//*--------------------------------------------------------------------------------------------*/
void esDbgSendMessage (
    esDbgMessage_T      * message);

/** @} *//*--------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#endif /* OPT_HAL_DBG */

/** @endcond *//** @} *//*************************************************************************
 * END of dbg.h
 *************************************************************************************************/
#endif /* HAL_DBG_H_ */
