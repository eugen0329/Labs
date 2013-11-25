#include <iostream>
#include "Matrix.hpp"

using namespace std;

void setMatrixSize(int&, int&);

int main()
{
    int sizeX, sizeY;

	cout << "Set the first matrix size" << endl;
    setMatrixSize(sizeX, sizeY);
    Matrix first(sizeX, sizeY);

	cout << "Set the second matrix size" << endl;
    setMatrixSize(sizeX, sizeY);
	Matrix second(sizeX, sizeY);

	cout << "Set the first martix" << endl;
    first.setMatrix();
    cout << "Set the second martix" << endl;
	second.setMatrix();
    cout << endl << "The first matrix is:" << endl << endl;
    first.displayMatrix();
    cout << endl << "The second matrix is:" << endl << endl;
    second.displayMatrix();

	if (first.getSizeX() != second.getSizeX() || first.getSizeY() != second.getSizeY()) {
        cout << "The result of summing doesn't exists" << endl;
    }
	else 
	{
		cout << endl << "The result of summing of two matrix is:" << endl << endl;
		Matrix sum = first.sumMatrix(second);
		sum.displayMatrix();
	}

	if (first.getSizeX() != second.getSizeY()) 
	{
        cout << "The result of multiplation doesn't exists" << endl;
    }
	else
	{
		cout << endl << "The result of multiplation of two matrix is:" << endl << endl;
		Matrix multiply = first.multiplyMatrix(second);
		multiply.displayMatrix();
	}

    return 0;
}

void setMatrixSize(int& sizeX, int& sizeY)
{
    cout << endl <<"x= ";
    cin >> sizeX;
    cout << endl <<"y= ";
    cin >> sizeY;
}
