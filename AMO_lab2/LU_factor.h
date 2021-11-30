#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Matrix.h"


void LUMatrix(std::vector<std::vector<double>> a_matrix, std::vector<std::vector<double>>& l_matrix, std::vector<std::vector<double>>& u_matrix, int n);
void y_find(const std::vector<std::vector<double>>& l_matrix,
	std::vector<double>& y_vector, const std::vector<double>& b_vector, int n);

void x_find(const std::vector<std::vector<double>>& u_matrix,
	const std::vector<double>& y_vector, std::vector<double>& x_vector, int n);
void LU(std::vector<std::vector<double>> arr, std::vector<double> vec);