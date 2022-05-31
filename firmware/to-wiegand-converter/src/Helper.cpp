#include "Helper.h"

const char* intToConstChar(int number, char* buffer) {
  // Allocate memory for this later. For now it is ok.
  sprintf(buffer, "%d", number);
  return buffer;
}
