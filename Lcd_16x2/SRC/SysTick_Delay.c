
/***************************************************************
 *                       HEADER FILES
 ***************************************************************/

#include "SysTick_Delay.h"
#include "Raayan_Mini.h"
#include <stdint.h>


/***************************************************************
 *                  SYSTICK REGISTER POINTER
 *
 * Pointer to the SysTick peripheral registers.
 * Used to access the hardware timer directly.
 ***************************************************************/

SYSTICK_RegDef_t *SYSTICK_DEVICE = SYSTICK_DEVICE_CONTROLLER;


/***************************************************************
 *                  FUNCTION DEFINITIONS
 ***************************************************************/


/***************************************************************
 *                    SYSTICK DELAY FUNCTION
 *
 * Function : MS_delay_SYS()
 *
 * Purpose  : Generates a delay in milliseconds using the
 *            ARM Cortex-M SysTick timer.
 *
 * Parameter:
 * value    : Delay duration in milliseconds.
 *
 * Working:
 * 1. Reset the current SysTick counter value.
 * 2. Configure the reload value for 1 ms.
 * 3. Enable SysTick with the processor clock.
 * 4. Wait for the COUNTFLAG after every millisecond.
 * 5. Repeat until the requested delay is completed.
 * 6. Disable the SysTick timer.
 *
 ***************************************************************/

void MS_delay_SYS(uint32_t value)
{
    volatile uint32_t count = 0;

    // Reset the current SysTick counter value.
    SYSTICK_DEVICE->VALUE = 0U;

    // Configure reload value for a 1 ms delay.
    // Assumes a 16 MHz processor clock.
    SYSTICK_DEVICE->LOAD = 16000U - 1U;

    // Enable SysTick and select processor clock.
    // ENABLE = 1, TICKINT = 0, CLKSOURCE = 1.
    SYSTICK_DEVICE->CTRL |= 5U;


    // Wait until the requested delay is completed.
    while (count < value)
    {
        // Wait for the COUNTFLAG (bit 16).
        while (!(SYSTICK_DEVICE->CTRL & (1U << 16)))
        {
            // Wait for one millisecond.
        }

        count++;
    }


    // Disable SysTick timer.
    SYSTICK_DEVICE->CTRL &= ~(1U << 0);
}
