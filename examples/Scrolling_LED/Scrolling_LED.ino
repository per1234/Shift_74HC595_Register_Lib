/*
 * Scrolling LED - Phillip Steiner 5/28/16
 * 
 * Uses:
 *  1x 74HC595 Serial in, Parallel out shift register
 *  8x LED
 *  1x limiting resistor (~200 ohm)
 * 
 * Connect:
 * 
 *  Arduino -> 74HC595
 *  ==================
 *  Pin 7 -> SRCLK or SHCP (Serial Input Clock)
 *  Pin 6 -> DS or SER (Serial Data Input)
 *  Pin 5 -> RCLK or STCP (Storage Register Clock)
 *  5v -> Vcc
 *  5v -> SRCLR or MR (Serial Clear)
 *  GND -> GND
 *  GND -> OE (Output Enable)
 *  
 *  Connect the Anode (Long end) of one led to pin Q0 of the shift register.
 *  Connect the Cathode (Short end) of the led to the limiting resistor
 *  Connect the other end of the limiting resistor to GND
 *  Repeat for all pins of the shift register
 *  
 */


#include <shift_74HC595.h>

Shift74HC595 reg; 

void setup() {
  // reg.begin(serial_clock_pin, serial_data_pin, storage_clock_pin);
  reg.begin(7, 6, 5); // Set pin modes to output mode for shift register
}

void loop() {
  for (int pin = 0; pin < 8; pin ++) { // Loop 8 times because we are using an 8 bit shift register
    reg.setPinValue(pin, HIGH); // Set current pin High
    reg.shiftOut(); // Output values to parallel pins
  
    delay(100); // Wait a bit
    
    reg.setPinValue(pin, LOW); // Set current pin Low
    reg.shiftOut(); // Output values to parallel pins
  }
}
