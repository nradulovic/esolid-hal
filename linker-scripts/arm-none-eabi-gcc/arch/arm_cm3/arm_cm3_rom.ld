/*
 * Exported symbols:
 *  - _stext                    - start of text section
 *  - _etext                    - end of text section
 *  - __exidx_start
 *  - __exidx_end
 *  - __preinit_array_start
 *  - __preinit_array_end
 *  - __init_array_start
 *  - __preinit_array_end
 *  - __fini_array_start
 *  - __fini_array_end
 *  - _sidata                   - used by .data init loop in start-up
 *  - _sdata                    - start of data section in RAM
 *  - _edata                    - end of data section in RAM
 *  - _sbss                     - start of bss section in RAM
 *  - _ebss                     - end of bss section in RAM
 *  - _sstack                   - start of stack
 *  - _estack                   - end of stack
 *  - _sheap                    - start of heap
 *  - _eheap                    - end of heap
 *  - _sram                     - begin of RAM address space
 *  - _eram                     - end of RAM address space
 */
 
 
ENTRY(Reset_Handler)                                                            /* Entry point                                              */

_Min_Stack_Size = ALIGN(_Min_Stack_Size, 8);
_Min_Heap_Size  = ALIGN(_Min_Heap_Size, 4);

SECTIONS
{
    .isr_vector :                                                               /* ISR vector goes first into FLASH                         */
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH
    
    .text :                                                                     /* The program code and other data goes into FLASH          */
    {
        . = ALIGN(4);
        _stext = .;                                                             /* define a global symbol at start of code                  */
        *(.text*)                       
        
        KEEP (*(.init))
        KEEP (*(.fini))
        
        *(.rodata*)                     
        *(.glue_7)                                                              /* glue arm to thumb code                                   */
        *(.glue_7t)                                                             /* glue thumb to arm code                                   */

        KEEP(*(.eh_frame*))
        _etext = .;                                                             /* define a global symbols at end of code                   */
    } > FLASH
    
    .ARM.extab : 
    { 
        *(.ARM.extab*)
        *(.gnu.linkonce.armextab.*) 
    } > FLASH
    
    .ARM : 
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        *(.gnu.linkonce.armexidx.*) 
        __exidx_end = .;
    } > FLASH

    .preinit_array :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } > FLASH
    
    .init_array :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > FLASH
    
    .fini_array :
    {
        . = ALIGN(4);
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(.fini_array*))
        KEEP (*(SORT(.fini_array.*)))
        PROVIDE_HIDDEN (__fini_array_end = .);
    } > FLASH
    
    _sidata = .;                                                                /* used by the startup to initialize data                   */
    
    .data : AT ( _sidata )                                                      /* Initialized data sections goes into RAM, load LMA copy after code */
    {
        . = ALIGN(4);
        _sdata = .;                                                             /* define a global symbol at data start                     */
        _sram = .;                                                              /* define a global symbol at start of RAM                   */
        *(vtable)
        *(.data*)                       
        . = ALIGN(4);
        _edata = .;                                                             /* define a global symbol at data end                       */
    } > RAM
    
    .bss :                                                                      /* This is used by the startup in order to initialize the .bss secion */
    {
        . = ALIGN(4);
        _sbss = .;                                                              /* define a global symbol at bss start                      */
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;                                                              /* define a global symbol at bss end                        */
    } > RAM
    
    .stack :
    {
        _sstack = .;                                                            /* define a global symbol at stack start                    */
        . += _Min_Stack_Size;
        . = ALIGN(8);
        _estack = .;                                                            /* define a global symbol at stack end                      */
    } > RAM

    .heap :
    {
        _sheap = .;                                                             /* define a global symbol at heap start                     */
        . = ORIGIN(RAM) + LENGTH(RAM);
        _eheap = .;                                                             /* define a global symbol at heap end                       */
        _eram = .;                                                              /* define a global symbol at end of RAM                     */
    } > RAM
    
    /DISCARD/ :                                                                 /* Remove information from the standard libraries           */
    {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
    }

    .ARM.attributes 0 : 
    { 
        *(.ARM.attributes) 
    }
}

ASSERT((_eheap - _sheap)>=_Min_Heap_Size, "Not enough RAM space to fit HEAP memory.");