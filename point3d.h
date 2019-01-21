#ifndef POINT3D_H
#define POINT3D_H

#include <GL/glut.h>
class Point3D
{

public:
    Point3D(GLfloat x,GLfloat y, GLfloat z);
    void setX(GLfloat x);
    void setY(GLfloat y);
    void setZ(GLfloat z);

    GLfloat getX();
    GLfloat getY();
    GLfloat getZ();

private:
    GLfloat x,y,z;
};

#endif // POINT3D_H
