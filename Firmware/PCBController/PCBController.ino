#include <Joystick.h>

// Initialize Gamepad with 14 buttons and 2 dual-axis joysticks (X, Y, Rx, Ry)
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
  JOYSTICK_TYPE_GAMEPAD, 
  14, 0,                 // 14 Buttons, 0 Hat Switches
  true, true, false,     // Joystick 1: X Axis, Y Axis
  true, true, false,     // Joystick 2: Rx Axis, Ry Axis
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

// Arduino IDE pins mapped from ATmega32U4 physical pins:
// [28, 29, 30, 12, 18, 19, 20, 21, 25, 22, 26, 27] + [31, 32]
const int buttonPins[14] = {
  8,  9, 10, 11, // Pins 28, 29, 30, 12
  3,  2,  0,  1, // Pins 18, 19, 20, 21
  4, 30, 12,  6, // Pins 25, 22, 26, 27
  5, 13          // Pins 31, 32 (Joystick Click Buttons)
};

// Potentiometer Analog Pins
const int joy1X = A5; // IC Pin 41
const int joy1Y = A4; // IC Pin 40
const int joy2X = A3; // IC Pin 39
const int joy2Y = A2; // IC Pin 38

void setup() {
  // Configure all 14 button pins as pull up
  for (int i = 0; i < 14; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  //Begin joystick library
  Joystick.begin();
  
  //Set joystick range (0-1023)
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
  Joystick.setRxAxisRange(0, 1023);
  Joystick.setRyAxisRange(0, 1023);
}

void loop() {
  // Re-assert PD5 (ATmega Pin 22 / Arduino Pin 30) as INPUT with internal PULLUP
  DDRD &= ~(1 << 5);  // Clear direction bit (sets as INPUT)
  PORTD |= (1 << 5);  // Set port bit (enables internal Pull-up)

  //Read Buttons
  for (int i = 0; i < 14; i++) {
    Joystick.setButton(i, !digitalRead(buttonPins[i]));
  }

  //Read Joysticks
  Joystick.setXAxis(analogRead(joy1X));   
  Joystick.setYAxis(analogRead(joy1Y));   
  Joystick.setRxAxis(analogRead(joy2X));  
  Joystick.setRyAxis(analogRead(joy2Y));  

  delay(10); 
}