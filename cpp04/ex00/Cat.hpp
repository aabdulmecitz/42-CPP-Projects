#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
protected:
    std::string _type;
public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    std::string getType(void) const;
    void setType(std::string type);
    void makeSound() const;

};

#endif