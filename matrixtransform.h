#ifndef MATRIXTRANSFORM_H
#define MATRIXTRANSFORM_H

#include <GL/glut.h>
#include <iostream>
#include "matrix4x4.h"
#include "math.h"
using namespace std;


class MatrixTransform
{
public:
    Matrix4x4 rotateXaxis(Matrix4x4 m, GLfloat angle);
    Matrix4x4 rotateYaxis(Matrix4x4 m, GLfloat angle);
    Matrix4x4 rotateZaxis(Matrix4x4 m, GLfloat angle);
    Matrix4x4 translation(Matrix4x4 m,GLfloat x, GLfloat y, GLfloat z);
    Matrix4x4 scale(Matrix4x4 m, GLfloat x, GLfloat y, GLfloat z);

    void loadResultToGLMatrix(uint16_t pname, Matrix4x4 m);



};
#endif // MATRIXTRANSFORM_H
