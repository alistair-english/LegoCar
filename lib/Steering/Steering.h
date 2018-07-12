#ifndef Steering_h
#define Steering_h

#include <Common.h>
#include <Servo.h>

class Steering {
public:
    Steering(int pin);
    void set(int steer);

private:
    Servo steerServo;

};

#endif
