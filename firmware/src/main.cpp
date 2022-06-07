#include <Arduino.h>
#include "Buffer.h"
#include "Timeout.h"
#include "WebServer.h"
#include "Wiegand.h"
#include "Replay.h"

enum STATE {
  WAITING,
  IDENTIFICATION,
  PARSE,
  REPLICATE,
  RECOVER
};

uint8_t state = WAITING;
Buffer buffer(&Serial);
unsigned long lastReadAttempt = 0;

void _identify();
void _parse();
void _read();
void _recover();
void _replicate();
void _waitAndRead();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Wemos D1 Mini Booting... !");
  buffer.create(BUFFER_SIZE);
  setWifi();
  setWebServer(cardType);
  io();
}

void loop() {
  switch (state) {
    case WAITING:
      _waitAndRead();
      break;
    case IDENTIFICATION:
      _identify();
      break;
    case PARSE:
      _parse();
      break;
    case REPLICATE:
      _replicate();
      break;
    case RECOVER:
      _recover();
      break;

    default:
      exit(0);
      break;
  }
  // Global timeout.
  if (hasExceedTimeout(lastReadAttempt, READING_TIMEOUT) && buffer.length()) {
    state = RECOVER;
  }
  // Necessary to update dns
  MDNS.update();
}

void _waitAndRead() {
  if (Serial.available() > 0) {
    _read();
    // Check if the program is ready to jump to the evalutation state.
    if (isReadyToIdentify(buffer.length())) { state = IDENTIFICATION; }
  }
}

void _read() {
  lastReadAttempt = millis();
  buffer.add(Serial.read());
}

void _identify() {
  if (Serial.available() > 0) {
    _read();
    return;
  }
  state = PARSE;
}

void _parse() {
  int error = parse(buffer.get(), buffer.length(), &Serial);
  state = error ? RECOVER : REPLICATE;
}

void _replicate() {
  _replay(buffer.get(), buffer.length());
  state = RECOVER;
}

void _recover() {
  // Free buffer. Create a new one to store a new reading.
  buffer.reset(BUFFER_SIZE);
  // Clear the global variables.
  lastReadAttempt = 0;
  // Jump to the beginning.
  state = WAITING;
}
