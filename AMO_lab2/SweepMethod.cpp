#include "TMA.h"


std::vector<std::vector<double>> tmaMatrix()
{
	return  { {-49, -13, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{162, 577, 97, 0, 0, 0, 0, 0, 0, 0},
		{0, -351, -733, 44, 0, 0, 0, 0, 0, 0},
		{0, 0, 175, -399, 192, 0, 0, 0, 0, 0},
		{0, 0, 0, 128, -427, 169, 0, 0, 0, 0},
		{0, 0, 0, 0, 75, 195, 87, 0, 0, 0},
		{0, 0, 0, 0, 0, 22, 98, 7, 0, 0},
		{0, 0, 0, 0, 0, 0, -51, -949, 139, 0},
		{0, 0, 0, 0, 0, 0, 0, -5, 42, 18},
		{0, 0, 0, 0, 0, 0, 0, 0, 460, 659} };
}

std::vector<double> tmaRVector()
{
	return { -255, 186, 745, 867, 337, -587, 308, -856, -187, 334 };
}

bool tmaCheck(std::vector<std::vector<double>>& matrix)
{
	bool b=0, c=0, d=0;
	for (int i = 0; i < matrix[0].size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (std::fabs(i - j) > 1 && matrix[i][j] != 0)
				return 0;
			else if(std::fabs(i-j)<= 1 && (c == 0 || b == 0 || d == 0))
			{ 
				if (b == 0 && i != 0 && matrix[i][i - 1] != 0)
					b = 1;
				if ( c == 0 && matrix[i][i] != 0)
					c = 1;
				if (d == 0 && i != (matrix[0].size() - 1) && matrix[i][i + 1] != 0)
					d = 1;
			}
		}
	}
	return 1;
}

std::vector<std::pair<double, double>> straightRun(const std::vector<std::vector<double>>& arr,
	const std::vector<double>& r)
{
	std::vector<std::pair<double, double>> res;
	double lamda = 0, delta = 0;
	int n = arr[0].size();
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			delta = (-1 * arr[i][i + 1]) / arr[i][i];
			lamda = r[i] / arr[i][i];
		}
		else if (i == n - 1)
		{
			delta = 0;
			lamda = (r[n - 1] - arr[i][i - 1] * res[i - 1].second)
				/ (arr[i][i] + arr[i][i - 1] * res[i - 1].first);
		}
		else
		{
			delta = (-1 * arr[i][i + 1]) /
				(arr[i][i] + arr[i][i - 1] * res[i - 1].first);
			lamda = (r[i] - arr[i][i - 1] * res[i - 1].second) /
				(arr[i][i] + arr[i][i-1] * res[i - 1].first);
		}

		res.push_back(std::make_pair(delta, lamda));
	}
	return res;
}

std::vector<double> reverseRun(const std::vector<std::pair<double, double>>& vec)
{
	int n = vec.size();
	std::vector<double> res(n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (i != n - 1)
			res[i] = vec[i].second + vec[i].first * res[i + 1];
		else
			res[i] = vec[i].second;
	}
	return res;
}

void printTMAResult(const std::vector<double>& res)
{
	for (auto a : res)
		std::cout << a << " "; 
	std::cout << std::endl;
}

void printVectorOfPairs(const std::vector<std::pair<double, double>>& vec)
{
	int i = 0;
	for (auto a : vec)
	{
		std::cout << "delta[" << i << "] = " << a.first
			<< "  lamda[" << i << "] = " << a.second << std::endl;
		i++;
	}
}
void tmaMethod()
{
	std::vector<std::vector<double>> arr = tmaMatrix();
	std::vector<double> vec = tmaRVector();
	if (tmaCheck(arr))
	{
		auto for_reverse_run = straightRun(arr, vec);
		auto result = reverseRun(for_reverse_run);
		printVectorOfPairs(for_reverse_run);
		std::cout << std::endl;
		printTMAResult(result);
	}
}