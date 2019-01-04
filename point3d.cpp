#include "point3d.h"

Point3D::Point3D(GLfloat x,GLfloat y, GLfloat z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
void Point3D::setX(GLfloat x)
{
    this->x=x;
}
void Point3D::setY(GLfloat y)
{
    this->y=y;
}
void Point3D::setZ(GLfloat z)
{
    this->z=z;
}

GLfloat Point3D::getX()
{
    return x;
}
GLfloat Point3D::getY()
{
    return y;
}
GLfloat Point3D::getZ()
{
    return z;
}
