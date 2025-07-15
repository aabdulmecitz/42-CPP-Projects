#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor has called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

std::string Brain::get_idea(unsigned int index) const
{
    if (index >= 100)
        return "";
    return _ideas[index];
}

void Brain::set_idea(unsigned int index, std::string idea)
{
    if (index < 100)
        _ideas[index] = idea;
}
