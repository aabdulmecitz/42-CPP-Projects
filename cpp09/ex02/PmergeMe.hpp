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
void merge_insert_sort(T& container)
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


#endif