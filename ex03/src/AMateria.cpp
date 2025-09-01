#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type("default AMateria")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria parameterized constructor called with type: " << type << std::endl;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}
