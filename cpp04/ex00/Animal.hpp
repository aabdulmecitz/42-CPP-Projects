#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    ~Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);

    std::string get_type(void) const;
    void set_type(std::string type);

    virtual void makesound() const;
};

std::ostream& operator<<(std::ostream& os, const Animal& animal);

#endif

