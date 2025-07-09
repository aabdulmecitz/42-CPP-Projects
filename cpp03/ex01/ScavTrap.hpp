#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
private:
    std::string _name;
    int hp = 10;
    int ep = 10;
    int attack_damage = 0;
public:
    ScavTrap();
    ScavTrap(std::string name);
    ~ScavTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

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

