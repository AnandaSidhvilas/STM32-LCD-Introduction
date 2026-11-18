#include "RTE_Components.h"
#include CMSIS_device_header

#include "Raayan_Mini.h"
#include "Lcd.h"
#include "SysTick_Delay.h"

#include <stdint.h>


/***************************************************************
 *                 CUSTOM CHARACTER PATTERNS
 ***************************************************************/

// Character 0: Smiley
uint8_t smiley[8] =
{
    0x00, 0x0A, 0x00, 0x00,
    0x11, 0x0E, 0x00, 0x00
};

// Character 1: Heart
uint8_t heart[8] =
{
    0x00, 0x0A, 0x1F, 0x1F,
    0x0E, 0x04, 0x00, 0x00
};

// Character 2: Right Arrow
uint8_t arrow[8] =
{
    0x04, 0x02, 0x1F, 0x02,
    0x04, 0x00, 0x00, 0x00
};

// Character 3: Star
uint8_t star[8] =
{
    0x04, 0x15, 0x0E, 0x1F,
    0x0E, 0x15, 0x04, 0x00
};


/***************************************************************
 *                    MAIN FUNCTION
 ***************************************************************/

int main(void)
{
    // Initialize LCD.

Lcd_Init();


    /***********************************************************
     *                LOAD CUSTOM CHARACTERS
     ***********************************************************/

    Lcd_Create_Custom_Char(0U, smiley);
    Lcd_Create_Custom_Char(1U, heart);
    Lcd_Create_Custom_Char(2U, arrow);
    Lcd_Create_Custom_Char(3U, star);


    /***********************************************************
     *                    INFINITE LOOP
     ***********************************************************/

    for (;;)
    {

        //=======================================================
        // SCREEN 1: GREETING
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_Write_Char(0U);  // Smiley
        Lcd_String_Write_Display(" YO LINKEDIN!");

        Lcd_Set_Cursor(2U, 1U);
        Lcd_String_Write_Display("WHAT'S UP? :D");

        MS_delay_SYS(2500U);


        //=======================================================
        // SCREEN 2: INTRODUCTION
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_String_Write_Display("IT'S ANANDA!");

        Lcd_Set_Cursor(1U, 14U);
        Lcd_Write_Char(1U);  // Heart

        Lcd_Set_Cursor(2U, 1U);
        Lcd_String_Write_Display("NICE TO MEET U");

        MS_delay_SYS(2500U);


        //=======================================================
        // SCREEN 3: BEGINNER JOURNEY
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_String_Write_Display("NEWBIE MODE ON");

        Lcd_Set_Cursor(1U, 15U);
        Lcd_Write_Char(2U);  // Arrow

        Lcd_Set_Cursor(2U, 1U);
        Lcd_String_Write_Display("LEVELING UP!");

        MS_delay_SYS(2500U);


        //=======================================================
        // SCREEN 4: TECHNICAL INTERESTS
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_Write_Char(3U);  // Star
        Lcd_String_Write_Display(" FIRMWARE NERD");

        Lcd_Set_Cursor(2U, 1U);
        Lcd_String_Write_Display("EMBEDDED LIFE");

        MS_delay_SYS(2500U);


        //=======================================================
        // SCREEN 5: TECHNICAL SKILLS
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_String_Write_Display("C IS MY VIBE");

        Lcd_Set_Cursor(1U, 14U);
        Lcd_Write_Char(3U);  // Star

        Lcd_Set_Cursor(2U, 1U);
        Lcd_String_Write_Display("DRIVER LOADING");

        MS_delay_SYS(2500U);


        //=======================================================
        // SCREEN 6: CLOSING MESSAGE
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_String_Write_Display("NO CAP, JUST");

        Lcd_Set_Cursor(1U, 15U);
        Lcd_Write_Char(0U);  // Smiley

        Lcd_Set_Cursor(2U, 1U);
        Lcd_String_Write_Display("CODE & LEARN!");

        MS_delay_SYS(2500U);


        //=======================================================
        // SCREEN 7: FINAL THANK YOU
        //=======================================================

        Lcd_Clear_Display();

        Lcd_Set_Cursor(1U, 1U);
        Lcd_Write_Char(1U);  // Heart
        Lcd_String_Write_Display(" THANK YOU!");

        Lcd_Set_Cursor(2U, 1U);
        Lcd_Write_Char(3U);  // Star
        Lcd_String_Write_Display(" SEE YOU SOON!");

        MS_delay_SYS(3000U);

    }
}