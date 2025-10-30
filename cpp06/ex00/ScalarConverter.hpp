#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <string>
# include <cctype>
# include <climits>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

class ScalarConverter
{
private:
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ScalarConverter();
    ~ScalarConverter();
public:
    static void	convert(const std::string& str);
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& animal);
bool	isLiteralType(const std::string& str);
void	convertLiteral(const std::string& str);
void	convertChar(const std::string& str, size_t& len);
void	convertInt(const std::string& str);
void	convertFloat(const std::string& str);
void	convertDouble(const std::string& str);

#endif