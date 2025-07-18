#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
    
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(const float x, const float y);
    ~Point(void);
    Point(const Point& other);
    Point& operator=(const Point& other);
    bool operator==(const Point &other) const;

    const Fixed &get_x() const;
    const Fixed &get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif