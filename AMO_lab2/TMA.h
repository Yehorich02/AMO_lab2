#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <iomanip>

bool tmaCheck(std::vector<std::vector<double>>& matrix);
std::vector<std::pair<double, double>> straightRun(const std::vector<std::vector<double>>& arr,
	const std::vector<double>& r);
std::vector<double> reverseRun(const std::vector<std::pair<double, double>>& vec);
void tmaMethod(std::vector<std::vector<double>> arr,
	std::vector<double> vec);
void printTMAResult(const std::vector<double>& res);
void printVectorOfPairs(const std::vector<std::pair<double, double>>& vec);

// for det part
double findDetViaTMA(const std::vector<std::vector<double>>& arr,
	const std::vector < std::pair < double, double>>& vec);
void printDetViaTMA(std::vector<std::vector<double>> arr,
	std::vector<double> vec);