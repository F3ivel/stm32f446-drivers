
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

#define BASIC_TIMER_MASTER_MODE_MASK (7U << 4)
#define BASIC_TIMER_MASTER_MODE_RESET 0x00000000
#define BASIC_TIMER_MASTER_MODE_ENABLE 0x00000010
#define BASIC_TIMER_MASTER_MODE_UPDATE 0x00000020

#define BASIC_TIMER_UPDATE_DMA_REQUEST_ENABLE 0x00000100
#define BASIC_TIMER_UPDATE_DMA_REQUEST_DISABLE 0xFFFFFEFF

#define BASIC_TIMER_UPDATE_INTERRUPT_ENABLE 0x00000001
#define BASIC_TIMER_UPDATE_INTERRUPT_DISABLE 0xFFFFFFF0

#define BASIC_TIMER_UPDATE_INTERRUPT_FLAG 0x00000001

#define BASIC_TIMER_GENERATE_UPDATE_EVENT 0x00000001

// enums
typedef enum
{
    BASIC_TIMER_UPDATE_INTERRUPT_FLAG_ERROR = -1,
    BASIC_TIMER_UPDATE_INTERRUPT_FLAG_NOT_SET = 0,
    BASIC_TIMER_UPDATE_INTERRUPT_FLAG_SET = 1
} Basic_Timer_Update_Interrupt_Flag_Status;

typedef enum
{
    BASIC_TIMER_STATUS_ERROR = -1,
    BASIC_TIMER_STATUS_OK = 0
} Basic_Timer_Status;

// struct definitions

/**
 * @brief Basic timer peripheral
 *
 * This struct represents the basic timer peripheral.
 */
typedef struct
{
    volatile uint32_t CR1;       ///< Control Register 1
    volatile uint32_t CR2;       ///< Control Register 2
    volatile uint32_t RESERVED1; ///< Reserved Area
    volatile uint32_t DIER;      ///< DMA/Interrupt Enable Register
    volatile uint32_t SR;        ///< Status Register
    volatile uint32_t EGR;       ///< Event Generation Register
    volatile uint32_t RESERVED2; ///< Reserved Area
    volatile uint32_t RESERVED3; ///< Reserved Area
    volatile uint32_t RESERVED4; ///< Reserved Area
    volatile uint32_t CNT;       ///< Counter
    volatile uint32_t PSC;       ///< Prescaler
    volatile uint32_t ARR;       ///< Auto-Reload Register
} Basic_Timer;

// function prototypes

/**
 * @brief Enable basic timer
 *
 * This function enables the specified basic timer.
 *
 * @param basic_timer Basic timer to enable (TIMER6 or TIMER7).
 */
void Basic_Timer_Counter_Enable(Basic_Timer *basic_timer);

/**
 * @brief Disable basic timer
 *
 * This function disables the specified basic timer.
 *
 * @param basic_timer Basic timer to disable (TIMER6 or TIMER7).
 */
void Basic_Timer_Counter_Disable(Basic_Timer *basic_timer);

/**
 * @brief Enable update event generation
 *
 * This function enables the update event generation for the specified basic timer.
 *
 * @param basic_timer Basic timer for which to enable update event generation (TIMER6 or TIMER7).
 */
void Basic_Timer_Update_Event_Enable(Basic_Timer *basic_timer);

/**
 * @brief Disable update event generation
 *
 * This function disables the update event generation for the specified basic timer.
 *
 * @param basic_timer Basic timer for which to disable update event generation (TIMER6 or TIMER7).
 */
void Basic_Timer_Update_Event_Disable(Basic_Timer *basic_timer);

/**
 * @brief Set update event sources
 *
 * With this function, you can set the sources for the update event generation.
 *
 * @param basic_timer Basic timer for which to set the update request source (TIMER6 or TIMER7).
 * @param update_request_source Update event sources. This value can be:
 * * BASIC_TIMER_UPDATE_REQUEST_SOURCE_ANY: counter overflow/underflow / setting the UG bit / update generation through the slave mode controller
 * * BASIC_TIMER_UPDATE_REQUEST_SOURCE_OVERFLOW_UNDERFLOW: only counter overflow/underflow
 */
void Basic_Timer_Set_Update_Request_Source(Basic_Timer *basic_timer, uint32_t update_request_source);

/**
 * @brief Enable One-pulse mode
 *
 * This function enables the One-pulse mode for the specified basic timer.
 *
 * @param basic_timer Basic timer for which to enable One-pulse mode (TIMER6 or TIMER7).
 */
void Basic_Timer_One_Pulse_Mode_Enable(Basic_Timer *basic_timer);

/**
 * @brief Disable One-pulse mode
 *
 * This function disables the One-pulse mode for the specified basic timer.
 *
 * @param basic_timer Basic timer for which to disable One-pulse mode (TIMER6 or TIMER7).
 */
void Basic_Timer_One_Pulse_Mode_Disable(Basic_Timer *basic_timer);

/**
 * @brief Enable auto-reload preload
 *
 * This function enables the auto-reload preload for the specified basic timer. This means, that the TIMx_ARR register is buffered.
 *
 * @param basic_timer Basic timer for which to enable auto-reload preload (TIMER6 or TIMER7).
 */
void Basic_Timer_Auto_Reload_Preload_Enable(Basic_Timer *basic_timer);

/**
 * @brief Disable auto-reload preload
 *
 * This function disables the auto-reload preload for the specified basic timer. This means, that the TIMx_ARR register is not buffered.
 *
 * @param basic_timer Basic timer for which to disable auto-reload preload (TIMER6 or TIMER7).
 */
void Basic_Timer_Auto_Reload_Preload_Disable(Basic_Timer *basic_timer);

