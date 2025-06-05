#include <iostream>
#include <string>

// Color definitions
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce();
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);