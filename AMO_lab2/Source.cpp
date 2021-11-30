#include "Gauss.h"
#include "Hol_method.h"
#include "LU_factor.h"
#include "TMA.h"
#include <string>
#include "Matrix.h"
int main()
{
	int command = 0;
	std::string method;
	while (command != -1)
	{
		std::cout << "What matrix do you want to solve: ";
		std::cin >> command;
		switch (command)
		{
		case 1:
			std::cout << "Which method do you want to solve the matrix (LU or Gauss methods): ";
			std::cin >> method;
			if (method == "LU")
			{
				LU(firstMatrix(), firstVector());
			}
			else if (method == "Gauss")
			{
				Gausse_method(firstMatrix(), firstVector());
			}
			else
				break;
			break;
		case 2:
			std::cout << "Which method do you want to solve the matrix (Cholesky, LU or Gauss methods): ";
			std::cin >> method;
			if (method == "Cholesky")
			{
				Cholesky_factorization(secondMatrix(), secondVector());
			}
			else if (method == "LU")
			{
				LU(secondMatrix(), secondVector());
			}
			else if (method == "Gauss")
			{
				Gausse_method(secondMatrix(), secondVector());
			}
			else
				break;
			break;
		case 3:
			std::cout << "Which method do you want to solve the matrix (TMA, LU or Gauss methods): ";
			std::cin >> method;
			if (method == "TMA")
			{
				tmaMethod(thirdMatrix(), thirdVector());
			}
			else if (method == "LU")
			{
				LU(thirdMatrix(), thirdVector());
			}
			else if (method == "Gauss")
			{
				Gausse_method(thirdMatrix(), thirdVector());
			}
			else
				break;
			break;
		default:
			break;
		}
	}
	//hol_method();
	//Gausse_method();
	//LU();
	//printDetViaTMA();
	//tmaMethod();
}