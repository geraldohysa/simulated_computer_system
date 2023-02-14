#ifndef CPU_H
#define CPU_H

#include <vector>
#include <string>
#include "mmu.h"
#include "console.h"


struct Instruction {
    std::string type_;
    int reg;
    int regA;
    int regB;
    int regC;
    int offset;
    int port_;
    int address_;
    int number_;
    std::string str;
};

class Cpu {
    private:
        std::vector<int> registers_;
        Mmu *memory_;
        std::vector<Console*> cons_;
        int instrPtr;
    public:
        Cpu();
        void setup_memory(Mmu *mem);
        void setup_io(Console *cons);
        void run(std::vector<Instruction> instrList);
        void eval(Instruction instr);
};



#endif