#include "Wiegand.h"

// Default card type.
uint8_t cardType = HID_BIT_26;
int facilityCode = 0;
int cardNumber = 0;

void parse(uint8_t *data, uint8_t length, Stream *serial) {
  // Validate format.
  if (!supportedFormat(length)) {
    char *buffer = new char[5];
    sendEvent(CARD_FACILITY_EVENT, intToConstChar(0, buffer));
    sendEvent(CARD_NUMBER_EVENT, intToConstChar(0, buffer));
    sendEvent(CARD_FORMAT_EVENT, intToConstChar(0, buffer));
    delete []buffer;
    return;
  }
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
  uint8_t facilityCodeStartIndex = wiegand[cardType][FACILITY_CODE][0];
  uint8_t facilityCodeEndIndex = wiegand[cardType][FACILITY_CODE][1];
  for (uint8_t i = facilityCodeEndIndex; i > facilityCodeStartIndex; i--) {
    // Subtrate 48 to convert from decimal to binary.
    // This might change in the future.
    facilityCode += (*(data + i) - 48) << (facilityCodeEndIndex - i);
  }
  uint8_t cardNumberStartIndex = wiegand[cardType][CARD_NUMBER][0];
  uint8_t cardNumberEndIndex = wiegand[cardType][CARD_NUMBER][1];
  for (uint8_t i = cardNumberEndIndex; i >= cardNumberStartIndex; i--) {
    cardNumber += (*(data + i) - 48) << (cardNumberEndIndex - i);
  }
  // Prepare to send an event.
  char *buffer = new char[40];
  sendEvent(CARD_FACILITY_EVENT, intToConstChar(facilityCode, buffer));
  sendEvent(CARD_NUMBER_EVENT, intToConstChar(cardNumber, buffer));
  delete []buffer;
}

bool supportedFormat(uint8_t length) {
  for (uint8_t i = 0; i < sizeof(wiegandFormats); i++) {
    if (
      wiegandFormats[i] == length &&
      length >= wiegand[cardType][MIN_LENGTH][0]
    ) {
      return true;
    }
  }
  return false;
}

void printWiegand(uint8_t *data, uint8_t format, Stream *serial) {
  String _data = "";
  for (size_t i = 0; i < format; i++) {
    _data += (char) *(data + i);
  }
  serial->println(_data);
}

void removeParityBits(uint8_t *data, uint8_t *length, Stream *serial) {
  // Update Wiegand format on Web page.
  char *buffer = new char[5];
  sendEvent(CARD_FORMAT_EVENT, intToConstChar(*length, buffer));
  delete []buffer;
  // Data & Length are both passed by reference.
  if (
    *length == wiegandFormats[BIT_26] ||
    *length == wiegandFormats[BIT_34] ||
    *length == wiegandFormats[BIT_44]
  ) {
    uint8_t newLength = *length - 2;
    // Take the 2 parity bits. Dont verify integrity.
    for (int i = 0; i < newLength; i++) { *(data + i) = *(data + i + 1); }
    // Update length according to the new size.
    *length = newLength;
  }
}

bool isReadyToIdentify(uint8_t counter) {
  return (counter == WIEGAND_FORMAT_DEFAULT);
}
