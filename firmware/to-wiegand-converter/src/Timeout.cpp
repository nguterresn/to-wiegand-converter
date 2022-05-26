#include "Timeout.h"

bool hasExceedTimeout(unsigned long start, unsigned long timeout) {
  return (millis() - start > timeout);
}
