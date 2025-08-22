#pragma once

#include "Animal.hpp"

#include <string>

#define CAT_COLOR "\033[90m"

class Brain;

class Cat : public Animal
{
private:
    Brain *brain;

public:
    Cat();
    ~Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);

    // member functions
	void makeSound() const override;
};
