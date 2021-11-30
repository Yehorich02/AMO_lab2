#include "Hol_method.h"

std::vector<std::vector<double>> Cholesky_Ut_matrix(const std::vector<std::vector<double>>& arr)
{
	std::vector<std::vector<double>> Ut (arr[0].size(), std::vector<double>(arr[0].size()));
	double sum = 0;
	double sumDiagonEl = 0;
	for (int i = 0; i < signed(arr[0].size()); i++)
	{
		//find diagon elements
		//for (int k = 0; k <= i - 1; k++)
		//{
		//	sum += std::pow(Ut[k][i], 2);
		//}
		sumDiagonEl += std::pow(Ut[i][i], 2);

		Ut[i][i] = std::sqrt(arr[i][i] - sumDiagonEl);
	//	std::cout << "Ut[" << i << "][" << i << "] = " << Ut[i][i] << std::endl;

		// find other elements
		for (int j = i + 1; j < signed(arr[0].size()); j++)
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

std::vector<double> Cholesky_y_find(const std::vector<std::vector<double>>& Ut, std::vector<double> b)
{
	std::vector<double> y;
	double sum = 0;
	for (int i = 0; i < signed(Ut[0].size()); i++)
	{
		for (int k = 0; k <= i - 1; k++)
			sum += Ut[k][i] * y[k];
		y.push_back((b[i] - sum) / Ut[i][i]);
		sum = 0;
	}
	return y;
}

std::vector<double> Cholesky_x_find(const std::vector<std::vector<double>>& Ut, std::vector<double> y)
{
	std::vector<double> x(Ut[0].size());
	double sum = 0;
	for (int i = Ut[0].size()-1; i >= 0; i--)
	{
		for (int k = i + 1; k < signed(Ut[0].size()); k++)
			sum += Ut[i][k] * x[k];
		x[i]=(y[i] - sum) / Ut[i][i];
		sum = 0;
	}
	return x;
}
void Cholesky_factorization(std::vector<std::vector<double>> arr, std::vector<double> vec)
{
	double sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		std::vector<std::vector<double>> U;
		auto start = std::chrono::system_clock::now();
		U = Cholesky_Ut_matrix(arr);
		auto end = std::chrono::system_clock::now();
		std::vector<double> x = Cholesky_x_find(U, Cholesky_y_find(U, vec));
		
		sum += std::chrono::duration<float>(end - start).count();
	}
	std::cout << sum / 10000;
	//std::vector<std::vector<double>> U;
	//U = Cholesky_Ut_matrix(arr);
	//std::vector<double> x = Cholesky_x_find(U, Cholesky_y_find(U, vec));
}