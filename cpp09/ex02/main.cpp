#include "./PmergeMe.hpp"
#include <ctime>
#include <iomanip>

// Color codes for terminal output
#define COLOR_RESET     "\033[0m"
#define COLOR_BOLD      "\033[1m"
#define COLOR_CYAN      "\033[36m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_BLUE      "\033[34m"

void print_datas(std::vector<int>& numbers)
{
    if (numbers.empty())
        return;
    const size_t MAX_DISPLAY = 10;
    
    std::cout << COLOR_CYAN << COLOR_BOLD << "Before: " << COLOR_RESET;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (i > 0)
            std::cout << " ";
        if (i < MAX_DISPLAY)
            std::cout << COLOR_YELLOW << numbers[i] << COLOR_RESET;
        else if (i == MAX_DISPLAY)
        {
            std::cout << COLOR_MAGENTA << "[...]" << COLOR_RESET;
            break;
        }
    }
    std::cout << std::endl;
    
    clock_t start_vector = clock();
    std::vector<int> sorted_vector = numbers;
    merge_insert_sort(sorted_vector);
    clock_t end_vector = clock();
    
    std::cout << COLOR_GREEN << COLOR_BOLD << "After: " << COLOR_RESET;
    for (size_t i = 0; i < sorted_vector.size(); i++)
    {
        if (i > 0)
            std::cout << " ";
        if (i < MAX_DISPLAY)
            std::cout << COLOR_GREEN << sorted_vector[i] << COLOR_RESET;
        else if (i == MAX_DISPLAY)
        {
            std::cout << COLOR_MAGENTA << "[...]" << COLOR_RESET;
            break;
        }
    }
    std::cout << std::endl;

    double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << COLOR_BLUE << "Time to process a range of " << sorted_vector.size() 
              << " elements with " << COLOR_BOLD << "std::vector" << COLOR_RESET << COLOR_BLUE 
              << " : " << COLOR_YELLOW << time_vector << COLOR_BLUE << " us" << COLOR_RESET << std::endl;
        clock_t start_deque = clock();
    std::deque<int> sorted_deque(numbers.begin(), numbers.end());
    merge_insert_sort(sorted_deque);
    clock_t end_deque = clock();

    double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;
    std::cout << COLOR_BLUE << "Time to process a range of " << sorted_deque.size() 
              << " elements with " << COLOR_BOLD << "std::deque" << COLOR_RESET << COLOR_BLUE 
              << " : " << COLOR_YELLOW << time_deque << COLOR_BLUE << " us" << COLOR_RESET << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> numbers = init_vector(argc, argv);
    if (numbers.empty())
        return 1;
    
    print_datas(numbers);
    
    return 0;
}

