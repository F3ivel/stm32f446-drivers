
#ifndef BASIC_TIMER_H
#define BASIC_TIMER_H

// includes
#include <stdint.h>

// defines
#define TIMER6_PERIPHERAL_BASE_ADDRESS 0x40001000
#define TIMER7_PERIPHERAL_BASE_ADDRESS 0x40001400

#define TIMER6 ((Basic_Timer *)TIMER6_PERIPHERAL_BASE_ADDRESS)
#define TIMER7 ((Basic_Timer *)TIMER7_PERIPHERAL_BASE_ADDRESS)

#define BASIC_TIMER_COUNTER_ENABLE 0x00000001
#define BASIC_TIMER_COUNTER_DISABLE 0xFFFFFFFE

// struct definitions
typedef struct
{
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

// function prototypes
void Basic_Timer_Counter_Enable(Basic_Timer *basic_timer);
void Basic_Timer_Counter_Disable(Basic_Timer *basic_timer);

#endif // BASIC_TIMER_H
