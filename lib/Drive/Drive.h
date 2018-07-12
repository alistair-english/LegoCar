#ifndef Drive_h
#define Drive_h

#include <Common.h>
#include <Encoder.h>

class Drive {
public:
    Drive();
    void setSpeed(int speed);
    void brake(int amount);
    void stop();
    double getRPM();

private:
    bool currDir; // false = forwards, true = backwards
    int currPWM;
    unsigned long encLastCall = 0;
    double lastRPM = 0;

    Encoder driveEncoder = Encoder(Enc_1, Enc_2);

};

#endif
