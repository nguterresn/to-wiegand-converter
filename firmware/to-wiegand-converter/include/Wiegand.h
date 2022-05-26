#ifndef Wiegand_H
#define Wiegand_H

#include <Arduino.h>

// A File to Parse and Send TTL alike Wiegand Data.

#define WIEGAND_FORMAT_DEFAULT  26

enum WIEGAND_FORMAT {
  EVEN_PARITY_BIT,
  FACILITY_CODE,
  CARD_NUMBER,
  ODD_PARITY_BIT
};

enum WIEGAND_LENGTH {
  BIT_26,
  BIT_32,
  BIT_34,
  BIT_40,
  BIT_44
};

enum WIEGAND_ARRAY {
  START,
  END
};

void printWiegand(uint8_t *data, uint8_t format, Stream *serial);
// void identifyFormat(uint8_t length);
bool supportedFormat(uint8_t length);
void parse(uint8_t *data, uint8_t length, Stream *serial);
bool isReadyToIdentify(uint8_t counter);

#endif
