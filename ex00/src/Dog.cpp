#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), type("Dog") {
    std::cout << DOG_COLOR << "Default constructor called for Dog" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << DOG_COLOR << "Destructor called for Dog" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << DOG_COLOR << "Copy constructor called for Dog" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << DOG_COLOR << "Assignment operator called for Dog" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << DOG_COLOR << "Dog barks" << RESET << std::endl;
}
