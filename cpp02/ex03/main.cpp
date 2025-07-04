#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

int main()
{
    // Corner of triangle
    Point A(0, 0);
    Point B(4, 0);
    Point C(2, 4);

    // CASE 1: The Point is certain center of triangle
    Point P1(2, 1);
    std::cout << MAGENTA << "CASE 1: " << RESET << bsp(A, B, C, P1) << std::endl;
    // Predicted: 1 (The point is inside of triangle)

    // CASE 2: The point is on a corner of triangle (A)
    Point P2(0, 0);
    std::cout << MAGENTA << "CASE 2: " << RESET << bsp(A, B, C, P2) << std::endl;
    // Predicted: 0 (The point is outside of triangle)

    // CASE 3: The point exists on a line (AB line)
    Point P3(2, 0);
    std::cout << MAGENTA << "CASE 3: " << RESET << bsp(A, B, C, P3) << std::endl;
    // Predicted: 0 (On a line)

    // CASE 4: The point is outside of triangle
    Point P4(5, 5);
    std::cout << MAGENTA << "CASE 4: " << RESET << bsp(A, B, C, P4) << std::endl;
    // Predicted: 0 (The point is outside of triangle)

    return 0;
}
