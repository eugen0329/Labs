#ifndef TWO_D_SHAPES_HPP
#define TWO_D_SHAPES_HPP

#include "Shapes.hpp"

class TwoDShape: public Shape 
{
public:
    float getArea();
    float getVolume(); 
    virtual ~TwoDShape();
};

class Circle: public TwoDShape
{
public:
    Circle(int);
    float getArea();
    virtual ~Circle();
private:
    int radius;
};

class Treangle: public TwoDShape
{
public:
    Treangle(int, int);
    float getArea();
    virtual ~Treangle();
private:
    int heigth;
    int base;
};

class Rectangle: public TwoDShape
{
public:
    Rectangle(int, int);
    float getArea();
    virtual ~Rectangle();
private:
    int heigth;
    int base;
};

#endif
