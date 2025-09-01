#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << ICE_COLOR << "================================== Test Ice Creation ==================================" << RESET << std::endl;
        Ice *ice = new Ice();
        std::cout << "Ice Constructed, Type: " << ice->getType() << std::endl;
        delete ice;
    }
    {
        std::cout << CURE_COLOR << "================================= Test Cure Creation ==================================" << RESET << std::endl;
        Cure *cure = new Cure();
        std::cout << "Cure Constructed, Type: " << cure->getType() << std::endl;
        delete cure;
    }

    return 0;
}
