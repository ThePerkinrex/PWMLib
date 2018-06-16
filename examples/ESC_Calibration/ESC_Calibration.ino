#include <PWM.h>

ESC m1(7);
RCRecv ch1(4); // Throttle channel
RCRecv ch5(5); // Aux channel 1 connected to switch

void setup() {
  m1.begin(1000, 2000); // Begin the calibration (batteries disconnected)
  // Will wait until user says batteries are connected
  while(ch5.read() < 1400){  // Wait until the switch on the remote is on
    m1.update(); // Keep setting the speed
  }
  m1.calibrate(); // Start actual calibration
}

void loop() {
  m1.write(ch1.read()); // Set the speed of the motor as the throttle
}
