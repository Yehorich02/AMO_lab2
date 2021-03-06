#include "Matrix.h"

std::vector<std::vector<double>> firstMatrix()
{
	return { {30, -64, -96, 49, -13, -75, -12, -47,89},
		{-35,-26, 36, -28, -69, 78, -96, 62, -18},
		{39, 41, -57, -82, 9, 30, -72, 92, 4},
		{-8, 48, -39, -82, 95, -16, 26, 27, -89},
		{-71, 25, -22, -72, -90, -28, 52, 47, 81},
		{-37, 23, -83, 80, 79, 15, -82, -59, -81},
		{-98, -47, 42, -29, -33, 11, 75, 95, 48},
		{-71, 40, 28, 60, 68, -64, 67, 11, 78},
		{-26, -33, 32, 78, 75, -80, 23, 66,22 } };
}

std::vector<double> firstVector()
{
	return { -70, -70, 16, -53, 30, 12, 28, -71, -56 };
}

std::vector<std::vector<double>> secondMatrix()
{
	return { {41, 21, 12, 24, -18, -19, -27, -4, 10, -14},
		{21, 47, 19, -1, -9, -25, -14, -3, -2, -1},
		{12, 19, 24, 6, 13, -15, -14, 4, -11, 6},
		{24, -1, 6, 36, -6, -19, -29, -6, 25, 4},
		{-18, -9, 13, -6, 41, -3, -4, 24, -25, 7},
		{-19, -25, -15, -19, -3, 49, 30, -3, -12, 1},
		{-27, -14, -14, -29, -4, 30, 50, -3, -17, 16},
		{-4, -3, 4, -6, 24, -3, -3, 33, -22, -5},
		{10, -2, -11, 25, -25, -12, -17, -22, 43, 5},
		{-14, -1, 6, 4, 7, 1, 16, -5, 5, 44} };
}

std::vector<double> secondVector()
{
	return { -36, 7, -30, 16, 48, -3, 22, 25, 46, 19 };
}

std::vector<std::vector<double>> thirdMatrix()
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

std::vector<double> thirdVector()
{
	return { -255, 186, 745, 867, 337, -587, 308, -856, -187, 334 };
}

void printMatrix(const std::vector<std::vector<double>>& arr)
{
	for (const auto& a : arr)
	{
		for (const auto& b : a)
		{
			std::cout << std::setw(12) << std::setfill(' ')  << std::setprecision(5) << b;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void printVector(const std::vector<double>& arr)
{
	for (const auto& a : arr)
		std::cout << a << " ";
	std::cout << std::endl << std::endl;
}
void printVectorResult(const std::vector<double>& vec)
{
	int i = 0;
	std::cout << "---- RESULTS ----" << std::endl;
	for (const auto& a : vec)
	{
		std::cout << "x[" << i << "] = " << std::setprecision(9) << a << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void printVectorResult(const std::vector<double>& vec, std::string str)
{
	int i = 0;
	std::cout << "---- RESULTS for vector " << str << " ----" << std::endl;
	for (const auto& a : vec)
	{
		std::cout << str << "[" << i << "] = " << std::setprecision(9) << a << std::endl;
		i++;
	}
	std::cout << std::endl;
}

bool matrixSemetric(const std::vector<std::vector<double>>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < i; j++)
			if (arr[i][j] != arr[j][i])
				return 0;
	}
	return 1;
}


void printMatrix(std::pair< std::vector<std::vector<double>>, std::vector<double>> a_b) {
	for (auto a = 0; a< signed(a_b.first[0].size()); a++)
	{
		for (auto b = 0; b < signed(a_b.first[0].size()); b++)
			std::cout << a_b.first[a][b] << " ";
		std::cout << "    " << a_b.second[a] << std::endl;
	}
	std::cout << std::endl;
}
