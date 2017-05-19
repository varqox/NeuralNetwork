#pragma once
#include <vector>

class Matrix;

class Vector
{
public:
	Vector(int x);
	Vector(std::initializer_list<double> s);
	Vector(Matrix m);
	Vector();

	int size();
	int width();
	int height();
	int length();

	Vector operator+(Vector m);
	Vector& operator+=(Vector m);
	Vector operator-(Vector m);
	Vector& operator-=(Vector m);
	double operator*(Vector m);
	Vector operator*(double scalar);
	Vector& operator*=(double scalar);
	double& operator[](int i);

	std::vector<double>::iterator begin();
	std::vector<double>::iterator end();

private:
	std::vector<double> v;
};
std::ostream& operator<<(std::ostream &os, Vector m);

class Matrix
{
public:
	Matrix(int x, int y);
	Matrix(std::initializer_list< std::initializer_list<double> > s);
	Matrix();
	Matrix(Vector v);

	int width();
	int height();

	Matrix operator+(Matrix m);
	Matrix& operator+=(Matrix m);
	Matrix operator-(Matrix m);
	Matrix& operator-=(Matrix m);
	Matrix operator*(Matrix m);
	Matrix& operator*=(Matrix m);
	Matrix operator*(double scalar);
	Matrix& operator*=(double scalar);
	Vector& operator[](int i);

private:
	std::vector<Vector> v;
};
std::ostream& operator<<(std::ostream &os, Matrix m);



