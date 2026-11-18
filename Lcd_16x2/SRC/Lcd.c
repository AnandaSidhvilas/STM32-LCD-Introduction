
/***************************************************************
 *                       HEADER FILES
 ***************************************************************/

#include "Raayan_Mini.h"
#include "SysTick_Delay.h"
#include "Lcd.h"
#include <stdint.h>


/***************************************************************
 *                    GPIO PORT DECLARATION
 ***************************************************************/

// Pointer to GPIOB peripheral registers.
GPIO_RegDef_t *GPIO_B_PORT = GPIO_B;


/***************************************************************
 *                 STATIC FUNCTION DECLARATIONS
 *
 * These functions are private to this LCD driver file.
 ***************************************************************/

static void Pulse_Enable(void);
static void Data_Bit_Shift_Pin(uint8_t value);
static void Lcd_Display_Data(unsigned char value);
static void Lcd_Boot_sequences(void);


/***************************************************************
 *                  STATIC FUNCTION DEFINITIONS
 ***************************************************************/


/***************************************************************
 *                       ENABLE PULSE
 *
 * Generates a HIGH-to-LOW pulse on the LCD Enable pin.
 * The LCD reads the data/command during this pulse.
 ***************************************************************/

static void Pulse_Enable(void)
{
    // Set Enable pin HIGH.
    GPIO_B_PORT->ODR |= (1U << LCD_EN);

    MS_delay_SYS(2);

    // Set Enable pin LOW.
    GPIO_B_PORT->ODR &= ~(1U << LCD_EN);

    MS_delay_SYS(2);
}


/***************************************************************
 *                   DATA PIN CONFIGURATION
 *
 * Writes the lower 4 bits of the given value to GPIOB pins
 * connected to LCD data pins D4-D7.
 ***************************************************************/

static void Data_Bit_Shift_Pin(uint8_t value)
{
    // Clear previous data from PB0-PB3.
    GPIO_B_PORT->ODR &= ~(0x0FU);

    MS_delay_SYS(2);

    // Write new 4-bit data to PB0-PB3.
    GPIO_B_PORT->ODR |= (value & 0x0FU);
}


/***************************************************************
 *                    LCD DATA WRITE
 *
 * Sends an 8-bit character to the LCD in 4-bit mode.
 *
 * The higher nibble is transmitted first, followed by
 * the lower nibble.
 ***************************************************************/

static void Lcd_Display_Data(unsigned char value)
{
    // RS = 1: Select data register.
    // RW = 0: Select write operation.
    GPIO_B_PORT->ODR &= ~(1U << LCD_RW);
    GPIO_B_PORT->ODR |=  (1U << LCD_RS);

    // Send higher 4 bits.
    Data_Bit_Shift_Pin((value >> 4) & 0x0FU);
    Pulse_Enable();

    MS_delay_SYS(1);

    // Send lower 4 bits.
    Data_Bit_Shift_Pin(value & 0x0FU);
    Pulse_Enable();
}


/***************************************************************
 *                    LCD BOOT SEQUENCE
 *
 * Performs the LCD initialization sequence.
 * Configures the LCD for 4-bit communication and enables
 * the display.
 ***************************************************************/

static void Lcd_Boot_sequences(void)
{
    // Wait for LCD power-up.
    MS_delay_SYS(20);

    // Initialize LCD into 4-bit communication mode.
    Lcd_Command_Write(LCD_INIT_1);
    Lcd_Command_Write(LCD_INIT_2);

    // Configure LCD for 4-bit mode and 2-line display.
    Lcd_Command_Write(LCD_4BIT_2LINE);

    // Turn ON display and disable cursor.
    Lcd_Command_Write(LCD_DISPLAY_ON);

    // Set cursor to increment after each character.
    Lcd_Command_Write(LCD_ENTRY_INC);

    // Clear LCD display.
    Lcd_Clear_Display();

    // Wait for LCD clear operation to complete.
    MS_delay_SYS(2);
}

/***************************************************************
 *                  PUBLIC FUNCTION DEFINITIONS
 ***************************************************************/


/***************************************************************
 *                       LCD INITIALIZATION
 *
 * Enables GPIOB clock and configures the LCD-connected pins
 * as general-purpose output pins.
 *
 * Pin configuration:
 * PB0-PB3 : LCD data pins D4-D7
 * PB4     : LCD RS
 * PB5     : LCD RW
 * PB8     : LCD Enable
 ***************************************************************/

