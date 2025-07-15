#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << "Animal Constructor has called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor has called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    _type = other._type;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::setType(std::string type)
{
    this->_type = type;
}

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
    os << "Animal type: " << animal.getType();
    return os;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound!" << std::endl;
}