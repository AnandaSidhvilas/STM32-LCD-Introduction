
#ifndef RAAYAN_MINI_H
#define RAAYAN_MINI_H

/***************************************************************
 *                      HEADER FILE
 ***************************************************************/

#include <stdint.h>

/***************************************************************
 *                  GPIO REGISTER STRUCTURE
 *
 * This structure represents the GPIO peripheral registers.
 * Each member corresponds to a 32-bit hardware register.
 ***************************************************************/

typedef struct
{
    volatile uint32_t MODER;       // GPIO port mode register
    volatile uint32_t OTYPER;      // GPIO output type register
    volatile uint32_t OSPEEDR;     // GPIO output speed register
    volatile uint32_t PUPDR;       // GPIO pull-up/pull-down register
    volatile uint32_t IDR;         // GPIO input data register
    volatile uint32_t ODR;         // GPIO output data register
    volatile uint32_t BSRR;        // GPIO bit set/reset register
    volatile uint32_t LCKR;        // GPIO configuration lock register
    volatile uint32_t AFR[2];      // GPIO alternate function registers

} GPIO_RegDef_t;


/***************************************************************
 *                  RCC REGISTER STRUCTURE
 *
 * This structure represents the Reset and Clock Control (RCC)
 * peripheral registers.
 *
 * Reserved fields maintain the correct memory offsets between
 * hardware registers.
 ***************************************************************/

typedef struct
{
    volatile uint32_t RCC_CR;          // Clock control register
    volatile uint32_t RCC_PLLCFGR;     // PLL configuration register
    volatile uint32_t RCC_CFGR;        // Clock configuration register
    volatile uint32_t RCC_CIR;         // Clock interrupt register

    volatile uint32_t RCC_AHB1RSTR;    // AHB1 peripheral reset register
    volatile uint32_t RCC_AHB2RSTR;    // AHB2 peripheral reset register
    volatile uint32_t Reserved_1;
    volatile uint32_t Reserved_2;

    volatile uint32_t RCC_APB1RSTR;    // APB1 peripheral reset register
    volatile uint32_t RCC_APB2RSTR;    // APB2 peripheral reset register
    volatile uint32_t Reserved_3;
    volatile uint32_t Reserved_4;

    volatile uint32_t RCC_AHB1ENR;     // AHB1 peripheral clock enable
    volatile uint32_t RCC_AHB2ENR;     // AHB2 peripheral clock enable
    volatile uint32_t Reserved_5;
    volatile uint32_t Reserved_6;

    volatile uint32_t RCC_APB1ENR;     // APB1 peripheral clock enable
    volatile uint32_t RCC_APB2ENR;     // APB2 peripheral clock enable
    volatile uint32_t Reserved_7;
    volatile uint32_t Reserved_8;

    volatile uint32_t RCC_AHB1LPENR;   // AHB1 low-power clock enable
    volatile uint32_t RCC_AHB2LPENR;   // AHB2 low-power clock enable
    volatile uint32_t Reserved_9;
    volatile uint32_t Reserved_10;

    volatile uint32_t RCC_APB1LPENR;   // APB1 low-power clock enable
    volatile uint32_t RCC_APB2LPENR;   // APB2 low-power clock enable
    volatile uint32_t Reserved_11;
    volatile uint32_t Reserved_12;

    volatile uint32_t RCC_BDCR;        // Backup domain control register
    volatile uint32_t RCC_CSR;         // Clock control and status register
    volatile uint32_t Reserved_13;
    volatile uint32_t Reserved_14;

    volatile uint32_t RCC_SSCGR;       // Spread spectrum clock generation
    volatile uint32_t RCC_PLLI2SCFGR;  // PLLI2S configuration register
    volatile uint32_t Reserved_15;
    volatile uint32_t RCC_DCKCFGR;     // Dedicated clock configuration

} CLOCK_RegDef_t;


/***************************************************************
 *                  SYSTICK REGISTER STRUCTURE
 *
 * This structure represents the SysTick timer registers.
 * SysTick is a 24-bit down-counter used for timing operations.
 ***************************************************************/

typedef struct
{
    volatile uint32_t CTRL;       // SysTick control and status register
    volatile uint32_t LOAD;       // SysTick reload value register
    volatile uint32_t VALUE;      // SysTick current value register
    volatile uint32_t CALIB;      // SysTick calibration value register

} SYSTICK_RegDef_t;


/***************************************************************
 *                  PERIPHERAL BASE ADDRESSES
 *
 * These macros map peripheral structures to their respective
 * memory-mapped hardware addresses.
 ***************************************************************/

#define GPIO_B \
    ((GPIO_RegDef_t *)0x40020400U)   // GPIOB peripheral base address

#define SYSTICK_DEVICE_CONTROLLER \
    ((SYSTICK_RegDef_t *)0xE000E010U) // SysTick peripheral base address

#define CLOCK_DEVICE_CONTROLLER \
    ((CLOCK_RegDef_t *)0x40023800U)   // RCC peripheral base address


#endif /* RAAYAN_MINI_H */
