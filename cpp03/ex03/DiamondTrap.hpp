#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& other);              // Eksik
    DiamondTrap& operator=(const DiamondTrap& other);   // Eksik
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI(void);
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