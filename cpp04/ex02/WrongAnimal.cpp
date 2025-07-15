#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal Constructor has called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor has called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    _type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!" << std::endl;
}
