#include "timer.h"
#include "io.h"


/* 6MHz for timer0 count freq*/
#define TIMER0_HZ    (6000000)

#if 0
static void sunxi_timer0_start(void)
{
    unsigned int tmp;
    
    tmp = readl(TMR0_CTRL_REG);
    tmp |= (1 << TMR0_EN);
    writel(tmp, TMR0_CTRL_REG);
}

static void sunxi_timer0_stop(void)
{
    unsigned int tmp;
    
    tmp = readl(TMR0_CTRL_REG);
    tmp &= ~(1 << TMR0_EN);
    writel(tmp, TMR0_CTRL_REG);
}
#endif

/* accurate delay */
void udelay(unsigned int usec)
{
    unsigned int count;
    unsigned int tmp;

    /* write interval value */
    count = (TIMER0_HZ / 1000000 ) * ((unsigned int)usec);
    writel(count, TMR0_INTV_VALUE_REG);
    
    /* reload and start timer0 must be operated at the same time */
    tmp = readl(TMR0_CTRL_REG);
    tmp |= (1 << TMR0_RELOAD);
    tmp |= (1 << TMR0_EN);
    writel(tmp, TMR0_CTRL_REG);
    /* wait for interrupt */
    while (!(readl(TMR_IRQ_STA_REG) & (1 << TMR0_IRQ_PEND)));
    /* clear timer0 interrupt */
    tmp = readl(TMR_IRQ_STA_REG);
    tmp |= (1 << TMR0_IRQ_PEND);
    writel(tmp, TMR_IRQ_STA_REG);
}

void sunxi_timer0_init(void)
{
    unsigned int tmp;

    /* single mode, /4 divide, clock source is OSC24M, reload . so clk_freq = 24M / 4 = 6M*/
    tmp = (0x1 << TMR0_MODE) | (0x2 << TMR0_CLK_PRES) | (0x1 << TMR0_CLK_SRC) | (0x1 << TMR0_RELOAD);
    writel(tmp, TMR0_CTRL_REG);
    /* clear timer0 interrupt */
    tmp = readl(TMR_IRQ_STA_REG);
    tmp |= (1 << TMR0_IRQ_PEND);
    writel(tmp, TMR_IRQ_STA_REG);
    /* enable timer0 interrupt */
    tmp = readl(TMR_IRQ_EN_REG);
    tmp |= (1 << TMR0_IRQ_EN);
    writel(tmp, TMR_IRQ_EN_REG);
}