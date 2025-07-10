#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
    : hp(10), ep(10), attack_damage(0)
{
    std::cout << "Constructor has called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
    : _name(name), hp(10), ep(10), attack_damage(0)
{
    std::cout << "Constructor has called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (get_ep() == 0 || get_hp() == 0)
    {
        std::cout << "ClapTrap " << get_name() << " cannot attack because it has no ";
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
    
    std::cout << "ClapTrap " << this->get_name() << 
    " attacks " << target << ", causing " <<
    this->get_attack_d() << " points of damage!" << 
    std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((int)amount >= get_hp())
        this->set_hp(0);
    else
        this->set_hp(get_hp() - amount);
    std::cout << "ClapTrap " << get_name() <<" takes " 
    << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (get_ep() == 0 || get_hp() == 0)
    {
        std::cout << "ClapTrap " << get_name() 
        << " cannot be repaired!" << std::endl;
        return;
    }

    this->set_ep(get_ep() - 1);
    this->set_hp(get_hp() + amount);

    std::cout << "ClapTrap " << get_name() 
    << " is repaired for " << amount << " hit points!"
    << std::endl;
}

//Getters and Setters

std::string ClapTrap::get_name(void)
{
    return this->_name;
}

void ClapTrap::set_name(std::string name)
{
    this->_name = name;
}

int ClapTrap::get_hp(void)
{
    return this->hp;
}

void ClapTrap::set_hp(int hpoints)
{
    this->hp = hpoints;
}

int ClapTrap::get_ep(void)
{
    return this->ep;
}

void ClapTrap::set_ep(int energy_points)
{
    this->ep = energy_points;
}

int ClapTrap::get_attack_d(void)
{
    return this->attack_damage;
}

void ClapTrap::set_attack_d(int attack_damage)
{
    this->attack_damage = attack_damage;
}