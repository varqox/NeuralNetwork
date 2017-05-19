#pragma once
#include <fstream>
#include <vector>
#include "Matrix.h"

class Network
{
public:
	Network();
	void set_training_data(std::fstream &file);
	double f(double x);
	double f_derivative(double x);
	Matrix f(Matrix x);
	Matrix f_derivative(Matrix x);
	double random_from_0_to_1();
	void iterate();
	Matrix get_input();
	Matrix get_output();

private:
	double learning_rate;
	int iterations;
	int hidden_units;
	int input_size;
	int examples;
	Matrix verticles_input_to_hidden;
	Vector verticles_hidden_to_output;
	Matrix hidden_layer_sum;
	Matrix hidden_layer_results;
	Matrix input;
	Vector target;
};