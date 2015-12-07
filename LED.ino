#include "LED_driver.h"
#include "SD_driver.h"
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
    Serial.begin(9600);
    SD_init();
}
void loop() {
  // put your main code here, to run repeatedly:
    show(msg);
    while(Serial.available() > 0)
    {
        write_msg(input);
        read_msg("log/1");
        Serial.read();
    }
}

