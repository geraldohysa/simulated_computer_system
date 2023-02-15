#include <iostream>
#include "rom.h"
#include "ram.h"
#include "mmu.h"
#include "console.h"
#include "cpu.h"

void machine_program()
{
  Console cons;
  Rom rom(1000);
  Ram ram(1000);
  Mmu mmu;
  Cpu cpu;

  // attaching the memory devices to the mmu
  mmu.attach(&rom, 0);
  mmu.attach(&ram, 1000);

  // settingup the memory and console to cpu
  cpu.setup_memory(&mmu);
  cpu.setup_io(&cons);

  std::vector<Instruction> instrs{

      {"Data", "Please Enter a Number betwen 0-9: ", 0, 0, 0, 0, 0, 0, 10, 0}, // Init string at address 10
      {"OutStr", "", 0, 0, 0, 0, 0, 0, 10, 0},                                 // outstring to the user
      {"InB", "", 1, 0, 0, 0, 0, 0, 0, 0},                                     // get the input from the user and store at register 1
      {"LoadImm", "", 2, 0, 0, 0, 0, 0, 0, 48},                                // Load register 2 with number 48 to sub with input to get the int value
      {"Sub", "", 0, 1, 2, 0, 0, 0, 0, 0},                                     // sub register 1 with 2 and store the value to register 0 this is the input number
      {"Store", "", 0, 0, 0, 0, 0, 0, 1000, 0},                                // Store register 0 in memmory 1000

      {"LoadImm", "", 3, 0, 0, 0, 0, 0, 0, 0},                                 // Load register 3 with number 0 this will be the Fibonacci value
      {"Store", "", 3, 0, 0, 0, 0, 0, 1030, 0},                                // Store register 3 in memmory 1030

      {"LoadImm", "", 1, 0, 0, 0, 0, 0, 0, 0},                                 // Init register 1 with first Fibonacci 0
      {"Store", "", 1, 0, 0, 0, 0, 0, 1010, 0},                                // Store register 1 in memmory 1010

      {"LoadImm", "", 2, 0, 0, 0, 0, 0, 0, 1},                                 // Init register 2 with second Fibonacci 1
      {"Store", "", 2, 0, 0, 0, 0, 0, 1020, 0},                                // Store register 2 in memmory 1020

      {"LoadImm", "", 5, 0, 0, 0, 0, 0, 0, 1},                                 // Init register 5 with 1 to decrement the input value
      {"Sub", "", 0, 0, 5, 0, 0, 0, 0, 0},                                     // decrement input value with 1 because loop start at 0;


      {"JZ", "", 0, 0, 0, 0, 8, 0, 0, 0},                                      // if the value at register 0 is equal to 0 then break looping
      {"Add", "", 0, 1, 2, 3, 0, 0, 0},                                        // Register 3 = reg 1 + reg 2
      {"Store", "", 3, 0, 0, 0, 0, 0, 1030, 0},                                // Store register 3 in memmory 1030    
      {"Load", "", 1, 0, 0, 0, 0, 0, 1020, 0},                                 // reg 1 = reg 2
      {"Store", "", 1, 0, 0, 0, 0, 0, 1010, 0},                                // Store register 1 in memmory 1010
      {"Load", "", 2, 0, 0, 0, 0, 0, 1030, 0},                                 // reg 2 = reg 3
      {"Store", "", 2, 0, 0, 0, 0, 0, 1020, 0},                                // Store register 2 in memmory 1020
      {"Sub", "", 0, 0, 5, 0, 0, 0, 0, 0},                                     //  counter or input value --
      {"J", "", 0, 0, 0, 0, -9, 0, 0, 0},                                      // Jumb back to the start of loop

      {"Data", "The Fibonacci value of you Number is: ", 0, 0, 0, 0, 0, 0, 100, 0},  // Init string at address 100
      {"OutStr", "", 0, 0, 0, 0, 0, 0, 100, 0},                                      // outstring to the user

      {"Data", "\n", 0, 0, 0, 0, 0, 0, 150, 0},                                      // Init string at address 150
      {"OutNum", "", 3, 0, 0, 0, 0, 0, 0, 0},                                        // sending final rezult number to console
      {"OutStr", "", 0, 0, 0, 0, 0, 0, 150, 0},                                      // outstring to the user
  };


  cpu.run(instrs);
}