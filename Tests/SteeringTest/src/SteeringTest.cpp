#include <Common.h>
#include <Servo.h>

Servo steering;

int pos = 0;
void setup(){
    steering.attach(Steering_Pin); // attach the steering to the pin

    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}

void loop(){
    // for(pos = 20; pos <= 160; pos+=5){
    //     steering.write(pos);
    //     Serial.println(pos);
    //     delay(15);
    // }
    //
    // for(pos = 160; pos >= 20; pos-=5){
    //     steering.write(pos);
    //     Serial.println(pos);
    //     delay(15);
    // }

    // steering.write(90);
    // delay(500);
    // steering.write(160);
    // delay(500);
    // steering.write(20);
    // delay(500);

    // delay(500);
    steering.write(10);
    delay(1000);
    steering.write(90);
    delay(2000);
    steering.write(170);
    delay(1000);
    steering.write(90);
    delay(2000);

}
