#include "Form.hpp"

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) 
    : _name(name), _isSigned(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), 
      _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
    return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() 
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute() << ".";
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