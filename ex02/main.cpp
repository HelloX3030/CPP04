#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
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
    std::cout << "=================== Deep Copy Tests ===================" << std::endl;
    {
        Cat *cat1 = new Cat();
        Cat *cat2 = new Cat(*cat1);
        delete cat1;
        cat2->print();
        delete cat2;

        Dog *dog1 = new Dog();
        Dog *dog2 = new Dog(*dog1);
        delete dog1;
        dog2->print();
        delete dog2;
    }
    std::cout << "=================== Custom Tests ===================" << std::endl;
    {
        Cat c1;
        c1.makeSound();
        c1.print();
        Cat c2 = c1;
        Cat c3(c1);
    }
    {
        Dog d1;
        d1.makeSound();
        d1.print();
        Dog d2 = d1;
        Dog d3(d1);
    }
    // Animal is pure Virtual:
    // {
    //     Animal *meta = new Animal();
    //     meta->makeSound();
    //     meta->print();
    //     delete meta;
    // }
    return 0;
}
