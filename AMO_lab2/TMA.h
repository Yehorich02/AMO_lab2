#pragma once
#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> tmaMatrix();
std::vector<double> tmaRVector();
bool tmaCheck(std::vector<std::vector<double>>& matrix);
std::vector<std::pair<double, double>> straightRun(const std::vector<std::vector<double>>& arr,
	const std::vector<double>& r);
std::vector<double> reverseRun(const std::vector<std::pair<double, double>>& vec);
void tmaMethod();
void printTMAResult(const std::vector<double>& res);
void printVectorOfPairs(const std::vector<std::pair<double, double>>& vec);

// for det part
double findDetViaTMA(const std::vector<std::vector<double>>& arr,
	const std::vector < std::pair < double, double>>& vec);
void printDetViaTMA();