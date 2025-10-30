#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

std::ostream& operator<<(std::ostream& os, const ScalarConverter& sc)
{
	(void)sc;
	os << "ScalarConverter";
	return os;
}

bool	isLiteralType(const std::string& str)
{
	if (str == "nan" || str == "nanf" ||
		str == "+inf" || str == "+inff" ||
		str == "-inf" || str == "-inff")
		return true;
	return false;
}

void	convertLiteral(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	// Check for pseudo-literals first
	if (isLiteralType(str))
	{
		convertLiteral(str);
		return;
	}

	// Single character (not digit) -> char literal
	if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
	{
		char c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		std::cout.unsetf(std::ios::fixed);
		return;
	}

	bool isFloat = false;
	bool isDouble = false;

	if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
		isFloat = true;
	else if (str.find('.') != std::string::npos)
		isDouble = true;
	if (isFloat)
		convertFloat(str);
	else if (isDouble)
		convertDouble(str);
	else
		convertInt(str);
}
