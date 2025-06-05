#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;

    phoneBook.setIndex(0);
    while (1)
    {
        std::string cmd;
        std::cout << YELLOW << "Phonebook> " << RESET;
        std::getline(std::cin, cmd);

        if (std::cin.eof())
        {
            std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
            return 0;
        }
        if (cmd == "ADD")
            phoneBook.add();
        else if (cmd == "SEARCH")
            phoneBook.search();
        else if (cmd == "EXIT")
            phoneBook.exit();
        else
            std::cout << RED << "Invalid command. Please use ADD, SEARCH, or EXIT." 
            << RESET << std::endl;

    }
}