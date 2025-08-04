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
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing WRONG non-virtual behavior ===" << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    WrongCat* directWrongCat = new WrongCat();
    
    std::cout << wrong->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << directWrongCat->getType() << " " << std::endl;
    
    wrong->makeSound();
    wrongCat->makeSound();
    directWrongCat->makeSound();
    
    delete wrong;
    delete wrongCat;
    delete directWrongCat;

    return 0;
}
