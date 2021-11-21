#include "LU_factor.h"

std::vector<std::vector<int>> aMatrix()
{
	//return { {30, -64, -96, 49, -13, -75, -12, -47,89},
	//	{-35,-26, 36, -28, -69, 78, -96, 62, -18},
	//	{39, 41, -57, -82, 9, 30, -72, 92, 4},
	//	{-8, 48, -39, -82, 95, -16, 26, 27, -89},
	//	{-71, 25, -22, -72, -90, -28, 52, 47, 81},
	//	{-37, 23, -83, 80, 79, 15, -82, -59, -81},
	//	{-98, -47, 42, -29, -33, 11, 75, 95, 48},
	//	{-71, 40, 28, 60, 68, -64, 67, 11, 78},
	//	{-26, -33, 32, 78, 75, -80, 23, 66,22 } };

	// for TMA
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

void LUMatrix(std::vector<std::vector<int>> a_matrix, std::vector<std::vector<double>> &l_matrix, std::vector<std::vector<double>> &u_matrix, int n)
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
void LU()
{
	//std::cout << S;
	std::vector<std::vector<double>> l_arr(S, std::vector<double>(S));
	std::vector<std::vector<double>> u_arr(S, std::vector<double>(S));
	std::vector<double > y_vec(S);
	std::vector<double > x_vec(S);
	//std::vector<double > b_vec = { -70, -70, 16, -53, 30, 12, 28, -71, -56};
	std::vector<double > b_vec = { -255, 186, 745, 867, 337, -587, 308, -856, -187, 334 }; // for TMA
	for (int a = 0; a < S; a++)
	{
		u_arr[a][a] = 1;
	}
	LUMatrix(aMatrix(), l_arr, u_arr, S);
	for (auto a : l_arr)
	{
		for ( auto b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (auto a : u_arr)
	{
		for (auto b : a)
			std::cout << b << " ";
		std::cout << std::endl;
	}
	y_find(l_arr, y_vec, b_vec, S);
	std::cout << std::endl;
	for (auto b : y_vec)
		std::cout << b << " ";
	std::cout << std::endl;
	x_find(u_arr, y_vec, x_vec, S);
	std::cout << std::endl;
	for (auto b : x_vec)
		std::cout << b << " ";
	std::cout << std::endl;
}