#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;

    phoneBook.i = 0;
    while (1)
    {
        std::string cmd;
        std::cout << "Phonebook> ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
            phoneBook.add();
        else if (cmd == "SEARCH")
            phoneBook.search();
        else if (cmd == "EXIT")
            phoneBook.exit();
        if (std::cin.eof())
        {
            std::cout << "\nExiting PhoneBook." << std::endl;
            break;
        }
    }
}