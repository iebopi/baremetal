/*
 * (C) Copyright 2014 Conan Liang <lknlfy@163.com>
 *
 * two leds on Cubieboard2 flashing alternately
 * 
 */

/* GPIO reg addr */
#define SUNXI_PIO_BASE          0x01C20800
#define SUNXI_PIO_PH_CFG2_BASE  (SUNXI_PIO_BASE + 0x28)
#define SUNXI_PIO_PH_DAT_BASE   (SUNXI_PIO_BASE + 0x34)

/* global entry point */
.globl _start
_start: b    reset

reset:
    ldr r0, =SUNXI_PIO_PH_CFG2_BASE
    /* before write, read the reg value into r1*/
    ldr r1, [r0]
    /* blue led is connected to PH21, green led is connected to PH20 */
    ldr r2, =((0xf << 12) | (0xf << 8))
    mvn r3, r2
    /* clear 4 bits for PH21 & PH20*/
    and r1, r1, r3
    /* set PH21 & PH20 for output function */
    orr r1, r1, #((0x1 << 12) | (0x1 << 8))
    str r1, [r0]

    ldr r0, =SUNXI_PIO_PH_DAT_BASE
loop:
    /* read the PH data reg */
    ldr r1, [r0]
    /* clear PH.20(green led off) */
    ldr r2, =(1 << 10)
    mvn r3, r2
    and r1, r1, r3
    /* set PH.21(blue led on) */
    orr r1, r1, #(1 << 11)
    str r1, [r0]
    
    bl delay

    /* read the PH data reg */
    ldr r1, [r0]
    /* clear PH.21(blue led off) */
    ldr r2, =(1 << 11)
    mvn r3, r2
    and r1, r1, r3
    /* set PH.20(green led on) */
    orr r1, r1, #(1 << 10)
    str r1, [r0]

    bl delay
    b loop
    /* never reach */
f:
    b f

/* inaccurate delay */
delay:
    mov r5, #0
    ldr r4, =0x3ffff
d:
    sub r4, r4, #1
    cmp r5, r4
    bne d
    mov pc, lr
