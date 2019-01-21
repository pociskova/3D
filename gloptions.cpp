#include "gloptions.h"

void pushTransformationMatrix()
{
    glPushMatrix();
}

void popTransformationMatrix()
{
    glPopMatrix();
}

void GLOptions::aliasingOnLine()
{
    glEnable(GL_LINE_SMOOTH);
}

void GLOptions::aliasingOffLine()
{
    glDisable(GL_LINE_SMOOTH);
}

void GLOptions::aliastingOnPoints()
{
    glEnable(GL_POINT_SMOOTH);
}

void GLOptions::aliasingOffPoints()
{
    glDisable(GL_POINT_SMOOTH);
}

void GLOptions::shadeModelFlat()
{
    glShadeModel( GL_FLAT );
}

void GLOptions::shadeModelSmooth()
{
    glShadeModel( GL_SMOOTH );
}

void GLOptions::frontFaceClockDirection()
{
    glFrontFace(GL_CW);
}

void GLOptions::frontFaceContraryClockDirection()
{
    glFrontFace(GL_CCW);
}

void GLOptions::setFrontPolygonMode(int mode)
{
    switch(mode)
    {
    case LINE:
        glPolygonMode(GL_FRONT, GL_LINE);
        break;
    case POINT:
        glPolygonMode(GL_FRONT, GL_POINT);
        break;
    case FILL:
        glPolygonMode(GL_FRONT, GL_FILL);
        break;
    default:
        break;
    }

}

void GLOptions::setBackPolygonMode(int mode)
{
    switch(mode)
    {
    case LINE:
        glPolygonMode(GL_BACK, GL_LINE);
        break;
    case POINT:
        glPolygonMode(GL_BACK, GL_POINT);
        break;
    case FILL:
        glPolygonMode(GL_BACK, GL_FILL);
        break;
    default:
        break;
    }
}

void GLOptions::setFrontAndBackPolygonMode(int mode)
{
    switch(mode)
    {
    case LINE:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
    case POINT:
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        break;
    case FILL:
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    default:
        break;
    }
}

void GLOptions::setFrontCullFace()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

}

void GLOptions::setBackCullFace()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void GLOptions::setFrontAndBackCullFace()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT_AND_BACK);
}

void GLOptions::setEdgeFlag(bool state)
{
    if(state == true)
        glEdgeFlag(GL_TRUE);
    else
        glEdgeFlag(GL_FALSE);
}

void GLOptions::setFrontMaterial(int mode, GLfloat color)
{
    switch(mode)
    {
    case AMBIENT:
        glMaterialf(GL_FRONT, GL_AMBIENT, color);
        break;
    case DIFFUSE:
        glMaterialf(GL_FRONT, GL_DIFFUSE, color);
        break;
    case SPECULAR:
        glMaterialf(GL_FRONT, GL_SPECULAR, color);
        break;
    case AMBIENT_AND_DIFFUSE:
        glMaterialf(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        break;
    case SHININESS:
        glMaterialf(GL_FRONT, GL_SHININESS, color);
        break;
    case EMISSION:
        glMaterialf(GL_FRONT, GL_EMISSION, color);
        break;
    default:
        break;
    }

}

void GLOptions::setBackMaterial(int mode, GLfloat color)
{
    switch(mode)
    {
    case AMBIENT:
        glMaterialf(GL_BACK, GL_AMBIENT, color);
        break;
    case DIFFUSE:
        glMaterialf(GL_BACK, GL_DIFFUSE, color);
        break;
    case SPECULAR:
        glMaterialf(GL_BACK, GL_SPECULAR, color);
        break;
    case AMBIENT_AND_DIFFUSE:
        glMaterialf(GL_BACK, GL_AMBIENT_AND_DIFFUSE, color);
        break;
    case SHININESS:
        glMaterialf(GL_BACK, GL_SHININESS, color);
        break;
    case EMISSION:
        glMaterialf(GL_BACK, GL_EMISSION, color);
        break;
    default:
        break;
    }
}

void GLOptions::setFrontAndBackMaterial(int mode, GLfloat color)
{
    switch(mode)
    {
    case AMBIENT:
        glMaterialf(GL_FRONT_AND_BACK, GL_AMBIENT, color);
        break;
    case DIFFUSE:
        glMaterialf(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
        break;
    case SPECULAR:
        glMaterialf(GL_FRONT_AND_BACK, GL_SPECULAR, color);
        break;
    case AMBIENT_AND_DIFFUSE:
        glMaterialf(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
        break;
    case SHININESS:
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, color);
        break;
    case EMISSION:
        glMaterialf(GL_FRONT_AND_BACK, GL_EMISSION, color);
        break;
    default:
        break;
    }
}

void trackingFrontMaterial(int mode)
{
    switch(mode)
    {
    case AMBIENT:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_AMBIENT);
        break;
    case DIFFUSE:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_DIFFUSE);
        break;
    case SPECULAR:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_SPECULAR);
        break;
    case AMBIENT_AND_DIFFUSE:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        break;
    case SHININESS:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_SHININESS);
        break;
    case EMISSION:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT, GL_EMISSION);
        break;
    default:
        break;
    }
}

void trackingBackMaterial(int mode)
{
    switch(mode)
    {
    case AMBIENT:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_BACK, GL_AMBIENT);
        break;
    case DIFFUSE:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_BACK, GL_DIFFUSE);
        break;
    case SPECULAR:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_BACK, GL_SPECULAR);
        break;
    case AMBIENT_AND_DIFFUSE:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_BACK, GL_AMBIENT_AND_DIFFUSE);
        break;
    case SHININESS:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_BACK, GL_SHININESS);
        break;
    case EMISSION:
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_BACK, GL_EMISSION);
        break;
    default:
        break;
    }
}

void trackingFrontAndBackMaterial(int mode)
{
    switch(mode)
    {
    case AMBIENT:
         glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
        break;
    case DIFFUSE:
         glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
        break;
    case SPECULAR:
         glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
        break;
    case AMBIENT_AND_DIFFUSE:
         glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        break;
    case SHININESS:
         glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_SHININESS);
        break;
    case EMISSION:
         glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
        break;
    default:
        break;
    }
}

void setGlobalLightLocalViewer(GLfloat value)
{
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, value);
}

void setGlobalLightTwoSide(GLfloat value)
{
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, value);
}

void setGlobalLightAmbient(GLfloat value)
{
    glLightModelf(GL_LIGHT_MODEL_AMBIENT, value);
}

void saveLightState()
{
    glPushAttrib(GL_LIGHTING_BIT);
}

void readLightState()
{
    glPopAttrib();
}
