#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    // Test basic functionality
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongAnimal();
    
    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrong->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    wrong->makeSound();
    
    delete meta;
    delete j;
    delete i;
    delete wrong;

    std::cout << "\n--- Testing array of Animals ---\n";
    
    // Test array of Animals
    const int size = 4;
    Animal* animals[size];
    
    for (int idx = 0; idx < size; idx++) {
        if (idx < size / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }
    
    for (int idx = 0; idx < size; idx++) {
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
