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
    drive.setSpeed(30);
    for(int i=0; i<=40; i++){
        steering.set(i);
        delay(50);
    }
    drive.stop();
    delay(2000);
    drive.setSpeed(-30);
    for(int i=0; i>=-40; i-=1){
        steering.set(i);
        delay(50);
    }
    drive.stop();
    delay(2000);
}
