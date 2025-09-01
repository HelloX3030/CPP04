#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type("default AMateria")
{
    std::cout << AMATERIA_COLOR << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
    std::cout << AMATERIA_COLOR << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
    std::cout << AMATERIA_COLOR << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << AMATERIA_COLOR << "AMateria copy assignment operator called" << RESET << std::endl;
    // No copying of 'type' like specified in the subject
    // if (this != &other)
    //     type = other.type;
    return *this;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << AMATERIA_COLOR << "AMateria parameterized constructor called with type: " << type << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << AMATERIA_COLOR << "* uses " << type << " on " << target.getName() << " *" << RESET << std::endl;
}
