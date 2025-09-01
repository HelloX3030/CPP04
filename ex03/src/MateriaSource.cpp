#include "../include/MateriaSource.hpp"
#include "../include/AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << MATERIA_SOURCE_COLOR << "MateriaSource default constructor called" << RESET << std::endl;
    for (int i = 0; i < MATERIA_SOURCE_INVENTORY_SIZE; ++i)
        materiaInventory[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MATERIA_SOURCE_INVENTORY_SIZE; ++i)
    {
        if (materiaInventory[i])
            delete materiaInventory[i];
    }
    std::cout << MATERIA_SOURCE_COLOR << "MateriaSource destructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << MATERIA_SOURCE_COLOR << "MateriaSource copy constructor called" << RESET << std::endl;
    for (int i = 0; i < MATERIA_SOURCE_INVENTORY_SIZE; ++i)
    {
        if (other.materiaInventory[i])
            materiaInventory[i] = other.materiaInventory[i]->clone();
        else
            materiaInventory[i] = nullptr;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << MATERIA_SOURCE_COLOR << "MateriaSource copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < MATERIA_SOURCE_INVENTORY_SIZE; ++i)
        {
            if (materiaInventory[i])
                delete materiaInventory[i];
            if (other.materiaInventory[i])
                materiaInventory[i] = other.materiaInventory[i]->clone();
            else
                materiaInventory[i] = nullptr;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
    {
        std::cout << MATERIA_SOURCE_COLOR << "Cannot learn a null materia." << RESET << std::endl;
        return;
    }

    for (int i = 0; i < MATERIA_SOURCE_INVENTORY_SIZE; ++i)
    {
        if (!materiaInventory[i])
        {
            materiaInventory[i] = m->clone();
            std::cout << MATERIA_SOURCE_COLOR << "Learned materia of type: " << m->getType() << " in slot " << i << RESET << std::endl;
            return;
        }
    }
    std::cout << MATERIA_SOURCE_COLOR << "MateriaSource inventory full, cannot learn more materias." << RESET << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < MATERIA_SOURCE_INVENTORY_SIZE; ++i)
    {
        if (materiaInventory[i] && materiaInventory[i]->getType() == type)
        {
            std::cout << MATERIA_SOURCE_COLOR << "Creating materia of type: " << type << RESET << std::endl;
            return materiaInventory[i]->clone();
        }
    }
    std::cout << MATERIA_SOURCE_COLOR << "Materia of type: " << type << " not found." << RESET << std::endl;
    return nullptr;
}
