#pragma once
#include <fstream>
#include <vector>
#include "Matrix.h"

class Network
{
public:
	Network();
	void set_training_data(std::fstream file);


private:
	double learning_rate;
	int iterations;
	int hidden_units;
	Matrix verticles;

};