#pragma once

#include <string>

#define WRONG_ANIMAL_COLOR "\033[31m"

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);

	// member functions
	virtual void makeSound() const;
	std::string getType() const;
};
