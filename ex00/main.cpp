#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

int main(void)
{
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
