
#ifndef BASIC_TIMER_H
#define BASIC_TIMER_H

#include <stdint.h>

#define TIMER6_PERIPHERAL_BASE_ADDRESS 0x40001000
#define TIMER7_PERIPHERAL_BASE_ADDRESS 0x40001400

typedef struct {
    volatile uint32_t CR1;       // Control Register 1
    volatile uint32_t CR2;       // Control Register 2
    volatile uint32_t RESERVED1; // Reserved Area
    volatile uint32_t DIER;      // DMA/Interrupt Enable Register
    volatile uint32_t SR;        // Status Register
    volatile uint32_t EGR;       // Event Generation Register
    volatile uint32_t RESERVED2; // Reserved Area
    volatile uint32_t RESERVED3; // Reserved Area
    volatile uint32_t RESERVED4; // Reserved Area
    volatile uint32_t CNT;       // Counter
    volatile uint32_t PSC;       // Prescaler
    volatile uint32_t ARR;       // Auto-Reload Register
} Basic_Timer;

#define TIMER6 ((Basic_Timer*)TIMER6_PERIPHERAL_BASE_ADDRESS)
#define TIMER7 ((Basic_Timer*)TIMER7_PERIPHERAL_BASE_ADDRESS)

#endif // BASIC_TIMER_H
