#include "./BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#define RESET		"\033[0m"
#define BOLD		"\033[1m"
#define CYAN		"\033[36m"
#define MAGENTA		"\033[35m"
#define GREEN		"\033[32m"
#define RED			"\033[31m"

bool isFileOpenable(char *path)
{
    std::ifstream file(path);
    return file.good();
}

bool isValidDate(const std::string& date)
{
    // Format: YYYY-MM-DD
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
    
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}

bool isValidValue(const std::string& valueStr, float& value)
{
    std::istringstream iss(valueStr);
    if (!(iss >> value))
        return false;
    
    // Check if entire string was consumed (no extra characters)
    if (iss.peek() != EOF)
        return false;
    
    if (value < 0)
        return false;
    
    if (value > 1000)
        return false;
    
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: you need to give a file arguement" << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    
    try
    {
        btc.loadDatabase("data.csv");
    }
    catch (const BitcoinExchange::FileException& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    
    std::string line;
    std::getline(inputFile, line); // Skip header
    
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
        
        // Extract date and value
        std::string dateStr = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        
        // Trim spaces from date
        while (!dateStr.empty() && dateStr[dateStr.length() - 1] == ' ')
            dateStr.erase(dateStr.length() - 1);
        // Trim spaces from value
        while (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);
        while (!valueStr.empty() && valueStr[valueStr.length() - 1] == ' ')
            valueStr.erase(valueStr.length() - 1);
        
        // Validate date
        if (!isValidDate(dateStr))
        {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        // Validate value
        float value;
        if (!isValidValue(valueStr, value))
        {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else
                std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Get exchange rate
        try
        {
            float rate = btc.getExchangeRate(dateStr);
            float result = value * rate;
            
            std::cout << dateStr << " => " << value;
            if (value == (int)value)
                std::cout << " = ";
            else
                std::cout << " = ";
            std::cout << std::fixed << std::setprecision(1) << result << std::endl;
        }
        catch (const BitcoinExchange::BadInputException& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    inputFile.close();
    return 0;
}

