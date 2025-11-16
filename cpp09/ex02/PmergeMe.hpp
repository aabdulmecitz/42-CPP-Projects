#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <stack>
# include <sstream>
# include <vector>
# include <cctype>
# include <cerrno>
# include <climits>
# include <cstdlib>

std::vector<int>    init_vector(int argc, char *argv[]);
void                print_vector(const std::vector<int>& vec);


#endif