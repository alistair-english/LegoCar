#include <Drive.h>

Drive::Drive(){
    pinMode(PWM_Pin, OUTPUT);
    pinMode(Dir_Pin, OUTPUT);
    pinMode(Brk_Pin, OUTPUT);

    analogWrite(PWM_Pin, 0);
    digitalWrite(Dir_Pin, LOW);
    digitalWrite(Brk_Pin, HIGH);
}

void Drive::call(){
    double rpm = getRPM();
    double val = rpmPID.update(abs(rpm) < 5 ? 0 : rpm, targetRPM);
    toWrite = constrain(toWrite+val, -255, 255);

    // Serial.printf("%f %f %f\n", val, toWrite, rpm);

    digitalWrite(Brk_Pin, toWrite == 0);
    digitalWrite(Dir_Pin, toWrite < 0); // HIGH is backwards
    analogWrite(PWM_Pin, abs(toWrite));

    if(toWrite != 0){
        currDir = toWrite < 0;
        currPWM = abs(toWrite);
    }
}

void Drive::setRPM(int rpm){
    targetRPM = rpm;
}

void Drive::stop(){
    // will halt the program until the car is stopped, only called once
    while((getRPM() > 0 && !currDir) || getRPM() < 0 && currDir){
        digitalWrite(Brk_Pin, LOW);
        digitalWrite(Dir_Pin, !currDir);
        analogWrite(PWM_Pin, currPWM);
    }

    digitalWrite(Brk_Pin, HIGH);
    digitalWrite(Dir_Pin, currDir);
    analogWrite(PWM_Pin, 0);
}

double Drive::getRPM(){
    unsigned long currTime = millis();
    double timeDiff = (currTime - encLastCall)/60000.0; // in minutes
    if(currTime - encLastCall < 10){
        return lastRPM;
    }

    double rotations = (double)driveEncoder.read()/720.0; // div by 360*2
    encLastCall = currTime;
    driveEncoder.write(0);
    lastRPM = rotations/timeDiff;
    return lastRPM;
}

void setPWM(int pwm){ // pwm is 0-255
    digitalWrite(Brk_Pin, pwm == 0);
    digitalWrite(Dir_Pin, pwm < 0); // HIGH is backwards
    analogWrite(PWM_Pin, abs(pwm));
}
