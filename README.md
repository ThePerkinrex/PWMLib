# PWM
An Arduino library that deals with PWM stuff like reading from RC Receivers and writing to ESCs

A very crude example from ESC_RC example
```cpp
#include <PWM.h>

ESC m1(7);      // ESC initialiazed to digital pin 7
RCRecv ch1(2);  // RCRecv initialiazed to digital pin 2

void setup(){}

void loop(){
  m1.write(max(ch1.read() - 100, 0));
}

```

In the code the first thing defined after including the library is the definition of an `ESC` object and a `RCRecv` object,
which handle respectively controlling the ESCs speed and reading from an RC reciever.


Then for setting the ESCs speed just use the `write` function. For reading signal with an `RCRecv`, just use the `read` function.

## Reference

##### `void ESC::write(unsigned long t)`:  
This function takes in an `unsigned long` beacause time can't be negative (`unsigned`) an it can be a lot (`long`)  

##### `unsigned long RCRecv::read()`:  
This function gives out an `unsigned long` number for the same reason the write takes it in
