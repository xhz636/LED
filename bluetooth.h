#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <Arduino.h>
extern char input[32];
extern byte msg_offset, msg_begin, msg_long;
void read_input(void);
void fill_input(void);
#endif
