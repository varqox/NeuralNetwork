#include "Network.h"
#include <iostream>
#include <time.h>
#include <string>

Network::Network()
{
	learning_rate = 0.2;
	iterations = 1000000;
	hidden_units = 3;
	input_size = 2;
	examples = 1000;
	verticles_input_to_hidden = Matrix(input_size, hidden_units);
	verticles_hidden_to_output = Vector(hidden_units);
	srand(time(NULL));
	for (int i = 0; i < verticles_input_to_hidden.width(); ++i)
		for (int j = 0; j < verticles_input_to_hidden.height(); ++j)
			verticles_input_to_hidden[i][j] = random_from_0_to_1();
	for (int i = 0; i < verticles_hidden_to_output.size(); ++i)
		verticles_hidden_to_output[i] = random_from_0_to_1();
}

double Network::f(double x)
{
	return x / (1 + abs(x));
}

double Network::f_derivative(double x)
{
	double absx = abs(x);
	return 1 / ((absx + 1) * (absx + 1));
}

Matrix Network::f(Matrix m)
{
	for (int i = 0; i < m.width(); ++i)
		for (int j = 0; j < m.height(); ++j)
			m[i][j] = f(m[i][j]);
	return m;
}

Matrix Network::f_derivative(Matrix m)
{
	for (int i = 0; i < m.width(); ++i)
		for (int j = 0; j < m.height(); ++j)
			m[i][j] = f_derivative(m[i][j]);
	return m;
}

double Network::random_from_0_to_1()
{
	return ((double)rand() / RAND_MAX);
}


double Network::iterate(Vector input, double output)
{
	Vector hidden_layer_sum = verticles_input_to_hidden * input;
	Vector hidden_layer_results = f(hidden_layer_sum);
	double output_sum = hidden_layer_results * verticles_hidden_to_output;
	double output_result = f(output_sum);
	double margin_of_error = output - output_result;

	double delta_output_sum = margin_of_error * f_derivative(output_sum);
	Vector weights = hidden_layer_results * delta_output_sum;

	for (int i = 0; i < hidden_units; ++i)
	{
		double delta_hidden_sum =
			delta_output_sum
			* verticles_hidden_to_output[i]
			* f_derivative(hidden_layer_sum[i]);

		for (int j = 0; j < input_size; ++j)
			verticles_input_to_hidden[j][i] += delta_hidden_sum * input[j] * learning_rate;
	}

	verticles_hidden_to_output += weights * learning_rate;

	return margin_of_error;
}