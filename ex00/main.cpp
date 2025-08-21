#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include <iostream>

int main(void)
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }

    {
        Animal a1;
        a1.makeSound();
    }
    {
        Cat c1;
        c1.makeSound();
    }
    {
        Dog d1;
        d1.makeSound();
    }
    return 0;
}
