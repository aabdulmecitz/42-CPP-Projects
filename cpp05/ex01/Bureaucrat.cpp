
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name)
{
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::set_name(std::string name)
{
    this->_name = name;
}

std::string Bureaucrat::get_name(std::string name) const
{
    return _name;
}