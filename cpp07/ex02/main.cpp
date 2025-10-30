#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

int main(int, char**)
{
    std::cout << CYAN << "=== Test 1: Creating and filling array ===" << RESET << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << GREEN << "Array created and filled with " << numbers.size() << " elements" << RESET << std::endl;

    std::cout << BLUE << "\n=== Test 2: Copy constructor and assignment ===" << RESET << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << GREEN << "Copy constructor and assignment successful" << RESET << std::endl;
    }

    std::cout << YELLOW << "\n=== Test 3: Verifying copy integrity ===" << RESET << std::endl;
    bool mismatch = false;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << RED << "✗ didn't save the same value!!" << RESET << std::endl;
            mismatch = true;
            break;
        }
    }
    if (!mismatch)
        std::cout << GREEN << "All values match perfectly!" << RESET << std::endl;

    std::cout << MAGENTA << "\n=== Test 4: Out of range exception (negative index) ===" << RESET << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << YELLOW << "⚠ Caught: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n=== Test 5: Out of range exception (index too large) ===" << RESET << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << YELLOW << "⚠ Caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== Test 6: String array ===" << RESET << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Template";
    std::cout << GREEN;
    for (unsigned int i = 0; i < stringArray.size(); i++)
        std::cout << stringArray[i] << " ";
    std::cout << RESET << std::endl;

    std::cout << CYAN << "\n=== Test 7: Float array ===" << RESET << std::endl;
    Array<float> floatArray(4);
    floatArray[0] = 1.5f;
    floatArray[1] = 2.5f;
    floatArray[2] = 3.5f;
    floatArray[3] = 4.5f;
    std::cout << CYAN;
    for (unsigned int i = 0; i < floatArray.size(); i++)
        std::cout << floatArray[i] << " ";
    std::cout << RESET << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;
    return 0;
}