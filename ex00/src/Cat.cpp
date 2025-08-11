#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
    std::cout << CAT_COLOR << "Default constructor called for Cat" << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << CAT_COLOR << "Destructor called for Cat" << RESET << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << CAT_COLOR << "Copy constructor called for Cat" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << CAT_COLOR << "Assignment operator called for Cat" << RESET << std::endl;
    }
    return *this;
}

void Cat::makeSound() {
    std::cout << CAT_COLOR << "Cat meows" << RESET << std::endl;
}
