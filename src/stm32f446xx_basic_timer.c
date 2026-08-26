
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

void Basic_Timer_Update_Event_Enable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 &= BASIC_TIMER_UPDATE_EVENT_ENABLE;
}

void Basic_Timer_Update_Event_Disable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 |= BASIC_TIMER_UPDATE_EVENT_DISABLE;
}

void Basic_Timer_Set_Update_Request_Source(Basic_Timer *basic_timer, uint32_t update_request_source)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    if (update_request_source == BASIC_TIMER_UPDATE_REQUEST_SOURCE_OVERFLOW_UNDERFLOW)
    {
        basic_timer->CR1 |= BASIC_TIMER_UPDATE_REQUEST_SOURCE_OVERFLOW_UNDERFLOW;
        return;
    }
    else if (update_request_source == BASIC_TIMER_UPDATE_REQUEST_SOURCE_ANY)
    {
        basic_timer->CR1 &= BASIC_TIMER_UPDATE_REQUEST_SOURCE_ANY;
        return;
    }
    else
    {
        // No valid value for update_request_source were given
        return;
    }
}