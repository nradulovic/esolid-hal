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
 * @brief       Interfejs modula za vodjenje dnevnika (log).
 * ------------------------------------------------------------------------------------------------
 * @addtogroup  hal_log
 * @brief		Interfejs modula za vodjenje dnevnika (log).
 ****************************************************************************************//** @{ */


#ifndef HAL_LOG_H_
#define HAL_LOG_H_

/*============================================================================  INCLUDE FILES  ==*/
/*----------------------------------------------------------------------------------  EXTERNS  --*/
/** @cond */
#ifdef HAL_LOG_H_VAR
# define HAL_LOG_H_EXT
#else
# define HAL_LOG_H_EXT extern
#endif
/** @endcond*/

/*==================================================================================  DEFINES  ==*/
/*==================================================================================  MACRO's  ==*/
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Definisanje imena modula.
 * @param       moduleName              Ime modula koji se definise.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) || defined(__DOXYGEN__)
# define ES_LOG_DEFINE_MODULE(moduleName)                                       \
    static const C_ROM char * const C_ROM_VAR LOG_THIS_FILE = __FILE__;         \
    static const C_ROM char * const C_ROM_VAR LOG_THIS_MODULE = ES_STRING(moduleName)
#else
# define ES_LOG_DEFINE_MODULE(moduleName)                                       \
    extern C_UNUSED_VAR(uint8_t, unusedDefineModule)
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Vrsi proveru da li su argumenti predati funkciji ispravni
 * @mseffect
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) && defined(OPT_HAL_LOG_CHECK) || defined(__DOXYGEN__)
# if defined(__GNUC__)
#  define ES_LOG_CHECK(expr)                                                    \
    ((expr) ? (void)0 : esLogCheckFailed(LOG_THIS_MODULE, LOG_THIS_FILE, __func__, ES_STRING(expr), (uint16_t)__LINE__))
# else
static const C_ROM char * const C_ROM_VAR LOG_THIS_FUNC = "Unknown function";
#  define ES_LOG_CHECK(expr)                                                    \
    ((expr) ? (void)0 : esLogCheckFailed(LOG_THIS_MODULE, LOG_THIS_FILE, LOG_THIS_FUNC, ES_STRING(expr), (uint16_t)__LINE__))
# endif
#else
# define ES_LOG_CHECK(expr)                (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izvrsava akcije ASSERT makroa.
 * @param       expr                    Izraz/uslov koji treba da bude istinit.
 * @details     Ukoliko uslov @c expr nije istinit poziva se @c extern funkcija
 *              @c dbgAssertFailed koja stampa mesto nastanka greske.
 * @mseffect
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) && defined(OPT_HAL_LOG_ASSERT) || defined(__DOXYGEN__)
# define ES_LOG_ASSERT(expr)                                                    \
    ((expr) ? (void)0 : esLogAssertFailed(HAL_LOG_THIS_MODULE, HAL_LOG_THIS_FILE, ES_STRING(expr), (uint16_t)__LINE__))
#else
# define ES_LOG_ASSERT(expr)               (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Assert makro koji bezuslovno prikazuje gresku.
 * @param       msg                     Poruka o gresci koja se ispisuje
 *                                      korisniku.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) && defined(OPT_HAL_LOG_ASSERT) || defined(__DOXYGEN__)
# define ES_LOG_ASSERT_ALWAYS(msg)                                              \
    esLogAssertFailed(LOG_THIS_MODULE, LOG_THIS_FILE, ES_STRING(msg), (uint16_t)__LINE__)
#else
# define ES_LOG_ASSERT_ALWAYS(msg)         (void)0
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Makro koji se izvrsava za vreme kompajliranja.
 * @param       expr                    Izraz/uslov koji treba da prodje
 *                                      ispitivanje.
 * @details     Ovaj makro se najcesce postavlja u delovima koda koji su poznati
 *              za vreme kompajliranja.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) && defined(OPT_HAL_LOG_ASSERT) || defined(__DOXYGEN__)
# define ES_LOG_ASSERT_COMPILE(expr)                                            \
    extern char ES_CONCAT(compileAssert, __LINE__) [(expr) ? 1 : -1]
#else
# define ES_LOG_ASSERT_COMPILE(expr)                                            \
    extern C_UNUSED_VAR(uint8_t, ES_CONCAT(dbgVar, __LINE__))
#endif

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Izvrsavanje debug @c expr koda.
 * @details     Ovaj makro izvrsava @c expr kod samo kada je Debug modul ukljucen.
 *//*--------------------------------------------------------------------------------------------*/
