#include "./BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	BitcoinExchange btc;
	
	try
	{
		btc.loadDatabase("data.csv");
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	std::string line;
	std::getline(inputFile, line); // Skip header if present, or check if it matches "date | value"

	// The subject example has a header "date | value". 
	// If the first line parses as date, we should probably process it unless use knows it's header.
	// But standard practice in subjects is specific header. Let's assume the first line is header.
	
	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string dateStr = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);
		
		// Manual trimming since we didn't expose trim as static or public helper, 
		// but wait, I can make it public or just copy logic. 
		// Cleaner to rely on valid format check.
		// Let's just do a quick manual trim here as in previous code, it's safe.
		
		while (!dateStr.empty() && std::isspace(dateStr[dateStr.length() - 1]))
			dateStr.erase(dateStr.length() - 1);
		while (!dateStr.empty() && std::isspace(dateStr[0]))
			dateStr.erase(0, 1);
			
		while (!valueStr.empty() && std::isspace(valueStr[0]))
			valueStr.erase(0, 1);
		while (!valueStr.empty() && std::isspace(valueStr[valueStr.length() - 1]))
			valueStr.erase(valueStr.length() - 1);
		
		if (!btc.isValidDate(dateStr))
		{
			std::cout << "Error: bad input => " << dateStr << std::endl;
			continue;
		}
		
		float value;
		if (!btc.isValidValue(valueStr, value))
		{
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		try
		{
			float rate = btc.getExchangeRate(dateStr);
			float result = value * rate;
			
			std::cout << dateStr << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	inputFile.close();
	return 0;
}

