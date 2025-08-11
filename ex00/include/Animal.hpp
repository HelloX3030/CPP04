#pragma once

#include <string>

#define RESET "\033[0m"
#define ANIMAL_COLOR "\033[35m"

class Animal
{
private:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	// member functions
	virtual void makeSound();
};
