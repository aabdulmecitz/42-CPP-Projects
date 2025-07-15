#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    //this virtual defining for virtual functions
    virtual ~Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);

    virtual std::string getType(void) const;
    void setType(std::string type);

    //You said that this function is pure virtual function so this 
        //class abstract, you are not able to create object directly
    //child classes must implement this class
    //there is not any implementation about this sign.
    //you said that the child classes gonna implement this.
    virtual void makeSound() const = 0; // Pure virtual function
};

std::ostream& operator<<(std::ostream& os, const Animal& animal);

#endif

