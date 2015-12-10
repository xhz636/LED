#include "bluetooth.h"
#include "SD_driver.h"
void read_input(void)
{
    byte input_size = 0;
    while(Serial.available() > 0)
    {
        if(Serial.peek() == 0x0d || Serial.peek() == 0x0a)
        {
            while(Serial.available() > 0)
                Serial.read();
            break;
        }
        else
            input[input_size++] = Serial.read();
        if(input_size == 30)
        {
            while(Serial.available() > 0)
                Serial.read();
            Serial.println("The input is too long, only save 30 byte!");
            break;
        }
    }
    input[input_size] = '\0';
    if(input[0] == '.')
        return;
    if(strlen(input) < 8)
        fill_input();
    if(strlen(input) > 8)
        strcat(input, " ");
    msg_long = strlen(input);
    msg_offset = 0;
    msg_begin = 0;
}
void fill_input(void)
{
    byte input_long;
    byte front, rear;
    int i;
    input_long = strlen(input);
    front = (8 - input_long) / 2;
    rear = 8 - input_long - front;
    for(i = 7; i >= 0; i--)
    {
        if(rear)
        {
            input[i] = ' ';
            rear--;
        }
        else if(input_long)
        {
            input[i] = input[--input_long];
        }
        else if(front)
        {
            input[i] = ' ';
            front--;
        }
    }
    input[8] = '\0';
}

