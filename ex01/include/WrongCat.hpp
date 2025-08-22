#pragma once

#include "WrongAnimal.hpp"

#include <string>

#define WRONG_CAT_COLOR "\033[36m"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);

    // member functions
	void makeSound() const override;
};
