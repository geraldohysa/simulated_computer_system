#include "ram.h"


Ram::Ram(int size) : Rom(size) {
}

void Ram::write(int address, int byte) {
    data_[address] = byte;
}