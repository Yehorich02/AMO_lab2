#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include "Matrix.h"

void modify_matrix(std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b, int n);
void Gausse_method(std::vector<std::vector<double>> arr, std::vector<double> vec);
std::vector<double> scaling(const std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b, int n);
void transformation(std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b, std::vector<double>& vec, int n);
std::vector<double> result(const std::pair< std::vector<std::vector<double>>, std::vector<double>>& a_b);