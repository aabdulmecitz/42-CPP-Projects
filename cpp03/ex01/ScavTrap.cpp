#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default")
{
    this->hp = 100;
    this->ep = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (get_ep() == 0 || get_hp() == 0)
    {
        std::cout << "ScavTrap " << get_name() << " cannot attack because it has no ";
        if (get_ep() == 0 && get_hp() == 0)
            std::cout << "energy points and hit points";
        else if (get_ep() == 0)
            std::cout << "energy points";
        else
            std::cout << "hit points";
        std::cout << "!" << std::endl;
        return;
    }
    
    this->set_ep(get_ep() - 1);
    
    std::cout << "ScavTrap " << this->get_name() << 
    " attacks " << target << ", causing " <<
    this->get_attack_d() << " points of damage!" << 
    std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)get_hp())
        this->set_hp(0);
    else
        this->set_hp(get_hp() - amount);
    std::cout << "ScavTrap " << get_name() << " takes " 
    << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (get_ep() == 0 || get_hp() == 0)
    {
        std::cout << "ScavTrap " << get_name() 
        << " cannot be repaired!" << std::endl;
        return;
    }

    this->set_ep(get_ep() - 1);
    this->set_hp(get_hp() + amount);

    std::cout << "ScavTrap " << get_name() 
    << " is repaired for " << amount << " hit points!"
    << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode!" << std::endl;
}

//Getters and Setters

std::string ScavTrap::get_name(void)
{
    return this->_name;
}

void ScavTrap::set_name(std::string name)
{
    this->_name = name;
}

int ScavTrap::get_hp(void)
{
    return this->hp;
}

void ScavTrap::set_hp(int hpoints)
{
    this->hp = hpoints;
}

int ScavTrap::get_ep(void)
{
    return this->ep;
}

void ScavTrap::set_ep(int energy_points)
{
    this->ep = energy_points;
}

int ScavTrap::get_attack_d(void)
{
    return this->attack_damage;
}

void ScavTrap::set_attack_d(int attack_damage)
{
    this->attack_damage = attack_damage;
}