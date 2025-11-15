#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <algorithm>
# include <vector>
# include <exception>
# include <climits>

class Span
{
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
public:
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);
    void addNumber(int number);
    long longestSpan() const;
    long shortestSpan() const;

    class SpanFullException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Error: Span is already full.";
        }
    };

    class SpanTooSmallException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Error: Cannot compute span - not enough numbers (need at least 2).";
        }
    };

    class ElementNotFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Error: Element not found in the container.";
        }
    };

};

template <typename T>
typename T::const_iterator easyfind(T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
    {
        throw Span::ElementNotFoundException();
    }

    return it;
    
}


#endif