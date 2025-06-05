#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

class PhoneBook{
    private:
        Contact contact[8];
        int i;
    public:
        void add();
        void search();
        void exit();

        int getIndex();
        void setIndex(int index);
};