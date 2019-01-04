#ifndef GLOPTIONS_H
#define GLOPTIONS_H

#include <GL/glut.h>
#include <iostream>
using namespace std;

enum modes
{
    LINE ,
    POINT ,
    FILL ,
    AMBIENT ,
    DIFFUSE ,
    SPECULAR ,
    AMBIENT_AND_DIFFUSE ,
    SHININESS ,
    EMISSION
};

class GLOptions
{
public:
    void aliasingOnLine();
    void aliasingOffLine();
    void aliastingOnPoints();
    void aliasingOffPoints();
    void shadeModelFlat();
    void shadeModelSmooth();
    void frontFaceClockDirection();
    void frontFaceContraryClockDirection();
    void setFrontPolygonMode(int mode);
    void setBackPolygonMode(int mode);
    void setFrontAndBackPolygonMode(int mode);
    void setFrontCullFace();
    void setBackCullFace();
    void setFrontAndBackCullFace();
    void setEdgeFlag(bool state);
    void setFrontMaterial(int mode, GLfloat color);
    void setBackMaterial(int mode, GLfloat color);
    void setFrontAndBackMaterial(int mode, GLfloat color);
    void trackingFrontMaterial(int mode);
    void trackingBackMaterial(int mode);
    void trackingFrontAndBackMaterial(int mode);


};

#endif // GLOPTIONS_H
