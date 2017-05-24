#include "led.h"
#include "io.h"

/* set two LEDs on */
void set_led_on(void)
{
    unsigned int tmp;
    
    /* PH20 and PH21 output 1 */
    tmp = readl(PH_DAT);
    tmp |= (0x1 << 20);
    tmp |= (0x1 << 21);
    writel(tmp, PH_DAT);
}

/* set two LEDs off */
void set_led_off(void)
{
    unsigned int tmp;

    /* PH20 and PH21 output 0 */
    tmp = readl(PH_DAT);
    tmp &= ~(0x1 << 20);
    tmp &= ~(0x1 << 21);
    writel(tmp, PH_DAT);
}

/* init PIO */
void led_init(void)
{
    unsigned int tmp;
    
    /* set PH20 and PH21 output */
    tmp = readl(PH_CFG2);
    tmp &= ~(0x7 << 16);
    tmp &= ~(0x7 << 20);
    tmp |= (0x1 << 16);
    tmp |= (0x1 << 20);
    writel(tmp, PH_CFG2);
    /* set PH20 and PH21 output 0 */
    tmp = readl(PH_DAT);
    tmp &= ~(0x1 << 20);
    tmp &= ~(0x1 << 21);
    writel(tmp, PH_DAT);
}
