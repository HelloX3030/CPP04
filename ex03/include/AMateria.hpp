#pragma once

#include <string>

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
