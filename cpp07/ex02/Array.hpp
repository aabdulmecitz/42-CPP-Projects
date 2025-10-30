#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

# define MAX_VAL 750

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

template <class T>
class Array
{
private:
    T*              _arr;
    unsigned int    _size;
public:
    Array() : _arr(new T[0]), _size(0) {}
    Array(unsigned int n) : _arr(new T[n]), _size(n) {}
    Array(const Array &other) : _arr(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
    ~Array()
    {
        if (this->_arr != NULL)
            delete[] this->_arr;
    }
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] this->_arr;
            _size = other._size;
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                this->_arr[i] = other._arr[i];
        }
        return (*this);
    }

    T operator[](unsigned int idx) const
    {
        if (idx >= _size)
            throw (Array::InvalidIndexException ());
        return (this->_arr[idx]);
    }
    T &operator[](unsigned int idx)
    {
        if (idx >= _size)
            throw (Array::InvalidIndexException ());
        return (this->_arr[idx]);
    }
    
    unsigned int size() const { return (this->_size); }

    class InvalidIndexException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Error: Invalid index");
        }
    };
};

#endif