#include "light.h"

void Light::lightOn(int type)
{
    glEnable(GL_DEPTH_TEST);

    switch(type)
    {
    case LIGHT:
         glEnable(GL_LIGHTING);
        break;
    case LIGHT0:
         glEnable(GL_LIGHT0);
        break;
    case LIGHT1:
        glEnable(GL_LIGHT1);
        break;
    case LIGHT2:
         glEnable(GL_LIGHT2);
        break;
    case LIGHT3:
        glEnable(GL_LIGHT3);
        break;
    case LIGHT4:
        glEnable(GL_LIGHT4);
        break;
    case LIGHT5:
         glEnable(GL_LIGHT5);
        break;
    case LIGHT6:
        glEnable(GL_LIGHT6);
        break;
    case LIGHT7:
         glEnable(GL_LIGHT7);
        break;
    default:
        break;
     }

}

void Light::setLightAmbient(int type,GLfloat x, GLfloat y, GLfloat z, GLfloat w  )
{
    lightAmb[0]=x;
    lightAmb[1]=y;
    lightAmb[2]=z;
    lightAmb[3]=w;

    switch(type)
    {
    case LIGHT0:
         glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
        break;
    case LIGHT1:
         glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb);
        break;
    case LIGHT2:
         glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmb);
        break;
    case LIGHT3:
         glLightfv(GL_LIGHT3, GL_AMBIENT, lightAmb);
        break;
    case LIGHT4:
         glLightfv(GL_LIGHT4, GL_AMBIENT, lightAmb);
        break;
    case LIGHT5:
         glLightfv(GL_LIGHT5, GL_AMBIENT, lightAmb);
        break;
    case LIGHT6:
         glLightfv(GL_LIGHT6, GL_AMBIENT, lightAmb);
        break;
    case LIGHT7:
         glLightfv(GL_LIGHT7, GL_AMBIENT, lightAmb);
        break;
    default:
        break;
    }

}

void Light::setLightDiffuse(int type,GLfloat x, GLfloat y, GLfloat z, GLfloat w  )
{
    lightDif[0]=x;
    lightDif[1]=y;
    lightDif[2]=z;
    lightDif[3]=w;

    switch(type)
    {
    case LIGHT0:
         glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
        break;
    case LIGHT1:
         glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDif);
        break;
    case LIGHT2:
         glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDif);
        break;
    case LIGHT3:
         glLightfv(GL_LIGHT3, GL_DIFFUSE, lightDif);
        break;
    case LIGHT4:
         glLightfv(GL_LIGHT4, GL_DIFFUSE, lightDif);
        break;
    case LIGHT5:
         glLightfv(GL_LIGHT5, GL_DIFFUSE, lightDif);
        break;
    case LIGHT6:
         glLightfv(GL_LIGHT6, GL_DIFFUSE, lightDif);
        break;
    case LIGHT7:
         glLightfv(GL_LIGHT7, GL_DIFFUSE, lightDif);
        break;
    default:
        break;
    }

}
void Light::setLightPositionToType(int type)
{
    switch(type)
    {
    case LIGHT0:
         glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        break;
    case LIGHT1:
         glLightfv(GL_LIGHT1,  GL_POSITION, lightPosition);
        break;
    case LIGHT2:
         glLightfv(GL_LIGHT2, GL_POSITION, lightPosition);
        break;
    case LIGHT3:
         glLightfv(GL_LIGHT3, GL_POSITION, lightPosition);
        break;
    case LIGHT4:
         glLightfv(GL_LIGHT4,  GL_POSITION, lightPosition);
        break;
    case LIGHT5:
         glLightfv(GL_LIGHT5,  GL_POSITION, lightPosition);
        break;
    case LIGHT6:
         glLightfv(GL_LIGHT6,  GL_POSITION, lightPosition);
        break;
    case LIGHT7:
         glLightfv(GL_LIGHT7,  GL_POSITION, lightPosition);
        break;
    default:
        break;
    }
}

void Light::setConstantAttenaution(int type)
{
    switch(type)
    {
    case LIGHT0:
         glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT1:
         glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT2:
         glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT3:
         glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT4:
         glLightf(GL_LIGHT4,  GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT5:
         glLightf(GL_LIGHT5,  GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT6:
         glLightf(GL_LIGHT6,  GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT7:
         glLightf(GL_LIGHT7,  GL_CONSTANT_ATTENUATION, 1.0);
         glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    default:
        break;
    }
}

void Light::setLinearAttenaution(int type)
{  switch(type)
    {
    case LIGHT0:
         glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT1:
         glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT2:
         glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT3:
         glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT4:
         glLightf(GL_LIGHT4,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT5:
         glLightf(GL_LIGHT5,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT6:
         glLightf(GL_LIGHT6,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    case LIGHT7:
         glLightf(GL_LIGHT7,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 1.0);
         glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.0);
        break;
    default:
        break;
    }
}

void Light::setQuadraticAttenaution(int type)
{
    switch(type)
    {
    case LIGHT0:
         glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT1:
         glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT2:
         glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT3:
         glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT4:
         glLightf(GL_LIGHT4,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT5:
         glLightf(GL_LIGHT5,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT6:
         glLightf(GL_LIGHT6,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    case LIGHT7:
         glLightf(GL_LIGHT7,  GL_CONSTANT_ATTENUATION, 0.0);
         glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.0);
         glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 1.0);
        break;
    default:
        break;
    }
}

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

    //lightPosition[3]=1.0;

}

void SpotLight::setSpotCuttof(int type)
{
    switch(type)
    {
    case LIGHT0:
         glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT1:
         glLightfv(GL_LIGHT1,  GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT2:
         glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT3:
         glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT4:
         glLightfv(GL_LIGHT4,  GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT5:
         glLightfv(GL_LIGHT5,  GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT6:
         glLightfv(GL_LIGHT6,  GL_SPOT_CUTOFF, lightPosition);
        break;
    case LIGHT7:
         glLightfv(GL_LIGHT7,  GL_SPOT_CUTOFF, lightPosition);
        break;
    default:
        break;
    }
}
void SpotLight::setSpotDirection(int type)
{
    switch(type)
    {
    case LIGHT0:
         glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT1:
         glLightfv(GL_LIGHT1,  GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT2:
         glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT3:
         glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT4:
         glLightfv(GL_LIGHT4,  GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT5:
         glLightfv(GL_LIGHT5,  GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT6:
         glLightfv(GL_LIGHT6,  GL_SPOT_DIRECTION, lightPosition);
        break;
    case LIGHT7:
         glLightfv(GL_LIGHT7,  GL_SPOT_DIRECTION, lightPosition);
        break;
    default:
        break;
    }
}
void SpotLight::setSpotExponent(int type)
{
    switch(type)
    {
    case LIGHT0:
         glLightfv(GL_LIGHT0, GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT1:
         glLightfv(GL_LIGHT1,  GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT2:
         glLightfv(GL_LIGHT2, GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT3:
         glLightfv(GL_LIGHT3, GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT4:
         glLightfv(GL_LIGHT4,  GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT5:
         glLightfv(GL_LIGHT5,  GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT6:
         glLightfv(GL_LIGHT6,  GL_SPOT_EXPONENT, lightPosition);
        break;
    case LIGHT7:
         glLightfv(GL_LIGHT7,  GL_SPOT_EXPONENT, lightPosition);
        break;
    default:
        break;
    }
}
