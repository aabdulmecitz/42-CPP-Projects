#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Serializer Tester ===" << std::endl << std::endl;

	// Create a Data structure
	Data data;
	data.name = "Alice";
	data.age = 25;
	data.next = NULL;

	std::cout << "Original Data:" << std::endl;
	std::cout << "  name: " << data.name << std::endl;
	std::cout << "  age: " << data.age << std::endl;
	std::cout << "  address: " << &data << std::endl << std::endl;

	// Test 1: Serialize the Data pointer
	std::cout << "Test 1: Serialize pointer" << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "  Serialized value: " << serialized << std::endl << std::endl;

	// Test 2: Deserialize and verify
	std::cout << "Test 2: Deserialize and verify" << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "  Deserialized Data:" << std::endl;
	std::cout << "    name: " << deserialized->name << std::endl;
	std::cout << "    age: " << deserialized->age << std::endl;
	std::cout << "    address: " << deserialized << std::endl << std::endl;

	// Test 3: Verify the pointers match
	std::cout << "Test 3: Verify pointer integrity" << std::endl;
	if (deserialized == &data)
	{
		std::cout << "  ✓ Pointers match - Serialization successful!" << std::endl;
	}
	else
	{
		std::cout << "  ✗ Pointers don't match - Serialization failed!" << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Modify deserialized data and verify original changes
	std::cout << "Test 4: Modify through deserialized pointer" << std::endl;
	deserialized->name = "Bob";
	deserialized->age = 30;
	std::cout << "  Modified data.name to: " << data.name << std::endl;
	std::cout << "  Modified data.age to: " << data.age << std::endl << std::endl;

	std::cout << "=== All tests completed ===" << std::endl;

	return (0);
}
