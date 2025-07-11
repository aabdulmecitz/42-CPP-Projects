#include "Cat.hpp"

Cat::Cat(void) 
{
    std::cout << "Constructor has called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor has called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _type = other._type;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string Cat::get_type(void)
{
    return this->_type;
}

void Cat::set_type(std::string type)
{
    this->set_type(type);
}
