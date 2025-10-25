#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "================== TEST 1: ShrubberyCreationForm ==================" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 140);
        ShrubberyCreationForm shrubbery("home");
        
        std::cout << "Form: " << shrubbery << std::endl;
        std::cout << "Bureaucrat: " << alice << std::endl;
        
        std::cout << "\nAttempting to sign..." << std::endl;
        alice.signForm(shrubbery);
        
        std::cout << "After signing: " << shrubbery << std::endl;
        
        std::cout << "\nAttempting to execute..." << std::endl;
        alice.executeForm(shrubbery);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 2: RobotomyRequestForm ==================" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 40);
        RobotomyRequestForm robotomy("42 Student");
        
        std::cout << "Form: " << robotomy << std::endl;
        std::cout << "Bureaucrat: " << bob << std::endl;
        
        std::cout << "\nAttempting to sign..." << std::endl;
        bob.signForm(robotomy);
        
        std::cout << "After signing: " << robotomy << std::endl;
        
        std::cout << "\nAttempting to execute (multiple times to see randomness)..." << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Attempt " << (i + 1) << ": ";
            bob.executeForm(robotomy);
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 3: PresidentialPardonForm ==================" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 3);
        PresidentialPardonForm pardon("a guilty person");
        
        std::cout << "Form: " << pardon << std::endl;
        std::cout << "Bureaucrat: " << charlie << std::endl;
        
        std::cout << "\nAttempting to sign..." << std::endl;
        charlie.signForm(pardon);
        
        std::cout << "After signing: " << pardon << std::endl;
        
        std::cout << "\nAttempting to execute..." << std::endl;
        charlie.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 4: Execute without signing ==================" << std::endl;
    try
    {
        Bureaucrat diana("Diana", 1);
        ShrubberyCreationForm shrubbery2("garden");
        
        std::cout << "Form: " << shrubbery2 << std::endl;
        std::cout << "Bureaucrat: " << diana << std::endl;
        
        std::cout << "\nAttempting to execute WITHOUT signing..." << std::endl;
        diana.executeForm(shrubbery2);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 5: Grade too low to sign ==================" << std::endl;
    try
    {
        Bureaucrat eve("Eve", 150);
        RobotomyRequestForm robotomy2("Intern");
        
        std::cout << "Form: " << robotomy2 << std::endl;
        std::cout << "Bureaucrat: " << eve << std::endl;
        
        std::cout << "\nAttempting to sign (insufficient grade)..." << std::endl;
        eve.signForm(robotomy2);
        
        std::cout << "After failed sign: " << robotomy2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 6: Grade too low to execute ==================" << std::endl;
    try
    {
        Bureaucrat frank("Frank", 100);
        RobotomyRequestForm robotomy3("Subject");
        
        std::cout << "Form: " << robotomy3 << std::endl;
        std::cout << "Bureaucrat: " << frank << std::endl;
        
        std::cout << "\nSigning with a higher grade bureaucrat..." << std::endl;
        Bureaucrat grace("Grace", 50);
        grace.signForm(robotomy3);
        
        std::cout << "After signing: " << robotomy3 << std::endl;
        
        std::cout << "\nAttempting to execute with lower grade bureaucrat..." << std::endl;
        frank.executeForm(robotomy3);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 7: Presidential Pardon (insufficient grade) ==================" << std::endl;
    try
    {
        Bureaucrat henry("Henry", 10);
        PresidentialPardonForm pardon2("criminal");
        
        std::cout << "Form: " << pardon2 << std::endl;
        std::cout << "Bureaucrat: " << henry << std::endl;
        
        std::cout << "\nAttempting to sign with insufficient grade..." << std::endl;
        henry.signForm(pardon2);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n================== TEST 8: All three forms with grade 1 bureaucrat ==================" << std::endl;
    try
    {
        Bureaucrat admin("Admin", 1);  // Highest grade
        
        std::cout << "Bureaucrat: " << admin << std::endl;
        
        std::cout << "\n--- Shrubbery Form ---" << std::endl;
        ShrubberyCreationForm shrub("park");
        admin.signForm(shrub);
        admin.executeForm(shrub);
        
        std::cout << "\n--- Robotomy Form ---" << std::endl;
        RobotomyRequestForm robot("Bender");
        admin.signForm(robot);
        admin.executeForm(robot);
        
        std::cout << "\n--- Presidential Form ---" << std::endl;
        PresidentialPardonForm pres("Zoidberg");
        admin.signForm(pres);
        admin.executeForm(pres);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
