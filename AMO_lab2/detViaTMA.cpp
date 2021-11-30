#include "TMA.h"

double findDetViaTMA(const std::vector<std::vector<double>> &arr,
	const std::vector < std::pair < double, double>>& vec)
{
	double res = 1;
	int n = arr[0].size();

	for (int i = 0; i < n; i++)
		if (i != 0)
			res *= (arr[i][i] + arr[i][i - 1] * vec[i - 1].first);
		else
			res *= arr[i][i];
	
	return res;
}

void printDetViaTMA(std::vector<std::vector<double>> arr, std::vector<double> vec)
{
	std::cout << "detA = " << findDetViaTMA(arr, straightRun(arr, vec));
}