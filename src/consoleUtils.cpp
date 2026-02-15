#include <iostream>
#include "consoleUtils.h"

void clearScreen()
{
    std::cout << "\x1B[2J\x1B[H";
}
