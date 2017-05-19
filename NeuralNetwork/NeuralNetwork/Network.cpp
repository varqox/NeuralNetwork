#include "Network.h"
#include <iostream>
#include <time.h>
#include <string>

Network::Network()
{
	learning_rate = 0.5;
	iterations = 1000;
	hidden_units = 3;
	input_size = 2;
	examples = 5;
	verticles_input_to_hidden = Matrix(hidden_units, input_size);
	verticles_hidden_to_output = Vector(hidden_units);
	srand(time(NULL));
	for (int i = 0; i < verticles_input_to_hidden.width(); ++i)
		for (int j = 0; j < verticles_input_to_hidden.height(); ++j)
			verticles_input_to_hidden[i][j] = random_from_0_to_1();
	for (int i = 0; i < verticles_hidden_to_output.size(); ++i)
		verticles_hidden_to_output[i] = random_from_0_to_1();
	std::fstream file;
	file.open("examples.txt", std::ios::in);
	set_training_data(file);

}

double Network::f(double x)
{
	return 1 / (1 + exp(-x));
}

double Network::f_derivative(double x)
{
	double s = f(x);
	return s * (1 - s);
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


void Network::set_training_data(std::fstream &file)
{
	std::string line;
	input = Matrix(input_size, examples);
	target = Matrix(1, examples);
	for (int i = 0; i < examples; ++i)
	{
		for (int j = 0; j < input_size; ++j)
			file >> input[j][i];
		file >> target[i];
	}
}

void Network::iterate()
{
	hidden_layer_sum = input * verticles_input_to_hidden;
	hidden_layer_results = f(hidden_layer_sum);
	Vector output_sum = hidden_layer_results * verticles_hidden_to_output;
	Vector output_result = f(output_sum);
	Vector margin_of_error = target - output_result;

	for (int i = 0; i < examples; ++i)
	{
		double delta_output_sum = margin_of_error[i] * f_derivative(output_sum[i]);
		Vector weights = Vector(hidden_layer_results[i]) * delta_output_sum;
		verticles_hidden_to_output += weights * learning_rate;

		for (int j = 0; j < hidden_units; j++)
		{
			double delta_hidden_sum =
				delta_output_sum
				* verticles_hidden_to_output[j]
				* f_derivative(hidden_layer_sum[i][j]);
			for (int k = 0; k < input_size; k++)
			{
				verticles_input_to_hidden[j][k] += delta_output_sum * input[i][k] * learning_rate;
			}
		}
	}
}

Matrix Network::get_input()
{
	return input;
}

Matrix Network::get_output()
{
	return target;
}