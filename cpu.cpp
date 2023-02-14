#include "cpu.h"


Cpu::Cpu() {
    registers_.resize(8);
}


void Cpu::setup_memory(Mmu *mem) {
    memory_ = mem;
}

void Cpu::setup_io(Console *cons) {
    cons_.push_back(cons);
}


void Cpu::run(std::vector<Instruction> instrList) {
    instrPtr = 0;

    while (instrPtr < (int)instrList.size() && instrList[instrPtr].type_ != "Halt") { 
        eval(instrList[instrPtr]);
        instrPtr++;
    }
}

void Cpu::eval(Instruction instr) {


    if (instr.type_ == "Data")
        memory_->initialize(instr.address_, instr.str);
    else if (instr.type_ == "LoadImm")
        registers_[instr.reg] = instr.number_;
    else if (instr.type_ == "Load")
        registers_[instr.reg] = memory_->read(instr.address_);
    else if (instr.type_ == "Store")
        memory_->write(instr.address_, registers_[instr.reg]);
     else if (instr.type_ == "InB")
         registers_[instr.reg] = cons_[instr.port_]->read();
     else if (instr.type_ == "OutB")
         cons_[instr.port_]->write(registers_[instr.reg]);
     else if (instr.type_ == "OutNum")
         cons_[instr.port_]->write(registers_[instr.reg]);
     else if (instr.type_ == "OutStr") {
          int i = 0;
         while (char(memory_->read(instr.address_ + i)) != '\0') {
                 cons_[instr.port_]->write(instr.address_);
                 i++;
             }
     }
    else if (instr.type_ == "Add")
        registers_[instr.regC] = instr.regA + instr.regB;
    else if (instr.type_ == "Sub")
        registers_[instr.regC] = instr.regA - instr.regB;
    else if (instr.type_ == "J")
        instrPtr += instr.offset;
    else if (instr.type_ == "JZ") {
         if (registers_[instr.reg] == 0)
            instrPtr += instr.offset;
    }
    else if (instr.type_ == "JNZ") {
         if (registers_[instr.reg] == 0)
            instrPtr += instr.offset;
    }
    else if (instr.type_ == "JReg")
        instrPtr += registers_[instr.reg];
        
}