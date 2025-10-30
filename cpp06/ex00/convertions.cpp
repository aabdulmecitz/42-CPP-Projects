#include "./ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <sstream>

void	convertChar(const std::string& str, size_t& len)
{
    int c = 0;
    if (len == 1)
        c = str[0];
    else
        c = str[1];
    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << c << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	convertInt(const std::string& str)
{
    char* end = NULL;
    long num = strtol(str.c_str(), &end, 10);

    // Check for conversion errors
    if (*end != '\0')
    {
        std::cerr << "Error: Invalid integer format" << std::endl;
        return;
    }

    // Check for overflow
    if (num > INT_MAX || num < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (num >= 0 && num <= 127)
    {
        if (isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	convertFloat(const std::string& str)
{
    char* end = NULL;
    float num = strtof(str.c_str(), &end);

    if ((num == 0.0f && end == str.c_str()) || 
        (str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F'))
    {
        if (str != "nanf" && str != "+inff" && str != "-inff")
        {
            std::cerr << "Error: Invalid float format" << std::endl;
            return;
        }
    }
    std::cout << "char: ";
    if (std::isnan(num))
        std::cout << "impossible" << std::endl;
    else if (std::isinf(num))
        std::cout << "impossible" << std::endl;
    else if (num >= 0 && num <= 127)
    {
        if (isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int: ";
    if (std::isnan(num) || std::isinf(num) || num > INT_MAX || num < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << num << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	convertDouble(const std::string& str)
{
    char* end = NULL;
    double num = strtod(str.c_str(), &end);

    if (num == 0.0 && end == str.c_str())
    {
        if (str != "nan" && str != "+inf" && str != "-inf")
        {
            std::cerr << "Error: Invalid double format" << std::endl;
            return;
        }
    }
    std::cout << "char: ";
    if (std::isnan(num))
        std::cout << "impossible" << std::endl;
    else if (std::isinf(num))
        std::cout << "impossible" << std::endl;
    else if (num >= 0 && num <= 127)
    {
        if (isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int: ";
    if (std::isnan(num) || std::isinf(num) || num > INT_MAX || num < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << num << std::endl;
}

