#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int hit_p = 10;
    int enrg_p = 10;
    int attck_damage = 0;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string get_name(void);
    void set_name(std::string name);

    int get_hit_p(void);
    void set_hit_p(int hit_points);

    int get_enrg_p(void);
    void set_enrg_p(int energy_points);

    int get_attack_d(void);
    void set_attack_d(int attack_damage);


};

