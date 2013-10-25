#ifndef SHAPES_HPP
#define SHAPES_HPP

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
    virtual float getArea();
    virtual float getVolume();
};

class TwoDShape: public Shape 
{
public:
    TwoDShape();
    TwoDShape(int);
    float getArea();
    float getVolume();
protected:
    int measurement;
};

class ThreeDShape: public Shape
{
public:
    ThreeDShape();
    float getArea();
    float getVolume();
protected:
    int measurement1;
    int measurement2;
};

#endif 
