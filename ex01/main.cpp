#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"
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

    std::cout << "=================== Custom Tests ===================" << std::endl;
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
    {
        WrongAnimal *wrong_animal = new WrongAnimal();
        wrong_animal->makeSound();
        std::cout << "Wrong Type: " << wrong_animal->getType() << std::endl;
        delete wrong_animal;
    }
    {
        WrongAnimal *wrong_cat = new WrongCat();
        wrong_cat->makeSound();
        std::cout << "Wrong Type: " << wrong_cat->getType() << std::endl;
        delete wrong_cat;
    }
    return 0;
}
