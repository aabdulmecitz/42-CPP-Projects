#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
private:
    int _rawBits;
    static const int _fractionalBits = 8;
public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed(int const value);
    Fixed(float const value);
    float toFloat(void) const;
    int toInt(void) const;

    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif