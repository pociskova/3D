#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <GL/glut.h>
#include <iostream>
using namespace std;


class Matrix4x4
{
public:
    Matrix4x4(GLfloat tab[]);
    void resetMatrix();
    void loadMatrix();
    GLfloat *getMatrix();
    Matrix4x4 operator +( const Matrix4x4 & m );

private:

    GLfloat matrix[16];

};

#endif // MATRIX4X4_H
