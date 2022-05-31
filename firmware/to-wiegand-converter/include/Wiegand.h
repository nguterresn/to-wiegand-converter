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
  CARD_NUMBER
};

enum CARD_TYPE {
  HID_BIT_26,
  HID_BIT_26_NO_FC,
};

// [ [1, 8], [9, 24] ]
// Support Only HID 26-bit for now.
const uint8_t wiegand[2][2][2] = {
  {{ 1, 8 }, { 9, 24 }},
  {{ 8, 8 }, { 9, 24 }}
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
