#pragma once
#include <vector>

class Matrix
{
public:
	Matrix(std::vector< std::vector<double> > m);
	Matrix(int x, int y);
	Matrix(std::initializer_list< std::initializer_list<double> > s);
	Matrix();
	int width();
	int height();
	Matrix operator+(Matrix &m);
	Matrix operator+=(Matrix &m);
	Matrix operator-(Matrix &m);
	Matrix operator-=(Matrix &m);
	Matrix operator*(Matrix &m);
	Matrix operator*=(Matrix &m);
	Matrix operator*(int scalar);
	Matrix operator*=(int scalar);
	std::vector<double>& operator[](int i);
private:
	std::vector< std::vector<double> > v;
};
std::ostream& operator<<(std::ostream &os, Matrix &m);