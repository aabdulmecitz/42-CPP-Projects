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
    // Üçgen köşeleri
    Point A(0, 0);
    Point B(4, 0);
    Point C(2, 4);

    // CASE 1: Nokta üçgenin tam ortasında
    Point P1(2, 1);
    std::cout << MAGENTA << "CASE 1: " << RESET << bsp(A, B, C, P1) << std::endl;
    // Beklenen: 1 (Nokta üçgenin içindedir)

    // CASE 2: Nokta köşelerden birinde (A)
    Point P2(0, 0);
    std::cout << MAGENTA << "CASE 2: " << RESET << bsp(A, B, C, P2) << std::endl;
    // Beklenen: 0 (Nokta kenar/köşe üzerindedir, iç sayılmaz)

    // CASE 3: Nokta bir kenar üzerinde (AB kenarında)
    Point P3(2, 0);
    std::cout << MAGENTA << "CASE 3: " << RESET << bsp(A, B, C, P3) << std::endl;
    // Beklenen: 0 (Kenar üzerinde)

    // CASE 4: Nokta üçgenin dışarısında
    Point P4(5, 5);
    std::cout << MAGENTA << "CASE 4: " << RESET << bsp(A, B, C, P4) << std::endl;
    // Beklenen: 0 (Nokta üçgenin dışındadır)

    // CASE 5: Nokta üçgenin içinde ama çok yakın kenara
    Point P5(1.999, 0.001);
    std::cout << MAGENTA << "CASE 5: " << RESET << bsp(A, B, C, P5) << std::endl;
    // Beklenen: 1 (Nokta içtedir)

    // CASE 6: Üçgen çok küçük, nokta içinde
    Point A2(0, 0);
    Point B2(0.001, 0);
    Point C2(0, 0.001);
    Point P6(0.0003, 0.0003);
    std::cout << MAGENTA << "CASE 6: " << RESET << bsp(A2, B2, C2, P6) << std::endl;
    // Beklenen: 1 (Küçük üçgenin içinde)

    return 0;
}
