#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <stack>
# include <sstream>
# include <vector>
# include <deque>
# include <cctype>
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <algorithm>
# include <ctime>

std::vector<int>    init_vector(int argc, char *argv[]);
void                print_vector(const std::vector<int>& vec);
void                print_datas(std::vector<int>& numbers);

template <typename T>
void insert_sort(T& container)
{
    int n = container.size();
    for (int i = 0; i < n; i++)
    {
        int num = container[i];
        int j = i-1;
        while (j >= 0 && container[j] > num)
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = num;
    }
}

template <typename T>
void merge_insert_sort(T& container)
{
    const size_t THRESHOLD = 5;
    if (container.size() <= THRESHOLD)
    {
        insert_sort(container);
        return;
    }

    size_t mid = container.size() / 2;
    T left(container.begin(), container.begin() + mid);
    T right(container.begin() + mid, container.end());

    merge_insert_sort(left);
    merge_insert_sort(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }
    while (i < left.size())
        container[k++] = left[i++];
    while (j < right.size())
        container[k++] = right[j++];
    
}

#endif