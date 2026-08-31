
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

#define BASIC_TIMER_UPDATE_EVENT_ENABLE 0xFFFFFFFD
#define BASIC_TIMER_UPDATE_EVENT_DISABLE 0x00000002

#define BASIC_TIMER_UPDATE_REQUEST_SOURCE_ANY 0xFFFFFFFB
#define BASIC_TIMER_UPDATE_REQUEST_SOURCE_OVERFLOW_UNDERFLOW 0x00000004

#define BASIC_TIMER_ONE_PULSE_MODE_ENABLE 0x00000008
#define BASIC_TIMER_ONE_PULSE_MODE_DISABLE 0xFFFFFFF7

#define BASIC_TIMER_AUTO_RELOAD_PRELOAD_ENABLE 0x00000080
#define BASIC_TIMER_AUTO_RELOAD_PRELOAD_DISABLE 0xFFFFFF7F

#define BASIC_TIMER_UPDATE_DMA_REQUEST_ENABLE 0x00000100
#define BASIC_TIMER_UPDATE_DMA_REQUEST_DISABLE 0xFFFFFEFF

#define BASIC_TIMER_UPDATE_INTERRUPT_ENABLE 0x00000001
#define BASIC_TIMER_UPDATE_INTERRUPT_DISABLE 0xFFFFFFF0

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
void Basic_Timer_Update_Event_Enable(Basic_Timer *basic_timer);
void Basic_Timer_Update_Event_Disable(Basic_Timer *basic_timer);
void Basic_Timer_Set_Update_Request_Source(Basic_Timer *basic_timer, uint32_t update_request_source);
void Basic_Timer_One_Pulse_Mode_Enable(Basic_Timer *basic_timer);
void Basic_Timer_One_Pulse_Mode_Disable(Basic_Timer *basic_timer);
void Basic_Timer_Auto_Reload_Preload_Enable(Basic_Timer *basic_timer);
void Basic_Timer_Auto_Reload_Preload_Disable(Basic_Timer *basic_timer);
void Basic_Timer_Update_Dma_Request_Enable(Basic_Timer *basic_timer);
void Basic_Timer_Update_Dma_Request_Disable(Basic_Timer *basic_timer);
void Basic_Timer_Update_Interrupt_Enable(Basic_Timer *basic_timer);
void Basic_Timer_Update_Interrupt_Disable(Basic_Timer *basic_timer);

#endif // BASIC_TIMER_H
