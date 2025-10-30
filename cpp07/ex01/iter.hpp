#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename U>
void iter(T arr, const int len, U f)
{
    for(int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void cout(T const &value) {
    std::cout << value << std::endl;
}

#endif