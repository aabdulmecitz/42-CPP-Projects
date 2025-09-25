#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   _name;
    const int           _signGrade;
    const int           _execGrade;
    bool                _isSigned = false;

public:
    Form(const std::string& name, int signGrade, int execGrade, bool isSigned);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw(); //noexcept
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif

