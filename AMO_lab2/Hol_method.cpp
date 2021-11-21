#include "Hol_method.h"

std::vector<std::vector<double>> hol_matrix()
{
	std::vector<std::vector<double>> matrix;
	matrix = { {41, 21, 12, 24, -18, -19, -27, -4, 10, -14},
		{21, 47, 19, -1, -9, -25, -14, -3, -2, -1},
		{12, 19, 24, 6, 13, -15, -14, 4, -11, 6},
		{24, -1, 6, 36, -6, -19, -29, -6, 25, 4},
		{-18, -9, 13, -6, 41, -3, -4, 24, -25, 7},
		{-19, -25, -15, -19, -3, 49, 30, -3, -12, 1},
		{-27, -14, -14, -29, -4, 30, 50, -3, -17, 16},
		{-4, -3, 4, -6, 24, -3, -3, 33, -22, -5},
		{10, -2, -11, 25, -25, -12, -17, -22, 43, 5},
		{-14, -1, 6, 4, 7, 1, 16, -5, 5, 44} };
	return matrix;
}

std::vector<double> hol_b_vector()
{
	return {-36, 7, -30, 16, 48, -3, 22, 25, 46, 19};
}

std::vector<std::vector<double>> hol_Ut_matrix(const std::vector<std::vector<double>>& arr)
{
	std::vector<std::vector<double>> Ut (arr[0].size(), std::vector<double>(arr[0].size()));
	double sum = 0;
	for (int i = 0; i < arr[0].size(); i++)
	{
		sum = 0;
		//find diagon elements
		for (int k = 0; k <= i - 1; k++)
		{
			sum += std::pow(Ut[k][i], 2);
		}
		Ut[i][i] = std::sqrt(arr[i][i] - sum);
		std::cout << "Ut[" << i << "][" << i << "] = " << Ut[i][i] << std::endl;

		// find other elements
		for (int j = i + 1; j < arr[0].size(); j++)
		{
			sum = 0;
			for (int k = 0; k <= i - 1; k++)
			{
				sum += Ut[k][j] * Ut[k][i];
			}
			Ut[i][j] = (arr[i][j] - sum) / Ut[i][i];
		}
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