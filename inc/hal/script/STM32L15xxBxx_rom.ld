/*
 *  Abstract    Linker script for stm32l1xxBxx Device with 128KByte FLASH, 16KByte RAM
 *
 *              Set heap size and stack size according to application requirements.
 */

_Min_Heap_Size = 0;                     /* required amount of heap  */
_Min_Stack_Size = 0x200;                /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 16K
}

INCLUDE "cortex_m3_rom.ld"