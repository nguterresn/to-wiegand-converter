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

enum CARD_TYPE {
  HID_BIT_26
};

// Default card type.
extern uint8_t cardType;
// Wiegand Supported Formats.
const uint8_t wiegandFormats[5] = { 26, 32, 34, 40, 44 };
// FORMAT ARRAY
// [ [0, 0], [1, 8], [9, 24], [25, 25] ]
// Support Only HID 26-bit for now.
const uint8_t wiegand[1][4][2] = {
  {
    { 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }
  }
};

bool isReadyToIdentify(uint8_t counter);
bool supportedFormat(uint8_t length);
void parse(uint8_t *data, uint8_t length, Stream *serial);
void parseCardData(uint8_t *data, uint8_t length, Stream *serial);
void printWiegand(uint8_t *data, uint8_t format, Stream *serial);
void removeParityBits(uint8_t *data, uint8_t *length, Stream *serial);

#endif
