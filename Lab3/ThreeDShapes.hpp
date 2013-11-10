#ifndef THREE_D_SHAPES_HPP
#define THREE_D_SHAPES_HPP

#include "Shapes.hpp"

class ThreeDShape: public Shape
{
public:
    ThreeDShape();
    float getArea();
    float getVolume();
    virtual ~ThreeDShape();
protected:
    int heigth;
};

class Parallelepiped: public ThreeDShape
{
public:
    Parallelepiped(int, int, int);
    float getVolume();
    virtual ~Parallelepiped();
private:
    int length;
    int width;
    
};

class Tetrahedron: public ThreeDShape
{
public:
    Tetrahedron(int, int);
    float getVolume();
    virtual ~Tetrahedron();
private:
    int side;
};

class Cylinder: public ThreeDShape
{
public:
    Cylinder(int, int);
    float getVolume();
    virtual ~Cylinder();
private:
    int baseRadius;
};

#endif
