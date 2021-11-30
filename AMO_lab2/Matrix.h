#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

std::vector<std::vector<double>> firstMatrix();
std::vector<double> firstVector();
std::vector<std::vector<double>> secondMatrix();
std::vector<double> secondVector();
std::vector<std::vector<double>> thirdMatrix();
std::vector<double> thirdVector();

void printMatrix(const std::vector<std::vector<double>>& arr);
void printVectorResult(const std::vector<double>& vec);