#include "Wiegand.h"

// FORMAT ARRAY
// [ [0, 0], [1, 8], [9, 24], [25, 25] ]
// unsigned char wiegand[5][4][2] = {
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }},
//   {{ 0, 0 }, { 1, 8 }, { 9, 24 }, { 25, 25 }}
// };

uint8_t wiegandFormats[5] = { 26, 32, 34, 40, 44 };

void parse(uint8_t *data, uint8_t length, Stream *serial) {
  // Validate format.
  if (!supportedFormat(length)) { return; }
  serial->println("Format is supported");
  // Identify format.
  // Take parity bits.
  // Parse FC and CN.
}

bool supportedFormat(uint8_t length) {
  bool found = false;
  for (uint8_t i = 0; i < sizeof(wiegandFormats); i++) {
    if (wiegandFormats[i] == length) {
      found = true;
      break;
    }
  }
  return found;
}

void printWiegand(uint8_t *data, uint8_t format, Stream *serial) {
  String _data = "";
  for (size_t i = 0; i < format; i++) {
    _data += (char) *(data + i);
  }
  serial->println(_data);
}

bool isReadyToIdentify(uint8_t counter) {
  return (counter == WIEGAND_FORMAT_DEFAULT);
}
