#define TIMER0_HZ              (6000000)
#define TMR_BASE               0x01c20c00
#define TMR0_INTV_VALUE_REG    (TMR_BASE+0x14)
#define TMR0_CTRL_REG          (TMR_BASE+0x10)
#define TMR_IRQ_STA_REG        (TMR_BASE+0x4)
#define TMR_IRQ_EN_REG         (TMR_BASE+0x0)

/* TMR0_CTRL_REG */
#define TMR0_MODE              7
#define TMR0_CLK_PRES          4
#define TMR0_CLK_SRC           2
#define TMR0_RELOAD            1
#define TMR0_EN                0

/* TMR_IRQ_EN_REG */
#define TMR0_IRQ_EN            0

/* TMR_IRQ_STA_REG */
#define TMR0_IRQ_PEND          0

void udelay(unsigned int usec);

void sunxi_timer0_init(void);

