#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <algorithm>

class ElementNotFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Error: Element not found in the container.";
    }
};

template <typename T>
typename T::const_iterator easyfind(T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
    {
        throw ElementNotFoundException();
    }

    return it;
    
}


#endif