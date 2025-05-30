#include "PhoneBook.hpp"

void PhoneBook::add()
{
    std::string firstname, lastname, nickname, phonenum, darkestscreet;

    std::cout << "First Name> ";
    std::getline(std::cin, firstname);
    
    std::cout << "Last Name> ";
    std::getline(std::cin, lastname);

    std::cout << "Nickname> ";
    std::getline(std::cin, nickname);

    std::cout << "Phone Number> ";
    std::getline(std::cin, phonenum);

    std::cout << "Darkest Screet> ";
    std::getline(std::cin, darkestscreet);

    int index = i%8;

    if (firstname.empty() || lastname.empty() || nickname.empty() || phonenum.empty() || darkestscreet.empty())
    {
        std::cout << "Check Your Enterances" << std::endl;
        return;
    }
    this->contact[index].first_name = firstname;
    this->contact[index].last_name = lastname;
    this->contact[index].nickname = nickname;
    this->contact[index].phonenum = phonenum;
    this->contact[index].darkest_scret = darkestscreet;
    std::cout << "Contact Added Successfully!" << std::endl;
    i++;
}

void PhoneBook::exit()
{

}

void PhoneBook::search()
{
    std::string input;

    std::cout << "Search> ";
    std::getline(std::cin, input);
    for (int i = 0; i < 8; i++)
    {
        if(input == this->contact[i].first_name || 
           input == this->contact[i].last_name || 
           input == this->contact[i].nickname || 
           input == this->contact[i].phonenum || 
           input == this->contact[i].darkest_scret)
        {
            std::cout << "Found Contact: " << std::endl;
            std::cout << "First Name: " << this->contact[i].first_name << std::endl;
            std::cout << "Last Name: " << this->contact[i].last_name << std::endl;
            std::cout << "Nickname: " << this->contact[i].nickname << std::endl;
            std::cout << "Phone Number: " << this->contact[i].phonenum << std::endl;
            std::cout << "Darkest Screet: " << this->contact[i].darkest_scret << std::endl;
            return;
        }
    }
    
    
}