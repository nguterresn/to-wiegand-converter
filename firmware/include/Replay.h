#ifndef REPLAY_H
#define REPLAY_H

#include <Arduino.h>

#define DATA0 D6
#define DATA1 D7

void _high(uint8_t pin);
void _low();
void io();
void replay(uint8_t *data, uint8_t length);

#endif

