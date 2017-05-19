#pragma once
#include <vector>

class Vector;

class Matrix
{
public:
	Matrix(std::vector< std::vector<double> > m);
	Matrix(int x, int y);
	Matrix(std::initializer_list< std::initializer_list<double> > s);
	Matrix();
	Matrix(Vector v);

	int width();
	int height();

	Matrix operator+(Matrix m);
	Matrix operator+=(Matrix m);
	Matrix operator-(Matrix m);
	Matrix operator-=(Matrix m);
	Matrix operator*(Matrix m);
	Matrix operator*=(Matrix m);
	Matrix operator*(double scalar);
	Matrix operator*=(double scalar);
	std::vector<double>& operator[](int i);

	// std::vector< std::vector<double> >::iterator begin();
	// std::vector< std::vector<double> >::iterator end();
	// std::vector<double>::iterator begin();
	// std::vector<double>::iterator end();

private:
	std::vector< std::vector<double> > v;
};
std::ostream& operator<<(std::ostream &os, Matrix m);

class Vector
{
public:
	Vector(std::vector<double> m);
	Vector(int x);
	Vector(std::initializer_list<double> s);
	Vector(Matrix m);
	Vector();

	int size();
	int width();
	int height();

	Vector operator+(Vector m);
	Vector operator+=(Vector m);
	Vector operator-(Vector m);
	Vector operator-=(Vector m);
	double operator*(Vector m);
	Vector operator*(double scalar);
	Vector operator*=(double scalar);
	double& operator[](int i);

	std::vector<double>::iterator begin();
	std::vector<double>::iterator end();

private:
	std::vector<double> v;
};
std::ostream& operator<<(std::ostream &os, Vector m);
