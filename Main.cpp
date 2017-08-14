#include "Matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Matrix m1(3, 3);
	Matrix m2(3, 3);
	Matrix m3 = Matrix().intToMatrix(3);
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (int i = 0; i < 3; i++)
	{
		m1.SetColumn(v, i);
		m2.SetRow(v, i);
	}
	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	cout << m1.matrixToDouble() << endl << endl;
	cout << m1 + m2 << endl;
	cout << m1 - m2 << endl;
	cout << m1 * m2 << endl;
	cout << m1 + 2 << endl;
	cout << m1 - 2 << endl;
	cout << m1 * 2 << endl;
	cout << m1 / 2 << endl;
	return 0;
}
