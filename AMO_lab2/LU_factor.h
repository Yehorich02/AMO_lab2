#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#define S 10

std::vector<std::vector<int>> aMatrix();
void LUMatrix(std::vector<std::vector<int>> a_matrix, std::vector<std::vector<double>>& l_matrix, std::vector<std::vector<double>>& u_matrix, int n);
void y_find(const std::vector<std::vector<double>>& l_matrix,
	std::vector<double>& y_vector, const std::vector<double>& b_vector, int n);

void x_find(const std::vector<std::vector<double>>& u_matrix,
	const std::vector<double>& y_vector, std::vector<double>& x_vector, int n);
void LU();