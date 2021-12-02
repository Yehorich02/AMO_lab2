#include "Gauss.h"


void modify_matrix(std::pair< std::vector<std::vector<double>>, std::vector<double>> &a_b, int n)
{
	double max = 0;
	std::vector<double> vec;
	int pos = n;
	int val = 0;
	for (int i = n; i < signed(a_b.first[0].size()); i++)
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

std::vector<double> scaling(const std::pair< std::vector<std::vector<double>>, std::vector<double>> &a_b, int n)
{
	std::vector<double> vec;
	for (int i=n+1; i < signed(a_b.first[0].size()); i++)
	{
		vec.push_back(a_b.first[i][n] / a_b.first[n][n]);
	}
	return vec;
}

void transformation(std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b, std::vector<double> &vec, int n)
{
	int N = a_b.first[0].size();
	for (int i = n+1; i < N; i++)
	{
		for (int j = n; j < N; j++)
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
		for (int j = i + 1; j < signed(a_b.first[0].size()); j++)
		{
			sum += a_b.first[i][j] * result[j];
		}
		result[i] = (a_b.second[i] - sum) / a_b.first[i][i];
		sum = 0;
	}
	return result;
}

void Gausse_method(std::vector<std::vector<double>> arr, std::vector<double> vec)
{
	std::pair< std::vector<std::vector<double>>, std::vector<double>> AB(arr, vec);
	
	std::vector<double> vecRes;
	int N = arr[0].size();
	std::cout << "---- GIVEN MATRIX ----" << std::endl;
	printMatrix(AB.first);
	for (int i = 0; i < N; i++)
	{
		modify_matrix(AB ,i);
		std::cout << "---- MODIFIED MATRIX N." << i << " ----" << std::endl;
		printMatrix(AB.first);

		vecRes = scaling(AB, i);
		std::cout << "---- SCALLING COEFFICIENT VECTOR N." << i << " ----" << std::endl;
		printVector(vecRes);

		transformation(AB, vecRes, i);
		std::cout << "---- TRANFOMATED MATRIX N." << i << " ----" << std::endl;
		printMatrix(AB.first);

		vecRes = result(AB);
		std::cout << "---- MODIFIED RESULT VECTOR N." << i << " ----" << std::endl;
		printVector(vecRes);
	}
	printVectorResult(vecRes);
}