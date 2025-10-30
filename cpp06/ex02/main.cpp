#include "./Base.hpp"

int main()
{
    Base *ptr = generate();
    std::cout << std::endl;

    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}
