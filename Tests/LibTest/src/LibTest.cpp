#include <Common.h>
#include <Steering.h>
#include <Drive.h>

Steering steering(Steering_Pin);
Drive drive(PWM_Pin, Dir_Pin, Brk_Pin, Enc_1, Enc_2);

void setup(){
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}


void loop(){
    steering.set(0);
    drive.setSpeed(50);
}
