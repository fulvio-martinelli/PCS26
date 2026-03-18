#include <iostream>

int main(int argc, const char* argv[])
{
	// Note: argv[0] contains the program name, not a parameter provided by the user.
	
	// Display number of command-line parameters provided by the user, i.e. argc-1
	std::cout << "Number of parameters provided by the user: " << argc-1 << std::endl;
	
	// Display individual parameter values. (Start the loop from 1.)
	for (int i=1; i<argc; i++) 
	{
		std::cout << "Parameter " << i << " has value = " << argv[i] << std::endl;
	}
	
	return 0;
}
