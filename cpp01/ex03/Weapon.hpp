#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Weapon
{
private:
    std::string type;
public:
    Weapon(const std::string& type = "default weapon");
    ~Weapon();
    std::string getType() const;
    void setType(const std::string& newType);
};

#endif
