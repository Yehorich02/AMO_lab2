#include "Hol_method.h"

std::vector<std::vector<double>> Cholesky_U_matrix(const std::vector<std::vector<double>>& arr)
{
	std::vector<std::vector<double>> U (arr.size(), std::vector<double>(arr[0].size()));
	double sum = 0;
	int n = signed(arr.size());
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		//find diagon elements
		for (int k = 0; k <= i - 1; k++)
		{
			sum += U[k][i] * U[k][i];
		}
		U[i][i] = std::sqrt(arr[i][i] - sum);

	//	std::cout << "Ut[" << i << "][" << i << "] = " << Ut[i][i] << std::endl;
		// find other elements
		for (int j = i + 1; j < n; j++)
		{
			sum = 0;
			for (int k = 0; k <= i - 1; k++)
			{
				sum += U[k][j] * U[k][i];
			}
			U[i][j] = (arr[i][j] - sum) / U[i][i];
		}

		std::cout << "----U(" << i << ") matrix----" << std::endl;
		printMatrix(U);
	}

	return U;
}

std::vector<double> Cholesky_find(const std::vector<std::vector<double>>& U, std::vector<double> b)
{
	int n = signed(U.size());
	std::vector<double> y (n);
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k <= i - 1; k++)
			sum += U[k][i] * y[k];
		y[i] = (b[i] - sum) / U[i][i];
		sum = 0;
	}

	printVectorResult(y, "y");

	std::vector<double> x(n);

	for (int i = n - 1; i >= 0; i--)
	{
		for (int k = i + 1; k < n; k++)
			sum += U[i][k] * x[k];
		x[i] = (y[i] - sum) / U[i][i];
		sum = 0;
	}
	return x;
}

void Cholesky_factorization(std::vector<std::vector<double>> arr, std::vector<double> vec)
{
	std::cout << "----Input matrix A----" << std::endl;
	printMatrix(arr);
	std::cout << "----Input vector B----" << std::endl;
	printVector(vec);

	if (matrixSemetric(arr))
	{
		std::vector<std::vector<double>> U(arr.size(), std::vector<double>(arr[0].size()));
		std::vector<double> x;
		for (int i = 0; i< signed(arr.size()); i++)
			for (int j = 0; j < signed(arr.size()); j++)
				U[i][j] = 0;
		U = Cholesky_U_matrix(arr);
		x = Cholesky_find(U, vec);

		std::cout << "----matrix U----" << std::endl;
		printMatrix(arr);

		printVectorResult(x);
	}
	else
	{
		std::cout << "This matrix is not semetric";
	}
}