#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--- Testing Abstract Animal Class ---\n";
    
    // This would cause compilation error - Animal is abstract
    // const Animal* meta = new Animal(); // ERROR!
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    
    delete j;
    delete i;

    std::cout << "\n--- Testing WRONG non-virtual behavior ---\n";
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat(); // This is the key test!
    WrongCat* directWrongCat = new WrongCat();
    
    std::cout << wrong->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << directWrongCat->getType() << " " << std::endl;
    
    wrong->makeSound(); // Will call WrongAnimal::makeSound()
    wrongCat->makeSound(); // Will call WrongAnimal::makeSound() - WRONG! Should be WrongCat
    directWrongCat->makeSound(); // Will call WrongCat::makeSound() - Only when used directly
    
    delete wrong;
    delete wrongCat;
    delete directWrongCat;

    std::cout << "\n--- Testing array of Animals ---\n";
    
    // Test array of Animals (only derived classes)
    const int size = 4;
    Animal* animals[size];
    
    for (int idx = 0; idx < size; idx++) {
        if (idx < size / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }
    
    for (int idx = 0; idx < size; idx++) {
        std::cout << "Animal " << idx << ": ";
        animals[idx]->makeSound();
        delete animals[idx];
    }

    std::cout << "\n--- Testing deep copy ---\n";
    
    // Test deep copy
    Dog original;
    original.getBrain()->set_idea(0, "I am a good dog");
    
    Dog copy = original;
    copy.getBrain()->set_idea(0, "I am a copy dog");
    
    std::cout << "Original idea: " << original.getBrain()->get_idea(0) << std::endl;
    std::cout << "Copy idea: " << copy.getBrain()->get_idea(0) << std::endl;

    return 0;
}
