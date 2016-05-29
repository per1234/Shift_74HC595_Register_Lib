/*
 * Cascading Shift Registers - Phillip Steiner 5/28/16
 *
 * Uses:
 *  3x 74HC595 Serial in, Parallel out shift register
 *  24x LED
 *  1x limiting resistor (~200 ohm)
 * 
 * Connect:
 * 
 *  Arduino -> 74HC595 (connect to all shift registers unless otherwise specified)
 *  ==================
 *  Pin 7 -> SRCLK or SHCP (Serial Input Clock)
 *  Pin 6 -> DS or SER (Serial Data Input) (only connect to shift register #1)
 *  Pin 5 -> RCLK or STCP (Storage Register Clock)
 *  5v -> Vcc
 *  5v -> SRCLR or MR (Serial Clear)
 *  GND -> GND
 *  GND -> OE (Output Enable)
 *  
 *  Connect the QH (Serial Output) pin of shift register #1 to DS or SER of shift register #2
 *  Connect the QH (Serial Output) pin of shift register #2 to DS or SER of shift register #3
 *  
 *  Connect the Anode (Long end) of one led to pin Q0 of shift register #1.
 *  Connect the Cathode (Short end) of the led to the limiting resistor
 *  Connect the other end of the limiting resistor to GND
 *  Repeat for all pins of all shift registers
 *  
 */

#include <shift_74HC595.h>
#define NUM_PINS 24 // Define the number of pins the shift registers will have combined. 3 8 bit shift registers have a total of 24 bits

Shift74HC595 reg;

void setup() {
  // reg.begin(serial_clock_pin, serial_data_pin, storage_clock_pin, number_of_pins);
  reg.begin(7, 6, 5, NUM_PINS); // Set pin modes to output mode for shift register (s) and set number of pins
}

void loop() {
  reg.setPinValue(random(0, NUM_PINS-1), random(0,2)); // Set a random pin to a random state
  reg.shiftOut(); // Output values to parallel pins

  delay(10); // Wait a bit
}
