#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char **argv)
{
    
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; j < (int)strlen(argv[i]); j++)
            std::cout << (char)toupper(argv[i][j]);
        std::cout << " ";
    }
    std::cout << "\n";
    return 0;
} 