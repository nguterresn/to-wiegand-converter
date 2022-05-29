#ifndef Timeout_H
#define Timeout_H

#include <Arduino.h>

#define READING_TIMEOUT             10000
#define IDENTIFICATION_TIMEOUT      2000

bool hasExceedTimeout(unsigned long start, unsigned long timeout);

#endif
