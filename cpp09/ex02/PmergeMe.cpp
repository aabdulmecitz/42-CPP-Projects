#include "PmergeMe.hpp"

std::vector<int> init_vector(int argc, char *argv[])
{
    std::vector<int> result;
    
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return result;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        bool valid = true;
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(arg[j]))
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            std::cerr << "Error" << std::endl;
            result.clear();
            return result;
        }
        errno = 0;
        char *endptr;
        long value = strtol(arg.c_str(), &endptr, 10);
        if (errno == ERANGE || value > INT_MAX || value < 0)
        {
            std::cerr << "Error" << std::endl;
            result.clear();
            return result;
        }
        result.push_back(static_cast<int>(value));
    }
    if (result.empty())
        std::cerr << "Error" << std::endl;
    return result;
}

void print_vector(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

