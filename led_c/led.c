#include "led.h"
#include "io.h"

/* set two LEDs off */
void set_led_off(void)
{
    unsigned int tmp;
    
    /* PB10 and PB11 output 1 */
    tmp = readl(PH_DAT);
    tmp |= (0x1 << 10);
    tmp |= (0x1 << 11);
    writel(tmp, PH_DAT);
}

/* set two LEDs on */
void set_led_on(void)
{
    unsigned int tmp;

    /* PB10 and PB11 output 0 */
    tmp = readl(PH_DAT);
    tmp &= ~(0x1 << 10);
    tmp &= ~(0x1 << 11);
    writel(tmp, PH_DAT);
}

/* init PIO */
void led_init(void)
{
    unsigned int tmp;
    
    /* set PB10 and PB11 output */
    tmp = readl(PH_CFG2);
    tmp &= ~(0x7 << 8);
    tmp &= ~(0x7 << 12);
    tmp |= (0x1 << 8);
    tmp |= (0x1 << 12);
    writel(tmp, PH_CFG2);
    /* set PB10 and PB11 output 0 */
    tmp = readl(PH_DAT);
    tmp &= ~(0x1 << 8);
    tmp &= ~(0x1 << 12);
    writel(tmp, PH_DAT);
}
