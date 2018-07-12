#ifndef Drive_h
#define Drive_h

#include <Common.h>
#include <Encoder.h>

class Drive {
public:
    Drive(int PWM_,int Dir_, int Brk_, int enc1_, int enc2_);
    void setSpeed(int speed);
    void brake();
    double getRPM();

private:
    int PWM, Dir, Brk;
    bool currDir; // false = forwards, true = backwards
    int currPWM;
    unsigned long encLastCall = 0;

    Encoder driveEncoder = Encoder(1, 2);

};

#endif
