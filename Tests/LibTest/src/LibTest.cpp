#include <Common.h>
#include <Steering.h>
#include <Drive.h>

Steering steering;
Drive drive;

void setup(){
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}

void loop(){
    // Serial.println(drive.getRPM());

    steering.set(0);
    drive.setSpeed(100);
    delay(1000);
    drive.stop();
    delay(1000);
}
