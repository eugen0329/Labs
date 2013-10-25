#include "TwoDShapes.hpp"

TwoDShape::TwoDShape()
{
    measurement = 2;
}

TwoDShape::TwoDShape(int value)
{
    this->measurement = value;
}

float Circle::getArea()
{
    return PI * pow(radius, 2);
}


Circle::Circle() 
{
    this->radius = measurement;
}

Rectangle::Rectangle(int base)
{
    this->base = base;
    this->heigth = measurement;
}

float Rectangle::getArea()
{
    return base * heigth;
}

float Treangle::getArea()
{
    return heigth * base / 2;
}

Treangle::Treangle(int heigth)
{
    this->heigth = heigth;
    this->base = measurement;
}


