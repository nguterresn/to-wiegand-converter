#include "Wiegand.h"

void PrintWiegand(uint8_t *data, uint8_t format, Stream *serial) {
  for (size_t i = 0; i < format; i++) {
    serial->print(*(data + i), DEC);
  }
  serial->println(" ");
}
