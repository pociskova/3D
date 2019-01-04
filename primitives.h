#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <GL/glut.h>
#include <vector>
#include "point3d.h"

class Primitives{

  public:
    void line(std::vector<Point3D> points);
    void brokenLine(std::vector<Point3D> points);
    void closeBrokenLine(std::vector<Point3D> points);
    void triangle(std::vector<Point3D> points);
    void triangleStrip(std::vector<Point3D> points);
    void wireSphere(GLdouble radius, GLint slices, GLint stacks);
    void wireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
    void wireCube(GLdouble size);
    void wireTorus(GLdouble innerRadius,GLdouble outerRadius, GLint nsides, GLint rings);
    void wireDodecahedron();
    void wireTeapot(GLdouble size);
    void wireOctahedron();
    void wireTetrahedron();
    void wireIcosahedron();
    void solidSphere(GLdouble radius, GLint slices, GLint stacks);
    void solidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
    void solidCube(GLdouble size);
    void solidTorus(GLdouble innerRadius,GLdouble outerRadius, GLint nsides, GLint rings);
    void solidDodecahedron();
    void solidTeapot(GLdouble size);
    void solidOctahedron();
    void solidTetrahedron();
    void solidIcosahedron();
};

#endif // PRIMITIVES_H
