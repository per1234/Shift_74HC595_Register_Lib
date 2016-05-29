/*
 *  Library for a 74HC595 Shift Register
 */
 
#ifndef  shift_74HC595_h
#define shift_74HC595_h

#define MAX_PINS 128 // Define the maximum number of output pins for the shift register
#define PULSE_DELAY 8 // Pulse lick delay length (microseconds)

class Shift74HC595 {
    
    public:
        
        Shift74HC595();
        
        void begin(int clk_pin, int data_pin, int latch_pin); // Set PinModes with the default 8 pins
        
        void begin(int clk_pin, int data_pin, int latch_pin, int num_pins); // Set pinModes with a specified # of pins
        
        void setPinValue(int pin, int state); // Write to array in preperation to shiftOut()
        
        void shiftOut(); // Output pulses
        
        void fastWrite(uint8_t pin, uint8_t val); // Stripped down digital write
    
    private:
        
        // Define pins for object
        int clk_pin;
        int data_pin;
        int latch_pin;
        
        int num_pins;
        
        uint8_t out_value[MAX_PINS]; // Array for storing parallel pin values
    
};


#endif