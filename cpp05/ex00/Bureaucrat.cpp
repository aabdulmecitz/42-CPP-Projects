
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{ 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // _name is const, so we can only assign _grade
        _grade = other._grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
    _grade--;
    if (_grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    
}

void Bureaucrat::decrementGrade()
{
    _grade++;
    if (_grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high! Minimum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low! Maximum grade is 150.";
}

