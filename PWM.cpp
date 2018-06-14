/*
 * PWM.h - A library that handles PWM stuff for interfacing with RC recievers and ESCs
 * Created by ThePerkinrex, June 14, 2018
 * Released into public domain.
 */

#include "Arduino.h"
#include "PWM.h"

// Creates a pulseOut function and wraps it
ESC::ESC(int pin){
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	_pin = pin;
}

void ESC::write(unsigned long t){
	digitalWrite(_pin, HIGH);
	delayMicroseconds(t);
	digitalWrite(_pin, LOW);
}

// Wrapper for pulseIn function
RCRecv::RCRecv(int pin){
	pinMode(pin, INPUT);
	_pin = pin;
}

unsigned long RCRecv::read(){
	return pulseIn(_pin, HIGH);
}
