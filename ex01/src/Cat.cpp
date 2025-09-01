#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    std::cout << CAT_COLOR << "Default constructor called for Cat" << RESET << std::endl;
    type = "Cat";
    brain = new Brain("Default Cat Idea");
}

Cat::~Cat() {
    std::cout << CAT_COLOR << "Destructor called for Cat" << RESET << std::endl;
    delete brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << CAT_COLOR << "Copy constructor called for Cat" << RESET << std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << CAT_COLOR << "Assignment operator called for Cat" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << CAT_COLOR << "Cat meows" << RESET << std::endl;
}

void Cat::print() const {
    std::cout << CAT_COLOR << "Cat type: " << type << RESET << std::endl;
    if (brain) {
        brain->print_ideas();
    } else {
        std::cout << CAT_COLOR << "Cat has no brain assigned." << RESET << std::endl;
    }
}
