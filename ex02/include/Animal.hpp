#pragma once

#include <string>

#define RESET "\033[0m"
#define ANIMAL_COLOR "\033[35m"

class Animal
{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	// member functions
	virtual void makeSound() const = 0;
	std::string getType() const;
	virtual void print() const;
};
