#include "Wiegand.h"

// Default card type.
uint8_t cardType = HID_BIT_26;
// Default data type.
uint8_t dataType = ASCII;

int parse(uint8_t *data, uint8_t length, Stream *serial) {
  _transformData(data, length, serial);
  // Validate format.
  if (!_supportedFormat(length)) {
    sendEvent(CARD_FACILITY_EVENT, 0);
    sendEvent(CARD_NUMBER_EVENT, 0);
    sendEvent(CARD_FORMAT_EVENT, 0);
    return ERROR;
  }
  // Take off parity bits.
  _removeParityBits(data, &length, serial);
  #ifdef DEBUG
  _printWiegand(data, length, serial);
  #endif
  // Parse FC and CN.
  _parseCardData(data, length, serial);
  return SUCCESS;
}

void _parseCardData(uint8_t *data, uint8_t length, Stream *serial) {
  int facilityCode = 0;
  int cardNumber = 0;
  // facilityCodeEndIndex is handy when there is no facility code. We can set
  // the array as {15, 15}, so the card number is on the next index (16).
  uint8_t facilityCodeStartIndex = card[cardType][FACILITY_CODE][0];
  uint8_t facilityCodeEndIndex = card[cardType][FACILITY_CODE][1];
  for (uint8_t i = facilityCodeEndIndex; i > facilityCodeStartIndex; i--) {
    // Subtrate 48 to convert from decimal to binary.
    // This might change in the future.
    facilityCode += (*(data + i) - 48) << (facilityCodeEndIndex - i);
  }
  uint8_t cardNumberStartIndex = card[cardType][CARD_NUMBER][0];
  uint8_t cardNumberEndIndex = card[cardType][CARD_NUMBER][1];
  for (uint8_t i = cardNumberEndIndex; i >= cardNumberStartIndex; i--) {
    cardNumber += (*(data + i) - 48) << (cardNumberEndIndex - i);
  }
  // Prepare to send an event.
  sendEvent(CARD_FACILITY_EVENT, facilityCode);
  sendEvent(CARD_NUMBER_EVENT, cardNumber);
}

bool _supportedFormat(uint8_t length) {
  if (length < card[cardType][MIN_LENGTH][0]) { return false; }
  for (uint8_t i = 0; i < sizeof(wiegandFormats); i++) {
    if (wiegandFormats[i] == length) {
      return true;
    }
  }
  return false;
}

void _removeParityBits(uint8_t *data, uint8_t *length, Stream *serial) {
  // Update Wiegand format on Web page.
  sendEvent(CARD_FORMAT_EVENT, *length);
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

void _transformData(uint8_t *data, uint8_t length, Stream *serial) {
  
}

bool isReadyToIdentify(uint8_t counter) {
  if (dataType == ASCII) {
    return (counter == WIEGAND_FORMAT_DEFAULT_ASCII);
  }
  if (dataType == BINARY) {
    return (counter == WIEGAND_FORMAT_DEFAULT_BINARY);
  }
  return false;
}

#ifdef DEBUG
void _printWiegand(uint8_t *data, uint8_t format, Stream *serial) {
  String _data = "";
  for (size_t i = 0; i < format; i++) {
    _data += (char) *(data + i);
  }
  serial->println(_data);
}
#endif
