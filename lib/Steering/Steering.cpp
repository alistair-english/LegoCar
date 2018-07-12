#include <Steering.h>

Steering::Steering(int pin){
    steerServo.attach(pin);
}

void Steering::set(int steer){ // steer is from -40 to 40 (left to right)
    steer = constrain(steer, -40, 40);
    steerServo.write(180-((steer*2)+90));
}
