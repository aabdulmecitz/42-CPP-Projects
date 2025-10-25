#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->_grade_to_sign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _grade_to_sign(signGrade), _grade_to_execute(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned),\
    _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm: Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName();
    os << ", form sign grade " << f.getSignGrade();
    os << ", exec grade " << f.getExecGrade();
    os << ", signed: " << (f.getIsSigned() ? "yes" : "no");
    return os;
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _grade_to_sign;
}

int AForm::getExecGrade() const
{
    return _grade_to_execute;
}