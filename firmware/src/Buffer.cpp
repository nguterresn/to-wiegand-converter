#include "Buffer.h"

Buffer::Buffer(Stream *serial) {
  this->serial = serial;
};

void Buffer::Create(int size) {
  // Allocate first chunk of memory for this array.
  data = (uint8_t *) calloc(size, sizeof(uint8_t));
  if (data == NULL) {
    serial->println("Unable to allocate memory for `data` array");
    return;
  }
  index = 0;
  this->size = size;
  serial->print("Allocated ");
  serial->print(size);
  serial->println(" bytes for `data` array");
}

void Buffer::Add(uint8_t value) {
  if (data == NULL) {
    serial->println("Unable to find allocated memory for `data` array");
    return;
  }
  if (index >= size) {
    serial->println("The `data` array has reached its size limit.");
    // Reallocate more memory. Double the size.
    size *= 2;
    data = (uint8_t*) realloc(data, size * sizeof(uint8_t));
    if (data == NULL) {
      serial->println("Unable to reallocate memory for `data` array");
      return;
    }
  }
  *(data + index++) = value;
  serial->print("Value added: ");
  serial->println(value);
};

void Buffer::Reset(int size) {
  this->Delete();
  this->Create(size);
}

void Buffer::Delete() { free(data); }

uint8_t* Buffer::Get() {
  return data;
}

uint8_t Buffer::Length() {
  return index;
}