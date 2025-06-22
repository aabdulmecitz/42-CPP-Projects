#include "Harl.hpp"

int main(int argc, char** argv)
{
    Harl harl;

    if (argc != 2) {
        std::cerr << RED << "Error: Program requires exactly one argument" << RESET << std::endl;
        return 1;
    }
    if (argv[1] == std::string("DEBUG") || 
        argv[1] == std::string("INFO") || 
        argv[1] == std::string("WARNING") || 
        argv[1] == std::string("ERROR")) {
        harl.complain(argv[1]);
    } else {
        std::cout << MAGENTA << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
    }
    return 0;
}
