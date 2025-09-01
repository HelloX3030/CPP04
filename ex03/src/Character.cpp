#include "../include/Character.hpp"
#include "../include/AMateria.hpp"
#include <iostream>

Character::Character() : ICharacter(), name("default Character")
{
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i)
        inventory[i] = nullptr;
    std::cout << CHARACTER_COLOR << "Character default constructor called" << RESET << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i)
    {
        if (inventory[i])
            delete inventory[i];
    }
    std::cout << CHARACTER_COLOR << "Character destructor called" << RESET << std::endl;
}

Character::Character(const Character &other) : ICharacter(other), name(other.name)
{
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
    std::cout << CHARACTER_COLOR << "Character copy constructor called" << RESET << std::endl;
}

Character &Character::operator=(const Character &other)
{
    std::cout << CHARACTER_COLOR << "Character copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i)
        {
            if (inventory[i])
                delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = nullptr;
        }
    }
    return *this;
}

Character::Character(const std::string& name) : name(name)
{
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i)
        inventory[i] = nullptr;
    std::cout << CHARACTER_COLOR << "Character parameterized constructor called with name: " << name << RESET << std::endl;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << CHARACTER_COLOR << "Cannot equip a null AMateria." << RESET << std::endl;
        return;
    }
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            std::cout << CHARACTER_COLOR << name << " equipped " << m->getType() << " in slot " << i << "." << RESET << std::endl;
            return;
        }
    }
    std::cout << CHARACTER_COLOR << name << "'s inventory is full. Cannot equip " << m->getType() << "." << RESET << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= CHARACTER_INVENTORY_SIZE)
    {
        std::cout << CHARACTER_COLOR << "Index " << idx << " is out of bounds. Cannot unequip." << RESET << std::endl;
        return;
    }
    if (inventory[idx])
    {
        std::cout << CHARACTER_COLOR << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << "." << RESET << std::endl;
        inventory[idx] = nullptr;
    }
    else
    {
        std::cout << CHARACTER_COLOR << "Slot " << idx << " is already empty. Cannot unequip." << RESET << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= CHARACTER_INVENTORY_SIZE)
    {
        std::cout << CHARACTER_COLOR << "Index " << idx << " is out of bounds. Cannot use." << RESET << std::endl;
        return;
    }
    if (inventory[idx])
    {
        inventory[idx]->use(target);
    }
    else
    {
        std::cout << CHARACTER_COLOR << "Slot " << idx << " is empty. Cannot use." << RESET << std::endl;
    }
}
