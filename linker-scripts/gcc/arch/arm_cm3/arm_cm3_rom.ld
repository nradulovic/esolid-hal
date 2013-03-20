
ENTRY(Reset_Handler)                    /* Entry point */

_Min_Stack_Size = ALIGN(_Min_Stack_Size, 8);
_Min_Heap_Size  = ALIGN(_Min_Heap_Size, 4);

SECTIONS
{
    .isr_vector :                       /* ISR vector goes first into FLASH */
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))            /* ISR vector defined in Startup code */
        . = ALIGN(4);
    } >FLASH
    
    .text :                             /* The program code and other data goes into FLASH */
    {
        . = ALIGN(4);
        *(.text)                        /* .text sections (code) */
        *(.text*)                       /* .text* sections (code) */
        *(.rodata)                      /* .rodata sections (constants, strings, etc.) */
        *(.rodata*)                     /* .rodata* sections (constants, strings, etc.) */
        *(.glue_7)                      /* glue arm to thumb code */
        *(.glue_7t)                     /* glue thumb to arm code */
        *(.eh_frame)

        KEEP (*(.init))
        KEEP (*(.fini))

        . = ALIGN(4);
        _etext = .;                     /* define a global symbols at end of code */
    } >FLASH
    
    .ARM.extab : 
    { 
        *(.ARM.extab*)
        *(.gnu.linkonce.armextab.*) 
    } >FLASH
    
    .ARM : 
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } >FLASH

    .preinit_array :
    {
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } >FLASH
    
    .init_array :
    {
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } >FLASH
    
    .fini_array :
    {
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(.fini_array*))
        KEEP (*(SORT(.fini_array.*)))
        PROVIDE_HIDDEN (__fini_array_end = .);
    } >FLASH
    
    _sidata = .;                        /* used by the startup to initialize data */
    
    .data : AT ( _sidata )              /* Initialized data sections goes into RAM, load LMA copy after code */
    {
        . = ALIGN(4);
        _sdata = .;                     /* define a global symbol at data start */
        *(.data)                        /* .data sections */
        *(.data*)                       /* .data* sections */
        . = ALIGN(4);
        _edata = .;                     /* define a global symbol at data end */
    } >RAM
    
    .bss :                              /* This is used by the startup in order to initialize the .bss secion */
    {
        . = ALIGN(4);
        _sbss = .;                      /* define a global symbol at bss start */
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;                      /* define a global symbol at bss end */
    } >RAM
    
    _sstack = .;
    . += _Min_Stack_Size;
    . = ALIGN(8);
     _estack = .;

    /* Because the stack operation is a full descending stack (SP decrement before), 
    the initial SP value should be set to the first memory after the top of the 
    stack region. */
    _sheap = .;                         /* define a global symbol at heap start */
    . = ORIGIN(RAM) + LENGTH(RAM);
    _eheap = .;                         /* define a global symbol at heap end */

    
    /DISCARD/ :                         /* Remove information from the standard libraries */
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