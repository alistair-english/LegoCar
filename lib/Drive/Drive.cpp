#include <Drive.h>

Drive::Drive(int PWM_, int Dir_, int Brk_, int enc1_, int enc2_){
    PWM = PWM_;
    Dir = Dir_;
    Brk = Brk_;

    pinMode(PWM, OUTPUT);
    pinMode(Dir, OUTPUT);
    pinMode(Brk, OUTPUT);

    analogWrite(PWM, 0);
    digitalWrite(Dir, LOW);
    digitalWrite(Brk, HIGH);

    // driveEncoder = Encoder(enc1_, enc2_);
}

void Drive::setSpeed(int speed){ // speed is from -100 to 100
    speed = map(constrain(speed, -100, 100), -100, 100, -255, 255);
    digitalWrite(Brk, speed == 0);
    digitalWrite(Dir, speed < 0); // HIGH is backwards
    analogWrite(PWM, abs(speed));
    currDir = speed < 0;
    currPWM = abs(speed);

    Serial.println(driveEncoder.read());
}

void Drive::brake(){
    digitalWrite(Brk, LOW);
    digitalWrite(Dir, !currDir);
    analogWrite(PWM, currPWM);

    delay(50);

    digitalWrite(Brk, HIGH);
    digitalWrite(Dir, currDir);
    analogWrite(PWM, 0);
}

double Drive::getRPM(){
    unsigned long currTime = millis();
    unsigned long timeDiff = (currTime - encLastCall)/60000; // in minutes
    long rotations = driveEncoder.read()/720; // div by 360*2
    return rotations/timeDiff;
}
