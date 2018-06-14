/*
 * PWM Lib example
 */

#include <PWM.h>

ESC m1(7);	// ESC for Motor 1 on digital pin 7
RCRecv ch1(2);	// RC Reciever Channel 1 (In my case throttle) handler on digital pin 2.

void setup() {/* With this library you dont have to setup anything for this */}

void loop() {
	m1.write(max(RCRecv.read()-100, 0)); // Basicaly pipe the throttle reduced by a 100 or 0 (whichever is the maximum) to the ESC
}
