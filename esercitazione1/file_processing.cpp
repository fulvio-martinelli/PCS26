#include <iostream>
#include <fstream>
#include <cstdlib> // For exit status macros
#include <string>

int main(int argc, const char* argv[])
{
	// Validate user input.
	if (argc != 2) {
		std::cerr << "Incorrect number of command-line arguments: the program accepts one argument." << std::endl;
		return EXIT_FAILURE;
	}
	
	// Open file streeam
	std::ifstream input(argv[1]);
	if (input.is_open()) 
	{
		// Temporary variables.
		std::string city;
		double T1, T2, T3, T4;
		
		// Read from input stream as long as data is available.
		while (input >> city >> T1 >> T2 >> T3 >> T4) 
		{			
			// Display name and average.
			std::cout << city << " " << (T1+T2+T3+T4)/4 << std::endl;
		}
	}
	else
	{
		std::cerr << "Failed to open file." << std::endl;
		return EXIT_FAILURE;
	}
	
	// Close file stream and return.
	input.close();
	return EXIT_SUCCESS;
}
