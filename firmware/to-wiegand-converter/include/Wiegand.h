#ifndef Wiegand_H
#define Wiegand_H

#include <Arduino.h>
#include "WebServer.h"
#include "Helper.h"

// A File to Parse and Send TTL alike Wiegand Data.

#define WIEGAND_FORMAT_DEFAULT  26

enum WIEGAND_LENGTH {
  BIT_26,
  BIT_32,
  BIT_34,
  BIT_40,
  BIT_44
};

// Wiegand Supported Formats.
const uint8_t wiegandFormats[5] = { 26, 32, 34, 40, 44 };

enum WIEGAND_FORMAT {
  FACILITY_CODE,
  CARD_NUMBER,
  MIN_LENGTH
};

enum CARD_TYPE {
  HID_BIT_26,
  HID_BIT_26_NO_FC,
  HID_BIT_34,
  EM4100,
  TK4100
};

// Facility Coode + Card Number without Parity Bits.
// [ [1, 8], [9, 24] ]
// First index - enum CARD_TYPE length
// Second index - enum WIEGAND_FORMAT length
// Third index - start and end index
const uint8_t wiegand[5][3][2] = {
  {{ 0, 7 }, { 8, 23 }, { 26 }},
  {{ 7, 7 }, { 8, 23 }, { 26 }},
  {{ 0, 15 }, { 16, 31 }, { 34 }},
  {{ 0, 15 }, { 16, 31 }, { 32 }},
  {{ 0, 15 }, { 16, 31 }, { 32 }}
};

// Default card type.
extern uint8_t cardType;
// Default facility code.
extern int facilityCode;
// Default card number.
extern int cardNumber;

bool isReadyToIdentify(uint8_t counter);
bool supportedFormat(uint8_t length);
void parse(uint8_t *data, uint8_t length, Stream *serial);
void parseCardData(uint8_t *data, uint8_t length, Stream *serial);
void printWiegand(uint8_t *data, uint8_t format, Stream *serial);
void removeParityBits(uint8_t *data, uint8_t *length, Stream *serial);

#endif
