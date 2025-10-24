#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: Valid Form Creation ===" << std::endl;
    try
    {
        Form form1("Tax Form", 50, 100);
        std::cout << form1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Invalid Form - Grade too high (0) ===" << std::endl;
    try
    {
        Form form2("Invalid Form", 0, 100);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Invalid Form - Grade too low (151) ===" << std::endl;
    try
    {
        Form form3("Invalid Form", 50, 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Bureaucrat signing form with sufficient grade ===" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 30);
        Form form4("Travel Form", 50, 100);
        
        std::cout << "Before signing: " << form4 << std::endl;
        b1.signForm(form4);
        std::cout << "After signing: " << form4 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Bureaucrat signing form with insufficient grade ===" << std::endl;
    try
    {
        Bureaucrat b2("Bob", 100);
        Form form5("High Level Form", 30, 50);
        
        std::cout << "Before signing: " << form5 << std::endl;
        b2.signForm(form5);
        std::cout << "After signing: " << form5 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Grade 1 is higher than grade 2 ===" << std::endl;
    try
    {
        Bureaucrat b3("Charlie", 1);  // Highest grade
        Form form6("Executive Order", 1, 1);
        
        std::cout << "Bureaucrat: " << b3 << std::endl;
        std::cout << "Before signing: " << form6 << std::endl;
        b3.signForm(form6);
        std::cout << "After signing: " << form6 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Form copy constructor ===" << std::endl;
    try
    {
        Form form7("Original", 50, 100);
        Form form8(form7);
        
        std::cout << "Original: " << form7 << std::endl;
        std::cout << "Copy: " << form8 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 8: Form assignment operator ===" << std::endl;
    try
    {
        Form form9("Form A", 30, 60);
        Form form10("Form B", 40, 80);
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "Form 9: " << form9 << std::endl;
        std::cout << "Form 10: " << form10 << std::endl;
        
        form9 = form10;
        
        std::cout << "After form9 = form10:" << std::endl;
        std::cout << "Form 9: " << form9 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 9: Getters ===" << std::endl;
    try
    {
        Form form11("Getter Test", 45, 90);
        std::cout << "Name: " << form11.getName() << std::endl;
        std::cout << "Is Signed: " << (form11.isSigned() ? "yes" : "no") << std::endl;
        std::cout << "Grade to Sign: " << form11.getGradeToSign() << std::endl;
        std::cout << "Grade to Execute: " << form11.getGradeToExecute() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
