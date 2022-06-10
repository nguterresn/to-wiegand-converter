#include "Replay.h"

void _high(uint8_t pin) {
  digitalWrite(pin, 1);
}

void _low() {
  digitalWrite(DATA0, 0);
  digitalWrite(DATA1, 0);
}

void io() {
  pinMode(DATA0, OUTPUT);
  pinMode(DATA1, OUTPUT);

  _low();
}

void replay(uint8_t *data, uint8_t length) {
  // default: msb & decimal;
  for (int i = 0; i < length; i++) {
    if (data[i] == 48) {
      _low();
      _high(DATA0);
    } else if (data[i] == 49) {
      _low();
      _high(DATA1);
    }
    // Default interval is 2ms.
    delay(2);
  }
  _low();
}
