#ifndef Buffer_H
#define Buffer_H

#include <Arduino.h>

class Buffer {
  private:
    uint8_t *data;
    int index;
    int size;
    Stream *serial;

  public:
    Buffer(Stream *serial);
    void Create(int size);
    void Add(uint8_t value);
    void Reset(int size);
    void Delete();
    uint8_t* Get();
    uint8_t Length();
};

#endif
