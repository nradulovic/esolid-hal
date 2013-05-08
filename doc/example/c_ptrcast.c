#include "hah/hal.h"

typedef struct smm_blk {
    uint8_t a;
    uint8_t b;
} __attribute__ ((__may_alias__)) smm_blk_T;

typedef struct smm_blkHdr {
    smm_blk_T super;
    uint8_t   c;
} __attribute__ ((__may_alias__)) smm_blkHdr_T;

/* Nov zapis    */
void putDataNew(
    smm_blk_T *     block,
    uint8_t         data) {

    E_PTRCAST(smm_blk_T, smm_blkHdr_T, block).c = data;
}

/* Stari zapis  */
void putDataOld(
    smm_blk_T *     block,
    uint8_t         data) {

    ((smm_blkHdr_T *)block)->c = data;
}
