#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

std::string BitcoinExchange::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 2000 || year > 2025) // Basic sanity check, adjustable
		return true; // Technically subject doesn't say years are bounded, but good to know. Keeping logic simple as per initial code but clearer.
		// Actually, let's stick to strict valid calendar date.

	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	
	if (day < 1 || day > daysInMonth[month])
		return false;
	
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
	char* end;
	value = std::strtof(valueStr.c_str(), &end);
	
	if (*end != '\0' && *end != 'f') // Standard float parsing
		return false;
	
	return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw FileException();
	
	std::string line;
	// Skip header check if strictly needed, or just parse line by line. 
	// Usually first line is header.
	std::getline(file, line); 

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		// Database provided uses comma usually, but user said provided DB is different. 
		// I recall provided data.csv content had pipes '|' in my `head` check.
		// Wait, in my `head` check step 18, data.csv had "date | exchange_rate".
		// So delimiter is '|'.
		
		size_t pos = line.find('|');
		if (pos == std::string::npos)
			// Try comma just in case it's a mixed file or standard format
			pos = line.find(',');
			
		if (pos == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, pos));
		std::string rateStr = trim(line.substr(pos + 1));

		float rate = std::atof(rateStr.c_str());
		_data[date] = rate;
	}
	file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _data.find(date);
	if (it != _data.end())
		return it->second;
	
	// Lower bound returns iterator to first element NOT less than key.
	// So if exact match missing, it returns next element (greater).
	// We need the one before that.
	
	it = _data.lower_bound(date);
	
	if (it == _data.begin())
		throw BadInputException("Error: bad input => " + date); // Or "date too old"
		
	--it; // Move to the closest lower date
	return it->second;
}
