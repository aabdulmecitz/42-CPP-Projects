#include <iostream>
#include "Fixed.hpp"

int main() {
    // Constructor & Output Test
    Fixed a;
    Fixed b(5);            // From int
    Fixed c(3.14f);        // From float
    Fixed d = b;           // Copy constructor
    Fixed e;

    std::cout << "Default a      : " << a << '\n'
              << "From int b     : " << b << '\n'
              << "From float c   : " << c << '\n'
              << "Copy of b (d)  : " << d << "\n\n";

    // Assignment Operator
    e = c;
    std::cout << "Assignment e = c: " << e << "\n\n";

    // Comparison Operators
    std::cout << "b == d : " << (b == d) << '\n'
              << "b != c : " << (b != c) << '\n'
              << "b < c  : " << (b < c)  << '\n'
              << "b <= d : " << (b <= d) << '\n'
              << "c > b  : " << (c > b)  << '\n'
              << "d >= b : " << (d >= b) << "\n\n";

    // Arithmetic Operators
    std::cout << "b + c = " << (b + c) << '\n'
              << "b - c = " << (b - c) << '\n'
              << "b * c = " << (b * c) << '\n'
              << "b / c = " << (b / c) << "\n\n";

    // Pre/Post Increment and Decrement
    Fixed f;
    std::cout << "f         : " << f << '\n'
              << "++f       : " << ++f << '\n'
              << "f++       : " << f++ << '\n'
              << "f (after) : " << f << '\n'
              << "--f       : " << --f << '\n'
              << "f--       : " << f-- << '\n'
              << "f (after) : " << f << "\n\n";

    // Conversion Functions
    std::cout << "c.toFloat(): " << c.toFloat() << '\n'
              << "c.toInt()  : " << c.toInt() << "\n\n";

    // Min/Max Functions
    Fixed g(10.5f), h(42.42f);
    std::cout << "min(g, h): " << Fixed::min(g, h) << '\n'
              << "max(g, h): " << Fixed::max(g, h) << '\n';

    return 0;
}
