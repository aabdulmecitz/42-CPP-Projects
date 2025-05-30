#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook{
    public:
        Contact contact[8];
        int i;
    void add();
    void search();
    void exit();
};