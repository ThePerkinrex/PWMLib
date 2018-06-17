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
	_min = 0;
	_max = 0;
	speed = 0;
	//OLD _hasBegun = false;
}

void ESC::write(unsigned long t){
	speed = t;
	digitalWrite(_pin, HIGH);
	delayMicroseconds(t);
	digitalWrite(_pin, LOW);
}

void ESC::begin(unsigned long min, unsigned long max){
	write(max);
	//speed = max; WRITE DOES THIS
	_min = min;
	_max = max;
	// OLD _hasBegun = true;
}

void ESC::calibrate(){
	// Connect the batteries
	write(_min);
	//speed = _min; Write does this
	unsigned int start = millis();
	while(millis() + start < 7000){
		update();
	}
	write(0);
	start = millis();
	while(millis() + start < 1000){
		update();
	}
	// Arming
	write(_min);
	start = millis();
	while(millis() + start < 1000){
		update();
	}
}

void ESC::update(){
	write(speed);
}

// Wrapper for pulseIn function
RCRecv::RCRecv(int pin){
	pinMode(pin, INPUT);
	_pin = pin;
}

unsigned long RCRecv::read(){
	return pulseIn(_pin, HIGH);
}
