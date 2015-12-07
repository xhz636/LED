#include "SD_driver.h"
File HZK, ASCII, LED_MSG;
char input[128];
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
    if(file_test("sys/HZK16"))
        HZK = SD.open("sys/HZK16");
    if(file_test("sys/ASCII"))
        ASCII = SD.open("sys/ASCII");
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
    if(SD.exists("log/1"))
        SD.remove("log/1");
    file_test("log/1");
    LED_MSG = SD.open("log/1", FILE_WRITE);
    if(!LED_MSG)
    {
        Serial.println("open failed!");
        close_hz();
        return;
    }
    LED_MSG.seek(0);
    for(i = 0; i < 16; i++)
        for(j = 0; j < strlen(input); j++)
            if((byte)input[j] < 128)
                write_dots(input + j, 1, i);
            else
            {
                write_dots(input + j, 2, i);
                j++;
            }
    LED_MSG.close();
    close_hz();
    Serial.println("write done!");
}
void write_dots(char * s, byte byte_count, byte line)
{
    uint32_t offset;
    byte dots[2];
    if(byte_count == 1)
    {
        offset = (uint32_t)((byte)(*s) * 16 + line);
        ASCII.seek(offset);
        dots[0] = ASCII.read();
        LED_MSG.write(dots, 1);
    }
    else if(byte_count == 2)
    {
        offset = (uint32_t)(((byte)s[0] - 0xA1) * 94 + ((byte)s[1] - 0xA1)) * 0x20 + line * 2;
        HZK.seek(offset);
        dots[0] = HZK.read();
        dots[1] = HZK.read();
        LED_MSG.write(dots, 2);
    }
}
void read_msg(char * filename)
{
    byte i;
    byte input_long;
    uint32_t offset;
    if(file_test(filename))
        LED_MSG = SD.open(filename);
    else
    {
        Serial.println("read failed!");
        return;
    }
    input_long = strlen(input);
    for(i = 0; i < 16; i++)
    {
        offset = i * input_long;
        LED_MSG.seek(offset);
        LED_MSG.read(msg + i * 8, 8);
    }
    LED_MSG.close();
}

