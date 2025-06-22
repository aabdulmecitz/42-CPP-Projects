#include "Harl.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int main(int argc, char** argv)
{
    Harl harl;

    if (argc != 1) {
        std::cerr << RED << "Error: Program does not require any arguments" << RESET << std::endl;
        return 1;
    }
    (void)argv;
    std::cout << BLUE << "\n====== DEBUG Level ======" << RESET << std::endl;
    harl.complain("DEBUGGING");

    std::cout << GREEN << "\n====== INFO Level ======" << RESET << std::endl;
    harl.complain("INFO");

    std::cout << YELLOW << "\n====== WARNING Level ======" << RESET << std::endl;
    harl.complain("WARNING");

    std::cout << RED << "\n====== ERROR Level ======" << RESET << std::endl;
    harl.complain("ERROR");

    std::cout << MAGENTA << "\n====== No valid Level ======" << RESET << std::endl;
    harl.complain("ALARM");

    std::cout << std::endl;
    
    return 0;
}
