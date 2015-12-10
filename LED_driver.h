#ifndef LED_DRIVER_H
#define LED_DRIVER_H
#include <Arduino.h>
#define SignA 10
#define SignB 9
#define SignC 8
#define SignD 7
#define EN 6
#define R1 5
#define LAT 3
#define CLK 2
#define MSG_LONG 31
extern byte msg[16][MSG_LONG];
extern byte msg_offset, msg_begin, msg_long;
extern byte led_en;
void senddata(byte data);
void scan(byte row);
void show(void);
#endif
