#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Network.h"

int main()
{
	Network net;
	Matrix tests(net.examples, net.input_size);
	Vector target(net.examples); //512949324
	std::fstream file;
	file.open("examples.txt", std::ios::in);
	for (int i = 0; i < net.examples; ++i)
	{
		for (int j = 0; j < net.input_size; ++j)
			file >> tests[i][j];
		file >> target[i];
	}
	file.close();
	for (int i = 0; i < net.iterations; ++i)
	{
		if (i % 997 == 0)
			std::cout
			<< net.iterate(tests[i % net.examples], target[i % net.examples])
			<< "\n";
		else
			net.iterate(tests[i % net.examples], target[i % net.examples]);
	}
		
	system("pause");
}