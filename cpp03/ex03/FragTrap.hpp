#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    ~FragTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys(void);

    std::string get_name(void);
    void set_name(std::string name);

    int get_hp(void);
    void set_hp(int hpoints);

    int get_ep(void);
    void set_ep(int energy_points);

    int get_attack_d(void);
    void set_attack_d(int attack_damage);
};

#endif