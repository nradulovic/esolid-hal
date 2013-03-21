/**
 * @file
 * @date        20-March-2013
 * @brief       STM32F10x XL-Density Devices start-up
 * @details     This module performs:
 *                  - Disables interrupts
 *                  - Fill the RAM with 0xDEAD value
 *                  - Initialize .data section
 *                  - Initialize .bss section
 *                  - Call SystemInit function
 *                  - Call static constructors
 *                  - Jump to main() function
 ******************************************************************************/

    .syntax unified
    .cpu cortex-m3
    .fpu softvfp
    .thumb

.global     Default_Handler
.global     g_pfnVectors

/*
 * This is the list of linker defined variables
 */
    .word   _sram                                                               /* start address of RAM space                               */
    .word   _eram                                                               /* end address of RAM space                                 */
    .word   _sidata                                                             /* start address for the initialization values of the .data */
                                                                                /* section. defined in linker script.                       */
    .word   _sdata                                                              /* start address for the .data section. defined in linker   */
                                                                                /* script                                                   */
    .word   _edata                                                              /* end address for the .data section. defined in linker     */
                                                                                /* script                                                   */
    .word   _sbss                                                               /* start address for the .bss section. defined in linker    */
                                                                                /* script                                                   */
    .word   _ebss                                                               /* end address for the .bss section. defined in linker      */
                                                                                /* script                                                   */

/*
 * This is the code that gets called when the processor first starts execution
 * following a reset event. Only the absolutely necessary set is performed,
 * after which the application supplied main() routine is called.
 */
.section    .text.Reset_Handler
    .weak   Reset_Handler
    .type   Reset_Handler, %function
Reset_Handler:
    nop                                                                         /* Required for debugger: do not remove.                    */
    cpsid   i                                                                   /* Disable interrupts                                       */
    ldr     r0, = _sram
    ldr     r1, = _eram
    b       LoopFillDebug                                                       /* Fill RAM space with 0xDEAD value                         */

FillDebug:
    movw    r3, #57005
    movt    r3, #57005
    str     r3, [r0], #4

LoopFillDebug:
    cmp     r0, r1
    bne     FillDebug
    movs    r1, #0
    b       LoopCopyDataInit                                                    /* Init .data section                                       */

CopyDataInit:
    ldr     r3, = _sidata
    ldr     r3, [r3, r1]
    str     r3, [r0, r1]
    adds    r1, r1, #4

LoopCopyDataInit:
    ldr     r0, = _sdata
    ldr     r3, = _edata
    adds    r2, r0, r1
    cmp     r2, r3
    bcc     CopyDataInit
    ldr     r2, = _sbss
    b       LoopFillZerobss                                                     /* Init .bss section                                        */

FillZerobss:
    movs    r3, #0
    str     r3, [r2], #4

LoopFillZerobss:
    ldr     r3, = _ebss
    cmp     r2, r3
    bcc     FillZerobss

#ifndef __NO_SYSTEM_INIT
    bl      SystemInit                                                          /* Call the clock system intitialization function.          */
#endif
    bl      __libc_init_array                                                   /* Call static constructors                                 */
    bl      main                                                                /* Call the application's entry point.                      */
    bx      lr
    .size   Reset_Handler, .-Reset_Handler

/*
 * This is the code that gets called when the processor receives an unexpected
 * interrupt.  This simply enters an infinite loop, preserving the system state
 * for examination by a debugger.
 */
.section    .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
    b       Infinite_Loop
    .size   Default_Handler, .-Default_Handler

/*
 * The minimal vector table for a Cortex M3.  Note that the proper constructs
 * must be placed on this to ensure that it ends up at physical address
 * 0x0000.0000.
 *
 */
.section    .isr_vector,"a",%progbits
    .type   g_pfnVectors, %object
    .size   g_pfnVectors, .-g_pfnVectors
    .equ    BootRAM, 0xF108F85F
    
    
