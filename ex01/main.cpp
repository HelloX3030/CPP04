#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

#define ANIALS_AMOUNT 10

int main(void)
{
    std::cout << "=================== Subject Tests ===================" << std::endl;
    {
        Animal *animals[ANIALS_AMOUNT];
        for (int i = 0; i < ANIALS_AMOUNT; ++i) {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < ANIALS_AMOUNT; ++i) {
            std::cout << animals[i]->getType() << " ";
            animals[i]->makeSound();
            animals[i]->print();
        }
        for (int i = 0; i < ANIALS_AMOUNT; ++i) {
            delete animals[i];
        }
    }
    std::cout << "=================== Custom Tests ===================" << std::endl;
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
        a1.print();
    }
    {
        Cat c1;
        c1.makeSound();
        c1.print();
    }
    {
        Dog d1;
        d1.makeSound();
        d1.print();
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
