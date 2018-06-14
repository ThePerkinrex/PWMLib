/*
 * PWM.h - A library that handles PWM stuff for interfacing with RC recievers and ESCs
 * Created by ThePerkinrex, June 14, 2018
 * Released into public domain.
 */


#ifndef PWM_h
#define PWM_h

#include "Arduino.h"

class ESC {
	public:
		ESC(int pin);
		void write(unsigned long t);
		void setBatteryFlag();
		void calibrate(unsigned long min, unsigned long max);
	private:
		int _pin;
		bool _batteryFlag; // To be set with an interrupt
};

class RCRecv {
	public:
		RCRecv(int pin);
		unsigned long read();
	private:
		int _pin;
};

#endif
