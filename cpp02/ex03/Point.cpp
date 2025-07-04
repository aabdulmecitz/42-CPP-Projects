#include "Point.hpp"
#include <iostream>

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::Point(const Point& other): _x(other.get_x()), _y(other.get_y())
{
}

Point::~Point(void)
{
}

Point &Point::operator=(const Point &other)
{
    if (this == &other)
		return *this;
    return *this;
}

const Fixed &Point::get_x() const
{
    return this->_x;
}

const Fixed &Point::get_y() const
{
    return this->_y;
}

bool Point::operator==(const Point &other) const
{
    return  (this->get_x() == other.get_x()) &&
            (this->get_y() == other.get_y());
}