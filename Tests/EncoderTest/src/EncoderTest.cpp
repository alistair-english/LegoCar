#include <Common.h>
#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knobLeft(1, 2);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("TwoKnobs Encoder Test:");
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

long positionLeft  = -999;

void loop() {
  long newLeft;
  newLeft = knobLeft.read();
  Serial.println(newLeft);
  // if (newLeft != positionLeft) {
  //   Serial.print("Left = ");
  //   Serial.print(newLeft);
  //   positionLeft = newLeft;
  // }
  // // if a character is sent from the serial monitor,
  // // reset both back to zero.
  // if (Serial.available()) {
  //   Serial.read();
  //   Serial.println("Reset both knobs to zero");
  //   knobLeft.write(0);
  // }
}
