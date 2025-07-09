#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default")
{
    this->hp = 100;
    this->ep = 50;
    this->attack_damage = 30;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    this->hp = 100;
    this->ep = 50;
    this->attack_damage = 30;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::get_name(void)
{
    return this->_name;
}

void DiamondTrap::set_name(std::string name)
{
    this->_name = name;
}

int DiamondTrap::get_hp(void)
{
    return this->hp;
}

void DiamondTrap::set_hp(int hpoints)
{
    this->hp = hpoints;
}

int DiamondTrap::get_ep(void)
{
    return this->ep;
}

void DiamondTrap::set_ep(int energy_points)
{
    this->ep = energy_points;
}

int DiamondTrap::get_attack_d(void)
{
    return this->attack_damage;
}

void DiamondTrap::set_attack_d(int attack_damage)
{
    this->attack_damage = attack_damage;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    ScavTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    FragTrap::beRepaired(amount);
}
