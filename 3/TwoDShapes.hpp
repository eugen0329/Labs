#ifndef TWO_D_SHAPES_HPP
#define TWO_D_SHAPES_HPP

#include "Shapes.hpp"

class TwoDShape: public Shape 
{
public:
    TwoDShape(int);
    float getArea();
    float getVolume(); 
    virtual ~TwoDShape();
protected:
    int measurement1;
};

class Circle: public TwoDShape
{
public:
    Circle(int);
    float getArea();
    virtual ~Circle();
};

class Treangle: public TwoDShape
{
public:
    Treangle(int, int);
    float getArea();
    virtual ~Treangle();
private:
    int base;
};

class Rectangle: public TwoDShape
{
public:
    Rectangle(int, int);
    float getArea();
    virtual ~Rectangle();
private:
    int base;
};

#endif
