#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form
{
private:
    std::string _name;
public:
    Form(std::string name);
    ~Form();

    void set_name(std::string name);
    std::string get_name(std::string name) const;
};

#endif
