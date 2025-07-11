#include "Animal.hpp"

Animal::Animal(void) 
{
    std::cout << "Constructor has called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor has called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _type = other._type;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

std::string Animal::get_type(void) const
{
    return this->_type;
}

void Animal::set_type(std::string type)
{
    this->set_type(type);
}

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
    os << "Animal type: " << animal.get_type();
    return os;
}
