#include "Dog.hpp"

Dog::Dog(void) : Animal(), _type("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor has called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    _type = other._type;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string Dog::getType(void) const
{
    return this->_type;
}

void Dog::setType(std::string type)
{
    this->_type = type;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound!: Woff Wo" << std::endl;
}