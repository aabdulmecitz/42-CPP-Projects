#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    std::string _name;
public:
    Bureaucrat(std::string name);
    ~Bureaucrat();

    void set_name(std::string name);
    std::string get_name(std::string name) const;
};

#endif
