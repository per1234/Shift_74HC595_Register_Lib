/*
 *  Library for a 74HC595 Shift Register
 */

#include "Arduino.h"
#include "shift_74HC595.h"

Shift74HC595::Shift74HC595() {
    
};

void Shift74HC595::begin(int clk_pin, int data_pin, int latch_pin) {
    
    this->clk_pin = clk_pin;
    
    this->data_pin = data_pin;
    
    this->latch_pin = latch_pin;
    
    this->num_pins = 8; // Sets default number of pins as 8 (Amount of Output pins on a single 8 bit shift register)
    
    pinMode(this->clk_pin, OUTPUT);
    
    pinMode(this->data_pin, OUTPUT);
    
    pinMode(this->latch_pin, OUTPUT);
    
};

void Shift74HC595::begin(int clk_pin, int data_pin, int latch_pin, int num_pins) {
    
    this->clk_pin = clk_pin;
    
    this->data_pin = data_pin;
    
    this->latch_pin = latch_pin;
    
    this->num_pins = num_pins;
    
    pinMode(this->clk_pin, OUTPUT);
    
    pinMode(this->data_pin, OUTPUT);
    
    pinMode(this->latch_pin, OUTPUT);
    
};

void Shift74HC595::setPinValue(int pin, int state) {
    
    this->out_value[pin] = state;
    
};

void Shift74HC595::shiftOut() {
    
    for (int i = 0; i < this->num_pins; i++) {
        
        digitalWrite(this->data_pin, this->out_value[i]);
        
        digitalWrite(this->clk_pin, HIGH);
        
        delayMicroseconds(8);
        
        digitalWrite(this->clk_pin, LOW);
        
        digitalWrite(this->data_pin, LOW);
        
        delayMicroseconds(8);
        
    }
    
    digitalWrite(this->latch_pin, HIGH);
    
    delayMicroseconds(8);
    
    digitalWrite(this->latch_pin, LOW);
    
};

