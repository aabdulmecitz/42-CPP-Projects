#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "================ TEST 1: Intern creates ShrubberyCreationForm ================" << std::endl;
    try
    {
        Intern someIntern;
        AForm* form = someIntern.makeForm("shrubbery creation", "home");
        
        if (form)
        {
            std::cout << "Created form: " << form->getName() << std::endl;
            
            Bureaucrat alice("Alice", 140);
            alice.signForm(*form);
            alice.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 2: Intern creates RobotomyRequestForm ================" << std::endl;
    try
    {
        Intern someIntern;
        AForm* form = someIntern.makeForm("robotomy request", "Bender");
        
        if (form)
        {
            std::cout << "Created form: " << form->getName() << std::endl;
            
            Bureaucrat bob("Bob", 40);
            bob.signForm(*form);
            bob.executeForm(*form);
            bob.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 3: Intern creates PresidentialPardonForm ================" << std::endl;
    try
    {
        Intern someIntern;
        AForm* form = someIntern.makeForm("presidential pardon", "a criminal");
        
        if (form)
        {
            std::cout << "Created form: " << form->getName() << std::endl;
            
            Bureaucrat charlie("Charlie", 3);
            charlie.signForm(*form);
            charlie.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 4: Intern invalid form name ================" << std::endl;
    try
    {
        Intern someIntern;
        AForm* form = someIntern.makeForm("invalid form", "target");
        
        if (form)
        {
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 5: Multiple interns creating forms ================" << std::endl;
    try
    {
        Intern intern1;
        Intern intern2;
        Intern intern3;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "garden");
        AForm* form2 = intern2.makeForm("robotomy request", "Subject");
        AForm* form3 = intern3.makeForm("presidential pardon", "prisoner");
        
        if (form1 && form2 && form3)
        {
            Bureaucrat admin("Admin", 1);
            
            admin.signForm(*form1);
            admin.executeForm(*form1);
            
            admin.signForm(*form2);
            admin.executeForm(*form2);
            
            admin.signForm(*form3);
            admin.executeForm(*form3);
            
            delete form1;
            delete form2;
            delete form3;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 6: Case sensitivity test ================" << std::endl;
    try
    {
        Intern someIntern;
        // Try with incorrect case
        AForm* form = someIntern.makeForm("Shrubbery Creation", "target");
        if (form)
            delete form;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught (expected): " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 7: Direct form creation vs Intern creation ================" << std::endl;
    try
    {
        Intern someIntern;
        Bureaucrat boss("Boss", 1);
        
        // Create through intern
        AForm* internForm = someIntern.makeForm("robotomy request", "Subject1");
        
        // Create directly
        RobotomyRequestForm directForm("Subject2");
        
        std::cout << "Both forms created successfully" << std::endl;
        
        boss.signForm(*internForm);
        boss.signForm(directForm);
        
        boss.executeForm(*internForm);
        boss.executeForm(directForm);
        
        delete internForm;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================ TEST 8: Execute without signing (via Intern) ================" << std::endl;
    try
    {
        Intern someIntern;
        AForm* form = someIntern.makeForm("shrubbery creation", "yard");
        
        if (form)
        {
            Bureaucrat worker("Worker", 200);  // Grade too low
            worker.executeForm(*form);
            
            delete form;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================ All tests completed ================" << std::endl;
    return 0;
}
