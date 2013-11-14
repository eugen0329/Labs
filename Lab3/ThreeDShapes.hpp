#ifndef THREE_D_SHAPES_HPP
#define THREE_D_SHAPES_HPP

#include "Shapes.hpp"

class ThreeDShape: public Shape
{
public:
    ThreeDShape(int, int);
    float getArea();
    float getVolume();
    virtual ~ThreeDShape();
protected:
    int heigth;
    int measurement2;
};

class Parallelepiped: public ThreeDShape
{
public:
    Parallelepiped(int, int, int);
    float getVolume();
    virtual ~Parallelepiped();
private:
    int length;
};

class Tetrahedron: public ThreeDShape
{
public:
    Tetrahedron(int, int);
    float getVolume();
    virtual ~Tetrahedron();
};

class Cylinder: public ThreeDShape
{
public:
    Cylinder(int, int);
    float getVolume();
    virtual ~Cylinder();
};

#endif
