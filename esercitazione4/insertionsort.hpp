#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <vector>
#include <algorithm>

template<typename T>
void insertionsort(std::vector<T>& vec)
{
	size_t n = vec.size();

	for (size_t j = 1; j < n; j++) 
	{
		size_t i = j;
		while ((i > 0) && (vec[i-1] > vec[i])) 
		{
			std::swap(vec[i], vec[i-1]);
			i--;	
		}	
	}	
}

#endif
