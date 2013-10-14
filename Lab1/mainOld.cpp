#include <iostream>
using namespace std;

class Matrix
 {
  public:
    1Matrix();
    Matrix(int, int);
	~Matrix();
	
    void setMatrixSize();
    void setMatrix();
    void displayMatrix();
    Matrix *sumMatrix(Matrix);
    Matrix *multiplyMatrix(Matrix);
  private:
    int sizeX;
    int sizeY;
    int **matrix;
};

Matrix::Matrix(int sizeX, int sizeY)
{
    int i;

    this->sizeX = sizeX;
    this->sizeY = sizeY;
    matrix = new int *[sizeY];

    for (i = 0; i < sizeY; i++) 

        matrix[i] = new int[sizeX];
    
}

Matrix::Matrix()
{
    int i;
    setMatrixSize();

    matrix = new int *[sizeY];

    for (i = 0; i < sizeY; i++) 
    {
        matrix[i] = new int[sizeX];
    }
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

Matrix * Matrix::sumMatrix(Matrix secondMatrix)
{
    int i, j;
    Matrix *resultMatrix;

    if (sizeX != secondMatrix.sizeX || sizeY != secondMatrix.sizeY) {
        cout << "The result of summing doesn't exists\n";
        return 0;
    }

    resultMatrix = new Matrix(sizeX, sizeY);

    for (i = 0; i < sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            (*resultMatrix).matrix[i][j] = matrix[i][j] +
                secondMatrix.matrix[i][j];
        }
    }

    return resultMatrix;
}

void Matrix::setMatrixSize(void)
{
    cout << "\nThe x size = ";
    cin >> sizeX;
    cout << "\nThe y size = ";
    cin >> sizeY;
}

Matrix *Matrix::multiplyMatrix(Matrix secondMatrix)
{
    int i, j, k;
    Matrix *resultMatrix;

    if (sizeX != secondMatrix.sizeY) {
        cout << "The result of multiplation doesn't exists\n";
        return 0;
    }

    resultMatrix = new Matrix(sizeX, secondMatrix.sizeY);

    for (i = 0; i < secondMatrix.sizeY; i++) {
        for (j = 0; j < sizeX; j++) {
            (*resultMatrix).matrix[i][j] = 0;
            for (k = 0; k < sizeX; k++) {
                (*resultMatrix).matrix[i][j] += matrix[i][k] *
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
    Matrix first, second, *sum, *multiply;

    first.setMatrix();
    second.setMatrix();
    cout << "\nThe first matrix is:\n\n";
    first.displayMatrix();
    cout << "\nThe second matrix is:\n\n";
    second.displayMatrix();

    sum = first.sumMatrix(second);
    if (sum) {
        cout << "\nThe result of summing of two matrix is:\n\n";
        (*sum).displayMatrix();
    }
    multiply = first.multiplyMatrix(second);
    if (multiply) {
        cout << "\nThe result of multiplation of two matrix is:\n\n";
        (*multiply).displayMatrix();
    }

	if(sum) {
		delete sum;
	} 
	if(multiply) {
    	delete multiply;
	}

    return 0;
}

