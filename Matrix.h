#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
using namespace std;

class Matrix
{
private:
	unsigned int rows;
	unsigned int columns;
	int **array;
public:
	Matrix();
	Matrix(unsigned int, unsigned int);
	void SetRow(vector<int>, unsigned int);
	void SetColumn(vector<int>, unsigned int);
	vector<int> GetRow(unsigned int);
	vector<int> GetColumn(unsigned int);
	Matrix intToMatrix(int);
	double matrixToDouble();
	Matrix operator+(const int);
	Matrix operator+(const Matrix);
	Matrix operator-(const int);
	Matrix operator-(const Matrix);
	Matrix operator*(const int);
	Matrix operator*(const Matrix);
	Matrix operator/(const int);
	friend ostream& operator<<(ostream &output, const Matrix m);
	friend istream& operator >> (istream  &input, Matrix m);
	~Matrix();
};

