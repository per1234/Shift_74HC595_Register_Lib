/*
 *  Library for a 74HC595 Shift Register
 */

#include "Arduino.h"


Shift74HC595::Shift74HC595() {
    
}

void Shift74HC595::begin(int clk_pin, int data_pin, int latch_pin, int num_pins) {
    
    this->clk_pin = clk_pin;
    
    this->data_pin = data_pin;
    
    this->latch_pin = latch_pin;
    
    this->num_pins = num_pins;
    
    pinMode(this->clk_pin, OUTPUT);
    
    pinMode(this->data_pin, OUTPUT);
    
    pinMode(this->latch_pin, OUTPUT);
    
}