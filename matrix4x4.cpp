#include "matrix4x4.h"

#include <algorithm>

Matrix4x4::Matrix4x4()
{
    resetMatrix();
}

Matrix4x4::Matrix4x4(GLfloat tab[])
{
    std::copy_n(tab, 16, std::begin(matrix));
}

void Matrix4x4::resetMatrix()
{
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        matrix[i] = 0.0;
    }
}

void Matrix4x4::loadIdentityMatrix()
{
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        matrix[i] = (i % 5) ? 0.0 : 1.0;
    }
}

void Matrix4x4::loadGLMatrix(uint16_t pname)
{
    glGetFloatv(pname, matrix.data());
}

GLfloat *Matrix4x4::getMatrix()
{
    return matrix.data();
}

void Matrix4x4::printData() const
{
    for ( const auto&m : matrix)
    {
        std::cout << m << " ";
    }
}

Matrix4x4 Matrix4x4::operator +( Matrix4x4 & m )
{
    GLfloat tmp[16];
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        tmp[i] = m.getMatrix()[i] + matrix[i];
    }
    return Matrix4x4(tmp);
}

Matrix4x4 Matrix4x4::operator -( Matrix4x4 & m )
{
    GLfloat tmp[16];
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        tmp[i] = m.getMatrix()[i] - matrix[i];
    }
    return Matrix4x4(tmp);
}

Matrix4x4 Matrix4x4::operator *( Matrix4x4 & m )
{
    GLfloat tmp[4][4];
    GLfloat tmp2[4][4];
    GLfloat result[4][4];
    GLfloat r[16];

    for(int i = 0; i < 4; ++i)
    {
        tmp[i][0] =matrix[i];
        tmp[i][1] =matrix[i+4];
        tmp[i][2] =matrix[i+8];
        tmp[i][3] =matrix[i+12];
    }
    for(int i = 0; i < 4; ++i)
    {
        tmp2[i][0] =m.getMatrix()[i];
        tmp2[i][1] =m.getMatrix()[i+4];
        tmp2[i][2] =m.getMatrix()[i+8];
        tmp2[i][3] =m.getMatrix()[i+12];
    }

    for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    result[i][j] += tmp[i][k] * tmp2[k][j];
            }

    for(int i = 0; i < 4; ++i)
    {
        r[i] = result[i][0];
        r[i+4] = result[i][1];
        r[i+8] = result[i][2];
        r[i+12] = result[i][3];
    }

    return Matrix4x4(r);
}

Matrix4x4 Matrix4x4::operator =( Matrix4x4 & m )
{
    GLfloat tmp[16];
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        tmp[i] = m.getMatrix()[i];
    }
    return Matrix4x4(tmp);
}

bool Matrix4x4::operator ==( Matrix4x4 & m )
{
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        if(m.getMatrix()[i] != matrix[i] )
        {
            return false;
        }
    }

    return true;
}

bool Matrix4x4::operator !=( Matrix4x4 & m )
{
    for(int i = 0; i < MATRIX_SIZE; ++i)
    {
        if(m.getMatrix()[i] != matrix[i] )
        {
            return true;
        }
    }

    return false;
}
