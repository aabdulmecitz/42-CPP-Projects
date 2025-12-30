#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <iterator>
# include <cmath>
# include <climits>
# include <cerrno>
# include <cstdlib>

inline std::vector<size_t> generate_jacobsthal(size_t n)
{
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    
    size_t last = 3;
    size_t prev = 1;
    
    while (last < n)
    {
        size_t next = last + 2 * prev;
        jacobsthal.push_back(next);
        prev = last;
        last = next;
    }
    return jacobsthal;
}

std::vector<int>    init_vector(int argc, char *argv[]);
void                print_vector(const std::vector<int>& vec);
void                print_datas(std::vector<int>& numbers);

template <typename Container>
struct CompareData
{
    const Container& data;
    CompareData(const Container& d) : data(d) {}

    bool operator()(size_t val_idx, size_t element_idx) const
    {
        return data[val_idx] < data[element_idx];
    }
};

template <typename Container>
std::vector<size_t> recursive_sort(const Container& data, const std::vector<size_t>& indices)
{
    if (indices.size() < 2)
        return indices;

    std::vector<size_t> main_chain_indices;
    std::vector<size_t> my_pairs(data.size(), static_cast<size_t>(-1)); 
    
    size_t straggler = static_cast<size_t>(-1);
    bool has_straggler = (indices.size() % 2 != 0);

    for (size_t i = 0; i < indices.size() - (has_straggler ? 1 : 0); i += 2)
    {
        size_t idx1 = indices[i];
        size_t idx2 = indices[i + 1];

        if (data[idx1] > data[idx2])
        {
            main_chain_indices.push_back(idx1);
            my_pairs[idx1] = idx2;
        }
        else
        {
            main_chain_indices.push_back(idx2);
            my_pairs[idx2] = idx1;
        }
    }
    
    if (has_straggler)
        straggler = indices.back();

    std::vector<size_t> sorted_main = recursive_sort(data, main_chain_indices);

    std::vector<size_t> S;
    S.reserve(indices.size());

    if (!sorted_main.empty())
    {
        size_t first_main = sorted_main[0];
        size_t first_pending = my_pairs[first_main];
        
        S.push_back(first_pending);
        S.push_back(first_main);
        
        for (size_t i = 1; i < sorted_main.size(); ++i)
            S.push_back(sorted_main[i]);
    }
    else
    {
        if (has_straggler)
            S.push_back(straggler);
        return S;
    }

    std::vector<size_t> jacob = generate_jacobsthal(sorted_main.size());
    
    size_t last_processed_idx = 0; 
    
    CompareData<Container> comp(data);

    for (size_t k = 0; k < jacob.size(); ++k)
    {
        size_t jacob_idx = jacob[k];
        
        size_t right = jacob_idx - 1;
        if (right >= sorted_main.size())
            right = sorted_main.size() - 1;
            
        size_t left = last_processed_idx + 1;
        
        if (right < left)
            continue;
        
        for (size_t i = right; i >= left; --i)
        {
            size_t main_idx = sorted_main[i];
            size_t pendant = my_pairs[main_idx];
            
            typename std::vector<size_t>::iterator it = std::upper_bound(S.begin(), S.end(), pendant, comp);
            S.insert(it, pendant);
        }
        
        last_processed_idx = right;
    }
    
    if (has_straggler)
    {
        typename std::vector<size_t>::iterator it = std::upper_bound(S.begin(), S.end(), straggler, comp);
        S.insert(it, straggler);
    }
    
    return S;
}

template <typename T>
void merge_insert_sort(T& container)
{
    if (container.size() < 2)
        return;
    
    std::vector<size_t> indices(container.size());
    for (size_t i = 0; i < indices.size(); ++i)
        indices[i] = i;
        
    std::vector<size_t> sorted_indices = recursive_sort(container, indices);
    
    T result;
    // result.reserve(container.size()); 
    // Manual loop for push_back standard compliance
    for (size_t i = 0; i < sorted_indices.size(); ++i)
    {
        result.push_back(container[sorted_indices[i]]);
    }
    
    container = result;
}

#endif