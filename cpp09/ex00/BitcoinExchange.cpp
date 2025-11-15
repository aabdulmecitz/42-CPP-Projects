#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    // Format YYYY-MM-DD
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

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
    std::istringstream iss(valueStr);
    if (!(iss >> value))
        return false;
    if (iss.peek() != EOF)
        return false;
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileException();
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t pos = line.find('|');
        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);

        while (!date.empty() && date[date.length() - 1] == ' ')
            date.erase(date.length() - 1);
        while (!rateStr.empty() && rateStr[0] == ' ')
            rateStr.erase(0, 1);
        while (!rateStr.empty() && rateStr[rateStr.length() - 1] == ' ')
            rateStr.erase(rateStr.length() - 1);
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
    it = _data.lower_bound(date);    
    if (it == _data.begin())
        throw BitcoinExchange::BadInputException("Error: date not found in database.");
    --it;
    return it->second;
}
