#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <string>

std::vector<std::vector<double>> firstMatrix();
std::vector<double> firstVector();
std::vector<std::vector<double>> secondMatrix();
std::vector<double> secondVector();
std::vector<std::vector<double>> thirdMatrix();
std::vector<double> thirdVector();

bool matrixSemetric(const std::vector<std::vector<double>>& arr);


void printMatrix(const std::vector<std::vector<double>>& arr);
void printMatrix(std::pair< std::vector<std::vector<double>>, std::vector<double>> a_b);
void printVector(const std::vector<double>& arr);
void printVectorResult(const std::vector<double>& vec);
void printVectorResult(const std::vector<double>& vec, std::string str);