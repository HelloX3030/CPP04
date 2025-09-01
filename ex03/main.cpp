#include "Ice.hpp"
#include <iostream>

int main(void)
{
    {
        Ice *ice = new Ice();
        std::cout << "Ice Constructed, Type: " << ice->getType() << std::endl;
        delete ice;
    }
    return 0;
}
