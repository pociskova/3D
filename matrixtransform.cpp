#include "matrixtransform.h"

Matrix4x4 MatrixTransform::rotateXaxis(Matrix4x4 m,GLfloat angle)
{
    GLfloat rotX[] = {GLfloat(1.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),
    GLfloat(cos(angle)), GLfloat(sin(angle)),GLfloat(0.0),GLfloat(0.0),GLfloat(-sin(angle)),
    GLfloat(cos(angle)),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(1.0)};

   Matrix4x4 transformMatrix=Matrix4x4(rotX);
   Matrix4x4 resultMatrix = m * transformMatrix;
   return resultMatrix;
}

Matrix4x4 MatrixTransform::rotateYaxis(Matrix4x4 m,GLfloat angle)
{
    GLfloat rotX[] = {GLfloat(cos(angle)),GLfloat(0.0),GLfloat(-sin(angle)),GLfloat(0.0),GLfloat(0.0),
    GLfloat(1.0), GLfloat(0.0),GLfloat(0.0),GLfloat(sin(angle)),GLfloat(0.0),
    GLfloat(cos(angle)),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(1.0)};

   Matrix4x4 transformMatrix=Matrix4x4(rotX);
   Matrix4x4 resultMatrix = m * transformMatrix;
   return resultMatrix;
}

Matrix4x4 MatrixTransform::rotateZaxis(Matrix4x4 m,GLfloat angle)
{
    GLfloat rotX[] = {GLfloat(cos(angle)),GLfloat(sin(angle)),GLfloat(0.0),GLfloat(0.0),GLfloat(-sin(angle)),
    GLfloat(cos(angle)), GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),
    GLfloat(1.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(1.0)};

   Matrix4x4 transformMatrix=Matrix4x4(rotX);
   Matrix4x4 resultMatrix = m * transformMatrix;
   return resultMatrix;
}

Matrix4x4 MatrixTransform::translation(Matrix4x4 m, GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat trans[] = {GLfloat(1.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),
    GLfloat(1.0), GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),
    GLfloat(1.0),GLfloat(0.0),GLfloat(x),GLfloat(y),GLfloat(z),GLfloat(1.0)};

     Matrix4x4 transformMatrix=Matrix4x4(trans);
     Matrix4x4 resultMatrix = m + transformMatrix;
     return resultMatrix;
}

Matrix4x4 MatrixTransform::scale(Matrix4x4 m, GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat scale[] = {GLfloat(x),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),
    GLfloat(y), GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),
    GLfloat(z),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(0.0),GLfloat(1.0)};

    Matrix4x4 transformMatrix=Matrix4x4(scale);
    Matrix4x4 resultMatrix = m * transformMatrix;
    return resultMatrix;
}

void MatrixTransform::loadResultToGLMatrix(uint16_t pname, Matrix4x4 m)
{
    glMatrixMode(pname);
    glLoadMatrixf(m.getMatrix());

}
