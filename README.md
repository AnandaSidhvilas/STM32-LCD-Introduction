
# 🚀 STM32F401RBT6 – 16×2 LCD Driver Using Bare-Metal Embedded C

### From Registers to Pixels!

A bare-metal embedded systems project demonstrating how to interface an HD44780-compatible 16×2 character LCD with the STM32F401RBT6 microcontroller using a 4-bit parallel communication interface.

This project focuses on developing a custom LCD driver through direct memory-mapped register access, without depending on high-level STM32 HAL libraries or an I2C LCD interface.

The goal is to understand how microcontrollers communicate with external peripherals at the hardware level while building a reusable LCD driver using Embedded C.

---

## 📌 Project Overview

This project is part of my journey into Firmware and Embedded Systems Development.

Rather than simply displaying characters on an LCD, I wanted to understand what happens behind the scenes when a microcontroller communicates with an external display.

### Implementation Highlights

- Direct STM32 peripheral register configuration.
- GPIO initialization and pin control.
- LCD initialization in 4-bit mode.
- Command and data transmission.
- Upper and lower nibble handling.
- Cursor positioning and string display.
- Custom character generation using CGRAM.
- Millisecond delays using the SysTick timer.

The LCD displays a sequence of personal introduction messages, along with support for custom characters.

---

## 🛠️ Hardware Requirements

| Component | Specification |
|---|---|
| Microcontroller | STM32F401RBT6 |
| Display | 16×2 Character LCD |
| LCD Controller | HD44780 Compatible |
| Communication Interface | 4-bit Parallel |
| GPIO Port | GPIOB |
| Programming Language | Embedded C |

---

## 💻 Software & Development Environment

| Tool / Technology | Purpose |
|---|---|
| Visual Studio Code | Source code editing |
| Keil MDK 6 | Build and development environment |
| CMSIS | Cortex-M and STM32 device support |
| Git | Version control |
| GitHub | Source code hosting |

---

## 🔌 Hardware Connections

The LCD is connected to the STM32F401RBT6 through GPIOB.

Four GPIO pins are used for data transmission, while three additional pins handle LCD control operations.

### GPIO Pin Configuration

| LCD Pin | STM32 Pin | Function |
|---|---|---|
| D4 | PB0 | Data bit 4 |
| D5 | PB1 | Data bit 5 |
| D6 | PB2 | Data bit 6 |
| D7 | PB3 | Data bit 7 |
| RS | PB4 | Register Select |
| RW | PB5 | Read / Write |
| EN | PB8 | Enable |

### Additional Connections

- **VSS** → GND
- **VDD** → LCD-supported supply voltage
- **V0** → Potentiometer for contrast adjustment

**Communication:** 4-bit Parallel Interface.

---

## ⚙️ Features Implemented

### STM32 Peripheral Configuration

- Direct memory-mapped register programming.
- RCC peripheral clock enable for GPIOB.
- GPIO mode configuration using `MODER`.
- Output type configuration using `OTYPER`.
- Output speed configuration using `OSPEEDR`.
- Pull-up and pull-down configuration using `PUPDR`.

### LCD Driver Functionality

- LCD initialization in 4-bit mode.
- LCD command transmission.
- LCD data transmission.
- Upper and lower nibble processing.
- Enable pulse generation.
- Cursor positioning using row and column.
- String display functionality.
- Custom character generation using CGRAM.

### Timing Implementation

- SysTick timer configuration.
- Millisecond-based delay implementation.
- Timing control for LCD operations.

---

## 🧩 LCD Driver Architecture

The project follows a modular structure to separate peripheral definitions, LCD operations, timing functionality, and application logic.

| Module | Responsibility |
|---|---|
| `Raayan_Mini.h` | Peripheral register definitions and memory addresses |
| `Lcd.h` | LCD commands, pin definitions, and function declarations |
| `Lcd.c` | LCD initialization, command/data transmission, and display operations |
| `SysTick_Delay.h` | Delay function declarations |
| `SysTick_Delay.c` | SysTick-based millisecond delay implementation |
| `main.c` | Application logic and LCD display sequences |

