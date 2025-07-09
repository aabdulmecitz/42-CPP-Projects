#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap <" << this->get_name() << 
    "> attacks <" << target << ">, causing <" <<
    this->get_attack_d() << "> points of damage!" << 
    std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
}

void ClapTrap::beRepaired(unsigned int amount)
{

}