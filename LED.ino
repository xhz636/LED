#include "LED_driver.h"
#include "SD_driver.h"
#include "bluetooth.h"
uint32_t swift_last, swift_now;
int swift_delay = 200;
byte delay_count = 16;
byte roll_en = 1, led_en = 1;
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
    swift_last = millis();
}
void loop() {
  // put your main code here, to run repeatedly:
    show();
    swift_now = millis();
    if(swift_now - swift_last > swift_delay)
    {
        swift_last = swift_now;
        if(delay_count > 0)
            delay_count--;
        else if(msg_long > 8)
        {
            if(roll_en)
            {
                msg_offset++;
                if(msg_offset == 8)
                {
                    msg_offset = 0;
                    msg_begin++;
                    msg_begin %= msg_long;
                }
            }
        }
        else
        {
            msg_offset = 0;
            msg_begin = 0;
        }
    }
    while(Serial.available() > 0)
    {
        delay(100);
        read_input();
        if(input[0] == '.')
            do_cmd();
        else
        {
            write_msg(input);
            delay_count = 16;
        }
    }
}

