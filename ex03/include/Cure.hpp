#pragma once

#include "AMateria.hpp"

#define CURE_COLOR "\033[1;32m"

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);

    // Member Functions
    AMateria* clone() const override;
    void use(ICharacter& target) override;
};
