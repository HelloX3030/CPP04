#pragma once

#include "Animal.hpp"

#include <string>

#define DOG_COLOR "\033[33m" 

class Dog : public Animal
{
private:
	std::string type;

public:
    Dog();
    ~Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);

    // member functions
	void makeSound() override;
};

