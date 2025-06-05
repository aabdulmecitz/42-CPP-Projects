#include "Zombie.hpp"

int main()
{
    std::cout << YELLOW << "Creating a horde of 5 zombies:" << RESET << std::endl;
    
    int N = 5;
    Zombie* horde = zombieHorde(N, "Horde Zombie");
    
    std::cout << MAGENTA << "\nMaking zombies announce themselves:" << RESET << std::endl;
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    
    std::cout << YELLOW << "\nDestroying the horde:" << RESET << std::endl;
    delete[] horde;
    
    return 0;
}