#include "console.h"

Console::Console()
{
    input_string = "";
}

void Console::write(int value)
{
    std::cout << (char)value;
}

int Console::read()
{
    if (input_string.empty())
        std::getline(std::cin, input_string);
    int result = input_string[0];
    input_string = input_string.substr(1);
    return result;
}
