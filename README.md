🚀 STM32F401RBT6 – 16×2 LCD Driver Using Bare-Metal Embedded C

From Registers to Pixels!

A hands-on embedded systems project focused on interfacing a 16×2 character LCD with the STM32F401RBT6 microcontroller using 4-bit Parallel Communication through GPIO.

Instead of relying on an I2C LCD module or high-level HAL libraries, this project explores how LCD communication works at the register level by developing a custom LCD device driver using Bare-Metal Embedded C.

The LCD displays a personal introduction with multiple greeting sequences and custom characters.

📌 Project Overview

Hey LinkedIn! What's up? 👋

This project is part of my journey into Firmware and Embedded Systems Development.

The objective was not just to display text on an LCD, but to understand the underlying communication mechanism between a microcontroller and an external peripheral.

I configured GPIO registers, implemented LCD command and data transmission, explored 4-bit parallel communication, and created custom characters using the LCD's CGRAM.

🛠️ Hardware Requirements
Component	Specification
Microcontroller	STM32F401RBT6
Display	16×2 Character LCD
LCD Controller	HD44780 compatible
Communication	4-bit Parallel
GPIO Port	GPIOB
Programming Language	Embedded C
💻 Software & Development Environment
Tool	Purpose
Visual Studio Code	Code editing
Keil MDK 6	Build and development environment
CMSIS	Cortex-M and device support
Git	Version control
GitHub	Source code hosting
🔌 Hardware Connections

The LCD is interfaced with STM32 GPIOB using four data pins and three control pins.

LCD Pin	STM32 Pin	Function
D4	PB0	Data bit 4
D5	PB1	Data bit 5
D6	PB2	Data bit 6
D7	PB3	Data bit 7
RS	PB4	Register Select
RW	PB5	Read / Write
EN	PB8	Enable

Additional LCD connections:

VSS → GND
VDD → Supply voltage supported by the LCD module
V0 → Potentiometer for contrast adjustment

Communication mode: 4-bit Parallel Interface.

⚙️ Features Implemented
Direct memory-mapped peripheral register access.
RCC clock enable for GPIOB.
GPIO output configuration using MODER.
Output type configuration using OTYPER.
GPIO speed configuration using OSPEEDR.
Pull-up / Pull-down configuration using PUPDR.
LCD initialization in 4-bit mode.
LCD command and data transmission.
Upper and lower nibble transmission.
Cursor positioning using row and column.
String display functionality.
Custom character generation using CGRAM.
SysTick-based millisecond delay.
Multiple LCD greeting and introduction sequences.
🧩 LCD Driver Architecture

The project is organized into reusable modules.

Module	Responsibility
Raayan_Mini.h	Peripheral register definitions and memory addresses
Lcd.h	LCD commands, pin definitions and function declarations
Lcd.c	LCD initialization, commands, data and display operations
SysTick_Delay.h	Delay function declaration
SysTick_Delay.c	SysTick-based millisecond delay
main.c	Application logic and LCD display sequences
🔄 LCD Communication – 4-Bit Parallel Mode

The LCD operates using a 4-bit data interface.

Each 8-bit command or character is transmitted in two stages:

Upper nibble (D7–D4).
Lower nibble (D7–D4).

The Enable pin is pulsed to latch each nibble into the LCD controller.

This approach reduces the number of GPIO pins required compared with an 8-bit interface.

🎨 Custom Character Generation

One interesting feature of this project is generating custom characters using the LCD's Character Generator RAM (CGRAM).

An HD44780-compatible LCD supports up to eight user-defined characters in 5×8 dot mode.

Custom characters are created using 8-byte pixel patterns.

Planned character designs include:

CGRAM Location	Character	Usage
0	Smiley	Greeting
1	Heart	Introduction
2	Arrow	Learning journey
3	Star	Technical interests
📺 LCD Display Sequence

The LCD continuously displays a series of introduction messages.

01 – Greeting

text
YO LINKEDIN!
WHAT'S UP? :D


02 – Introduction

text
IT'S ANANDA!
NICE TO MEET U


03 – Learning Journey

text
NEWBIE MODE ON
LEVELING UP!


04 – Technical Interests

text
FIRMWARE NERD
EMBEDDED LIFE


05 – Technical Skills

text
C IS MY VIBE
DRIVER LOADING


06 – Developer Mindset

text
NO CAP, JUST
CODE & LEARN!


Custom characters are represented by CGRAM character codes, not standard Unicode symbols.

🧠 Key Learning Outcomes

Through this project, I explored:

Memory-mapped register programming.
STM32 GPIO peripheral configuration.
RCC peripheral clock management.
LCD 4-bit parallel communication.
LCD command and data handling.
CGRAM-based custom character generation.
SysTick timer and delay implementation.
Modular Embedded C driver development.
Reading and understanding technical documentation.

An important part of this project was exploring the differences between parallel and serial communication and understanding their respective advantages and trade-offs.

🚀 Future Improvements
Implement LCD display scrolling.
Add animated custom characters.
Implement button-controlled display navigation.
Improve timing using interrupt-based SysTick.
Develop reusable GPIO drivers.
Explore UART, SPI and I2C peripheral drivers.
Improve LCD driver portability.
📂 Repository Structure
text
Parallel_GPIO_Com/
│
├── .cmsis/
│
├── Character_Genarator/
│   └── LCD_Character_Generator.html
│
├── Lcd_16x2/
│   │
│   ├── INC/
│   │   ├── Lcd.h
│   │   ├── Raayan_Mini.h
│   │   └── SysTick_Delay.h
│   │
│   ├── SRC/
│   │   ├── Lcd.c
│   │   └── SysTick_Delay.c
│   │
│   ├── RTE/
│   │   └── Device/
│   │
│   ├── main.c
│   └── Lcd_16x2.cproject.yml
│
├── Lcd_Drivers.cbuild-pack.yml
├── Lcd_Drivers.csolution.yml
├── vcpkg-configuration.json
├── .gitignore
└── README.md

👨‍💻 Developer

D. Ananda Sidhvilas

Aspiring Firmware / Embedded Systems Engineer.

Currently exploring:

Embedded C
STM32 Microcontrollers
Bare-Metal Programming
GPIO and Peripheral Drivers
Microcontroller Architecture
Low-Level Device Driver Development
🤝 Connect With Me

LinkedIn – DUNNA ANANDA SIDHVILAS

BUILD. BREAK. DEBUG. REPEAT. 🔧

Learning one register at a time. Building one project at a time.
