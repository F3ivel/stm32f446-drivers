
#include "stm32f446xx_basic_timer.h"

void Basic_Timer_Counter_Enable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 |= BASIC_TIMER_COUNTER_ENABLE;
}

void Basic_Timer_Counter_Disable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 &= BASIC_TIMER_COUNTER_DISABLE;
}
