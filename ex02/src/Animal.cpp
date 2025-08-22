#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << ANIMAL_COLOR << "Default constructor called for Animal" << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << ANIMAL_COLOR << "Destructor called for Animal: " << type << RESET << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << ANIMAL_COLOR << "Copy constructor called for Animal: " << type << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << ANIMAL_COLOR << "Assignment operator called for Animal: " << type << RESET << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::print() const {
    std::cout << ANIMAL_COLOR << "Animal type: " << type << RESET << std::endl;
}
