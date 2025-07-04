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

    //Assignment operator overload
    Fixed& operator=(const Fixed& other);

    //Comparison operators overload
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;

    //Arithmetic operators overload
    float operator+(const Fixed &other) const;
    float operator-(const Fixed &other) const;
    float operator*(const Fixed &other) const;
    float operator/(const Fixed &other) const;

    //Pre-increment and post-increment operators overload
    Fixed operator++(); // Pre-increment
    Fixed operator++(int); // Post-increment

    //Pre-decrement and post-decrement operators overload
    Fixed operator--(); // Pre-decrement
    Fixed operator--(int); // Post-decrement

    //Min and max functions
    Fixed& min(Fixed &a, Fixed &b);
    const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    //Conversion functions
    // Getters and setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed(int const value);
    Fixed(float const value);
    float toFloat(void) const;
    int toInt(void) const;

    // Overload the output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif