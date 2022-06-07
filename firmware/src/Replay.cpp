#include "Replay.h"

void _replay(uint8_t *data, uint8_t length) {
  // default: msb
  for (int i = 0; i < length; i++) {
    if (data[i] == 48) {
      digitalWrite(DATA0, 1);
      digitalWrite(DATA1, 0);
    } else if (data[i] == 49) {
      digitalWrite(DATA0, 0);
      digitalWrite(DATA1, 1);
    }
    // Default interval is 2ms.
    delay(2);
  }
  digitalWrite(DATA0, 0);
  digitalWrite(DATA1, 0);
}

void io() {
  pinMode(DATA0, OUTPUT);
  pinMode(DATA1, OUTPUT);

  digitalWrite(DATA0, 0);
  digitalWrite(DATA1, 0);
}
