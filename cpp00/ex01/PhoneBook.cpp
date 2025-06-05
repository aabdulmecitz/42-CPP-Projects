#include "PhoneBook.hpp"

void PhoneBook::add()
{
    std::string firstname, lastname, nickname, phonenum, darkestscreet;

    std::cout << CYAN << "First Name> " << RESET;
    std::getline(std::cin, firstname);
    if (std::cin.eof())
    {
        std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
        std::exit(0);
    }
    std::cout << CYAN << "Last Name> " << RESET;
    std::getline(std::cin, lastname);
    if (std::cin.eof())
    {
        std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
        std::exit(0);
    }
    std::cout << CYAN << "Nickname> " << RESET;
    std::getline(std::cin, nickname);
    if (std::cin.eof())
    {
        std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
        std::exit(0);
    }
    std::cout << CYAN << "Phone Number> " << RESET;
    std::getline(std::cin, phonenum);
    if (std::cin.eof())
    {
        std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
        std::exit(0);
    }
    std::cout << CYAN << "Darkest Screet> " << RESET;
    std::getline(std::cin, darkestscreet);
    if (std::cin.eof())
    {
        std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
        std::exit(0);
    }
    int index = i%8;

    if (firstname.empty() || lastname.empty() || nickname.empty() || phonenum.empty() || darkestscreet.empty())
    {
        std::cout << RED << "Check Your Enterances" << RESET << std::endl;
        return;
    }
    this->contact[index].setFirstName(firstname);
    this->contact[index].setLastName(lastname);
    this->contact[index].setNickname(nickname);
    this->contact[index].setPhoneNum(phonenum);
    this->contact[index].setDarkestSecret(darkestscreet);
    std::cout << GREEN << "Contact Added Successfully!" << RESET << std::endl;
    i++;
}

void PhoneBook::exit()
{
    std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
    std::exit(0);
}

static std::string put_cell(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::search()
{
    std::string input;
    if (this->i == 0)
    {
        std::cout << RED << "No contacts available. Please add a contact first." << RESET << std::endl;
        return;
    }
    int index = this->i > 8 ? 8 : this->i;
    std::cout << CYAN << "Contacts: " << RESET << std::endl;
    std::cout << GREEN << "|" << std::setw(10) << "Index"
                    << "|" << std::setw(10) << "First Name"
                    << "|" << std::setw(10) << "Last Name"
                    << "|" << std::setw(10) << "Nickname" << "|" << RESET << std::endl;
    for (int i = 0; i < index; i++)
    {
            std::stringstream ss;
            ss << i;
            std::string str = ss.str();
            std::cout << "|" << std::setw(10) << put_cell(str);
            std::cout << "|" << std::setw(10) << put_cell(this->contact[i].getFirstName());
            std::cout << "|" << std::setw(10) << put_cell(this->contact[i].getLastName());
            std::cout << "|" << std::setw(10) << put_cell(this->contact[i].getNickname()) << "|" << std::endl; 
    }
    std::cout << CYAN << "Search> " << RESET;
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << RED << "Exiting PhoneBook. Goodbye!" << RESET << std::endl;
        std::exit(0);
    }
    int selectedIndex;
    std::stringstream ss(input);
    ss >> selectedIndex;
    if (input.empty() || !isdigit(input[0]) || ss.fail() || selectedIndex < 0 || selectedIndex >= index)
    {
        std::cout << RED << "Invalid index. Please enter a valid index." << RESET << std::endl;
        return;
    }
    else
    {
        std::cout << GREEN << "╔════════════════════════════════════════════╗" << RESET << std::endl;
        std::cout << GREEN << "║           Contact Information              ║" << RESET << std::endl;
        std::cout << GREEN << "╠════════════════════════════════════════════╣" << RESET << std::endl;
        std::cout << CYAN  << "║ First Name     : " << RESET << std::setw(26) << std::left << this->contact[selectedIndex].getFirstName() << GREEN << "║" << RESET << std::endl;
        std::cout << CYAN  << "║ Last Name      : " << RESET << std::setw(26) << std::left << this->contact[selectedIndex].getLastName() << GREEN << "║" << RESET << std::endl;
        std::cout << CYAN  << "║ Nickname       : " << RESET << std::setw(26) << std::left << this->contact[selectedIndex].getNickname() << GREEN << "║" << RESET << std::endl;
        std::cout << CYAN  << "║ Phone Number   : " << RESET << std::setw(26) << std::left << this->contact[selectedIndex].getPhoneNum() << GREEN << "║" << RESET << std::endl;
        std::cout << CYAN  << "║ Darkest Secret : " << RESET << std::setw(26) << std::left << this->contact[selectedIndex].getDarkestSecret() << GREEN << "║" << RESET << std::endl;
        std::cout << GREEN << "╚════════════════════════════════════════════╝" << RESET << std::endl;
    }
    
}

int PhoneBook::getIndex()
{
    return this->i % 8;
}

void PhoneBook::setIndex(int index)
{
    this->i = index;
}