#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Network.h"

int main()
{
	Network siec;
	std::cout << siec.get_input() << "\n" << siec.get_output();
	system("pause");
}