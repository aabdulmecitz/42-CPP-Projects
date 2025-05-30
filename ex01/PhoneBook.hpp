#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>


class PhoneBook{
    public:
        Contact contact[8];
        int i;
    void add();
    void search();
    void exit();
};