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
    virtual float getArea() = 0;
    virtual float getVolume() = 0;
};


#endif 
