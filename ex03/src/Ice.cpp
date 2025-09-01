#include "../include/Ice.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
    std::cout << ICE_COLOR << "Ice default constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
    std::cout << ICE_COLOR << "Ice destructor called" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout << ICE_COLOR << "Ice copy constructor called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << ICE_COLOR << "Ice assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Ice::clone() const
{
    std::cout << ICE_COLOR << "Ice clone method called" << RESET << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << ICE_COLOR << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
