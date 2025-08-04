#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing CORRECT virtual behavior ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will call Cat::makeSound() - CORRECT
    j->makeSound(); // Will call Dog::makeSound() - CORRECT
    meta->makeSound(); // Will call Animal::makeSound() - CORRECT
    
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing WRONG non-virtual behavior ===" << std::endl;
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

    return 0;
}
