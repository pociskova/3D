#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <array>
#include <GL/glut.h>
#include <iostream>
using namespace std;

constexpr auto MATRIX_SIZE = 16;


class Matrix4x4
{
public:
     Matrix4x4();
    Matrix4x4(GLfloat tab[]);
    void resetMatrix();
    void loadIdentityMatrix();
    void loadGLMatrix(uint16_t pname);
    GLfloat *getMatrix();
    Matrix4x4 operator +(Matrix4x4 &m );
    Matrix4x4 operator -(Matrix4x4 &m );
    Matrix4x4 operator *(Matrix4x4 &m );
    Matrix4x4 operator =(Matrix4x4 &m );
    bool operator ==(Matrix4x4 &m );
    bool operator !=(Matrix4x4 &m );
    void printData() const;
private:

    std::array<GLfloat, MATRIX_SIZE> matrix;

};

#endif // MATRIX4X4_H
