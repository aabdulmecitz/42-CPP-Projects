#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
protected:
    std::string _type;
public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    std::string getType(void) const;
    void setType(std::string type);
    void makeSound() const;
};

#endif