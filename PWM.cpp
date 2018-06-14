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
	_batteryFlag = false;
}

void ESC::write(unsigned long t){
	digitalWrite(_pin, HIGH);
	delayMicroseconds(t);
	digitalWrite(_pin, LOW);
}

void ESC::setBAtteryFlag(){
	_batteryFlag = true;
}

void ESC::calibrate(unsigned long min, unsigned long max){
	// Disconnect batteries before this
	write(max);
	while(!_bateryFlag){} // Wait until this flag is set
	// TODO Add a check for the baterries, or a led or a variable
	// Connect the batteries
	write(min);
	delay(7000);
	write(0);
	delay(1000);
	// Arming
	write(min);
	delay(1000);
}

// Wrapper for pulseIn function
RCRecv::RCRecv(int pin){
	pinMode(pin, INPUT);
	_pin = pin;
}

unsigned long RCRecv::read(){
	return pulseIn(_pin, HIGH);
}
