#include "Zombie.hpp"

int main()
{
    std::cout << YELLOW << "Creating zombie on stack:" << RESET << std::endl;
    Zombie stackZombie("Stack Bob");
    stackZombie.announce();
    
    std::cout << YELLOW << "\nCreating zombie on heap:" << RESET << std::endl;
    Zombie* heapZombie = newZombie("Heap Jim");
    heapZombie->announce();
    
    std::cout << YELLOW << "\nCreating random chump:" << RESET << std::endl;
    randomChump("Random Pete");
    
    delete heapZombie;
    
    return 0;
}