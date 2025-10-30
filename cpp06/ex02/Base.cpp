#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
    std::srand(std::time(0));
    if (std::rand() % 3 == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A;
    }
    else if (std::rand() % 3 == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return new C;
    }
    return NULL;
}

void identify(Base *p)
{
    std::cout << "Pointer Casting" << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
}

void identify(Base &p)
{
    std::cout << "Reference Casting" << std::endl;
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type: A" << std::endl;
    }
    catch(std::exception &e) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type: B" << std::endl;
    }
    catch(std::exception &e) {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type: C" << std::endl;
    }
    catch(std::exception &e) {}

}
