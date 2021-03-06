#include "Buffer.h"

Buffer::Buffer(Stream *serial) {
  this->serial = serial;
};

void Buffer::create(int size) {
  // Allocate first chunk of memory for this array.
  data = (uint8_t *) calloc(size, sizeof(uint8_t));
  if (data == NULL) {
    #ifdef DEBUG
    serial->println("Unable to allocate memory for `data` array");
    #endif
    return;
  }
  index = 0;
  this->size = size;
  #ifdef DEBUG
  serial->print("Allocated ");
  serial->print(size);
  serial->println(" bytes for `data` array");
  #endif
}

void Buffer::add(uint8_t value) {
  if (data == NULL) {
    #ifdef DEBUG
    serial->println("Unable to find allocated memory for `data` array");
    #endif
    return;
  }
  if (index >= size) {
    #ifdef DEBUG
    serial->println("The `data` array has reached its size limit.");
    #endif
    // Reallocate more memory. Double the size.
    size *= 2;
    data = (uint8_t*) realloc(data, size * sizeof(uint8_t));
    if (data == NULL) {
      #ifdef DEBUG
      serial->println("Unable to reallocate memory for `data` array");
      #endif
      return;
    }
  }
  *(data + index++) = value;
  #ifdef DEBUG
  serial->print("Value added: ");
  serial->println(value);
  #endif
};

void Buffer::reset(int size) {
  this->clear();
  this->create(size);
}

void Buffer::clear() { free(data); }

uint8_t* Buffer::get() {
  return data;
}

uint8_t Buffer::length() {
  return index;
}
