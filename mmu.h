#ifndef MMU_H
#define MMU_H

#include <vector>
#include <string>
#include "rom.h"
#include "ram.h"

class Mmu
{
private:
    Rom *rom_;
    Ram *ram_;
    int rom_address;
    int ram_address;

public:
    Mmu();
    void attach(Rom *rom, int address);
    void attach(Ram *ram, int address);
    int read(int address);
    void write(int address, int byte);
    void initialize(int address, std::string str);
};

#endif
