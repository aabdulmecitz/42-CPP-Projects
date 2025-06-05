#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << GREEN << name << RESET << " attacks with their " 
                  << CYAN << weapon->getType() << RESET << std::endl;
    else
        std::cout << RED << name << " has no weapon!" << RESET << std::endl;
}
