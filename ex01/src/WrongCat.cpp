#include "../include/WrongCat.hpp"
#include "../include/Animal.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal(), type("WrongCat") {
    std::cout << WRONG_CAT_COLOR << "Default constructor called for WrongCat" << RESET << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << WRONG_CAT_COLOR << "Destructor called for WrongCat" << RESET << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << WRONG_CAT_COLOR << "Copy constructor called for WrongCat" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << WRONG_CAT_COLOR << "Assignment operator called for WrongCat" << RESET << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << WRONG_CAT_COLOR << "WrongCat meows" << RESET << std::endl;
}
