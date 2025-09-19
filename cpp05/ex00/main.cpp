#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "=== Valid bureaucrats ===" << std::endl;
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        Bureaucrat b3("Charlie", 75);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;

        std::cout << "\n=== Increment / Decrement Tests ===" << std::endl;
        b3.incrementGrade(); // 75 -> 74
        std::cout << "After increment: " << b3 << std::endl;

        b3.decrementGrade(); // 74 -> 75
        std::cout << "After decrement: " << b3 << std::endl;

        std::cout << "\n=== Exception Tests ===" << std::endl;
        std::cout << "Trying to create bureaucrat with grade 0..." << std::endl;
        Bureaucrat invalid1("InvalidHigh", 0); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to create bureaucrat with grade 151..." << std::endl;
        Bureaucrat invalid2("InvalidLow", 151); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to increment grade of bureaucrat with grade 1..." << std::endl;
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to decrement grade of bureaucrat with grade 150..." << std::endl;
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
