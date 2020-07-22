/*
  EasyPin - Button-Pullup


  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2 configured as INPUT_PULLUP.

  (Partially based on the Button arduino tutorial created by DojoDave [http://www.arduino.cc/en/Tutorial/Button]).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from ground
  - (No resistor required)

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.
*/

//-----------------------------------------
// Add include to EasyPin.h
#include <EasyPin.h>

//-----------------------------------------
// Add using namespace
using namespace zsoft::io::utilities;

//-----------------------------------------
// initialize analog pin 2 as an INPUT_PULLUP:
EasyPin button(A2, PinType::PULLUP);

// initialize EasyPin in digital 13 pin for a LED as output:
EasyPin    led(13, PinType::OUT);

void setup() {
    led.init();
    button.init();
}

void loop() {
    // check if button is pressed.
    // ---FOR PULLUP PINS
    // readValue() returns TRUE for switch open, FALSE for switch closed
    if (button.readValue()) {
        // turn LED on:
        led.on();
    } else {
        // turn LED off:
        led.off();
    }
}
