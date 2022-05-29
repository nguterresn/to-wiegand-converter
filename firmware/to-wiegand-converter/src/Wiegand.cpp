#include "Wiegand.h"

// Default card type.
uint8_t cardType = HID_BIT_26;

void parse(uint8_t *data, uint8_t length, Stream *serial) {
  // Validate format.
  if (!supportedFormat(length)) { return; }
  serial->println("Format is supported");
  // Take off parity bits.
  removeParityBits(data, &length, serial);
  printWiegand(data, length, serial);
  // Parse FC and CN.
  parseCardData(data, length, serial);
}

void parseCardData(uint8_t *data, uint8_t length, Stream *serial) {
  // Do a client request.
  
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

void removeParityBits(uint8_t *data, uint8_t *length, Stream *serial) {
  if (
    *length == wiegandFormats[BIT_26] ||
    *length == wiegandFormats[BIT_34] ||
    *length == wiegandFormats[BIT_44]
  ) {
    // Data & Length are both passed by reference.
    uint8_t newLength = *length - 2;
    for (int i = 0; i < newLength; i++) {
      *(data + i) = *(data + i + 1);
    }
    *length = newLength;
  }
}

bool isReadyToIdentify(uint8_t counter) {
  return (counter == WIEGAND_FORMAT_DEFAULT);
}
