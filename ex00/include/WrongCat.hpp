#pragma once

#include "WrongAnimal.hpp"

#include <string>

#define WRONG_CAT_COLOR "\033[90m"

class WrongCat : public WrongAnimal
{
private:
	std::string type;

public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);

    // member functions
	void makeSound() const override;
};
