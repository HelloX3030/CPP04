#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << ICE_COLOR 
                  << "============================== Test Ice Class ==============================" 
                  << RESET << std::endl;
    
        // 1. Default constructor
        Ice ice1;
        std::cout << "ice1 constructed, Type: " << ice1.getType() << std::endl;
    
        // 2. Copy constructor
        Ice ice2(ice1);
        std::cout << "ice2 copy-constructed from ice1, Type: " << ice2.getType() << std::endl;
    
        // 3. Copy assignment
        Ice ice3;
        ice3 = ice1;
        std::cout << "ice3 copy-assigned from ice1, Type: " << ice3.getType() << std::endl;
    
        // 4. Dynamic allocation + destructor
        Ice* icePtr = new Ice();
        std::cout << "icePtr constructed on heap, Type: " << icePtr->getType() << std::endl;
        delete icePtr; // calls destructor
    
        // 5. clone()
        AMateria* cloned = ice1.clone();
        std::cout << "cloned->getType(): " << cloned->getType() << std::endl;
        delete cloned;
    
        // 6. use() — needs an ICharacter mock
        Character dummy("Dummy");    
        ice1.use(dummy);
    }
    {
        std::cout << CURE_COLOR 
                  << "============================== Test Cure Class ==============================" 
                  << RESET << std::endl;
    
        // 1. Default constructor
        Cure cure1;
        std::cout << "cure1 constructed, Type: " << cure1.getType() << std::endl;
    
        // 2. Copy constructor
        Cure cure2(cure1);
        std::cout << "cure2 copy-constructed from cure1, Type: " << cure2.getType() << std::endl;
    
        // 3. Copy assignment
        Cure cure3;
        cure3 = cure1;
        std::cout << "cure3 copy-assigned from cure1, Type: " << cure3.getType() << std::endl;
    
        // 4. Dynamic allocation + destructor
        Cure* curePtr = new Cure();
        std::cout << "curePtr constructed on heap, Type: " << curePtr->getType() << std::endl;
        delete curePtr; // calls destructor
    
        // 5. clone()
        AMateria* cloned = cure1.clone();
        std::cout << "cloned->getType(): " << cloned->getType() << std::endl;
        delete cloned;
    
        // 6. use() — needs an ICharacter
        Character dummy("Dummy");
        cure1.use(dummy);
    }
    {
        std::cout << CHARACTER_COLOR 
                  << "=============================== Test Character Creation ===============================" 
                  << RESET << std::endl;
    
        // 1. Default constructor + name constructor
        Character char1("Hero");
        std::cout << "char1 constructed, Name: " << char1.getName() << std::endl;

        Character char2;
        std::cout << "char2 default constructed, Name: " << char2.getName() << std::endl;
    
        // 2. Copy constructor
        Character char3(char1);
        std::cout << "char3 copy-constructed from char1, Name: " << char3.getName() << std::endl;
    
        // 3. Copy assignment
        char2 = char1;
        std::cout << "char2 copy-assigned from char1, Name: " << char2.getName() << std::endl;
    
        // 4. Equip AMateria
        Ice* ice = new Ice();
        Cure* cure = new Cure();
        char1.equip(ice);
        char1.equip(cure);
    
        std::cout << "char1 equipped ice and cure." << std::endl;
    
        // 5. Use AMateria
        Character target("DummyTarget");
        std::cout << "char1 uses equipped materias on target:" << std::endl;
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i) {
            char1.use(i, target);
        }
    
        // 6. Unequip
        char1.unequip(0);
        char1.unequip(-1);
        char1.unequip(4);
        std::cout << "char1 unequipped slot 0 (ice)." << std::endl;
    
        // 7. Clean up
        delete ice;
    
        // 8. Heap allocation test
        Character* charHeap = new Character("HeapHero");
        std::cout << "charHeap constructed on heap, Name: " << charHeap->getName() << std::endl;
        delete charHeap;
    }
    {
        std::cout << MATERIA_SOURCE_COLOR 
                  << "=============================== Test MateriaSource Creation ===============================" 
                  << RESET << std::endl;
    
        // 1. Default constructor
        MateriaSource source1;
        std::cout << "source1 constructed." << std::endl;
    
        // 2. Copy constructor
        MateriaSource source2(source1);
        std::cout << "source2 copy-constructed from source1." << std::endl;
    
        // 3. Copy assignment
        MateriaSource source3;
        source3 = source1;
        std::cout << "source3 copy-assigned from source1." << std::endl;
    
        // 4. Learn Materia
        Ice* ice = new Ice();
        Cure* cure = new Cure();
        source1.learnMateria(ice);
        source1.learnMateria(cure);
    
        std::cout << "source1 learned ice and cure." << std::endl;
    
        // 5. Create Materia
        AMateria* createdIce = source1.createMateria("ice");
        AMateria* createdCure = source1.createMateria("cure");
        AMateria* createdUnknown = source1.createMateria("fire");
    
        if (createdIce)
            std::cout << "Created materia of type: " << createdIce->getType() << std::endl;
        else
            std::cout << "Could not create materia of type 'ice'." << std::endl;
        if (createdCure)
            std::cout << "Created materia of type: " << createdCure->getType() << std::endl;
        else
            std::cout << "Could not create materia of type 'cure'." << std::endl;
        if (!createdUnknown)
            std::cout << "Could not create unknown materia type 'fire'." << std::endl;
        else
            std::cout << "Created materia of type: " << createdUnknown->getType() << " even when it should not have been possible." << std::endl;
    
        // 6. Clean up
        delete ice;
        delete cure;
        delete createdIce;
        delete createdCure;
    
        // 7. Heap allocation test
        MateriaSource* sourceHeap = new MateriaSource();
        std::cout << "sourceHeap constructed on heap." << std::endl;
        delete sourceHeap;
    }
    return 0;
}
