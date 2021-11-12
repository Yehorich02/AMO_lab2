#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <cmath>

std::vector<std::vector<double>> hol_matrix();
std::vector<double> hol_b_vector();
std::vector<std::vector<double>> hol_Ut_matrix(const std::vector<std::vector<double>>& arr);
void hol_method();
std::vector<double> hol_x_find(const std::vector<std::vector<double>>& Ut, std::vector<double> y);
std::vector<double> hol_y_find(const std::vector<std::vector<double>>& Ut, std::vector<double> b);
