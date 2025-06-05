#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << YELLOW << "Memory addresses:" << RESET << std::endl;
    std::cout << CYAN << "Original string: " << RESET << &str << std::endl;
    std::cout << CYAN << "Pointer address: " << RESET << stringPTR << std::endl;
    std::cout << CYAN << "Reference address: " << RESET << &stringREF << std::endl;

    std::cout << std::endl;
    
    std::cout << YELLOW << "Values:" << RESET << std::endl;
    std::cout << MAGENTA << "Original string: " << RESET << str << std::endl;
    std::cout << MAGENTA << "Pointer value: " << RESET << *stringPTR << std::endl;
    std::cout << MAGENTA << "Reference value: " << RESET << stringREF << std::endl;

    return 0;
}