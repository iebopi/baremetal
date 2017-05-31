/*
 * (C) Copyright 2014 conan liang <lknlfy@163.com>
 * 
 */

/* global entry point */
.globl _start
_start: b    reset

reset:
    /* disable IRQ & FIQ, set the cpu to SVC32 mode */
    mrs r0, cpsr
    and r1, r0, #0x1f
    teq r1, #0x1a
    bicne r0, r0, #0x1f
    orrne r0, r0, #0x13
    orr r0, r0, #0xc0
    msr cpsr, r0
    /* setup stack, so we can call C code */
    ldr sp, =(1024 * 10)
    /* call main function */
    bl main
loop:
    b loop