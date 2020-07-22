/*
 EasyPin - Blink

 Code sample to turns an LED on for one second, then off for one second,
 repeatedly. Using EasyPin library.

 Based on the blink arduino tutorial (http://www.arduino.cc/en/Tutorial/Blink).

 Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
 it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
 the correct LED pin independent of which board is used. If you want to know
 what pin the on-board LED is connected to on your Arduino model, check the
 Technical Specs of your board at: https://www.arduino.cc/en/Main/Products
*/

//-----------------------------------------
// Add include to EasyPin
#include <EasyPin.h>

//-----------------------------------------
// Add using namespace
using namespace zsoft::io::utilities;

//-----------------------------------------
// Declare an EasyPin object using LED_BUILTIN as pin number, and OUT to define
// Mode. In order to this test works for any Arduino board, LED_BUILTIN is
// selected as pin number. Any other pin could be selected.
EasyPin led(LED_BUILTIN, PinType::OUT);

// setup function runs once when you press reset or power the board
void setup() {

    // initialize led
    led.init();       // [REQUIRED]

}

// the loop function runs over and over again forever
void loop() {
    led.on();         // turn the LED on
    delay(2000);      // wait for two seconds
    led.off();        // turn the LED off
    delay(1000);      // wait for a second
}
