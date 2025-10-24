#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdbool.h>

class Form
{
private:
    std::string _name;
    bool _isSigned;
    const int _grade_to_sign;
    const int _grade_to_execute;
public:
    Form(std::string name);
    ~Form();

    void set_name(std::string name);
    std::string get_name(std::string name) const;

    void beSigned();
    
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

#endif