This modular approach makes the driver easier to understand, maintain, and extend.

---

## 🔄 Understanding LCD Communication – 4-Bit Mode

The LCD uses a 4-bit parallel interface, meaning that only four data lines (D4–D7) are required to communicate with the controller.

Since LCD commands and character data are 8 bits wide, each byte is transmitted in two stages.

### 1. Upper Nibble Transmission

The upper four bits (D7–D4) are placed on the LCD data pins.

### 2. Lower Nibble Transmission

The lower four bits (D3–D0) are transmitted using the same four data pins.

An Enable (EN) pulse is generated after each nibble to latch the data into the LCD controller.

This approach reduces GPIO pin requirements compared with an 8-bit parallel interface.

---

## 🎨 Custom Character Generation – CGRAM

One of the interesting features of this project is the implementation of custom characters using the LCD's **Character Generator RAM (CGRAM)**.

An HD44780-compatible LCD supports up to eight custom characters in 5×8 dot mode.

Each character is defined using an 8-byte pattern, with each byte representing one row of the character bitmap.

### Custom Character Mapping

| CGRAM Address | Character | Purpose |
|---|---|---|
| 0 | Smiley | Greeting |
| 1 | Heart | Introduction |
| 2 | Arrow | Learning journey |
| 3 | Star | Technical interests |

These characters are generated using custom pixel patterns and displayed through their corresponding CGRAM character codes.

**Note:** Custom LCD characters use CGRAM character codes rather than standard Unicode symbols.

---

## 📺 LCD Display Sequences

The LCD continuously cycles through a collection of personal introduction messages.

### 01. Greeting

```text
YO LINKEDIN!
WHAT'S UP? :D
```

### 02. Introduction

```text
IT'S ANANDA!
NICE TO MEET U
```

### 03. Learning Journey

```text
NEWBIE MODE ON
LEVELING UP!
```

### 04. Technical Interests

```text
FIRMWARE NERD
EMBEDDED LIFE
```

### 05. Technical Skills

```text
C IS MY VIBE
DRIVER LOADING
```

### 06. Developer Mindset

```text
NO CAP, JUST
CODE & LEARN!
```

Each sequence demonstrates LCD text handling, cursor positioning, and display control.

---

## 🧠 Key Learning Outcomes

Working on this project helped me develop a deeper understanding of:

- Memory-mapped peripheral register programming.
- STM32 GPIO peripheral configuration.
- RCC clock management.
- Register-level hardware control.
- 4-bit parallel communication.
- LCD command and data handling.
- CGRAM-based custom character generation.
- SysTick timer configuration and delays.
- Modular Embedded C driver development.
- Reading and interpreting microcontroller datasheets and technical reference manuals.

One important takeaway was understanding the differences between parallel and serial communication, including their respective advantages, limitations, and hardware requirements.

---

## 🚀 Future Improvements

There is still plenty of room to extend this project.

- [ ] Implement LCD text scrolling.
- [ ] Add animated custom characters.
- [ ] Implement button-controlled display navigation.
- [ ] Improve timing using interrupt-based SysTick.
- [ ] Develop reusable GPIO drivers.
- [ ] Explore UART, SPI, and I2C peripheral drivers.
- [ ] Improve LCD driver portability across STM32 microcontrollers.

---

## 📂 Repository Structure

```text
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
```

---

## 👨‍💻 Developer

**D. Ananda Sidhvilas**

Aspiring Firmware / Embedded Systems Engineer.

### Currently Exploring

- Embedded C Programming
- STM32 Microcontrollers
- Bare-Metal Development
- GPIO and Peripheral Drivers
- Microcontroller Architecture
- Low-Level Device Driver Development

---

## 🤝 Connect With Me

**LinkedIn:** DUNNA ANANDA SIDHVILAS

---

### 🔧 BUILD. BREAK. DEBUG. REPEAT.

*Learning one register at a time. Building one project at a time.*
