#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
using namespace std;

class Matrix
 {
  public:
    Matrix(int, int);
	~Matrix();
	Matrix(const Matrix&);

    void setMatrix();
    void displayMatrix();
    Matrix sumMatrix(Matrix);
	int getSizeX();
	int getSizeY();
    Matrix multiplyMatrix(Matrix);
  private:
    int sizeX;
    int sizeY;
    int **matrix;
};

#endif