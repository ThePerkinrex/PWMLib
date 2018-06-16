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
		void begin(unsigned long min, unsigned long max);
		void calibrate();
		void update();

		unsigned long speed;
	private:
		int _pin;
		unsigned long _min;
		unsigned long _max;
};

class RCRecv {
	public:
		RCRecv(int pin);
		unsigned long read();
	private:
		int _pin;
};

#endif
