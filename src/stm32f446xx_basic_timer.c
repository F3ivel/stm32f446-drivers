
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

void Basic_Timer_One_Pulse_Mode_Enable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 |= BASIC_TIMER_ONE_PULSE_MODE_ENABLE;
}

void Basic_Timer_One_Pulse_Mode_Disable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 &= BASIC_TIMER_ONE_PULSE_MODE_DISABLE;
}

void Basic_Timer_Auto_Reload_Preload_Enable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 |= BASIC_TIMER_AUTO_RELOAD_PRELOAD_ENABLE;
}

void Basic_Timer_Auto_Reload_Preload_Disable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->CR1 &= BASIC_TIMER_AUTO_RELOAD_PRELOAD_DISABLE;
}

void Basic_Timer_Update_Dma_Request_Enable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->DIER |= BASIC_TIMER_UPDATE_DMA_REQUEST_ENABLE;
}

void Basic_Timer_Update_Dma_Request_Disable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->DIER &= BASIC_TIMER_UPDATE_DMA_REQUEST_DISABLE;
}

void Basic_Timer_Update_Interrupt_Enable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->DIER |= BASIC_TIMER_UPDATE_INTERRUPT_ENABLE;
}

void Basic_Timer_Update_Interrupt_Disable(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->DIER &= BASIC_TIMER_UPDATE_INTERRUPT_DISABLE;
}

Basic_Timer_Update_Interrupt_Flag_Status Basic_Timer_Get_Update_Interrupt_Flag(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return BASIC_TIMER_UPDATE_INTERRUPT_FLAG_ERROR;
    }

    if ((basic_timer->SR & BASIC_TIMER_UPDATE_INTERRUPT_FLAG) != 0U)
    {
        return BASIC_TIMER_UPDATE_INTERRUPT_FLAG_SET;
    }

    return BASIC_TIMER_UPDATE_INTERRUPT_FLAG_NOT_SET;
}

void Basic_Timer_Generate_Update_Event(Basic_Timer *basic_timer)
{
    if ((basic_timer != TIMER6) && (basic_timer != TIMER7))
    {
        // No valid Basic_Timer peripheral address were given
        return;
    }

    basic_timer->EGR |= BASIC_TIMER_GENERATE_UPDATE_EVENT;
}
