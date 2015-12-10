#include "SD_driver.h"
#include "LED_driver.h"
File HZK, ASCII;
char input[32];
void SD_init(void)
{
    if(!SD.begin(CS))
    {
        Serial.println("SD init failed!");
        return;
    }
}
bool file_test(char * filename)
{
    File test;
    test = SD.open(filename, FILE_WRITE);
    if(test)
    {
        test.close();
        return true;
    }
    else
        return false;
}
void read_hz(void)
{
    if(file_test("LED/HZK16"))
        HZK = SD.open("LED/HZK16");
    if(file_test("LED/ASCII"))
        ASCII = SD.open("LED/ASCII");
    return;
}
void close_hz(void)
{
    HZK.close();
    ASCII.close();
}
void write_msg(char * s)
{
    char i, j;
    read_hz();
    for(i = 0; i < 16; i++)
        for(j = 0; j < msg_long; j++)
            if((byte)input[j] < 128)
                write_dots(input + j, 1, i, j);
            else
            {
                write_dots(input + j, 2, i, j);
                j++;
            }
    close_hz();
    Serial.println("write done!");
}
void write_dots(char * s, byte byte_count, byte line, byte col)
{
    uint32_t offset;
    if(byte_count == 1)
    {
        offset = (uint32_t)((byte)(*s) * 16 + line);
        ASCII.seek(offset);
        msg[line][col] = ASCII.read();
    }
    else if(byte_count == 2)
    {
        offset = (uint32_t)(((byte)s[0] - 0xA1) * 94 + ((byte)s[1] - 0xA1)) * 0x20 + line * 2;
        HZK.seek(offset);
        msg[line][col] = HZK.read();
        msg[line][col + 1] = HZK.read();
    }
}
void do_cmd(void)
{
    if(strcmp(input, ".stop") == 0)
        roll_en = 0;
    else if(strcmp(input, ".start") == 0)
        roll_en = 1;
    else if(strcmp(input, ".slow") == 0)
        swift_delay = 200;
    else if(strcmp(input, ".fast") == 0)
        swift_delay = 20;
    else if(strcmp(input, ".close") == 0)
        led_en = 0;
    else if(strcmp(input, ".open") == 0)
        led_en = 1;
}

