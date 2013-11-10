#include "TwoDShapes.hpp"

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
    return PI * pow(radius, 2);
}

Circle::Circle(int radius) 
{
    this->radius = radius;
}

Rectangle::Rectangle(int base, int heigth)
{
    this->base = base;
    this->heigth = heigth;
}

float Rectangle::getArea()
{
    return base * heigth;
}

float Treangle::getArea()
{
    return heigth * base / 2;
}

Treangle::Treangle(int heigth, int base)
{
    this->heigth = heigth;
    this->base = base;
}

