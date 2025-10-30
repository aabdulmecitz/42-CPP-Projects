#include <iostream>
#include <string>
#include "iter.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    ::cout("=== Testing iter with int array ===");
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, cout<int>);

    ::cout("=== Testing iter with float array ===");
    float floatArr[] = {1.5f, 2.5f, 3.5f, 4.5f};
    iter(floatArr, 4, cout<float>);

    ::cout("=== Testing iter with string array ===");
    std::string strArr[] = {"Hello", "World", "Template"};
    iter(strArr, 3, cout<std::string>);

    ::cout("=== Testing iter with double array ===");
    double doubleArr[] = {1.1, 2.2, 3.3};
    iter(doubleArr, 3, cout<double>);

    return 0;
}