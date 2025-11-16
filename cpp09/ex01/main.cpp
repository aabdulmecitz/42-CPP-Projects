#include "./RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::string cleanExpression = parseArgs(argc, argv);
    if (cleanExpression.empty())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        float result = calculateRPN(cleanExpression);
        std::cout << std::fixed << std::setprecision(0) << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

