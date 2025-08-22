#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), type("Cat") {
    std::cout << CAT_COLOR << "Default constructor called for Cat" << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << CAT_COLOR << "Destructor called for Cat" << RESET << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << CAT_COLOR << "Copy constructor called for Cat" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << CAT_COLOR << "Assignment operator called for Cat" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << CAT_COLOR << "Cat meows" << RESET << std::endl;
}
