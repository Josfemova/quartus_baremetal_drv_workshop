#ifndef UART_DRIVER_16550
#define UART_DRIVER_16550

#include <inttypes.h>
#include <stddef.h>

// get a value with bit x set 
#define BIT(x) (1UL << (x))

// get a value with bits h to l set
#define BITS(h, l) (~(BIT(l) - 1) & ((BIT(h) - 1) | BIT(h)))

// get a mask where the first n bits are set
#define BIT_MASK(n) (BIT(n) - 1UL)

struct uart16550{
    volatile uint8_t rb_thr_dlb1; // 0
    volatile uint8_t ier_dlb2;    // 1
    volatile uint8_t iir_fcr;     // 2 iir when read, fcr when written to
    volatile uint8_t lcr;         // 3
    volatile uint8_t mcr;         // 4
    volatile uint8_t lsr;         // 5
    volatile uint8_t msr;         // 6
    volatile uint32_t debug1;     // 8
    volatile uint32_t debug2;     // 12
};

struct uart16550_config{
    int _empty;
};

//=============================================
// LCR FIELDS
//=============================================

#define UART16550_LCR_WLEN_MASK   BITMASK(0,0)
#define UART16550_LCR_WLEN_OFFSET 0x

#define UART16550_LCR_STB_MASK   BITMASK(0,0)
#define UART16550_LCR_STB_OFFSET 0x

#define UART16550_LCR__MASK   BITMASK(0,0)
#define UART16550_LCR__OFFSET 0x

#define UART16550_LCR__MASK   BITMASK(0,0)
#define UART16550_LCR__OFFSET 0x

#define UART16550_LCR__MASK   BITMASK(0,0)
#define UART16550_LCR__OFFSET 0x

#define UART16550_LCR__MASK   BITMASK(0,0)
#define UART16550_LCR__OFFSET 0x

#define UART16550_LCR_DLAB_MASK   BIT(7)
#define UART16550_LCR_DLAB_OFFSET 0x7

//=============================================
// FCR FIELDS
//=============================================

#define UART16550_FCR_FIFOE_MASK   BIT(0)
#define UART16550_FCR_FIFOE_OFFSET 0x0

int uart16550_init(struct uart16550* regs, struct uart16550_config* cfg);

int uart16550_write(struct uart16550* regs, char* buffer, size_t count);

int uart16550_read(struct uart16550* regs, char* buffer, size_t count);


#endif