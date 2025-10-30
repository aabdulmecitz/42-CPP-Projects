#include "Serializer.hpp"
#include <iostream>

// ANSI Color codes
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"

int main(void)
{
	std::cout << BOLD << CYAN << "=== Serializer Tester ===" << RESET << std::endl << std::endl;

	// Create a Data structure
	Data data;
	data.name = "Alice";
	data.age = 25;
	data.next = NULL;

	std::cout << BOLD << YELLOW << "Original Data:" << RESET << std::endl;
	std::cout << "  " << BLUE << "name:" << RESET << " " << data.name << std::endl;
	std::cout << "  " << BLUE << "age:" << RESET << " " << data.age << std::endl;
	std::cout << "  " << BLUE << "address:" << RESET << " " << MAGENTA << &data << RESET << std::endl << std::endl;

	// Test 1: Serialize the Data pointer
	std::cout << BOLD << YELLOW << "Test 1: Serialize pointer" << RESET << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "  " << BLUE << "Serialized value:" << RESET << " " << MAGENTA << serialized << RESET << std::endl << std::endl;

	// Test 2: Deserialize and verify
	std::cout << BOLD << YELLOW << "Test 2: Deserialize and verify" << RESET << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "  " << BLUE << "Deserialized Data:" << RESET << std::endl;
	std::cout << "    " << BLUE << "name:" << RESET << " " << deserialized->name << std::endl;
	std::cout << "    " << BLUE << "age:" << RESET << " " << deserialized->age << std::endl;
	std::cout << "    " << BLUE << "address:" << RESET << " " << MAGENTA << deserialized << RESET << std::endl << std::endl;

	// Test 3: Verify the pointers match
	std::cout << BOLD << YELLOW << "Test 3: Verify pointer integrity" << RESET << std::endl;
	if (deserialized == &data)
	{
		std::cout << "  " << GREEN << BOLD << "✓ Pointers match - Serialization successful!" << RESET << std::endl;
	}
	else
	{
		std::cout << "  " << RED << BOLD << "✗ Pointers don't match - Serialization failed!" << RESET << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Modify deserialized data and verify original changes
	std::cout << BOLD << YELLOW << "Test 4: Modify through deserialized pointer" << RESET << std::endl;
	deserialized->name = "Bob";
	deserialized->age = 30;
	std::cout << "  " << BLUE << "Modified data.name to:" << RESET << " " << GREEN << data.name << RESET << std::endl;
	std::cout << "  " << BLUE << "Modified data.age to:" << RESET << " " << GREEN << data.age << RESET << std::endl << std::endl;

	std::cout << BOLD << CYAN << "=== All tests completed ===" << RESET << std::endl;

	return (0);
}
