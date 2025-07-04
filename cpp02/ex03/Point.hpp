#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
    
private:
    Fixed const x;
    Fixed const y;

public:
    Point(const float x, const float y);
    ~Point(void);
    Point(const Point& other);
    Point& operator=(const Point& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);

};
#endif