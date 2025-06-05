#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{

}

Zombie::~Zombie()
{
    std::cout << RED << name << " has been destroyed." << RESET << std::endl;
}

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}

void Zombie::announce()
{
    std::cout << GREEN << name << CYAN << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}