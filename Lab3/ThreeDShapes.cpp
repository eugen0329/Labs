#include "ThreeDShapes.hpp"

Tetrahedron::Tetrahedron()
{
    side = measurement1;
    heigth = measurement2;
}

float Tetrahedron::getVolume()
{
    return heigth * side * side * sin(PI/3); 
}

Parallelepiped::Parallelepiped(int inputHeigth)
{
    length = measurement1;
    width = measurement2;
    heigth = inputHeigth;
}

float Parallelepiped::getVolume()
{
    return length * heigth * width;
}

Cylinder::Cylinder()
{
    baseRadius = measurement1;
    heigth = measurement2;
}

float Cylinder::getVolume()
{
    return 3.14 * pow(baseRadius,2) * heigth;
}


