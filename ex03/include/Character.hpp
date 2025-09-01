#pragma once

#include "ICharacter.hpp"

#define CHARACTER_INVENTORY_SIZE 4
#define CHARACTER_COLOR "\033[1;31m"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character();
    ~Character();
    Character(const Character &other);
    Character &operator=(const Character &other);

    // Special Constructor
    Character(const std::string& name);

    // Member Functions
    std::string const &getName() const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;
};
