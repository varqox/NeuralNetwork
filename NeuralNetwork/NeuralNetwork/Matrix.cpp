#include <vector>
#include <cassert>
#include <iostream>
#include "Matrix.h"



Vector::Vector(int x)
{
	v.resize(x);
}

Vector::Vector(std::initializer_list<double> list)
{
	v.resize(list.size());
	for (auto i = list.begin(); i != list.end(); ++i)
		v[i - list.begin()] = *i;
}

Vector::Vector(Matrix m)
{
	assert(m.height() == 1 || m.width() == 1);
	if(m.width() == 1)
	{
		v.resize(m[0].size());
		for(int i = 0; i != m[0].size(); ++i)
			v[i] = m[0][i];
	}
	else
	{
		v.resize(m.height());
		for(int i = 0; i != m.width(); ++i)
			v[i] = m[i][0];
	}
}

Vector::Vector() {}

int Vector::size()
{
	return (int)v.size();
}

int Vector::width()
{
	return size();
}

int Vector::height()
{
	return size();
}

int Vector::length()
{
	return size();
}

Vector Vector::operator+(Vector m)
{
	assert(size() == m.size());
	Vector result(size());
	for(int i = 0; i != size(); ++i)
		result[i] = v[i] + m[i];
	return result;
}

Vector& Vector::operator+=(Vector m)
{
	assert(size() == m.size());
	Vector result(size());
	for(int i = 0; i != size(); ++i)
		v[i] += m[i];
	return *this;
}

Vector Vector::operator-(Vector m)
{
	assert(size() == m.size());
	Vector result(size());
	for(int i = 0; i != size(); ++i)
		result[i] = v[i] - m[i];
	return result;
}

Vector& Vector::operator-=(Vector m)
{
	assert(size() == m.size());
	Vector result(size());
	for(int i = 0; i != size(); ++i)
		v[i] -= m[i];
	return *this;
}

double Vector::operator*(Vector m)
{
	assert(size() == m.size());
	double result = 0;
	for(int i = 0; i != size(); ++i)
		result += v[i] * m[i];
	return result;
}

Vector Vector::operator*(double scalar)
{
	Vector result(size());
	for(int i = 0; i != size(); ++i)
		result[i] = v[i] * scalar;
	return result;
}

Vector& Vector::operator*=(double scalar)
{
	for(int i = 0; i != size(); ++i)
		v[i] *= scalar;
	return *this;
}

double& Vector::operator[](int i)
{
	return v[i];
}

std::vector<double>::iterator Vector::begin()
{
	return v.begin();
}

std::vector<double>::iterator Vector::end()
{
	return v.end();
}

std::ostream& operator<<(std::ostream &os, Vector m)
{
	os << "{ ";
	for(int i = 0; i != m.size(); ++i)
		os << m[i] << " ";
	return os << "}\n";
}










Matrix::Matrix(int x, int y)
{
	v.resize(x, Vector(y));
}

Matrix::Matrix(std::initializer_list< std::initializer_list<double> > list)
{
	assert(list.size() != 0);
	v.resize(list.begin()->size(), Vector(int(list.size())));
	for (auto i = list.begin(); i != list.end(); ++i)
		for (auto j = i->begin(); j != i->end(); ++j)
			v[j - i->begin()][i - list.begin()] = *j;
}

Matrix::Matrix(Vector m)
{
	v.resize(1, Vector(m.size()));
	for(int i = 0; i != m.size(); ++i)
		v[0][i] = m[i];
}

Matrix::Matrix() {}

int Matrix::width()
{
	return (int)v.size();
}

int Matrix::height()
{
	return width() == 0 ? 0 : v[0].size();
}

Matrix Matrix::operator+(Matrix m)
{
	assert(width() == m.width());
	assert(height() == m.height());
	Matrix result(width(), height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			result[x][y] = v[x][y] + m[x][y];
	return result;
}

Matrix& Matrix::operator+=(Matrix m)
{
	assert(width() == m.width());
	assert(height() == m.height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			v[x][y] += m[x][y];
	return *this;
}

Matrix Matrix::operator-(Matrix m)
{

	assert(width() == m.width());
	assert(height() == m.height());
	Matrix result(width(), height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			result[x][y] = v[x][y] - m[x][y];
	return result;
}

Matrix& Matrix::operator-=(Matrix m)
{
	assert(width() == m.width());
	assert(height() == m.height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			v[x][y] -= m[x][y];
	return *this;
}

Matrix Matrix::operator*(Matrix m)
{
	assert(width() == m.height());
	Matrix result(m.width(), height());
	for (int i = 0; i != m.width(); ++i)
		for (int j = 0; j != height(); ++j)
			for (int k = 0; k != width(); ++k)
				result[i][j] += v[k][j] * m[i][k];
	return result;
}

Matrix& Matrix::operator*=(Matrix m)
{
	assert(width() == m.height());
	Matrix result(m.width(), height());
	for (int i = 0; i != m.width(); ++i)
		for (int j = 0; j != height(); ++j)
			for (int k = 0; k != width(); ++k)
				result[i][j] += v[k][j] * m[i][k];

	v = result.v;
	return *this;
}

Matrix Matrix::operator*(double scalar)
{
	Matrix result(width(), height());
	for (int i = 0; i != height(); ++i)
		for (int j = 0; j != width(); ++j)
			result[i][j] = v[i][j] * scalar;
	return result;
}

Matrix& Matrix::operator*=(double scalar)
{
	for (int i = 0; i != height(); ++i)
		for (int j = 0; j != width(); ++j)
			v[i][j] *= scalar;
	return *this;
}

Vector& Matrix::operator[](int i)
{
	return v[i];
}

std::ostream& operator<<(std::ostream &os, Matrix m)
{
	os << "{\n";
	for (int j = 0; j != m.height(); ++j)
	{
		os << "  ";
		for (int i = 0; i != m.width(); ++i)
			os << m[i][j] << " ";
		os << "\n";
	}
	return os << "}\n";
}
