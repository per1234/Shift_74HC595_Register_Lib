/*
 *  Library for a 74HC595 Shift Register
 */
 
#ifndef  shift_74HC595_h
#define shift_74HC595_h

#define MAX_PINS 256 // Define the maximum number of output pins for the shift register

class Shift74HC595 {
    
    public:
        
        Shift74HC595();
        
        void begin(int clk_pin, int data_pin, int latch_pin, int num_pins);
        
        void setPinValue(int pin, int state);
        
        void shiftOut();
    
    private:
        
        // Define pins for object
        int clk_pin;
        int data_pin;
        int latch_pin;
        
        int num_pins;
        
        uint8_t out_value[MAX_PINS];
    
}


#endif