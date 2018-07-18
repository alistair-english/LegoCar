#ifndef Drive_h
#define Drive_h

#include <Common.h>
#include <PID.h>
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

class Drive {
public:
    Drive();
    void setRPM(int rpm);
    void stop();
    double getRPM();
    void call();

    // utility
    void setPWM(int pwm);

private:
    int targetRPM;
    double toWrite = 0;

    bool currDir; // false = forwards, true = backwards
    int currPWM;
    unsigned long encLastCall = 0;
    double lastRPM = 0;

    Encoder driveEncoder = Encoder(Enc_1, Enc_2);
    PID rpmPID = PID(rpmP, rpmI, rpmD, 255);

};

#endif
