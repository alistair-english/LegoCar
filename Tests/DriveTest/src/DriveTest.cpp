#include <Common.h>

void setup(){
    pinMode(PWM_Pin, OUTPUT);
    pinMode(Dir_Pin, OUTPUT);
    pinMode(Brk_Pin, OUTPUT);

    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    digitalWrite(Dir_Pin, HIGH);
    digitalWrite(Brk_Pin, LOW);
    analogWrite(PWM_Pin, 0);
}


void loop(){
    digitalWrite(Brk_Pin, LOW);
    analogWrite(PWM_Pin, 255);

    delay(1000);

    digitalWrite(Brk_Pin, HIGH);

    delay(500);

    digitalWrite(Brk_Pin, LOW);
    analogWrite(PWM_Pin, 255);

    delay(1000);

    analogWrite(PWM_Pin, 0);

    delay(500);


    // digitalWrite(Dir_Pin, HIGH);
    //
    // digitalWrite(Brk_Pin, HIGH);
    // analogWrite(PWM_Pin, 0);
    //
    // digitalWrite(Brk_Pin, LOW);
    //
    // for(int i=0; i<=255; i+=5){
    //     analogWrite(PWM_Pin, i);
    //     delay(100);
    // }
    //
    // digitalWrite(Dir_Pin, LOW);
    //
    // for(int i=255; i>=0; i-=5){
    //     analogWrite(PWM_Pin, i);
    //     delay(100);
    // }


}