/**
 * @brief Select Master mode
 *
 * With this function, you can select the Master mode for the specified basic timer.
 *
 * @param basic_timer Basic timer for which to select the Master mode (TIMER6 or TIMER7).
 * @param master_mode This value can be BASIC_TIMER_MASTER_MODE_RESET,BASIC_TIMER_MASTER_MODE_ENABLE or BASIC_TIMER_MASTER_MODE_UPDATE. See datasheet for more information.
 */
void Basic_Timer_Master_Mode_Selection(Basic_Timer *basic_timer, uint32_t master_mode);

/**
 * @brief Update event DMA request enable
 *
 * This function enables the DMA request by an update event for the given basic timer.
 *
 * @param basic_timer Basic timer for which to enable the DMA request by an update event (TIMER6 or TIMER7).
 */
void Basic_Timer_Update_Dma_Request_Enable(Basic_Timer *basic_timer);

/**
 * @brief Update event DMA request disable
 *
 * This function disables the DMA request by an update event for the given basic timer.
 *
 * @param basic_timer Basic timer for which to disable the DMA request by an update event (TIMER6 or TIMER7).
 */
void Basic_Timer_Update_Dma_Request_Disable(Basic_Timer *basic_timer);

/**
 * @brief Update event interrupt enable
 *
 * This function enables the interrupt generation by an update event for the given basic timer.
 *
 * @param basic_timer Basic timer for which to enable the interrupt generation by an update event (TIMER6 or TIMER7).
 */
void Basic_Timer_Update_Interrupt_Enable(Basic_Timer *basic_timer);

/**
 * @brief Update event interrupt disable
 *
 * This function disables the interrupt generation by an update event for the given basic timer.
 *
 * @param basic_timer Basic timer for which to disable the interrupt generation by an update event (TIMER6 or TIMER7).
 */
void Basic_Timer_Update_Interrupt_Disable(Basic_Timer *basic_timer);

/**
 * @brief Get the update interrupt flag
 *
 * This function returns the status of the update interrupt flag.
 *
 * @param basic_timer Basic timer for which to get the update interrupt flag (TIMER6 or TIMER7).
 * @return This function returns:
 * * BASIC_TIMER_UPDATE_INTERRUPT_FLAG_ERROR: No valid Basic_Timer peripheral address was given
 * * BASIC_TIMER_UPDATE_INTERRUPT_FLAG_NOT_SET: Update interrupt flag is not set
 * * BASIC_TIMER_UPDATE_INTERRUPT_FLAG_SET: Update interrupt flag is set
 */
Basic_Timer_Update_Interrupt_Flag_Status Basic_Timer_Get_Update_Interrupt_Flag(Basic_Timer *basic_timer);

/**
 * @brief Generate update event
 *
 * This function generates an update event.
 *
 * @param basic_timer Basic timer for which to generate an update event (TIMER6 or TIMER7).
 */
void Basic_Timer_Generate_Update_Event(Basic_Timer *basic_timer);

/**
 * @brief Get counter value
 *
 * This function puts the current counter value into the given variable cnt_value and returns a status code of the function.
 *
 * @param basic_timer Basic timer for which to get the counter value (TIMER6 or TIMER7).
 * @param cnt_value Variable to store the current counter value
 * @return This function returns:
 * * BASIC_TIMER_STATUS_ERROR: No valid Basic_Timer peripheral address was given or cnt_value was NULL
 * * BASIC_TIMER_STATUS_OK: On success
 */
Basic_Timer_Status Basic_Timer_Get_Counter_Value(Basic_Timer *basic_timer, uint16_t *cnt_value);

/**
 * @brief Set prescaler
 *
 * This function sets the prescaler for the specified basic timer.
 *
 * @param basic_timer Basic timer for which to set the prescaler (TIMER6 or TIMER7).
 * @param psc_value Value for the prescaler. Note: counter clock frequency = clock prescaler / (psc_value + 1). See datasheet for more information.
 */
void Basic_Timer_Set_Prescaler_Value(Basic_Timer *basic_timer, uint16_t psc_value);

/**
 * @brief Get prescaler
 *
 * This function puts the current counter value into the given variable cnt_value and returns a status code of the function.
 *
 * @param basic_timer Basic timer for which to get the prescaler value (TIMER6 or TIMER7).
 * @param psc_value Variable to store the current prescaler value
 * @return This function returns:
 * * BASIC_TIMER_STATUS_ERROR: No valid Basic_Timer peripheral address was given or psc_value was NULL
 * * BASIC_TIMER_STATUS_OK: On success
 */
Basic_Timer_Status Basic_Timer_Get_Prescaler_Value(Basic_Timer *basic_timer, uint16_t *psc_value);

/**
 * @brief Set auto-reload value
 *
 * This function sets the auto-reload value. This is the value to which the counter counts before he restarts.
 *
 * @param basic_timer Basic timer for which to set the prescaler (TIMER6 or TIMER7).
 * @param arr_value Value to which the counter should count.
 */
void Basic_Timer_Set_Auto_Reload_Value(Basic_Timer *basic_timer, uint16_t arr_value);

/**
 * @brief Get auto-reload value
 *
 * This function puts the current auto-reload value into the given variable arr_value and returns a status code of the function.
 *
 * @param basic_timer Basic timer for which to set the prescaler (TIMER6 or TIMER7).
 * @param arr_value Variable to store the current auto-reload value
 * @return This function returns:
 * * BASIC_TIMER_STATUS_ERROR: No valid Basic_Timer peripheral address was given or arr_value was NULL
 * * BASIC_TIMER_STATUS_OK: On success
 */
Basic_Timer_Status Basic_Timer_Get_Auto_Reload_Value(Basic_Timer *basic_timer, uint16_t *arr_value);

#endif // BASIC_TIMER_H
