#include "mmu.h"

Mmu::Mmu() {}

void Mmu::attach(Rom *rom, int address)
{
    rom_ = rom;
    rom_address = address;
}

void Mmu::attach(Ram *ram, int address)
{
    ram_ = ram;
    ram_address = address;
}

int Mmu::read(int address)
{
    if (address > rom_address && address <= rom_->capacity_ + rom_address)
        return rom_->read(address);
    else if (address > ram_address && address <= ram_->capacity_ + ram_address)
        return ram_->read(address);

    return -1;
}

void Mmu::write(int address, int byte)
{
    if (address > rom_address && address <= rom_->capacity_ + rom_address)
        rom_->write(address, byte);
    else if (address > ram_address && address <= ram_->capacity_ + ram_address)
        ram_->write(address, byte);
}

void Mmu::initialize(int address, std::string str)
{
    if (address > rom_address && address <= rom_->capacity_ + rom_address)
        rom_->initialize(address, str);
    else if (address > ram_address && address <= ram_->capacity_ + ram_address)
        ram_->initialize(address, str);
}
