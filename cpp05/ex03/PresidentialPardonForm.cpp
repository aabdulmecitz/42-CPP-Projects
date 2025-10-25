#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
