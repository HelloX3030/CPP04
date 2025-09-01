#pragma once

#include "../include/IMateriaSource.hpp"

#define MATERIA_SOURCE_COLOR "\033[1;35m"
#define MATERIA_SOURCE_INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
    AMateria* materiaInventory[MATERIA_SOURCE_INVENTORY_SIZE];

public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);

    // Member Functions
    void learnMateria(AMateria*) override;
    AMateria* createMateria(std::string const & type) override;
};
