#include "LU_factor.h"


void LUMatrix(std::vector<std::vector<double>> a_matrix, std::vector<std::vector<double>> &l_matrix, std::vector<std::vector<double>> &u_matrix, int n)
{
	for (int val = 0; val < n; val++)
	{
		double sum = 0;
		for (int i = val; i < n; i++)
		{
			for (int k = 0; k <= val - 1; k++)
			{
				sum += u_matrix[k][val] * l_matrix[i][k];
			}
			l_matrix[i][val] = a_matrix[i][val] - sum;
			sum = 0;
		}

		for (int j = val+1; j < n; j++)
		{
			for (int k = 0; k <= val - 1; k++)
			{
				sum += u_matrix[k][j] * l_matrix[val][k];
			}
			u_matrix[val][j] = (a_matrix[val][j] - sum) / l_matrix[val][val];
			sum = 0;
		}
		
	}
}

void y_find(const std::vector<std::vector<double>>& l_matrix,
	std::vector<double>& y_vector, const std::vector<double> &b_vector, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k=0; k<=i-1; k++)
		{
			sum += l_matrix[i][k] * y_vector[k];
		}
		y_vector[i] = (b_vector[i] - sum) / l_matrix[i][i];
		sum = 0;
	}
}
void x_find(const std::vector<std::vector<double>>& u_matrix,
	const std::vector<double>& y_vector, std::vector<double>& x_vector, int n)
{
	double sum = 0; 
	for (int i = n - 1; i >= 0; i--)
	{
		for (int k = i ; k < n;k++)
		{
			sum += u_matrix[i][k] * x_vector[k];
		}
		x_vector[i] = y_vector[i] - sum;
		sum = 0;
	}
}
void LU(std::vector<std::vector<double>> arr, std::vector<double> vec)
{
	double sum = 0;
	for (int a=0; a<10000; a++)
	{
		int S = arr[0].size();
		std::vector<std::vector<double>> l_arr(S, std::vector<double>(S));
		std::vector<std::vector<double>> u_arr(S, std::vector<double>(S));
		std::vector<double > y_vec(S);
		std::vector<double > x_vec(S);

		for (int a = 0; a < S; a++)
		{
			u_arr[a][a] = 1;
		}

		auto start = std::chrono::system_clock::now();
		LUMatrix(arr, l_arr, u_arr, S);
		auto end = std::chrono::system_clock::now();
		y_find(l_arr, y_vec, vec, S);
		x_find(u_arr, y_vec, x_vec, S);
		
		sum += std::chrono::duration<float>(end - start).count();
	}
	std::cout << sum / 10000;
	//int S = arr[0].size();
	//std::vector<std::vector<double>> l_arr(S, std::vector<double>(S));
	//std::vector<std::vector<double>> u_arr(S, std::vector<double>(S));
	//std::vector<double > y_vec(S);
	//std::vector<double > x_vec(S);
	//
	//for (int a = 0; a < S; a++)
	//{
	//	u_arr[a][a] = 1;
	//}
	//
	//auto start = std::chrono::system_clock::now();
	//LUMatrix(arr, l_arr, u_arr, S);
	//y_find(l_arr, y_vec, vec, S);
	//x_find(u_arr, y_vec, x_vec, S);
	//auto end = std::chrono::system_clock::now();
	//printMatrix(arr);
	//std::cout << "---- LOWER MATRIX ----" << std::endl;
	//printMatrix(l_arr);
	//std::cout << "---- UPPER MATRIX ----" << std::endl;
	//printMatrix(u_arr);
	//printVectorResult(x_vec);
	//std::cout << "Duration = " << std::setprecision(10) << std::chrono::duration<float>(end - start).count() * 100'000'0 << std::endl;
}