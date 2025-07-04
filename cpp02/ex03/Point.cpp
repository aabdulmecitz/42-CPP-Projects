#include "Point.hpp"
#include <iostream>

int Point::getRawBits(void) const
{
    return this->_rawBits;
}

Point::Point(void)
{
    _rawBits = 0;
}

Point::Point(const Point& other)
{
    _rawBits = other._rawBits;
}

Point::~Point(void)
{

}

Point &Point::operator=(const Point &other)
{
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    return *this;
}
