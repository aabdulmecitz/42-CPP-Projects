#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}


Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

//---------------------------------

long Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw SpanTooSmallException();
    
    std::vector<int> sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    
    long shortest = LONG_MAX;
    for (size_t i = 1; i < sorted_numbers.size(); ++i)
    {
        long span = (long)sorted_numbers[i] - (long)sorted_numbers[i - 1];
        if (span < shortest)
            shortest = span;
    }
    
    return shortest;
}

long Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw SpanTooSmallException();
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return (long)max - (long)min;
}
