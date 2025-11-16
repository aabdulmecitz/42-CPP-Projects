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


#endif