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


void setMatrixSize();

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



    //resultMatrix = new Matrix;

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            resultMatrix.matrix[i][j] = matrix[i][j] +
                secondMatrix.matrix[i][j];
        }
    }

    return resultMatrix;
}

void setMatrixSize(int* sizeX, int* sizeY)
{
    cout << "\nx= ";
    cin >> *sizeX;
    cout << "\ny= ";
    cin >> *sizeY;
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

    //return;
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

    //return;

}

int main()
{
    int sizeX, sizeY;

	cout << "Set the first matrix size\n";
    setMatrixSize(&sizeX, &sizeY);
    Matrix first(sizeX, sizeY);

	cout << "Set the second matrix size\n";
    setMatrixSize(&sizeX, &sizeY);
	Matrix second(sizeX, sizeY);

	cout << "Set the first martix\n";
    first.setMatrix();
    cout << "Set the second martix\n";
	second.setMatrix();
    cout << "\nThe first matrix is:\n\n";
    first.displayMatrix();
    cout << "\nThe second matrix is:\n\n";
    second.displayMatrix();

	if (first.getSizeX() != second.getSizeX() || first.getSizeY() != second.getSizeY()) {
        cout << "The result of summing doesn't exists\n";
    }
	else 
	{
		cout << "\nThe result of summing of two matrix is:\n\n";
		Matrix sum = first.sumMatrix(second);
		sum.displayMatrix();
	}

	if (first.getSizeX() != second.getSizeY()) 
	{
        cout << "The result of multiplation doesn't exists\n";
    }
	else
	{
		cout << "\nThe result of multiplation of two matrix is:\n\n";
		Matrix multiply = first.multiplyMatrix(second);
		multiply.displayMatrix();
	}

	

    return 0;
}

