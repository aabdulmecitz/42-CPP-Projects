
#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade, bool isSigned)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(isSigned)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
}

Form::~Form()
{ 
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // _name is const, so we can only assign _signGrade, _execGrade, and _isSigned
        _signGrade; = other._signGrade;
        _execGrade = other._execGrade;
        _isSigned = other._isSigned;
    }
    return *this;
}

const std::string &Form::getName() const
{
	return _name;
}

int Form::getGrade() const
{
	return _grade;
}

void Form::incrementGrade()
{
    _grade--;
    if (_grade < 1)
    {
        throw Form::GradeTooHighException();
    }
    
}

void Form::decrementGrade()
{
    _grade++;
    if (_grade > 150)
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName() << ", Form grade " << obj.getGrade() << ".";
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high! Minimum grade is 1.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low! Maximum grade is 150.";
}

