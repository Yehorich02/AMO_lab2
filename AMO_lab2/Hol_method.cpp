#include "Hol_method.h"

std::vector<std::vector<double>> hol_matrix()
{
	std::vector<std::vector<double>>  arr = { {81, -45, 45},
												{-45, 50, -15},
												{45, -15,38} };
	return arr;
}

std::vector<double> hol_b_vector()
{
	return { 531, -460, 193 };
}

std::vector<std::vector<double>> hol_Ut_matrix(const std::vector<std::vector<double>>& arr)
{
	std::vector<std::vector<double>> Ut (arr[0].size(), std::vector<double>(arr[0].size()));
	double sum = 0;
	for (int i = 0; i < arr[0].size(); i++)
	{
		//find diagon elements
		for (int k = 0; k <= i - 1; k++)
		{
			sum += std::pow(Ut[k][i], 2);
		}
		Ut[i][i] = std::sqrt(arr[i][i] - sum);

		sum = 0;
		// find other elements
		for (int j = i + 1; j < arr[0].size(); j++)
		{
			for (int k = 0; k <= i - 1; k++)
			{
				sum += Ut[k][j] * Ut[k][i];
			}
			Ut[i][j] = (arr[i][j] - sum) / Ut[i][i];
		}
		sum = 0;
	}
	return Ut;
}

std::vector<double> hol_y_find(const std::vector<std::vector<double>>& Ut, std::vector<double> b)
{
	std::vector<double> y;
	double sum = 0;
	for (int i = 0; i < Ut[0].size(); i++)
	{
		for (int k = 0; k <= i - 1; k++)
			sum += Ut[k][i] * y[k];
		y.push_back((b[i] - sum) / Ut[i][i]);
		sum = 0;
	}
	return y;
}

std::vector<double> hol_x_find(const std::vector<std::vector<double>>& Ut, std::vector<double> y)
{
	std::vector<double> x(Ut[0].size());
	double sum = 0;
	for (int i = Ut[0].size()-1; i >= 0; i--)
	{
		for (int k = i + 1; k < Ut[0].size(); k++)
			sum += Ut[i][k] * x[k];
		x[i]=(y[i] - sum) / Ut[i][i];
		sum = 0;
	}
	return x;
}
void hol_method()
{
	std::vector<std::vector<double>> eq = hol_matrix();
	std::vector<std::vector<double>> U;
	U = hol_Ut_matrix(eq);
	std::vector<double> x = hol_x_find(U, hol_y_find(U, hol_b_vector()));
	for (auto a : U)
	{
		for (auto b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (auto b : x)
		std::cout << b << " ";
	std::cout << std::endl;
}