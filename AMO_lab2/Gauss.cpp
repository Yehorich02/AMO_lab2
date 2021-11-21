#include "Header.h"


std::vector<std::vector<double>> Matrix()
{
	//std::vector<std::vector<double>> matrix;
	//matrix = { {30, -64, -96, 49, -13, -75, -12, -47,89},
	//	{-35,-26, 36, -28, -69, 78, -96, 62, -18},
	//	{39, 41, -57, -82, 9, 30, -72, 92, 4},
	//	{-8, 48, -39, -82, 95, -16, 26, 27, -89},
	//	{-71, 25, -22, -72, -90, -28, 52, 47, 81},
	//	{-37, 23, -83, 80, 79, 15, -82, -59, -81},
	//	{-98, -47, 42, -29, -33, 11, 75, 95, 48},
	//	{-71, 40, 28, 60, 68, -64, 67, 11, 78},
	//	{-26, -33, 32, 78, 75, -80, 23, 66,22 } };
	//return matrix;

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

std::vector<double> Vector()
{
	//return { -70, -70, 16, -53, 30, 12, 28, -71, -56 };
	return { -36, 7, -30, 16, 48, -3, 22, 25, 46, 19 };
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
			std::cout << a_b.first[a][b] << " ";
		std::cout << "    " << a_b.second[a] << std::endl;
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
	for (int i = 0; i < N; i++)
	{
		modify_matrix(AB ,i);
		vec = scaling(AB, i);
		transformation(AB, vec, i);
		vec = result(AB);
	}
	MatrixPrint(AB);
	VectorPrint(vec);
}