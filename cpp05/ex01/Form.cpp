#include "Form.hpp"

Form::Form(std::string name) : _isSigned(false)
{
}

Form::~Form()
{
}

void Form::set_name(std::string name)
{
    this->_name = name;
}

std::string Form::get_name(std::string name) const
{
    return _name;
}