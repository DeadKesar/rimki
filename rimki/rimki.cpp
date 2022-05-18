
#include "RimNumber.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    RimNumber rim1, rim2;
    rim1.CallSetFromConsole("введите римское число 1: ");
    std::cout << std::endl;
    rim2.CallSetFromConsole("введите римское число 2: ");
    std::cout << std::endl;
    std::cout << rim1 * rim2;


}


