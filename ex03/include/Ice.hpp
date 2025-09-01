#pragma once

#include "AMateria.hpp"

#define ICE_COLOR "\033[1;36m"

class Ice : public AMateria
{
public:
    Ice();
    ~Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);

    // Member Functions
    AMateria* clone() const override;
    void use(ICharacter& target) override;
};
