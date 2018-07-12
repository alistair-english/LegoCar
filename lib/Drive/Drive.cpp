#include <Drive.h>

Drive::Drive(){
    pinMode(PWM_Pin, OUTPUT);
    pinMode(Dir_Pin, OUTPUT);
    pinMode(Brk_Pin, OUTPUT);

    analogWrite(PWM_Pin, 0);
    digitalWrite(Dir_Pin, LOW);
    digitalWrite(Brk_Pin, HIGH);
}

void Drive::setSpeed(int speed){ // speed is from -100 to 100
    speed = map(constrain(speed, -100, 100), -100, 100, -255, 255);
    digitalWrite(Brk_Pin, speed == 0);
    digitalWrite(Dir_Pin, speed < 0); // HIGH is backwards
    analogWrite(PWM_Pin, abs(speed));
    currDir = speed < 0;
    currPWM = abs(speed);
}

void Drive::brake(){
    digitalWrite(Brk_Pin, LOW);
    digitalWrite(Dir_Pin, !currDir);
    analogWrite(PWM_Pin, currPWM);

    delay(50);

    digitalWrite(Brk_Pin, HIGH);
    digitalWrite(Dir_Pin, currDir);
    analogWrite(PWM_Pin, 0);
}

double Drive::getRPM(){
    unsigned long currTime = millis();
    double timeDiff = (currTime - encLastCall)/60000.0; // in minutes
    if(currTime - encLastCall < 100){
        return lastRPM;
    }

    double rotations = (double)driveEncoder.read()/720.0; // div by 360*2
    encLastCall = currTime;
    driveEncoder.write(0);
    lastRPM = rotations/timeDiff;
    return lastRPM;
}
