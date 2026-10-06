
#ifndef GPIO_H
#define GPIO_H

// includes
#include <stdint.h>

// defines
#define GPIOA_PERIPHERAL_BASE_ADDRESS 0x40020000
#define GPIOB_PERIPHERAL_BASE_ADDRESS 0x40020400
#define GPIOC_PERIPHERAL_BASE_ADDRESS 0x40020800
#define GPIOD_PERIPHERAL_BASE_ADDRESS 0X40020C00
#define GPIOE_PERIPHERAL_BASE_ADDRESS 0x40021000
#define GPIOF_PERIPHERAL_BASE_ADDRESS 0x40021400
#define GPIOG_PERIPHERAL_BASE_ADDRESS 0x40021800
#define GPIOH_PERIPHERAL_BASE_ADDRESS 0x40021C00

#define GPIOA ((Gpio *)GPIOA_PERIPHERAL_BASE_ADDRESS)
#define GPIOB ((Gpio *)GPIOB_PERIPHERAL_BASE_ADDRESS)
#define GPIOC ((Gpio *)GPIOC_PERIPHERAL_BASE_ADDRESS)
#define GPIOD ((Gpio *)GPIOD_PERIPHERAL_BASE_ADDRESS)
#define GPIOE ((Gpio *)GPIOE_PERIPHERAL_BASE_ADDRESS)
#define GPIOF ((Gpio *)GPIOF_PERIPHERAL_BASE_ADDRESS)
#define GPIOG ((Gpio *)GPIOG_PERIPHERAL_BASE_ADDRESS)
#define GPIOH ((Gpio *)GPIOH_PERIPHERAL_BASE_ADDRESS)

// struct definitions

/**
 * @brief GPIO peripheral
 *
 * This struct represents the gpio peripheral.
 */
typedef struct
{
    volatile uint32_t MODER;   ///< Mode Register
    volatile uint32_t OTYPER;  ///< Output Type Register
    volatile uint32_t OSPEEDR; ///< Output Speed Register
    volatile uint32_t PUPDR;   ///< Pull-up / Pull-down Register
    volatile uint32_t IDR;     ///< Input Data Register
    volatile uint32_t ODR;     ///< Output Data Register
    volatile uint32_t BSRR;    ///< Bit Set / Reset Register
    volatile uint32_t LCKR;    ///< Configuration Lock Register
    volatile uint32_t AFRL;    ///< Alternate Function Register Low
    volatile uint32_t AFRH;    ///< Alternate Function Register High
} Gpio;

#endif // GPIO_H