#include "light.h"

void DirectionalLight::setLightPosition(GLfloat x, GLfloat y, GLfloat z)
{
    lightPosition[0]=x;
    lightPosition[1]=y;
    lightPosition[2]=z;

    lightPosition[3]=0.0;

}

void PointLight::setLightPosition(GLfloat x, GLfloat y, GLfloat z)
{
    lightPosition[0]=x;
    lightPosition[1]=y;
    lightPosition[2]=z;

    lightPosition[3]=1.0;

}

void SpotLight::setLightPosition(GLfloat x, GLfloat y, GLfloat z)
{
    lightPosition[0]=x;
    lightPosition[1]=y;
    lightPosition[2]=z;

    lightPosition[3]=1.0;

}
