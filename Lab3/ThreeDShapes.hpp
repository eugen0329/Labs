#ifndef THREE_D_SHAPES_HPP
#define THREE_D_SHAPES_HPP

#include "shapes.hpp"

class Parallelepiped: public ThreeDShape
{
public:
    Parallelepiped(int);
    float getVolume();
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

class Cylinder: public ThreeDShape
{
public:
    Cylinder();
    float getVolume();
private:
    int baseRadius;
    int heigth;
};

#endif
