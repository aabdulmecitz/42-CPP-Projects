#include "Fixed.hpp"
#include <iostream>

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

Fixed::Fixed(void)
{
    //std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

//Constructors and Destructor

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}


Fixed::Fixed(int const value) {
    //std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
    return;
}

Fixed::Fixed(float const value) {
    //std::cout << "Float constructor called" << std::endl;
    _rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits))); // Convert float to fixed-point representation
    return;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) {
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    return *this;
}

// Comparison operators overload

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

// Arithmetic operators overload

float Fixed::operator+(const Fixed &other) const
{
    return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other) const
{
    return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other) const
{
    return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other) const
{
    return this->toFloat() / other.toFloat();
}

// Pre-increment and post-increment operators overload

Fixed Fixed::operator++()
{
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_rawBits++;
    return tmp;
}

//Pre-decrement and post-decrement operators overload

Fixed Fixed::operator--()
{
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_rawBits++;
    return tmp;
}

//Min and max functions

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return a;
    else
        return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.toFloat() > b.toFloat())
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

//some functions

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
