#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default")
{
    this->hp = 100;
    this->ep = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (get_ep() == 0 || get_hp() == 0)
    {
        std::cout << "FragTrap " << get_name() << " cannot attack because it has no ";
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
    
    std::cout << "FragTrap " << this->get_name() << 
    " attacks " << target << ", causing " <<
    this->get_attack_d() << " points of damage!" << 
    std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)get_hp())
        this->set_hp(0);
    else
        this->set_hp(get_hp() - amount);
    std::cout << "FragTrap " << get_name() << " takes " 
    << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (get_ep() == 0 || get_hp() == 0)
    {
        std::cout << "FragTrap " << get_name() 
        << " cannot be repaired!" << std::endl;
        return;
    }

    this->set_ep(get_ep() - 1);
    this->set_hp(get_hp() + amount);

    std::cout << "FragTrap " << get_name() 
    << " is repaired for " << amount << " hit points!"
    << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << get_name() << " requests a high five! ✋" << std::endl;
}

//Getters and Setters

std::string FragTrap::get_name(void)
{
    return this->_name;
}

void FragTrap::set_name(std::string name)
{
    this->_name = name;
}

int FragTrap::get_hp(void)
{
    return this->hp;
}

void FragTrap::set_hp(int hpoints)
{
    this->hp = hpoints;
}

int FragTrap::get_ep(void)
{
    return this->ep;
}

void FragTrap::set_ep(int energy_points)
{
    this->ep = energy_points;
}

int FragTrap::get_attack_d(void)
{
    return this->attack_damage;
}

void FragTrap::set_attack_d(int attack_damage)
{
    this->attack_damage = attack_damage;
}