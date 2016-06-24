/*
 *  Library for a 74HC595 Shift Register
 */

#include "Arduino.h"
#include "shift_74HC595.h"

Shift74HC595::Shift74HC595() {
    
};

void Shift74HC595::begin(uint8_t clk_pin, uint8_t data_pin, uint8_t latch_pin) {
    
    this->clk_pin = clk_pin;
    
    this->data_pin = data_pin;
    
    this->latch_pin = latch_pin;
    
    this->num_pins = 8; // Sets default number of pins as 8 (Amount of Output pins on a single 8 bit shift register)
    
    pinMode(this->clk_pin, OUTPUT);
    
    pinMode(this->data_pin, OUTPUT);
    
    pinMode(this->latch_pin, OUTPUT);
    
    fastWrite(this->clk_pin, LOW);
    
    fastWrite(this->data_pin, LOW);
    
    fastWrite(this->latch_pin, LOW);
    
};

void Shift74HC595::begin(uint8_t clk_pin, uint8_t data_pin, uint8_t latch_pin, uint16_t num_pins) {
    
    this->clk_pin = clk_pin;
    
    this->data_pin = data_pin;
    
    this->latch_pin = latch_pin;
    
    this->num_pins = num_pins;
    
    pinMode(this->clk_pin, OUTPUT);
    
    pinMode(this->data_pin, OUTPUT);
    
    pinMode(this->latch_pin, OUTPUT);
    
    fastWrite(this->clk_pin, LOW);
    
    fastWrite(this->data_pin, LOW);
    
    fastWrite(this->latch_pin, LOW);
    
};

void Shift74HC595::setPinValue(uint8_t pin, uint8_t state) {
    
    this->out_value[map(pin, 0, this->num_pins-1, this->num_pins-1, 0)] = state;
};

void Shift74HC595::shiftOut() {
    
    
    for (int i = 0; i < this->num_pins; i++) {
        
        fastWrite(this->clk_pin, HIGH);
        
        delayMicroseconds(PULSE_DELAY);
        
        fastWrite(this->clk_pin, LOW);
        
        fastWrite(this->data_pin, this->out_value[i]);
        
        delayMicroseconds(PULSE_DELAY);
        
        // Serial.print(this->out_value[i]);
        
    }
        
    fastWrite(this->clk_pin, LOW);
        
    fastWrite(this->data_pin, LOW);
    
    // Serial.println("");
    
    fastWrite(this->latch_pin, HIGH);
    
    delayMicroseconds(PULSE_DELAY);
    
    fastWrite(this->clk_pin, HIGH);
    
    fastWrite(this->latch_pin, LOW);
    
    delayMicroseconds(PULSE_DELAY);
    
    fastWrite(this->clk_pin, LOW);
    
    delayMicroseconds(PULSE_DELAY);
    
};

void Shift74HC595::fastWrite(uint8_t pin, uint8_t val) {
    
	uint8_t bit = digitalPinToBitMask(pin);
    volatile uint8_t *out = portOutputRegister(digitalPinToPort(pin));
    if (val == LOW) {
		*out &= ~bit;
	}
    else {
		*out |= bit;
	}
    
};