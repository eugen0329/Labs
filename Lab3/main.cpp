#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Shape
{
public:
    void printShape();
};

class TwoDShape: public Shape 
{
public:
    TwoDShape(int);
protected:
    int measurement;
};

class Rectangle: public TwoDShape
{
public:
    Rectangle(int, int);
    int getArea();
private:
    int heigth;
    int base;
};

class Treangle: public TwoDShape
{
public:
    Treangle(int, int);
    int getArea();
private:
    int heigth;
    int base;
};

Rectangle::Rectangle(int base, int heigth) : TwoDShape(heigth)
{
    this->base = base;
    this->heigth = measurement;
}

int Rectangle::getArea()
{
    return base * heigth;
}

int Treangle::getArea()
{
    return heigth * base / 2;
}

Treangle::Treangle(int heigth, int base) : TwoDShape(base)
{
    this->heigth = heigth;
    this->base = measurement;
}

TwoDShape::TwoDShape(int value)
{
    this->measurement = value;
}

void Shape::printShape()
{
    cout << "Shape";
}

int main()
{
    Treangle treangle(5, 2);
    Rectangle rectangle(3,4);

    cout << treangle.getArea();
    cout << rectangle.getArea();  
    return 0;
}

