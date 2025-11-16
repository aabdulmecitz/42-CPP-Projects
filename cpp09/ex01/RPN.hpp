#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <stack>

bool isOperator(char c);
float calculateRPN(const std::string& expression);
std::string parseArgs(int argc, char *argv[]);


#endif