#include "selectionsort.hpp"
#include "randfiller.h"
#include "helpers.hpp"

#include <cstdlib>

// Unit test for the selectionsort() function.

int main(void)
{
	// randfiller instance
	randfiller rf;
	
	// Loop over 100 vectors of random length and random min and max.
	for (size_t i = 0; i < 100; i++)
	{
		std::mt19937 gen(std::random_device{}());
		
		// Random length of current vector. Length is between 4 and 1000 elements.
		std::uniform_int_distribution<int> dist_length(4, 1000);
		int length = dist_length(gen);
		
		// Random min and max of current vector.
		// Both values can be negative, and are drawn from an uniform distribution.
		std::uniform_int_distribution<int> dist_minmax(-1000, 1000);
		int min = dist_minmax(gen);
		int max = dist_minmax(gen);
		if (min > max) 
		{
			std::swap(min, max);
		}

		// Prepare current vector of signed integers.
		std::vector<int> vi;
		vi.resize(length);
		rf.fill(vi, min, max);
    
		// Call selection sort.
		selectionsort(vi);
		
		// Test
		if (!is_sorted(vi))
		{
			return EXIT_FAILURE;
		}		
	}
	
	return EXIT_SUCCESS;
}
