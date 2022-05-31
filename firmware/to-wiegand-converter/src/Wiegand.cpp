#include "Wiegand.h"

// Default card type.
uint8_t cardType = HID_BIT_26;
int facilityCode = 0;
int cardNumber = 0;

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
  facilityCode = 0;
  cardNumber = 0;
  // facilityCodeEndIndex is handy when there is no facility code. We can set
  // the array as {15, 15}, so the card number is on the next index (16).
  uint8_t facilityCodeEndIndex = wiegand[cardType][FACILITY_CODE][1];
  uint8_t facilityCodeLength =
    facilityCodeEndIndex - wiegand[cardType][FACILITY_CODE][0];
  uint8_t cardNumberLength =
    wiegand[cardType][CARD_NUMBER][1] - wiegand[cardType][CARD_NUMBER][0];
  for (int8 i = facilityCodeLength; i > 0; i--) {
    // Subtrate 48 to convert from decimal to binary.
    // This might change in the future.
    facilityCode += (*(data + (facilityCodeLength - i)) - 48) << i;
  }
  for (int8 i = cardNumberLength; i > 0; i--) {
    cardNumber +=
      (*(data + (cardNumberLength + (facilityCodeEndIndex + 1) - i)) - 48) << i;
  }
  // Prepare to send an event.
  char *buffer = new char[40];
  sendEvent("card_facility", intToConstChar(facilityCode, buffer));
  sendEvent("card_number", intToConstChar(cardNumber, buffer));
  delete []buffer;
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
