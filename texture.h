#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>
#include <iostream>
using namespace std;

enum modes
{
    MIN_FILTER,
    MAG_FILTER,
    WRAP_S,
    WRAP_T,
    BORDER_COLOR,
    PRIORITY
};

class Texture{
  public:
    GLuint *getTexture();
    void textureFilter(int param, GLfloat value);

  private:
    GLuint text[1];
};

#endif // TEXTURE_H
