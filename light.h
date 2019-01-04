#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>
#include <iostream>
using namespace std;

class Light
{
public:
    virtual void setLightPosition(GLfloat x, GLfloat y, GLfloat z)=0;
    GLfloat lightPosition[4];
};


class DirectionalLight : Light
{
public:
    void setLightPosition(GLfloat x, GLfloat y, GLfloat z);
};

class PointLight : Light
{
public:
    void setLightPosition(GLfloat x, GLfloat y, GLfloat z);
};

class SpotLight : Light
{
public:
    void setLightPosition(GLfloat x, GLfloat y, GLfloat z);
};


#endif // LIGHT_H
