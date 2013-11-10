#include "ThreeDShapes.hpp"

ThreeDShape::ThreeDShape()
{
}

ThreeDShape::~ThreeDShape()
{
}

Cylinder::~Cylinder()
{
}

Tetrahedron::~Tetrahedron()
{
}

Parallelepiped::~Parallelepiped()
{
}

float ThreeDShape::getVolume()
{
    cout << "Calling for this functiong is no sense";
    return 0;
}

float ThreeDShape::getArea()
{
    cout << "Calling for this functiong is no sense";
    return 0;
}

Tetrahedron::Tetrahedron(int side, int heigth)
{
    this->side = side;
    this->heigth = heigth;
}

float Tetrahedron::getVolume()
{
    return heigth * side * side * sin(PI/3); 
}

Parallelepiped::Parallelepiped(int length, int width, int heigth)
{
    this->length = length;
    this->width = width;
    this->heigth = heigth;
}

float Parallelepiped::getVolume()
{
    return length * heigth * width;
}

Cylinder::Cylinder(int baseRadius, int heigth)
{
    this->baseRadius = baseRadius;
    this->heigth = heigth;
}

float Cylinder::getVolume()
{
    return PI * pow(baseRadius, 2) * heigth;
}

