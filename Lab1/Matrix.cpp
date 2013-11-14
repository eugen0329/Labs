#include "Matrix.hpp"

Matrix::Matrix(const Matrix& Obj)
{
	int i, j;

	sizeX = Obj.sizeX;
	sizeY = Obj.sizeY;

    matrix = new int *[sizeY];
    for (i = 0; i < sizeY; i++) 
        matrix[i] = new int[sizeX];

	for(i = 0; i < sizeY; i++)
	{
		for(j = 0; j < sizeX; j++)
		{
			matrix[i][j] = Obj.matrix[i][j];
		}
	}
}

Matrix::Matrix(int sizeX, int sizeY)
{
    int i;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    matrix = new int *[sizeY];
    for (i = 0; i < sizeY; i++) 
        matrix[i] = new int[sizeX];
    
}

int Matrix::getSizeX()
{
	return sizeX;
}

int Matrix::getSizeY()
{
	return sizeY;
}

Matrix::~Matrix()
{
	int i;
    if(matrix) 
    {
		for (i = 0; i < sizeY; i++)
		 {
       	    delete []matrix[i];
        }
        delete []matrix;
	}
}

Matrix Matrix::sumMatrix(Matrix secondMatrix)
{
    int i, j;
    Matrix resultMatrix(sizeX, sizeY);

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            resultMatrix.matrix[i][j] = matrix[i][j] +
                secondMatrix.matrix[i][j];
        }
    }

    return resultMatrix;
}

Matrix Matrix::multiplyMatrix(Matrix secondMatrix)
{
    int i, j, k;
    Matrix resultMatrix(secondMatrix.sizeX, sizeY);

    for (i = 0; i < sizeY; i++) 
	{
        for (j = 0; j < secondMatrix.sizeX; j++) 
		{
            resultMatrix.matrix[i][j] = 0;
            for (k = 0; k < sizeX; k++) 
			{
                resultMatrix.matrix[i][j] += matrix[i][k] *
                    secondMatrix.matrix[k][j];
            }
        }
    }

    return resultMatrix;
}

void Matrix::setMatrix(void)
{
    int i, j;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            cout << "Enter element [" << i + 1 << "][" << j +
                1 << "] of a matrix\n";
            cin >> Matrix::matrix[i][j];
        }
    }

}

void Matrix::displayMatrix()
{
    int i, j;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }

}