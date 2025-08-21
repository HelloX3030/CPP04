#pragma once

#include "Animal.hpp"

#include <string>

#define CAT_COLOR "\033[90m"

class Cat : public Animal
{
private:
	std::string type;

public:
    Cat();
    ~Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);

    // member functions
	void makeSound() override;
};