#if defined(OPT_HAL_LOG) && defined(OPT_HAL_LOG_TRACE) || defined(__DOXYGEN__)
# define ES_LOG_TRACE(filterBitMap, filterBitMask, format, ...)                               \
    if (0U != ((filterBitMask) & (filterBitMap))) {                               \
        esLogTrace(format, __VA_ARGS__);                                        \
    }
#else
# define ES_LOG_TRACE(filterBitMask, format, ...)                               \
    (void)0
#endif

/*-------------------------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================  DATA TYPES  ==*/
#if defined(OPT_HAL_LOG) || defined(__DOXYGEN__)
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Kategorije log poruka
 *//*--------------------------------------------------------------------------------------------*/
typedef enum esLogCategory {
/**
 * @brief       Poruka je izvestaj o gresci
 */
    ES_LOG_CATEGORY_ERR,

/**
 * @brief       Poruka je informativnog karaktera
 */
    ES_LOG_CATEGORY_INFO,

/**
 * @brief       Poruka upozorenja o mogucem problemu
 */
    ES_LOG_CATEGORY_WARNING
} esLogCategory_T;

/**
 * @brief		Nivo obelezavanja dogadjaja u dnevnik
 * @details		Aplikacija moze da ima nekoliko nivoa obelezavanja u dnevnik u
 * 				zavisnosti od znacaja/ozbiljnosti dogadjaja. Postoje sledeci
 * 				predefinisani nivoi znacaja dogadjaja.
 *
 * 				Aplikacija moze da odluci koji nivoi znacaja dogadjaja ce se
 * 				ubacivati u dnevnik. Na primer, ukoliko izvorni kod poseduje
 * 				sve navedene nivoe znacaja, a zeljeni nivo je postavljen na
 * 				nivo ES_LOG_LEVEL_WARN, onda se u dnevniku pojavljuju samo
 * 				poruke sa nivoom jednakim ili vecim od nivoa ES_LOG_LEVEL_WARN.
 * 				Poruke sa nizim nivoom se za vreme kompajliranja pretvaraju u
 * 				prazne izraze.
 */
typedef enum esLogLevel {
/**
 * @brief		Kriticne greske koje dovode do toga da se aplikacija zaustavi.
 */
	ES_LOG_LEVEL_FATAL,

/**
 * @brief		Greske za vreme izvrsavanja aplikacije, ali aplikacija moze da
 * 				nastavi sa izvrsavanjem.
 */
	ES_LOG_LEVEL_ERROR,

/**
 * @brief		Upozorenja
 */
	ES_LOG_LEVEL_WARN,

/**
 * @brief		Informativne poruke
 */
	ES_LOG_LEVEL_INFO,

/**
 * @brief		Debug poruke
 */
	ES_LOG_LEVEL_DEBUG,

/**
 * @brief		Poruke sa finim detaljima
 */
	ES_LOG_LEVEL_TRACE
};
/*-------------------------------------------------------------------------------------------*//**
 * @brief       Opis objekta generatora poruke
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esLogObject {
    const char C_ROM * C_ROM_VAR name;
    const char C_ROM * C_ROM_VAR type;
    const char C_ROM * C_ROM_VAR desc;
} esLogObject_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Opis izvornog mesta gde se objekat nalazi
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esLogSource {
    const char C_ROM * C_ROM_VAR module;
    const char C_ROM * C_ROM_VAR file;
    const char C_ROM * C_ROM_VAR func;
    int16_t line;
} esLogSource_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Tekst koji saopštava objekat
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esLogText {
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
 * @brief       Tip poruke. Pogledati @ref esLogCategory_T.
 */
    esLogCategory_T   type;
} esLogText_T;

/*-------------------------------------------------------------------------------------------*//**
 * @brief       Struktura jedne debug poruke
 *//*--------------------------------------------------------------------------------------------*/
typedef struct esLogMessage {
/**
 * @brief       Objekat koji je kreirao poruku
 */
    esLogObject_T object;

/**
 * @brief       Izvorno mesto poruke
 */
    esLogSource_T source;

/**
 * @brief       Text poruke
 */
    esLogText_T   text;

/**
 * @brief       Brojac vremena nastanka poruke
 */
    uint16_t      timestamp;
} esLogMessage_T;

/*=========================================================================  GLOBAL VARIABLES  ==*/
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
void esLogCheckFailed (
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
void esLogAssertFailed (
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
void esLogSendMessage (
    esLogMessage_T      * message);

/** @} *//*--------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*===================================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
#endif /* OPT_HAL_LOG */

/** @endcond *//** @} *//*************************************************************************
 * END of hal_log.h
 *************************************************************************************************/
#endif /* HAL_LOG_H_ */
