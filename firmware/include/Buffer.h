#ifndef Buffer_H
#define Buffer_H

#include <Arduino.h>

#define BUFFER_SIZE         100

class Buffer {
  private:
    uint8_t *data;
    int index;
    int size;
    Stream *serial;

  public:
    Buffer(Stream *serial);
    void create(int size);
    void add(uint8_t value);
    void reset(int size);
    void clear();
    uint8_t* get();
    uint8_t length();
};

#endif
