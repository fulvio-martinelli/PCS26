#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <vector>

// Helper to print the elements of a vector in a row.
template<typename T>
void print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

// Helper to determine whether a vector is sorted in ascending order.
template<typename T>
bool is_sorted(const std::vector<T>& v)
{
	// An empty vector is sorted.
	if (v.size() == 0) return true;
	
	// Scan the vector and return false if any element is larger than the following element.
	for (size_t i = 0; i < v.size()-1; i++)
	{
		if (v[i] > v[i+1]) 
		{
				return false;
		}
	}
	return true;
}

#endif