void Lcd_Init(void)
{
    // Enable GPIOB peripheral clock.
    CLOCK_DEVICE_CONTROLLER->RCC_AHB1ENR |= (1U << 1);


    // Configure LCD pins as general-purpose outputs.
    GPIO_B_PORT->MODER &= ~(
        (3U << (LCD_D4 * 2)) |
        (3U << (LCD_D5 * 2)) |
        (3U << (LCD_D6 * 2)) |
        (3U << (LCD_D7 * 2)) |
        (3U << (LCD_RS * 2)) |
        (3U << (LCD_RW * 2)) |
        (3U << (LCD_EN * 2))
    );

    GPIO_B_PORT->MODER |= (
        (1U << (LCD_D4 * 2)) |
        (1U << (LCD_D5 * 2)) |
        (1U << (LCD_D6 * 2)) |
        (1U << (LCD_D7 * 2)) |
        (1U << (LCD_RS * 2)) |
        (1U << (LCD_RW * 2)) |
        (1U << (LCD_EN * 2))
    );


    // Configure output type as push-pull.
    GPIO_B_PORT->OTYPER &= ~(
        (1U << LCD_D4) |
        (1U << LCD_D5) |
        (1U << LCD_D6) |
        (1U << LCD_D7) |
        (1U << LCD_RS) |
        (1U << LCD_RW) |
        (1U << LCD_EN)
    );


    // Configure output speed as low speed.
    GPIO_B_PORT->OSPEEDR &= ~(
        (3U << (LCD_D4 * 2)) |
        (3U << (LCD_D5 * 2)) |
        (3U << (LCD_D6 * 2)) |
        (3U << (LCD_D7 * 2)) |
        (3U << (LCD_RS * 2)) |
        (3U << (LCD_RW * 2)) |
        (3U << (LCD_EN * 2))
    );


    // Disable internal pull-up and pull-down resistors.
    GPIO_B_PORT->PUPDR &= ~(
        (3U << (LCD_D4 * 2)) |
        (3U << (LCD_D5 * 2)) |
        (3U << (LCD_D6 * 2)) |
        (3U << (LCD_D7 * 2)) |
        (3U << (LCD_RS * 2)) |
        (3U << (LCD_RW * 2)) |
        (3U << (LCD_EN * 2))
    );


    // Set all LCD-connected GPIO pins LOW.
    GPIO_B_PORT->BSRR = (
        (1U << (LCD_D4 + 16U)) |
        (1U << (LCD_D5 + 16U)) |
        (1U << (LCD_D6 + 16U)) |
        (1U << (LCD_D7 + 16U)) |
        (1U << (LCD_RS + 16U)) |
        (1U << (LCD_RW + 16U)) |
        (1U << (LCD_EN + 16U))
    );


    // Execute LCD initialization sequence.
    Lcd_Boot_sequences();
}


/***************************************************************
 *                     LCD COMMAND WRITE
 *
 * Sends an 8-bit instruction to the LCD in 4-bit mode.
 *
 * RS = 0: Command register
 * RW = 0: Write operation
 ***************************************************************/

void Lcd_Command_Write(uint8_t value)
{
    // Select command register and write operation.
    GPIO_B_PORT->ODR &= ~(
        (1U << LCD_RS) |
        (1U << LCD_RW)
    );

    // Send higher 4 bits.
    Data_Bit_Shift_Pin((value >> 4) & 0x0FU);
    Pulse_Enable();

    MS_delay_SYS(1);

    // Send lower 4 bits.
    Data_Bit_Shift_Pin(value & 0x0FU);
    Pulse_Enable();
}


/***************************************************************
 *                    LCD STRING WRITE
 *
 * Displays a null-terminated string on the LCD.
 *
 * Characters are transmitted one by one until the null
 * terminator ('\0') is encountered.
 ***************************************************************/

void Lcd_String_Write_Display(const char *STRING)
{
    while (*STRING != '\0')
    {
        Lcd_Display_Data(*STRING++);
    }
}


/***************************************************************
 *                     LCD DISPLAY CLEAR
 *
 * Clears the LCD display and returns the cursor to the
 * home position.
 ***************************************************************/

void Lcd_Clear_Display(void)
{
    // Send clear display command.
    Lcd_Command_Write(LCD_CLEAR);

    // Wait for LCD to complete the clear operation.
    MS_delay_SYS(2);
}

/***************************************************************
 *                 CREATE CUSTOM CHARACTER
 *
 * Creates a custom 5x8 character and stores it in CGRAM.
 *
 * location : Character location (0-7)
 * pattern  : Pointer to 8-byte character pattern
 ***************************************************************/

void Lcd_Create_Custom_Char(uint8_t location, const uint8_t *pattern)
{
    uint8_t i;

    // Check valid CGRAM location.
    if (location > 7U)
    {
        return;
    }

    // Set CGRAM address.
    Lcd_Command_Write(LCD_CGRAM | (location << 3));

    // Write 8 rows of pixel data.
    for (i = 0U; i < 8U; i++)
    {
        Lcd_Display_Data(pattern[i] & 0x1FU);
    }

    // Return cursor address to DDRAM.
    Lcd_Command_Write(LCD_LINE1);
}


/***************************************************************
 *                    SET LCD CURSOR
 *
 * Positions the cursor using row and column numbers.
 *
 * row    : 1 or 2
 * column : 1 to 16
 ***************************************************************/

void Lcd_Set_Cursor(uint8_t row, uint8_t column)
{
    uint8_t address;

    // Check valid row and column.
    if ((row < 1U) || (row > 2U) ||
        (column < 1U) || (column > 16U))
    {
        return;
    }

    // Calculate DDRAM address.
    if (row == 1U)
    {
        address = 0x80U + (column - 1U);
    }
    else
    {
        address = 0xC0U + (column - 1U);
    }

    // Move cursor to requested position.
    Lcd_Command_Write(address);
}

/***************************************************************
 *                   LCD CHARACTER WRITE
 *
 * Displays a single character or custom character on the LCD.
 *
 * value : ASCII value or CGRAM character location (0-7).
 ***************************************************************/
void Lcd_Write_Char(uint8_t value)
{
    Lcd_Display_Data(value);
}