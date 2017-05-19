#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Network.h"

int main()
{
	Network net;
	Matrix tests(net.examples, net.input_size);
	Vector target(net.examples);
	std::fstream file;
	file.open("examples", std::ios::in);
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
		
	while (1)
	{
		double a, b;
		std::cin >> a >> b;
		Vector task(2);
		task[0] = a;
		task[1] = b;
		std::cout << net.query(task) << "\n";
	}
	system("pause");
}