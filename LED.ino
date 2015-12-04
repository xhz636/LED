#include "LED_driver.h"
void setup() {
  // put your setup code here, to run once:
    pinMode(SignA, OUTPUT);
    pinMode(SignB, OUTPUT);
    pinMode(SignC, OUTPUT);
    pinMode(SignD, OUTPUT);
    pinMode(EN, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(LAT, OUTPUT);
    pinMode(CLK, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
    show(msg);
}

