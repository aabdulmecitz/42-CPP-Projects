#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
    std::cout << "Cat Constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat Destructor has called" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound!: Meeoww" << std::endl;
}

Brain* Cat::getBrain() const
{
    return _brain;
}