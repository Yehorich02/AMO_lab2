#include "Header.h"


std::vector<std::vector<double>> Matrix()
{
	std::vector<std::vector<double>> arr = { {3, 4, -9, 5},
											 {-15, -12, 50, -16},
											 {-27, -36, 73, 8},
											 {9, 12, -10, -16} };
	return arr;
}

std::vector<double> Vector()
{
	return { -14, 44, 142, -76 };
}
void modify_matrix(std::pair< std::vector<std::vector<double>>, std::vector<double>> &a_b, int n)
{
	double max = 0;
	std::vector<double> vec;
	int pos = n;
	int val = 0;
	for (int i = n; i < a_b.first[0].size(); i++)
	{
		if (std::fabs(a_b.first[i][n]) > max)
		{
			max = std::fabs(a_b.first[i][n]);
			val = pos;
		}
		pos++;
	}
	std::swap(a_b.first[n], a_b.first[val]);
	std::swap(a_b.second[n], a_b.second[val]);
}

void MatrixPrint(std::pair< std::vector<std::vector<double>>, std::vector<double>> a_b) {
	for (auto a = 0; a< a_b.first[0].size(); a++)
	{
		for (auto b = 0; b < a_b.first[0].size(); b++)
			std::cout << std::setw(6) <<std::setprecision(4) << a_b.first[a][b] << " ";
		std::cout << std::setprecision(4) << "    " << a_b.second[a] << std::endl;
	}
	std::cout << std::endl;
}

std::vector<double> scaling(const std::pair< std::vector<std::vector<double>>, std::vector<double>> &a_b, int n)
{
	std::vector<double> vec;
	for (int i=n+1; i < a_b.first[0].size(); i++)
	{
		vec.push_back(a_b.first[i][n] / a_b.first[n][n]);
	}
	return vec;
}

void transformation(std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b, std::vector<double> &vec, int n)
{
	for (int i = n+1; i < 4; i++)
	{
		for (int j = n; j <4; j++)
		{
			a_b.first[i][j] -= (vec[i-n-1] * a_b.first[n][j]);
			
		}
		a_b.second[i] -= (vec[i - n - 1] * a_b.second[n]);
	}
}

std::vector<double> result(const std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b)
{
	std::vector<double> result (a_b.first[0].size());
	double sum = 0;
	for (int i = a_b.first[0].size() - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < a_b.first[0].size(); j++)
		{
			sum += a_b.first[i][j] * result[j];
		}
		result[i] = (a_b.second[i] - sum) / a_b.first[i][i];
		sum = 0;
	}
	return result;
}
void VectorPrint(const std::vector<double>& vec)
{
	for (auto a : vec)
		std::cout << a << " ";
	std::cout << std::endl;
}
void Gausse_method()
{
	std::pair< std::vector<std::vector<double>>, std::vector<double>> AB(Matrix(), Vector());

	std::vector<double> vec;
	for (int i = 0; i < 4; i++)
	{
		modify_matrix(AB ,i);
		vec = scaling(AB, i);
		transformation(AB, vec, i);
		vec = result(AB);
	}
	MatrixPrint(AB);
	VectorPrint(vec);
}