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
	
	// Special Constructors
	Animal(std::string type);

	// member functions
	virtual void makeSound() const;
	std::string getType() const;
};
