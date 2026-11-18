
#ifndef LCD_H
#define LCD_H

/***************************************************************
 *                       HEADER FILE
 ***************************************************************/

#include <stdint.h>


/***************************************************************
 *                    LCD PIN DEFINITIONS
 *
 * Defines the GPIO pin numbers connected to the LCD.
 *
 * Data pins : D4, D5, D6, D7
 * Control pins: RS, RW, EN
 *
 * Used for 4-bit LCD communication.
 ***************************************************************/

#define LCD_D4       0U     // LCD data pin D4
#define LCD_D5       1U     // LCD data pin D5
#define LCD_D6       2U     // LCD data pin D6
#define LCD_D7       3U     // LCD data pin D7

#define LCD_RS       4U     // Register Select pin
#define LCD_RW       5U     // Read/Write pin
#define LCD_EN       8U     // Enable pin


/***************************************************************
 *                    LCD COMMAND DEFINITIONS
 ***************************************************************/


/***************************************************************
 *                 LCD INITIALIZATION COMMANDS
 *
 * Commands used to initialize the LCD in 4-bit mode.
 ***************************************************************/

#define LCD_INIT_1          0x33U
#define LCD_INIT_2          0x32U


/***************************************************************
 *                       FUNCTION SET
 *
 * Configures the LCD interface mode and display lines.
 ***************************************************************/

// 8-bit interface mode
#define LCD_8BIT_1LINE      0x30U    // 8-bit mode, 1 line
#define LCD_8BIT_2LINE      0x38U    // 8-bit mode, 2 lines

// 4-bit interface mode
#define LCD_4BIT_1LINE      0x20U    // 4-bit mode, 1 line
#define LCD_4BIT_2LINE      0x28U    // 4-bit mode, 2 lines


/***************************************************************
 *                     DISPLAY CONTROL
 *
 * Controls display, cursor, and cursor blinking.
 ***************************************************************/

// Display ON/OFF
#define LCD_DISPLAY_ON      0x0CU
#define LCD_DISPLAY_OFF     0x08U

// Cursor ON/OFF
#define LCD_CURSOR_ON       0x0AU
#define LCD_CURSOR_OFF      0x0CU

// Cursor blinking ON/OFF
#define LCD_BLINK_ON        0x0FU
#define LCD_BLINK_OFF       0x0EU


/***************************************************************
 *                      ENTRY MODE SET
 *
 * Controls cursor direction and automatic display shifting.
 ***************************************************************/

// Cursor increment/decrement
#define LCD_ENTRY_INC       0x06U
#define LCD_ENTRY_DEC       0x04U

// Automatic display shift
#define LCD_ENTRY_SHIFT_ON  0x07U
#define LCD_ENTRY_SHIFT_OFF 0x06U


/***************************************************************
 *                       DISPLAY SHIFT
 *
 * Shifts the entire display without changing DDRAM contents.
 ***************************************************************/

#define LCD_SHIFT_LEFT      0x18U
#define LCD_SHIFT_RIGHT     0x1CU


/***************************************************************
 *                      CURSOR MOVEMENT
 *
 * Moves the cursor one position left or right.
 ***************************************************************/

#define LCD_CURSOR_LEFT     0x10U
#define LCD_CURSOR_RIGHT    0x14U


/***************************************************************
 *                     CLEAR AND HOME
 ***************************************************************/

#define LCD_CLEAR           0x01U    // Clear display
#define LCD_HOME            0x02U    // Return cursor to home position


/***************************************************************
 *                     DDRAM ADDRESS
 *
 * Defines the starting addresses of LCD display lines.
 ***************************************************************/

#define LCD_LINE1           0x80U    // First row starting address
#define LCD_LINE2           0xC0U    // Second row starting address


/***************************************************************
 *                     CGRAM ADDRESS
 *
 * Used to access Character Generator RAM for custom characters.
 ***************************************************************/

#define LCD_CGRAM           0x40U


/***************************************************************
 *                    DDRAM POSITION DEFINITIONS
 *
 * Defines cursor positions for a 16x2 character LCD.
 ***************************************************************/

// First row (Column 1 to Column 16)
#define LCD_ROW1_COL1       0x80U
#define LCD_ROW1_COL2       0x81U
#define LCD_ROW1_COL3       0x82U
#define LCD_ROW1_COL4       0x83U
#define LCD_ROW1_COL5       0x84U
#define LCD_ROW1_COL6       0x85U
#define LCD_ROW1_COL7       0x86U
#define LCD_ROW1_COL8       0x87U
#define LCD_ROW1_COL9       0x88U
#define LCD_ROW1_COL10      0x89U
#define LCD_ROW1_COL11      0x8AU
#define LCD_ROW1_COL12      0x8BU
#define LCD_ROW1_COL13      0x8CU
#define LCD_ROW1_COL14      0x8DU
#define LCD_ROW1_COL15      0x8EU
#define LCD_ROW1_COL16      0x8FU

// Second row (Column 1 to Column 16)
#define LCD_ROW2_COL1       0xC0U
#define LCD_ROW2_COL2       0xC1U
#define LCD_ROW2_COL3       0xC2U
#define LCD_ROW2_COL4       0xC3U
#define LCD_ROW2_COL5       0xC4U
#define LCD_ROW2_COL6       0xC5U
#define LCD_ROW2_COL7       0xC6U
#define LCD_ROW2_COL8       0xC7U
#define LCD_ROW2_COL9       0xC8U
#define LCD_ROW2_COL10      0xC9U
#define LCD_ROW2_COL11      0xCAU
#define LCD_ROW2_COL12      0xCBU
#define LCD_ROW2_COL13      0xCCU
#define LCD_ROW2_COL14      0xCDU
#define LCD_ROW2_COL15      0xCEU
#define LCD_ROW2_COL16      0xCFU

/***************************************************************
 *                  CUSTOM CHARACTER DEFINITIONS
 ***************************************************************/

#define LCD_CUSTOM_CHAR_0    0U
#define LCD_CUSTOM_CHAR_1    1U
#define LCD_CUSTOM_CHAR_2    2U
#define LCD_CUSTOM_CHAR_3    3U
#define LCD_CUSTOM_CHAR_4    4U
#define LCD_CUSTOM_CHAR_5    5U
#define LCD_CUSTOM_CHAR_6    6U
#define LCD_CUSTOM_CHAR_7    7U


/***************************************************************
 *                    FUNCTION DECLARATIONS
 ***************************************************************/

// Initializes the LCD in 4-bit communication mode.
void Lcd_Init(void);

// Sends a command instruction to the LCD.
void Lcd_Command_Write(uint8_t value);

// Writes a string to the LCD display.
void Lcd_String_Write_Display(const char *STRING);

// Clears all characters from the LCD display.
void Lcd_Clear_Display(void);

// Creates a custom 5x8 character and stores it in CGRAM.
void Lcd_Create_Custom_Char(uint8_t location, const uint8_t *pattern);

// Sets the cursor to the specified row and column.
void Lcd_Set_Cursor(uint8_t row, uint8_t column);

// Writes a single ASCII or custom character to the LCD.
void Lcd_Write_Char(uint8_t value);


#endif /* LCD_H */
