#include "Fixed.hpp"
#include <iostream>

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    return *this;
}

Fixed::Fixed(int const value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
    return;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits))); // Convert float to fixed-point representation
    return;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
