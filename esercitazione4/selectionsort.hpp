#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <vector>
#include <algorithm>

template<typename T>
void selectionsort(std::vector<T>& vec)
{
	size_t n = vec.size();

	for (size_t j = 0; j < n-1; j++) 
	{
		size_t minId = j;
		
		for (size_t i = j+1; i < n; i++)
		{
			if (vec[i] < vec[minId])
			{
				minId = i;
			}
		}
		
		std::swap(vec[j], vec[minId]);				
	}	
}

#endif
