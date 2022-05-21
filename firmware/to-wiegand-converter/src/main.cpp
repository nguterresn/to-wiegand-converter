#include <Arduino.h>
#include "WebServer.h"
#include "Buffer.h"
#include "Wiegand.h"

#define BUILT_IN_LED_PIN    2
#define BUFFER_SIZE         100
#define READING_TIMEOUT     10000

enum FORMAT {
  BINARY,
  HEXDECIMAL,
  DECIMAL,
  ASCII
};

Buffer buffer(&Serial);
uint8_t numberOfReadings = 0;
unsigned long lastReadAttempt = 0;

bool _hasTimeout(unsigned long lastReadAttempt, unsigned long timeout);
void _getWiegandPayload();
void _readByteAndSave();
void _resetBuffer();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Wemos D1 Mini Booting... !");
  buffer.Create(BUFFER_SIZE);
}

void loop() {
  // If it is first time reading... store the time.
  if (Serial.available() > 0) {
    _readByteAndSave();
    if (numberOfReadings == WIEGAND_FORMAT_DEFAULT) { _getWiegandPayload(); }
  }
  if (_hasTimeout(lastReadAttempt, READING_TIMEOUT)) {
    _resetBuffer();
  }
}

void _readByteAndSave() {
  lastReadAttempt = millis();
  buffer.Add(Serial.read());
  ++numberOfReadings;
}

void _getWiegandPayload() {
  // Parse the reading result.
  Serial.println("Parse it");
  PrintWiegand(buffer.Get(), numberOfReadings, &Serial);
  _resetBuffer();
}

bool _hasTimeout(unsigned long lastReadAttempt, unsigned long timeout) {
  return numberOfReadings && (millis() - lastReadAttempt > timeout);
}

void _resetBuffer() {
  buffer.Reset(BUFFER_SIZE);
  numberOfReadings = 0;
  lastReadAttempt = 0;
}
