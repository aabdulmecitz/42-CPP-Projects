#include "./Span.hpp"
#include <iostream>

// Color codes
#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define CYAN		"\033[36m"
#define MAGENTA		"\033[35m"
#define GREEN		"\033[32m"
#define RED			"\033[31m"

int main()
{
	std::cout << BOLD << CYAN << "\n╔══════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << CYAN << "║  " << GREEN << "SPAN CLASS TEST SUITE" << CYAN << "           ║" << RESET << std::endl;
	std::cout << BOLD << CYAN << "╚══════════════════════════════════╝" << RESET << std::endl;

	std::cout << "\n" << BOLD << MAGENTA << "Test 1: Basic (5 numbers)" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << GREEN << "Shortest: " << RESET << sp.shortestSpan() << std::endl;
	std::cout << GREEN << "Longest: " << RESET << sp.longestSpan() << std::endl;

	// Test 2: 10,000 numbers
	std::cout << "\n" << BOLD << MAGENTA << "Test 2: 10,000 numbers" << RESET << std::endl;
	Span large = Span(10000);
	srand(time(NULL));
	for (int i = 0; i < 10000; ++i)
		large.addNumber(rand() % 10000);
	std::cout << GREEN << "Shortest: " << RESET << large.shortestSpan() << std::endl;
	std::cout << GREEN << "Longest: " << RESET << large.longestSpan() << std::endl;

	// Test 3: 50,000 numbers
	std::cout << "\n" << BOLD << MAGENTA << "Test 3: 50,000 numbers" << RESET << std::endl;
	Span huge = Span(50000);
	for (int i = 0; i < 50000; ++i)
		huge.addNumber(rand() % 100000);
	std::cout << GREEN << "Shortest: " << RESET << huge.shortestSpan() << std::endl;
	std::cout << GREEN << "Longest: " << RESET << huge.longestSpan() << std::endl;

	// Test 4: Exception - Full
	std::cout << "\n" << BOLD << MAGENTA << "Test 4: Full container" << RESET << std::endl;
	Span full = Span(2);
	full.addNumber(1);
	full.addNumber(2);
	try {
		full.addNumber(3);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// Test 5: Exception - Empty
	std::cout << "\n" << BOLD << MAGENTA << "Test 5: Empty container" << RESET << std::endl;
	Span empty = Span(5);
	try {
		empty.shortestSpan();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// Test 6: Exception - Single element
	std::cout << "\n" << BOLD << MAGENTA << "Test 6: Single element" << RESET << std::endl;
	Span single = Span(5);
	single.addNumber(42);
	try {
		single.longestSpan();
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << CYAN << "╔══════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << CYAN << "║  " << GREEN << "ALL TESTS PASSED!" << CYAN << "               ║" << RESET << std::endl;
	std::cout << BOLD << CYAN << "╚══════════════════════════════════╝" << RESET << std::endl << std::endl;

	return 0;
}
