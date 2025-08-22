#pragma once

#include <string>

#define BRAIN_COLOR "\033[35m"
#define BRAIN_SIZE 100

class Brain
{
protected:
	std::string ideas[BRAIN_SIZE];

public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	// Special Constructors
	Brain(const std::string idea);
};
