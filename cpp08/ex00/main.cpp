#include "./easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main( void ) {
    
    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "Testing with vector:" << std::endl;
    
    try {
        std::vector<int>::const_iterator it = easyfind(vec, 3);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const ElementNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(vec, 10);
    } catch (const ElementNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    // Test with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    std::cout << "\nTesting with list:" << std::endl;
    
    try {
        std::list<int>::const_iterator it = easyfind(lst, 20);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const ElementNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
