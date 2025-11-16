#include "RPN.hpp"

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

float calculateRPN(const std::string& expression)
{
    std::stack<float> st;
    
    for (size_t i = 0; i < expression.length(); ++i)
    {
        char c = expression[i];
        
        if (c == '(' || c == ')')
            throw std::runtime_error("Error");
        if (!std::isdigit(c) && !isOperator(c))
            throw std::runtime_error("Error");
        if (std::isdigit(c))
            st.push(float(c - '0')); // Convert char digit to float
        else if (isOperator(c))
        {
            if (st.size() < 2)
                throw std::runtime_error("Error");
            float b = st.top(); st.pop();
            float a = st.top(); st.pop();
            float result;

            if (c == '+')
                result = a + b;
            else if (c == '-')
                result = a - b;
            else if (c == '*')
                result = a * b;
            else if (c == '/')
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                result = a / b;
            }
            st.push(result);
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("Error");
    return st.top();
}

std::string parseArgs(int argc, char *argv[])
{
    std::string result = "";
    
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.length(); ++j)
        {
            char c = arg[j];
            if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
                continue;
            result += c;
        }
    }
    return result;
}

