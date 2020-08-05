# EasyPin

![GitHub release (latest by date)](https://img.shields.io/github/v/release/Zerfoinder/EasyPin)
![GitHub All Releases](https://img.shields.io/github/downloads/Zerfoinder/EasyPin/total)
![GitHub](https://img.shields.io/github/license/Zerfoinder/EasyPin)
![Github Arduino Library CI](https://github.com/Zerfoinder/EasyPin/workflows/Github%20Arduino%20Library%20CI/badge.svg)

EasyPin is an Arduino library to simplify access to arduino board pins.
This library is used to manage in a simple way all Arduino pins. For example, to control the turning on and off of LEDs.

If you like **EasyPin**, give it a star, or fork it and contribute!

[![donate](https://img.shields.io/badge/donate-PayPal-blue.svg)](https://paypal.me/zerfoinder)

## Installation

1. Navigate to the Releases page.
1. Download the latest release.
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

## Usage

```C++
// Include library
#include <EasyPin.h>

// Add using namespace
using namespace zsoft::io::utilities;

// Create object. Send pin number as parameter
EasyPin led(13);

void setup() {
    led.init();        // [REQUIRED] Always call init() within setup method.
}

void loop() {
    led.on();         // turn the LED on
    delay(2000);      // wait for two seconds
    led.off();        // turn the LED off
    delay(1000);      // wait for a second
}
```

## Components and functions

### PinType enum

**PintType** is an **enum** used to define pin type, there are three types: `PinType::IN`, `PinType::OUT` and `PinType::PULLUP`

### EasyPin Class

#### Example

```C++
EasyPin(13, PinType::OUT);
```

#### Public methods

| Method | Description |
| ---------- | ----------- |
| `EasyPin(int pinNumber, PinType ptype)` | Constructor. |
| `.init();` | Initialize arduino pin, it should run always in setup section. |
| `.on();`   | Turns on (set to HIGH) an Arduino pin. |
| `.off();`  | Turns off (set to LOW) an Arduino pin. |
| `.toggle();` | Toggle Arduino pin state (From ON to OFF, or from OFF to ON). |
| `.setValue(int value);`    | Set value for an Arduino PWM pin. **Note**: For PWM pins, accepts values between 0-255. |
| `.state();`    | Returns the current `bool` state of Arduino pin. Both type of pins (PWM/Digital) returns False on LOW and returns True for any other value. |
| `.value();`    | Returns value  PWM pin returns the current `int` value. Input pin returns always 0. |
| `.readValue();`    | Returns the current `unsigned long` value of Arduino INPUT pin direct from board. |

#### Code documentation

```C++
// Constructor
// param[pinNumber]  Arduino board pin number
// param[ptype]      PinType
EasyPin(int pinNumber, PinType ptype);
```

```C++
// Initialize arduino pin, it should run always in setup section.
void init();

// Turns on (set to HIGH) an Arduino pin.
void on();

// Turns off (set to LOW) an Arduino pin.
void off();

// Toggle Arduino pin state (From ON to OFF, or from OFF to ON).
void toggle();

// Set value for an Arduino PWM pin.
// note: For PWM pins, accepts values between 0-255.
void setValue(int value);

// Returns the current state of Arduino pin.
// Both type of pins (PWM/Digital) returns False on LOW and
// returns True for any other value.
bool state();

// Returns value  PWM pin returns the current value. Input
// pin returns always 0.
int value();

// Returns the current value of Arduino INPUT pin direct
// from board.
unsigned long readValue();
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

[![donate](https://img.shields.io/badge/donate-PayPal-blue.svg)](https://paypal.me/zerfoinder)

## License

This library is licensed under [GPLv3](https://www.gnu.org/licenses/quick-guide-gplv3.html).
