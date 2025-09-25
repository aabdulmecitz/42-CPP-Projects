#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        std::cout << "=== Form Creation Tests ===" << std::endl;
        Form form1("Tax Form", 50, 25, false);
        Form form2("Building Permit", 10, 5, false);
        Form form3("Parking Ticket", 150, 100, false);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;

        std::cout << "\n=== Form Details ===" << std::endl;
        std::cout << "Form1 - Name: " << form1.getName() 
                  << ", Sign Grade: " << form1.getSignGrade()
                  << ", Exec Grade: " << form1.getExecGrade()
                  << ", Signed: " << (form1.getIsSigned() ? "Yes" : "No") << std::endl;

        std::cout << "\n=== Bureaucrat Creation ===" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 25);
        Bureaucrat employee("Employee", 75);
        Bureaucrat intern("Intern", 150);

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << employee << std::endl;
        std::cout << intern << std::endl;

        std::cout << "\n=== Successful Form Signing Tests ===" << std::endl;
        
        // Boss can sign all forms
        try
        {
            form1.beSigned(boss);
            std::cout << boss.getName() << " signed " << form1.getName() << std::endl;
            std::cout << form1 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << boss.getName() << " couldn't sign " << form1.getName() << " because " << e.what() << std::endl;
        }
        
        // Manager can sign tax form (grade 50 requirement, manager is grade 25)
        Form taxForm2("Tax Form 2", 50, 25, false);
        try
        {
            taxForm2.beSigned(manager);
            std::cout << manager.getName() << " signed " << taxForm2.getName() << std::endl;
            std::cout << taxForm2 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << manager.getName() << " couldn't sign " << taxForm2.getName() << " because " << e.what() << std::endl;
        }
        
        // Employee can sign parking ticket (grade 150 requirement, employee is grade 75)
        try
        {
            form3.beSigned(employee);
            std::cout << employee.getName() << " signed " << form3.getName() << std::endl;
            std::cout << form3 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << employee.getName() << " couldn't sign " << form3.getName() << " because " << e.what() << std::endl;
        }

        std::cout << "\n=== Failed Form Signing Tests ===" << std::endl;
        
        // Intern cannot sign building permit (grade 10 requirement, intern is grade 150)
        try
        {
            form2.beSigned(intern);
            std::cout << intern.getName() << " signed " << form2.getName() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << intern.getName() << " couldn't sign " << form2.getName() << " because " << e.what() << std::endl;
        }
        std::cout << form2 << std::endl;
        
        // Employee cannot sign building permit (grade 10 requirement, employee is grade 75)
        try
        {
            Form strictForm("Strict Form", 10, 5, false);
            strictForm.beSigned(employee);
            std::cout << employee.getName() << " signed " << strictForm.getName() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << employee.getName() << " couldn't sign Strict Form because " << e.what() << std::endl;
        }

        std::cout << "\n=== Form Exception Tests ===" << std::endl;
        std::cout << "Trying to create form with sign grade 0..." << std::endl;
        Form invalidForm1("Invalid High Sign", 0, 50, false);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to create form with exec grade 151..." << std::endl;
        Form invalidForm2("Invalid Low Exec", 50, 151, false);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to create form with sign grade 200..." << std::endl;
        Form invalidForm3("Invalid Low Sign", 200, 50, false);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to create form with exec grade -5..." << std::endl;
        Form invalidForm4("Invalid High Exec", 50, -5, false);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Copy Constructor and Assignment Tests ===" << std::endl;
    try
    {
        Form originalForm("Original", 30, 20, false);
        std::cout << "Original: " << originalForm << std::endl;
        
        // Test copy constructor
        Form copiedForm(originalForm);
        std::cout << "Copied: " << copiedForm << std::endl;
        
        // Test assignment operator
        Form assignedForm("Temporary", 100, 100, false);
        assignedForm = originalForm;
        std::cout << "Assigned: " << assignedForm << std::endl;
        
        // Sign original form and check if others are affected
        Bureaucrat signer("Signer", 20);
        originalForm.beSigned(signer);
        std::cout << "After signing original:" << std::endl;
        std::cout << "Original: " << originalForm << std::endl;
        std::cout << "Copied: " << copiedForm << std::endl;
        std::cout << "Assigned: " << assignedForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Boundary Tests ===" << std::endl;
    try
    {
        // Test exact grade matching
        Form boundaryForm("Boundary Form", 75, 50, false);
        Bureaucrat exactGrade("Exact Grade", 75);
        
        std::cout << "Before signing: " << boundaryForm << std::endl;
        boundaryForm.beSigned(exactGrade);
        std::cout << exactGrade.getName() << " signed " << boundaryForm.getName() << std::endl;
        std::cout << "After signing: " << boundaryForm << std::endl;
        
        // Test one grade too low
        Form stricterForm("Stricter Form", 74, 50, false);
        try
        {
            stricterForm.beSigned(exactGrade); // Grade 75 cannot sign grade 74 requirement
        }
        catch (const std::exception& e)
        {
            std::cout << exactGrade.getName() << " couldn't sign " << stricterForm.getName() << " because " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
