#include "matrix4x4.h"
Matrix4x4::Matrix4x4(GLfloat tab[])
{
    for(int i=0 ; i<15 ; i++)
        matrix[i]=tab[i];
}

void Matrix4x4::resetMatrix()
{
    for(int i=0 ; i<15 ; i++)
        matrix[i]=0.0;

   matrix[0]=1.0;
   matrix[5]=1.0;
   matrix[10]=1.0;
   matrix[15]=1.0;
}

void Matrix4x4::loadMatrix()
{
    //glGet(GL_MODELVIEW_MATRIX);
}

GLfloat *Matrix4x4::getMatrix()
{
    return matrix;
}

Matrix4x4 Matrix4x4::operator +( const Matrix4x4 & m )
{
//    GLfloat tab[16] = m.getMatrix();
//    GLfloat tab2[16] =  getMatrix();
//    GLfloat tmp[16];
//    for(int i=0 ; i<15 ; i++)
//    {
//        tmp[i]=tab[i]+tab2[i];
//    }
//    Matrix4x4 ret(tmp);
//    return ret;
}
