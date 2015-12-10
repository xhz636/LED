#ifndef LED_DRIVER_H
#define LED_DRIVER_H
#include <Arduino.h>
#define SignA 5
#define SignB 6
#define SignC 7
#define SignD 8
#define EN 9
#define R1 10
#define LAT 2
#define CLK 3
#define MSG_LONG 24
extern byte msg[16][MSG_LONG];
extern byte msg_offset, msg_begin, msg_long;
void senddata(byte data);
void scan(byte row);
void show();
#endif
