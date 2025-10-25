#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::ofstream os((_target + "_shrubbery").c_str());
    if (!os || os.fail() || os.bad() || !os.is_open())
        throw std::runtime_error("There is a problem. Failed to open file!");
    
    os << "       _-_" << std::endl;
    os << "    /~~   ~~\\" << std::endl;
    os << " /~~         ~~\\" << std::endl;
    os << "{                }" << std::endl;
    os << " \\              /" << std::endl;
    os << "   \\  _-_-_-_  /" << std::endl;
    os << "     ~-_ _ _-~" << std::endl;
    os << "         | |" << std::endl;
    os << "        /| |\\" << std::endl;
    os << "         | |" << std::endl;
    os << std::endl;
    
}
