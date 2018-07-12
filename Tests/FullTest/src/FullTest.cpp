#include <Common.h>
#include <Servo.h>

Servo steering;

void setup(){
    pinMode(PWM_Pin, OUTPUT);
    pinMode(Dir_Pin, OUTPUT);
    pinMode(Brk_Pin, OUTPUT);

    steering.attach(Steering_Pin); // attach the steering to the pin

    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}


void loop(){
    digitalWrite(Dir_Pin, LOW);
    digitalWrite(Brk_Pin, LOW);
    analogWrite(PWM_Pin, 50);

    steering.write(90);

    delay(2000);

    steering.write(160);

    delay(5000);




}
