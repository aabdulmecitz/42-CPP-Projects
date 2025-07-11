#include "Dog.hpp"

Dog::Dog(void) 
{
    std::cout << "Constructor has called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor has called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _type = other._type;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string Dog::get_type(void)
{
    return this->_type;
}

void Dog::set_type(std::string type)
{
    this->set_type(type);
}
