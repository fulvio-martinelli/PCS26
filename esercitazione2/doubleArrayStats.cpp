#include <iostream>
#include <cmath>

int main(void)
{
	const size_t N = 10;
	double array[N] = { 0.2, 0.4, 7.5, 4.3, 3.23, 54.2, 3.3, -6.21, -4.4, 0.01 };

	// Min and max
	double min = array[0];
	double max = array[0];
	for (size_t i = 1; i < N; i++)  // Loop can start from 1 in this case
	{
		min = array[i] < min ? array[i] : min;
		max = array[i] > max ? array[i] : max;
	}

	// Display min and max
	std::cout << "Min = " << min << std::endl;
	std::cout << "Max = " << max << std::endl;

	// Mean and std
	double mu = 0; // mean
	double sigma = 0; // std
	for (size_t i = 0; i < N; i++)
	{
		mu += array[i] / N;
	}
	for (size_t i = 0; i < N; i++)
	{
		sigma += (array[i] - mu) * (array[i] - mu) / N;
	}
	sigma = std::sqrt(sigma);

	// Display mean and std
	std::cout << "Mean = " << mu << std::endl;
	std::cout << "Std = " << sigma << std::endl;
}
