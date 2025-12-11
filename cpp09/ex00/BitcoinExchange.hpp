#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <exception>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& other);
    
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& valueStr, float& value);
    void loadDatabase(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
    
    class FileException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Error: could not open file.";
        }
    };

    class BadInputException : public std::exception
    {
    private:
        std::string _message;
    public:
        BadInputException(const std::string& msg) : _message(msg) {}
        virtual ~BadInputException() throw() {}
        virtual const char* what() const throw()
        {
            return _message.c_str();
        }
    };
};

#endif