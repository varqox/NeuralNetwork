#include <iostream>
#include <fstream>
#include "Matrix.h"
int main()
{
	Matrix m1 = {
		{1, 2},
		{3, 4},
		{5, 6}
	}, m2 = {
		{1},
		{4}
	};
	std::cout << m1 << std::endl << m2 << std::endl << m1*m2;
	system("pause");
}