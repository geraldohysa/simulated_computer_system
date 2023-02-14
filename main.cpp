#include <iostream>
#include "rom.h"
#include "ram.h"
#include "mmu.h"
#include "console.h"
#include "cpu.h"

int main()
{
  Console cons;
  Rom rom(1000);
  Ram ram(1000);
  Mmu mmu;
  Cpu cpu;
  Instruction inst;

  inst.address_ = 10;
  inst.str = "hello world";

  mmu.attach(&rom, 0);
  mmu.attach(&ram, 1000);

  cpu.setup_memory(&mmu);
  cpu.setup_io(&cons);
}