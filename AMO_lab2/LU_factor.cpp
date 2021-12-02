#include "LU_factor.h"


void LUMatrix(std::vector<std::vector<double>> a_matrix, std::vector<std::vector<double>> &l_matrix, std::vector<std::vector<double>> &u_matrix, int n)
{
	double sum;
	for (int p = 0; p < n; p++)
	{
		// for L matrix
		for (int i = p; i < n; i++)
		{
			sum = 0;
			for (int k = 0; k < p; k++)
			{
				sum += u_matrix[k][p] * l_matrix[i][k];
			}
			l_matrix[i][p] = a_matrix[i][p] - sum;
		}

		
		// print L matrix
		std::cout << "---- LOWER MATRIX " << p << "----" << std::endl;
		printMatrix(l_matrix);

		//for U matrix
		for (int j = p + 1; j < n; j++)
		{
			sum = 0;
			for (int k = 0; k < p; k++)
				sum += u_matrix[k][j] * l_matrix[p][k];
			u_matrix[p][j] = (a_matrix[p][j] - sum) / l_matrix[p][p];
		}
		// print U matrix
		std::cout << "---- UPPER MATRIX " << p << "----" << std::endl;
		printMatrix(u_matrix);
	}
}

bool minors(std::vector<std::vector<double>>& arr)
{
	int n = arr.size();
	std::vector<double> vec;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int p = 0; p < n - 1; p++)
			{
				for (int r = p + 1; r < n; r++)
					vec.push_back(arr[i][p] * arr[j][r] - arr[i][r] * arr[j][p]);
			}
		}
	}
	std::vector<double> minors(vec.begin() + 9, vec.end());
	return std::any_of(minors.begin(), minors.end(), [](double tmp) {return tmp == 0; });
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
	if (!minors(arr))
	{
		std::cout << "---- GIVEN MATRIX ----" << std::endl;
		printMatrix(arr);
		int S = arr[0].size();
		std::vector<std::vector<double>> l_arr(S, std::vector<double>(S));
		std::vector<std::vector<double>> u_arr(S, std::vector<double>(S));
		std::vector<double > y_vec(S);
		std::vector<double > x_vec(S);

		for (int a = 0; a < S; a++)
			u_arr[a][a] = 1;

		auto start = std::chrono::system_clock::now();
		LUMatrix(arr, l_arr, u_arr, S);
		y_find(l_arr, y_vec, vec, S);
		x_find(u_arr, y_vec, x_vec, S);
		auto end = std::chrono::system_clock::now();

		std::cout << "---- LOWER MATRIX ----" << std::endl;
		printMatrix(l_arr);
		std::cout << "---- UPPER MATRIX ----" << std::endl;
		printMatrix(u_arr);

		printVectorResult(y_vec, "y");
		printVectorResult(x_vec);
	}
	else
	{
		std::cout << "Minor = 0" << std::endl;
	}
	
}