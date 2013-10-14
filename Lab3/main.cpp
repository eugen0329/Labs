#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define PI 3.14159265

class Shape
{
public:
    void printShape();
};

class TwoDShape: public Shape 
{
public:
    TwoDShape();
    TwoDShape(int);
protected:
    int measurement;
};

class ThreeDShape: public Shape
{
public:
    ThreeDShape();
protected:
    int measurement1;
    int measurement2;
};

ThreeDShape::ThreeDShape()
{
    measurement1 = 3;
    measurement2 = 4;
}

class Parallelepiped: public ThreeDShape
{
public:
    Parallelepiped(int);
    int getVolume();
private:
    int length;
    int heigth; 
    int width;
};

class Tetrahedron: public ThreeDShape
{
public:
    Tetrahedron();
    float getVolume();
private:
    int side;
    int heigth;
};

Tetrahedron::Tetrahedron()
{
    side = measurement1;
    heigth = measurement2;
}

float Tetrahedron::getVolume()
{
    return heigth * side * side * sin(PI/3); 
}

Parallelepiped::Parallelepiped(int inputHeigth)
{
    length = measurement1;
    width = measurement2;
    heigth = inputHeigth;
}

int Parallelepiped::getVolume()
{
    return length * heigth * width;
}
class Cylinder: public ThreeDShape
{
public:
    Cylinder();
    float getVolume();
private:
    int baseRadius;
    int heigth;
};

Cylinder::Cylinder()
{
    baseRadius = measurement1;
    heigth = measurement2;
}

float Cylinder::getVolume()
{
    return 3.14 * pow(baseRadius,2) * heigth;
}

class Circle: public TwoDShape
{
public:
    Circle();
    float getArea();
private:
    int radius;
};

float Circle::getArea()
{
    return 3.14 * pow(radius, 2);
}


Circle::Circle() 
{
    this->radius = measurement;
}

class Rectangle: public TwoDShape
{
public:
    Rectangle(int);
    int getArea();
private:
    int heigth;
    int base;
};

class Treangle: public TwoDShape
{
public:
    Treangle(int);
    int getArea();
private:
    int heigth;
    int base;
};

Rectangle::Rectangle(int base)
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

Treangle::Treangle(int heigth)
{
    this->heigth = heigth;
    this->base = measurement;
}

TwoDShape::TwoDShape()
{
    measurement = 2;
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
    Treangle treangle(5);
    Rectangle rectangle(3);
    Circle circle;
    Cylinder cylinder;
    Tetrahedron tetrahedron;
    Parallelepiped parallelepiped(5);    

    cout << tetrahedron.getVolume() << '\n';
    cout << parallelepiped.getVolume() << '\n';
    cout << cylinder.getVolume() << '\n';
    cout << circle.getArea() << '\n';
    cout << treangle.getArea() << '\n';
    cout << rectangle.getArea() << '\n';  
    return 0;
}

