
#ifndef SYSTICK_DELAY_H
#define SYSTICK_DELAY_H

/***************************************************************
 *                       HEADER FILE
 *
 * This file contains the function declaration for generating
 * millisecond delays using the STM32 SysTick timer.
 ***************************************************************/

 #include <stdint.h>

/***************************************************************
 *                    FUNCTION DECLARATION
 ***************************************************************/

/*
 * Function : MS_delay_SYS()
 *
 * Purpose  : Generates a delay using the SysTick timer.
 *
 * Parameter:
 * value    : Delay duration in milliseconds.
 *
 * Return   : None.
 */
void MS_delay_SYS(uint32_t value);


#endif /* SYSTICK_DELAY_H */
