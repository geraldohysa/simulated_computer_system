#ifndef RAM_H
#define RAM_H

#include <string>
#include "rom.h"

class Ram : public Rom {

    public:
        Ram(int size);
        void write(int address, int byte);
};


#endif