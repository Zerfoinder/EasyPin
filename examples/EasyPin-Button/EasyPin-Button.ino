/*
  EasyPin - Button


  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  (Based on the Button arduino tutorial created by DojoDave [http://www.arduino.cc/en/Tutorial/Button]).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

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
EasyPin button(A2, PinType::IN);

// initialize EasyPin in digital 13 pin for a LED as output:
EasyPin    led(13, PinType::OUT);

void setup() {
    led.init();
    button.init();
}

void loop() {
    // check if button is pressed.
    // ---For IN pins
    // readValue() returns TRUE for switch closed, FALSE for switch open
    if (button.readValue()) {
        // turn LED on:
        led.on();
    } else {
        // turn LED off:
        led.off();
    }
}
