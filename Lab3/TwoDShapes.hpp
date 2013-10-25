#ifndef TWO_D_SHAPES_HPP
#define TWO_D_SHAPES_HPP

#include "shapes.hpp"

class Circle: public TwoDShape
{
public:
    Circle();
    float getArea();
private:
    int radius;
};

class Treangle: public TwoDShape
{
public:
    Treangle(int);
    float getArea();
private:
    int heigth;
    int base;
};

class Rectangle: public TwoDShape
{
public:
    Rectangle(int);
    float getArea();
private:
    int heigth;
    int base;
};

#endif
