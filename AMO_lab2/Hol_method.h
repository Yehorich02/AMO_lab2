#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>
#include "Matrix.h"

std::vector<std::vector<double>> Cholesky_Ut_matrix(const std::vector<std::vector<double>>& arr);
void Cholesky_factorization(std::vector<std::vector<double>> arr, std::vector<double> vec);
std::vector<double> Cholesky_x_find(const std::vector<std::vector<double>>& Ut, std::vector<double> y);
std::vector<double> Cholesky_y_find(const std::vector<std::vector<double>>& Ut, std::vector<double> b);
