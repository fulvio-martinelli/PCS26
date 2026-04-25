#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <vector>
#include <algorithm>

template<typename T>
void bubblesort(std::vector<T>& vec)
{
	size_t n = vec.size();

	for (size_t j = 0; j < n-1; j++) 
	{
		for (size_t i = 0; i < n-1-j; i++) 
		{
			if (vec[i] > vec[i+1]) 
			{
				std::swap(vec[i], vec[i+1]);
			}
		}	
	}	
}

#endif
