#include "shapes.hpp"


float ThreeDShape::getArea()
{
    cout << "The call of getArea() of class ThreeDShape is no sense";
    return 0;
}

float ThreeDShape::getVolume()
{
    cout << "The call of getVolume() of class ThreeDShape is no sense";
    return 0;
}

float TwoDShape::getArea()
{
    cout << "The call of getArea() of class TwoDShape is no sense";
    return 0;
}

float TwoDShape::getVolume()
{
    cout << "The call of getVolume() of class TwoDShape is no sense";
    return 0;
}

float Shape::getArea()
{
    cout << "The call of getArea() of class Shape is no sense";
    return 0;
}

float Shape::getVolume()
{
    cout << "The call of getVolume() of class Shape is no sense";
    return 0;
}

ThreeDShape::ThreeDShape()
{
    measurement1 = 3;
    measurement2 = 4;
}
