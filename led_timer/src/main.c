#include "led.h"
#include "timer.h"


/* C code entry point */
int main(void)
{
    /* init PIO */
    led_init();
    /* init timer0 */ 
    sunxi_timer0_init();

    while (1) {
        /* two LEDs on */
        set_led_on();
        udelay(1000000);
        /* two LEDs off */
        set_led_off();
        udelay(1000000);
    }
    
    return 0;
}
