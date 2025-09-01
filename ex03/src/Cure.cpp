#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    std::cout << CURE_COLOR << "Cure default constructor called" << RESET << std::endl;
}

Cure::~Cure()
{
    std::cout << CURE_COLOR << "Cure destructor called" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    std::cout << CURE_COLOR << "Cure copy constructor called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << CURE_COLOR << "Cure assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Cure::clone() const
{
    std::cout << CURE_COLOR << "Cure clone method called" << RESET << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << CURE_COLOR << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
