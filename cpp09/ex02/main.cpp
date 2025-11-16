#include "./PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> numbers = init_vector(argc, argv);
    if (numbers.empty())
        return 1;
    
    print_vector(numbers);
    
    return 0;
}

