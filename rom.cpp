#include "rom.h"

Rom::Rom(int size) {
    data_.resize(size);
    capacity_ = size;
}

int Rom::read(int address) {
    return data_[address];
}

void Rom::write(int address, int byte) {
  
}

void Rom::initialize(int address, std::string str) {
      int i;
      for (i = 0; i < (int)str.length(); i++) {
        data_[address + i] = str[i]; 
      }
      data_[address + i + 1] = '\0';
}

