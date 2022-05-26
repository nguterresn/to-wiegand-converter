#include <Arduino.h>
#include "WebServer.h"
#include "Buffer.h"
#include "Wiegand.h"
#include "Timeout.h"

#define BUILT_IN_LED_PIN    2
#define BUFFER_SIZE         100
#define READING_TIMEOUT     10000
#define IDENTIFICATION_TIMEOUT     2000

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
void _recover();
void _read();
void _waitAndRead();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Wemos D1 Mini Booting... !");
  buffer.Create(BUFFER_SIZE);
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
      break;
    case RECOVER:
      _recover();
      break;

    default:
      exit(0);
      break;
  }
  // Global timeout.
  if (hasExceedTimeout(lastReadAttempt, READING_TIMEOUT) && buffer.Length()) {
    Serial.println("recover");
    state = RECOVER;
  }
}

void _waitAndRead() {
  if (Serial.available() > 0) {
    _read();
    // Check if the program is ready to jump to the evalutation state.
    if (isReadyToIdentify(buffer.Length())) { state = IDENTIFICATION; }
  }
}

void _read() {
  lastReadAttempt = millis();
  buffer.Add(Serial.read());
}

void _identify() {
  if (Serial.available() > 0) {
    _read();
    return;
  }
  state = PARSE;
}

void _parse() {
  parse(buffer.Get(), buffer.Length(), &Serial);
  state = RECOVER;
}

void _recover() {
  // Free buffer. Create a new one to store a new reading.
  buffer.Reset(BUFFER_SIZE);
  // Clear the global variables.
  lastReadAttempt = 0;
  // Jump to the beginning.
  state = WAITING;
}
