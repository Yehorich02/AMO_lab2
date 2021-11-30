#include "TMA.h"


bool tmaCheck(std::vector<std::vector<double>>& matrix)
{
	bool b=0, c=0, d=0;
	for (int i = 0; i < signed(matrix[0].size()); i++)
	{
		for (int j = 0; j < signed(matrix[0].size()); j++)
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
	for (const auto& a : vec)
	{
		std::cout << "delta[" << i << "] = " << a.first
			<< "  lamda[" << i << "] = " << a.second << std::endl;
		i++;
	}
}
void tmaMethod(std::vector<std::vector<double>> arr, 
	std::vector<double> vec)
{
	double sum = 0;
	for (int i = 0; i < 10000; i++) {
		auto start = std::chrono::system_clock::now();
		if (tmaCheck(arr))
		{
			auto for_reverse_run = straightRun(arr, vec);
			auto end = std::chrono::system_clock::now();
			auto result = reverseRun(for_reverse_run);
			
			sum += std::chrono::duration<float>(end - start).count();
		}
	}
	std::cout << "Duration = " << std::setprecision(10) <<sum/10000 << std::endl;
	//auto start = std::chrono::system_clock::now();
	//if (tmaCheck(arr))
	//{
	//	auto for_reverse_run = straightRun(arr, vec);
	//	auto result = reverseRun(for_reverse_run);
	//	auto end = std::chrono::system_clock::now();
	//	printVectorOfPairs(for_reverse_run);
	//	std::cout << std::endl;
	//	printTMAResult(result);
	//	std::cout << std::endl;
	//	std::cout << "Duration = " << std::setprecision(10) << std::chrono::duration<double>(end - start).count() << std::endl;
	//}
}