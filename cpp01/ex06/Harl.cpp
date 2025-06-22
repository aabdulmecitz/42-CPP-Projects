#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::_debug(void) {
    std::cout << "┌─────────────[ DEBUG ]─────────────┐" << std::endl;
    std::cout << "│ I love having extra bacon for my  │" << std::endl;
    std::cout << "│ 7XL-double-cheese-triple-pickle-  │" << std::endl;
    std::cout << "│ special-ketchup burger. I really  │" << std::endl;
    std::cout << "│ do!                               │" << std::endl;
    std::cout << "└───────────────────────────────────┘" << std::endl;
}

void Harl::_info(void) {
    std::cout << "┌─────────────[ INFO ]──────────────┐" << std::endl;
    std::cout << "│ I cannot believe adding extra     │" << std::endl;
    std::cout << "│ bacon costs more money. You don’t │" << std::endl;
    std::cout << "│ put enough! If you did I would    │" << std::endl;
    std::cout << "│ not have to ask for it!           │" << std::endl;
    std::cout << "└───────────────────────────────────┘" << std::endl;
}

void Harl::_warning(void) {
    std::cout << "┌───────────[ WARNING ]─────────────┐" << std::endl;
    std::cout << "│ I think I deserve to have some    │" << std::endl;
    std::cout << "│ extra bacon for free. I’ve been   │" << std::endl;
    std::cout << "│ coming here for years and you just│" << std::endl;
    std::cout << "│ started working here last month.  │" << std::endl;
    std::cout << "└───────────────────────────────────┘" << std::endl;
}

void Harl::_error(void) {
    std::cout << "┌────────────[ ERROR ]──────────────┐" << std::endl;
    std::cout << "│ This is unacceptable! I want to   │" << std::endl;
    std::cout << "│ speak to the manager now.         │" << std::endl;
    std::cout << "└───────────────────────────────────┘" << std::endl;
}

void unknown(void) {
    std::cout << "┌────────────[ UNKNOWN ]────────────┐" << std::endl;
    std::cout << "│ No valid level provided!          │" << std::endl;
    std::cout << "└───────────────────────────────────┘" << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4)
    {
        if (level == levels[i])
            break;
        i++;
    }
    
    switch (i)
    {
        case 0:
            Harl::_debug();
            Harl::_info();
            Harl::_warning();
            Harl::_error();
            break;
        case 1:
            Harl::_info();
            Harl::_warning();
            Harl::_error();
            break;
        case 2:
            Harl::_warning();
            Harl::_error();
            break;
        case 3:
            Harl::_error();
            break;
        default:
            unknown();
            break;
    }
}