#include "../include/Brain.hpp"
#include "../include/Animal.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << BRAIN_COLOR << "Brain constructor called" << RESET << std::endl;
}

Brain::~Brain() {
    std::cout << BRAIN_COLOR << "Brain destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << BRAIN_COLOR << "Brain copy constructor called" << RESET << std::endl;
    for (int i = 0; i < BRAIN_SIZE; ++i)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << BRAIN_COLOR << "Brain assignment operator called" << RESET << std::endl;
    if (this != &other) {
        for (int i = 0; i < BRAIN_SIZE; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

// Special Constructor
Brain::Brain(const std::string idea) {
    std::cout << BRAIN_COLOR << "Brain special constructor called with idea: " << idea << RESET << std::endl;
    for (int i = 0; i < BRAIN_SIZE; ++i)
        ideas[i] = idea;
}
