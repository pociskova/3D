#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>
#include <iostream>
using namespace std;

enum LightTypes{
    LIGHT,
    LIGHT0,
    LIGHT1,
    LIGHT2,
    LIGHT3,
    LIGHT4,
    LIGHT5,
    LIGHT6,
    LIGHT7
};

class Light
{
public:
    virtual void setLightPosition(GLfloat x, GLfloat y, GLfloat z)=0;
    void lightOn(int type);
    void setLightAmbient(int type,GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void setLightDiffuse(int type,GLfloat x, GLfloat y, GLfloat z, GLfloat w  );
    void setLightPositionToType(int type);
    void setConstantAttenaution(int type);
    void setLinearAttenaution(int type);
    void setQuadraticAttenaution(int type);
    GLfloat lightPosition[4];
    GLfloat lightAmb[4];
    GLfloat lightDif[4];
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
    void setSpotCuttof(int type);
    void setSpotDirection(int type);
    void setSpotExponent(int type);
};


#endif // LIGHT_H
