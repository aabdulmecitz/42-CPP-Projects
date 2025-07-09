#include "ScavTrap.hpp"

int main()
{
    ScavTrap clap1("Robot1");
    ScavTrap clap2("Robot2");
    
    clap1.attack("Enemy");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    return 0;
}