#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
    std::cout << "Dog Constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog Destructor has called" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound!: Woff Wo" << std::endl;
}

Brain* Dog::getBrain() const
{
    return _brain;
}