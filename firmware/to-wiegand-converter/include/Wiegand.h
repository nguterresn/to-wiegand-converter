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

// FORMAT ARRAY
// [ [0, 0], [1, 8], [9, 24], [25, 25] ]
// unsigned char foda[5][4][2] = {
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }}
// };

void PrintWiegand(uint8_t *data, uint8_t format, Stream *serial);

#endif
