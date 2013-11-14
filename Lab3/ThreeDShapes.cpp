#include "ThreeDShapes.hpp"

ThreeDShape::ThreeDShape(int measurement2, int heigth)
{
    this->heigth = heigth;
    this->measurement2 = measurement2;
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

Tetrahedron::Tetrahedron(int side, int heigth) : ThreeDShape(side, heigth)
{
}

float Tetrahedron::getVolume()
{
    return heigth * measurement2 * measurement2 * sin(PI/3); 
}

Parallelepiped::Parallelepiped(int length, int width, int heigth) :
ThreeDShape(width, heigth)
{
    this->length = length;
}

float Parallelepiped::getVolume()
{
    return length * heigth * measurement2;
}

Cylinder::Cylinder(int baseRadius, int heigth) : ThreeDShape(baseRadius, heigth)
{
}

float Cylinder::getVolume()
{
    return PI * pow(measurement2, 2) * heigth;
}

