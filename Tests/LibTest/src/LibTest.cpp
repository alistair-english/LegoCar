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
    steering.set(0);
    drive.setSpeed(50);
    // Serial.printf("%f\n", drive.getRPM());
    Serial.println(drive.getRPM());
    // drive.getRPM();
}
