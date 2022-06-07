#ifndef REPLAY_H
#define REPLAY_H

#include <Arduino.h>

#define DATA0 D6
#define DATA1 D7

void _replay(uint8_t *data, uint8_t length);
void io();

#endif

