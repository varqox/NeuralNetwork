#pragma once
#include <fstream>
#include <vector>
#include "Matrix.h"

class Network
{
public:
	Network();
	double f(double x);
	double f_derivative(double x);
	Matrix f(Matrix x);
	Matrix f_derivative(Matrix x);
	double random_from_0_to_1();
	double iterate(Vector input, double output);
	int iterations;
	int input_size;
	int examples;

private:
	double learning_rate;
	int hidden_units;
	Matrix verticles_input_to_hidden;
	Vector verticles_hidden_to_output;
};