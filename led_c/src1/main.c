#include "led.h"

/* just for test */
static void delay(void)
{
    unsigned int i;

    for (i = 0; i < 50000; i++);
}

/* C code entry point */
int main(void)
{
    /* init PIO */
    led_init();

    while (1) {
        /* two LEDs on */
        set_led_on();
        delay();
        /* two LEDs off */
        set_led_off();
        delay();
    }
    
    return 0;
}