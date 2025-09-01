#pragma once

#include <string>

#define RESET "\033[0m"
#define AMATERIA_COLOR "\033[1;33m"

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    virtual ~AMateria();
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);

    // Special Constructors
    AMateria(std::string const &type);

    // Member Functions
    std::string const &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
