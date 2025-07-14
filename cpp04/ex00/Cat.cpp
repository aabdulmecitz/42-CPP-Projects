#include "Cat.hpp"

Cat::Cat(void) : Animal(), _type("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor has called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    _type = other._type;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string Cat::getType(void) const
{
    return this->_type;
}

void Cat::setType(std::string type)
{
    this->_type = type;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound!: Meeoww" << std::endl;
}