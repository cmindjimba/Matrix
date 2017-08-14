#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(unsigned int r, unsigned int c)
{
	rows = r;
	columns = c;
	array = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = 0;
		}
	}
}

void Matrix::SetRow(vector<int> v, unsigned int index)
{
	if (index < rows && columns == v.size())
	{
		for (int i = 0; i < columns; i++)
		{
			array[index][i] = v[i];
		}
	}
}

void Matrix::SetColumn(vector<int> v, unsigned int index)
{
	if (index < columns && rows == v.size())
	{
		for (int i = 0; i < rows; i++)
		{
			array[i][index] = v[i];
		}
	}
}

vector<int> Matrix::GetRow(unsigned int index)
{
	vector<int> v;
	for (int i = 0; i < columns; i++)
	{
		v.push_back(array[index][i]);
	}
	return v;
}

vector<int> Matrix::GetColumn(unsigned int index)
{
	vector<int> v;
	for (int i = 0; i < rows; i++)
	{
		v.push_back(array[i][index]);
	}
	return v;
}

Matrix Matrix::intToMatrix(int n)
{
	return Matrix(n, n);
}

double Matrix::matrixToDouble()
{
	double average = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			average += array[i][j];
		}
	}
	return average / (rows * columns);
}

Matrix Matrix::operator+(const int scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] += scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix matrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] += matrix.array[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator-(const int scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] -= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix matrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] -= matrix.array[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator*(const int scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix matrix)
{
	Matrix newMatrix(rows, matrix.columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			newMatrix.array[i][j] = 0;
			for (int k = 0; k < columns; k++)
				newMatrix.array[i][j] += (array[i][k]) * (matrix.array[k][j]);
		}
	}
	return newMatrix;
}

Matrix Matrix::operator/(const int scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] /= scalar;
		}
	}
	return *this;
}

ostream& operator<<(ostream &output, const Matrix m)
{
	for (unsigned int i = 0; i < m.rows; i++)
	{
		for (unsigned int j = 0; j <m. columns; j++)
		{
			output << m.array[i][j] << " ";
		}
		output << endl;
	}
	return output;
}

istream& operator >> (istream  &input, Matrix m)
{
	for (unsigned int i = 0; i < m.rows; i++)
	{
		for (unsigned int j = 0; j < m.columns; j++)
		{
			input >> m.array[i][j];
		}
	}
	return input;
}
Matrix::~Matrix()
{
}
