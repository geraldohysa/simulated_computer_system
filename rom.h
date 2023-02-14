#ifndef ROM_H
#define ROM_H

#include <vector>
#include <string>

class Rom
{
public:
    std::vector<int> data_;
    int capacity_;
    Rom(int size);
    int read(int address);
    void write(int address, int byte);
    void initialize(int address, std::string str);
};

#endif