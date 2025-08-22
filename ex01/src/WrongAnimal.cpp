#include "../include/WrongAnimal.hpp"
#include "Animal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Animal") {
    std::cout << WRONG_ANIMAL_COLOR << "Default constructor called for WrongAnimal" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << WRONG_ANIMAL_COLOR << "Destructor called for WrongAnimal: " << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << WRONG_ANIMAL_COLOR << "Copy constructor called for WrongAnimal: " << type << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << WRONG_ANIMAL_COLOR << "Assignment operator called for WrongAnimal: " << type << RESET << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << WRONG_ANIMAL_COLOR << "WrongAnimal makes a sound" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
