#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "helpers.hpp"

#include "timecounter.h"
#include "randfiller.h"

#include <algorithm>
#include <iostream>
#include <fstream>

// Wall-clock time measurement of calls to bubblesort, insertionsort, selectionsort and std::sort
int main()
{
	// Timecounter and randfiller instances.
	timecounter tc;
	randfiller rf;
	
	// Measure for vectors of different lengths in the set {4, 8, 16, ...,8192}
	std::vector<size_t> lengths;
	lengths.resize(12);
	for (size_t i = 2; i <=13; i++) 
	{
		lengths[i-2] = 1 << i;
	}
	
	// Allocate the vectors to store the measurements
	std::vector<double> elapsed_time_bubblesort;
	std::vector<double> elapsed_time_insertionsort;
	std::vector<double> elapsed_time_selectionsort;
	std::vector<double> elapsed_time_stdsort;
	elapsed_time_bubblesort.resize(12);
	elapsed_time_insertionsort.resize(12);
	elapsed_time_selectionsort.resize(12);
	elapsed_time_stdsort.resize(12);

	// Open file stream to store the measurement; write file header.
	std::ofstream outfile("measurements.csv");
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file." << std::endl;
		return EXIT_FAILURE;		
	}
	outfile << "Length, BubbleSort, InsertionSort, SelectioSort, StdSort" << std::endl;
	
	// Loop over the lengths to perform the measurements
	for (size_t i = 0; i < 12; i++)
	{
			// Prepare vector of random values with length = lengths[i]
			std::vector<int> vec;
			vec.resize(lengths[i]);
			rf.fill(vec, -1000, 1000);
			
			// Measure execution time of the different algorithms
			std::vector<int> vecBubbleSort = vec;
			tc.tic();
			bubblesort(vecBubbleSort);
			elapsed_time_bubblesort[i] = tc.toc();

			std::vector<int> vecInsertionSort = vec;
			tc.tic();
			insertionsort(vecInsertionSort);
			elapsed_time_insertionsort[i] = tc.toc();

			std::vector<int> vecSelectionSort = vec;
			tc.tic();
			selectionsort(vecSelectionSort);
			elapsed_time_selectionsort[i] = tc.toc();

			std::vector<int> vecStdSort = vec;
			tc.tic();
			std::sort(vecStdSort.begin(), vecStdSort.end());
			elapsed_time_stdsort[i] = tc.toc();
			
			// Write results to file
			outfile << lengths[i] << ", " << elapsed_time_bubblesort[i] << ", " << elapsed_time_insertionsort[i] << ", " << elapsed_time_selectionsort[i] << ", " << elapsed_time_stdsort[i] << std::endl;
	}

	//	Close file and return
	outfile.close();	
	return EXIT_SUCCESS;
}