g_pfnVectors:
    .word   _estack
    .word   Reset_Handler
    .word   NMI_Handler
    .word   HardFault_Handler
    .word   MemManage_Handler
    .word   BusFault_Handler
    .word   UsageFault_Handler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   SVC_Handler
    .word   DebugMon_Handler
    .word   0
    .word   PendSV_Handler
    .word   SysTick_Handler
    .word   WWDG_IRQHandler
    .word   PVD_IRQHandler
    .word   TAMPER_IRQHandler
    .word   RTC_IRQHandler
    .word   FLASH_IRQHandler
    .word   RCC_IRQHandler
    .word   EXTI0_IRQHandler
    .word   EXTI1_IRQHandler
    .word   EXTI2_IRQHandler
    .word   EXTI3_IRQHandler
    .word   EXTI4_IRQHandler
    .word   DMA1_Channel1_IRQHandler
    .word   DMA1_Channel2_IRQHandler
    .word   DMA1_Channel3_IRQHandler
    .word   DMA1_Channel4_IRQHandler
    .word   DMA1_Channel5_IRQHandler
    .word   DMA1_Channel6_IRQHandler
    .word   DMA1_Channel7_IRQHandler
    .word   ADC1_2_IRQHandler
    .word   USB_HP_CAN1_TX_IRQHandler
    .word   USB_LP_CAN1_RX0_IRQHandler
    .word   CAN1_RX1_IRQHandler
    .word   CAN1_SCE_IRQHandler
    .word   EXTI9_5_IRQHandler
    .word   TIM1_BRK_TIM9_IRQHandler
    .word   TIM1_UP_TIM10_IRQHandler
    .word   TIM1_TRG_COM_TIM11_IRQHandler
    .word   TIM1_CC_IRQHandler
    .word   TIM2_IRQHandler
    .word   TIM3_IRQHandler
    .word   TIM4_IRQHandler
    .word   I2C1_EV_IRQHandler
    .word   I2C1_ER_IRQHandler
    .word   I2C2_EV_IRQHandler
    .word   I2C2_ER_IRQHandler
    .word   SPI1_IRQHandler
    .word   SPI2_IRQHandler
    .word   USART1_IRQHandler
    .word   USART2_IRQHandler
    .word   USART3_IRQHandler
    .word   EXTI15_10_IRQHandler
    .word   RTCAlarm_IRQHandler
    .word   USBWakeUp_IRQHandler
    .word   TIM8_BRK_TIM12_IRQHandler
    .word   TIM8_UP_TIM13_IRQHandler
    .word   TIM8_TRG_COM_TIM14_IRQHandler
    .word   TIM8_CC_IRQHandler
    .word   ADC3_IRQHandler
    .word   FSMC_IRQHandler
    .word   SDIO_IRQHandler
    .word   TIM5_IRQHandler
    .word   SPI3_IRQHandler
    .word   UART4_IRQHandler
    .word   UART5_IRQHandler
    .word   TIM6_IRQHandler
    .word   TIM7_IRQHandler
    .word   DMA2_Channel1_IRQHandler
    .word   DMA2_Channel2_IRQHandler
    .word   DMA2_Channel3_IRQHandler
    .word   DMA2_Channel4_5_IRQHandler
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   0
    .word   BootRAM                                                             /* @0x01E0. This is for boot in RAM mode for STM32F10x      */
                                                                                /* XL-Density devices.                                      */

