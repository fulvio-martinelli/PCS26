#include "insertionsort.hpp"
#include "helpers.hpp"

#include <cstdlib>

// Unit test for the insertionsort() function called on a string vector.

int main(void)
{
	// String vector
	std::vector<std::string> vs = {"Parigi", "Milano", "pizza", "Ferrari", "pazza", "mortadella", "aranciata", "Roma", "violino", "gatto"};

	// Call Bubblesort
	insertionsort(vs);
	
	// Test;
	return is_sorted(vs) ? EXIT_SUCCESS : EXIT_FAILURE;
}
