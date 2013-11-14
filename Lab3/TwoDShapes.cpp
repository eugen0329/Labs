#include "TwoDShapes.hpp"

TwoDShape::TwoDShape(int measurement1)
{
    this->measurement1 = measurement1;
}

Treangle::~Treangle()
{
}

Circle::~Circle()
{
}

Rectangle::~Rectangle()
{
}

TwoDShape::~TwoDShape()
{
}

float TwoDShape::getArea()
{
    cout << "The call of getArea() of class TwoDShape is no sense";
    return 0;
}

float TwoDShape::getVolume()
{
    cout << "The call of getArea() of class TwoDShape is no sense";
    return 0;
}

float Circle::getArea()
{
    return PI * pow(measurement1, 2);
}

Circle::Circle(int radius) : TwoDShape(radius)
{
}

Rectangle::Rectangle(int base, int heigth) : TwoDShape(heigth)
{
    this->base = base;
}

float Rectangle::getArea()
{
    return base * measurement1;
}

float Treangle::getArea()
{
    return measurement1 * base / 2;
}

Treangle::Treangle(int base, int heigth) : TwoDShape(heigth)
{
    this->base = base;
}