/*
 * Provide weak aliases for each Exception handler to the Default_Handler.
 * As they are weak aliases, any function with the same name will override
 * this definition.
 */
    
    .weak       NMI_Handler
    .thumb_set  NMI_Handler,Default_Handler
  
    .weak       HardFault_Handler
    .thumb_set  HardFault_Handler,Default_Handler
  
    .weak       MemManage_Handler
    .thumb_set  MemManage_Handler,Default_Handler
  
    .weak       BusFault_Handler
    .thumb_set  BusFault_Handler,Default_Handler

    .weak       UsageFault_Handler
    .thumb_set  UsageFault_Handler,Default_Handler

    .weak       SVC_Handler
    .thumb_set  SVC_Handler,Default_Handler

    .weak       DebugMon_Handler
    .thumb_set  DebugMon_Handler,Default_Handler

    .weak       PendSV_Handler
    .thumb_set  PendSV_Handler,Default_Handler

    .weak       SysTick_Handler
    .thumb_set  SysTick_Handler,Default_Handler

    .weak       WWDG_IRQHandler
    .thumb_set  WWDG_IRQHandler,Default_Handler

    .weak       PVD_IRQHandler
    .thumb_set  PVD_IRQHandler,Default_Handler

    .weak       TAMPER_IRQHandler
    .thumb_set  TAMPER_IRQHandler,Default_Handler

    .weak       RTC_IRQHandler
    .thumb_set  RTC_IRQHandler,Default_Handler

    .weak       FLASH_IRQHandler
    .thumb_set  FLASH_IRQHandler,Default_Handler

    .weak       RCC_IRQHandler
    .thumb_set  RCC_IRQHandler,Default_Handler

    .weak       EXTI0_IRQHandler
    .thumb_set  EXTI0_IRQHandler,Default_Handler

    .weak       EXTI1_IRQHandler
    .thumb_set  EXTI1_IRQHandler,Default_Handler

    .weak       EXTI2_IRQHandler
    .thumb_set  EXTI2_IRQHandler,Default_Handler

    .weak       EXTI3_IRQHandler
    .thumb_set  EXTI3_IRQHandler,Default_Handler

    .weak       EXTI4_IRQHandler
    .thumb_set  EXTI4_IRQHandler,Default_Handler

    .weak       DMA1_Channel1_IRQHandler
    .thumb_set  DMA1_Channel1_IRQHandler,Default_Handler

    .weak       DMA1_Channel2_IRQHandler
    .thumb_set  DMA1_Channel2_IRQHandler,Default_Handler

    .weak       DMA1_Channel3_IRQHandler
    .thumb_set  DMA1_Channel3_IRQHandler,Default_Handler

    .weak       DMA1_Channel4_IRQHandler
    .thumb_set  DMA1_Channel4_IRQHandler,Default_Handler

    .weak       DMA1_Channel5_IRQHandler
    .thumb_set  DMA1_Channel5_IRQHandler,Default_Handler

    .weak       DMA1_Channel6_IRQHandler
    .thumb_set  DMA1_Channel6_IRQHandler,Default_Handler

    .weak       DMA1_Channel7_IRQHandler
    .thumb_set  DMA1_Channel7_IRQHandler,Default_Handler

    .weak       ADC1_2_IRQHandler
    .thumb_set  ADC1_2_IRQHandler,Default_Handler

    .weak       USB_HP_CAN1_TX_IRQHandler
    .thumb_set  USB_HP_CAN1_TX_IRQHandler,Default_Handler

    .weak       USB_LP_CAN1_RX0_IRQHandler
    .thumb_set  USB_LP_CAN1_RX0_IRQHandler,Default_Handler

    .weak       CAN1_RX1_IRQHandler
    .thumb_set  CAN1_RX1_IRQHandler,Default_Handler

    .weak       CAN1_SCE_IRQHandler
    .thumb_set  CAN1_SCE_IRQHandler,Default_Handler

    .weak       EXTI9_5_IRQHandler
    .thumb_set  EXTI9_5_IRQHandler,Default_Handler

    .weak       TIM1_BRK_TIM9_IRQHandler
    .thumb_set  TIM1_BRK_TIM9_IRQHandler,Default_Handler

    .weak       TIM1_UP_TIM10_IRQHandler
    .thumb_set  TIM1_UP_TIM10_IRQHandler,Default_Handler

    .weak       TIM1_TRG_COM_TIM11_IRQHandler
    .thumb_set  TIM1_TRG_COM_TIM11_IRQHandler,Default_Handler

    .weak       TIM1_CC_IRQHandler
    .thumb_set  TIM1_CC_IRQHandler,Default_Handler

    .weak       TIM2_IRQHandler
    .thumb_set  TIM2_IRQHandler,Default_Handler

    .weak       TIM3_IRQHandler
    .thumb_set  TIM3_IRQHandler,Default_Handler

    .weak       TIM4_IRQHandler
    .thumb_set  TIM4_IRQHandler,Default_Handler

    .weak       I2C1_EV_IRQHandler
    .thumb_set  I2C1_EV_IRQHandler,Default_Handler

    .weak       I2C1_ER_IRQHandler
    .thumb_set  I2C1_ER_IRQHandler,Default_Handler

    .weak       I2C2_EV_IRQHandler
    .thumb_set  I2C2_EV_IRQHandler,Default_Handler

    .weak       I2C2_ER_IRQHandler
    .thumb_set  I2C2_ER_IRQHandler,Default_Handler

    .weak       SPI1_IRQHandler
    .thumb_set  SPI1_IRQHandler,Default_Handler

    .weak       SPI2_IRQHandler
    .thumb_set  SPI2_IRQHandler,Default_Handler

    .weak       USART1_IRQHandler
    .thumb_set  USART1_IRQHandler,Default_Handler

    .weak       USART2_IRQHandler
    .thumb_set  USART2_IRQHandler,Default_Handler

    .weak       USART3_IRQHandler
    .thumb_set  USART3_IRQHandler,Default_Handler

    .weak       EXTI15_10_IRQHandler
    .thumb_set  EXTI15_10_IRQHandler,Default_Handler

    .weak       RTCAlarm_IRQHandler
    .thumb_set  RTCAlarm_IRQHandler,Default_Handler

    .weak       USBWakeUp_IRQHandler
    .thumb_set  USBWakeUp_IRQHandler,Default_Handler

    .weak       TIM8_BRK_TIM12_IRQHandler
    .thumb_set  TIM8_BRK_TIM12_IRQHandler,Default_Handler

    .weak       TIM8_UP_TIM13_IRQHandler
    .thumb_set  TIM8_UP_TIM13_IRQHandler,Default_Handler

    .weak       TIM8_TRG_COM_TIM14_IRQHandler
    .thumb_set  TIM8_TRG_COM_TIM14_IRQHandler,Default_Handler

    .weak       TIM8_CC_IRQHandler
    .thumb_set  TIM8_CC_IRQHandler,Default_Handler

    .weak       ADC3_IRQHandler
    .thumb_set  ADC3_IRQHandler,Default_Handler

    .weak       FSMC_IRQHandler
    .thumb_set  FSMC_IRQHandler,Default_Handler

    .weak       SDIO_IRQHandler
    .thumb_set  SDIO_IRQHandler,Default_Handler

    .weak       TIM5_IRQHandler
    .thumb_set  TIM5_IRQHandler,Default_Handler

    .weak       SPI3_IRQHandler
    .thumb_set  SPI3_IRQHandler,Default_Handler

    .weak       UART4_IRQHandler
    .thumb_set  UART4_IRQHandler,Default_Handler

    .weak       UART5_IRQHandler
    .thumb_set  UART5_IRQHandler,Default_Handler

    .weak       TIM6_IRQHandler
    .thumb_set  TIM6_IRQHandler,Default_Handler

    .weak       TIM7_IRQHandler
    .thumb_set  TIM7_IRQHandler,Default_Handler

    .weak       DMA2_Channel1_IRQHandler
    .thumb_set  DMA2_Channel1_IRQHandler,Default_Handler

    .weak       DMA2_Channel2_IRQHandler
    .thumb_set  DMA2_Channel2_IRQHandler,Default_Handler

    .weak       DMA2_Channel3_IRQHandler
    .thumb_set  DMA2_Channel3_IRQHandler,Default_Handler

    .weak       DMA2_Channel4_5_IRQHandler
    .thumb_set  DMA2_Channel4_5_IRQHandler,Default_Handler
