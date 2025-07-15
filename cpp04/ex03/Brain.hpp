#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    ~Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);

    std::string get_idea(unsigned int index) const;
    void set_idea(unsigned int index, std::string idea);
};

#endif