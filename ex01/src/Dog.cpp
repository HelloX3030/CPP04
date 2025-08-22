#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    std::cout << DOG_COLOR << "Default constructor called for Dog" << RESET << std::endl;
    type = "Dog";
    brain = new Brain("Default Dog Idea");
}

Dog::~Dog() {
    std::cout << DOG_COLOR << "Destructor called for Dog" << RESET << std::endl;
    delete brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << DOG_COLOR << "Copy constructor called for Dog" << RESET << std::endl;
    delete brain;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << DOG_COLOR << "Assignment operator called for Dog" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << DOG_COLOR << "Dog barks" << RESET << std::endl;
}

void Dog::print() const {
    std::cout << DOG_COLOR << "Dog type: " << type << RESET << std::endl;
    if (brain) {
        brain->print_ideas();
    } else {
        std::cout << DOG_COLOR << "Dog has no brain assigned." << RESET << std::endl;
    }
}
