#include <iostream>
#include <fstream>
#include "isReal.h"

int main()
{
    const std::string PATH = "input.txt";
    int count = 1;
    while (true)
    {
        try
        {
            std::string str = openNewString(PATH);
            std::cout << "Строка номер " << count << '\n';
            std::cout << str << '\n';
            if (isFloatingPoint(str))
            {
                std::cout << "ДА\n";
            }
            else
            {
                std::cout << "НЕТ\n";
            }
        }
        catch (StrException& err)
        {
            std::cout << err.getError() << std::endl << std::endl;
            break;
        }
        count++;
    }
    return 0;
}