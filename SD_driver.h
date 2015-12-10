#ifndef SD_DRIVER_H
#define SD_DRIVER_H
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#define CS 4
//#define MOSI 11
//#define MISO 12
//#define CLK 13
extern File HZK, ASCII, LED_MSG;
extern char input[40];
void SD_init(void);
bool file_test(char * filename);
void read_hz(void);
void close_hz(void);
void write_msg(char * s);
void write_dots(char * s, byte index, byte line);
void read_msg(char * filename);
#endif
