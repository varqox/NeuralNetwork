#include <vector>
#include <cassert>
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(std::vector< std::vector<double> > m)
{
	v = m;
}

Matrix::Matrix(int x, int y)
{
	v.resize(x, std::vector<double>(y));
}

Matrix::Matrix(std::initializer_list< std::initializer_list<double> > list)
{
	assert(list.size() != 0);
	v.resize(list.begin()->size(), std::vector<double>(list.size()));
	for (auto i = list.begin(); i != list.end(); ++i)
		for (auto j = i->begin(); j != i->end(); ++j)
			v[j - i->begin()][i - list.begin()] = *j;
}

Matrix::Matrix() {}

int Matrix::width()
{
	return v.size();
}

int Matrix::height()
{
	return width() == 0 ? 0 : v[0].size();
}

Matrix Matrix::operator+(Matrix &m)
{
	assert(width() == m.width());
	assert(height() == m.height());
	Matrix result(width(), height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			result[x][y] = v[x][y] + m[x][y];
	return result;
}

Matrix Matrix::operator+=(Matrix &m)
{
	assert(width() == m.width());
	assert(height() == m.height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			v[x][y] += m[x][y];
	return *this;
}

Matrix Matrix::operator-(Matrix &m)
{

	assert(width() == m.width());
	assert(height() == m.height());
	Matrix result(width(), height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			result[x][y] = v[x][y] - m[x][y];
	return result;
}

Matrix Matrix::operator-=(Matrix &m)
{
	assert(width() == m.width());
	assert(height() == m.height());
	for (int x = 0; x != width(); ++x)
		for (int y = 0; y != height(); ++y)
			v[x][y] -= m[x][y];
	return *this;
}

Matrix Matrix::operator*(Matrix &m)
{
	assert(width() == m.height());
	Matrix result(m.width(), height());
	for (int i = 0; i != m.width(); ++i)
		for (int j = 0; j != height(); ++j)
			for (int k = 0; k != width(); ++k)
				result[i][j] += v[k][j] * m[i][k];
	return result;
}

Matrix Matrix::operator*=(Matrix &m)
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

Matrix Matrix::operator*(int scalar)
{
	Matrix result(width(), height());
	for (int i = 0; i != height(); ++i)
		for (int j = 0; j != width(); ++j)
			result[i][j] = v[i][j] * scalar;
	return result;
}

Matrix Matrix::operator*=(int scalar)
{
	for (int i = 0; i != height(); ++i)
		for (int j = 0; j != width(); ++j)
			v[i][j] *= scalar;
	return *this;
}

std::vector<double>& Matrix::operator[](int i)
{
	return v[i];
}

std::ostream& operator<<(std::ostream &os, Matrix &m)
{
	for (int j = 0; j != m.height(); ++j)
		for (int i = 0; i != m.width(); ++i)
			os << m[i][j] << " \n"[i == m.width() - 1];
	return os;
}