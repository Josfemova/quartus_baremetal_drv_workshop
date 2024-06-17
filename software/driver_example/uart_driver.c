#include "uart_driver.h"


int uart16550_init(struct uart16550* regs, struct uart16550_config* cfg){
    regs->lcr = 0x83; // 8N1, open config latches
    uint32_t dlb_val = ((50000000)/(16 * 115200));
    regs->rb_thr_dlb1 = dlb_val & 0xFF;
    regs->ier_dlb2 = dlb_val >> 8; 
    regs->lcr &= ~(1<<7); // close config latch
    regs->iir_fcr = 0b111; //Enable and Reset FIFOS
}

int uart16550_write(struct uart16550* regs, char* buffer, size_t count){
    size_t wrote = 0;
    while (wrote < count){
        while (!(regs->lsr & (1<<5))){ // FIFO NOT EMPTY
            continue;
        }
        regs->rb_thr_dlb1 = *(buffer + wrote);
        wrote++;
    }
    return 0;
}

int uart16550_read(struct uart16550* regs, char* buffer, size_t count){
    size_t read = 0;
    while (read < count){
        while (!(regs->lsr & 0x1)){ // READ NOT READY
            continue;
        }
        *(buffer+read) = regs->rb_thr_dlb1;
        read++;
    }
    return 0;
}
