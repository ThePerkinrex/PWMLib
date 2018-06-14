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
	_hasBegun = false;
}

void ESC::write(unsigned long t){
	digitalWrite(_pin, HIGH);
	delayMicroseconds(t);
	digitalWrite(_pin, LOW);
}

void ESC::begin(unsigned long min, unsigned long max){
	write(max);
	_min = min;
	_max = max;
	_hasBegun = true;
}

void ESC::calibrate(){
	if(_hasBegun){
		// Connect the batteries
		write(_min);
		delay(7000);
		write(0);
		delay(1000);
		// Arming
		write(_min);
		delay(1000);
	}
}

// Wrapper for pulseIn function
RCRecv::RCRecv(int pin){
	pinMode(pin, INPUT);
	_pin = pin;
}

unsigned long RCRecv::read(){
	return pulseIn(_pin, HIGH);
}
