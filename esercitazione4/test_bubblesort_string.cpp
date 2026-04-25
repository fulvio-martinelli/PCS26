#include "bubblesort.hpp"
#include "helpers.hpp"

#include <cstdlib>

// Unit test for the bubblesort() function called on a string vector.

int main(void)
{
	// String vector
	std::vector<std::string> vs = {"Parigi", "Milano", "pizza", "Ferrari", "pazza", "mortadella", "aranciata", "Roma", "violino", "gatto"};

	// Call Bubblesort
	bubblesort(vs);
	
	// Test;
	return is_sorted(vs) ? EXIT_SUCCESS : EXIT_FAILURE;
}
