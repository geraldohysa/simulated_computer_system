// console.h
#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

class Console {
    private:
    std::string input_string;
    
    public:
    Console();
    void write(int value);
    int read();
};

#endif
