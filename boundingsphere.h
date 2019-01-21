#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "point3d.h"
using namespace std;

class BoundingSphere{
public:
  // BoundingSphere(vector<Point3D> points);
   void setSphere(vector<Point3D> points);


private:
    void findMin(vector<Point3D> points);
    void findMax(vector<Point3D> points);
    Point3D centerPoint;
    GLfloat r, minX, maxX, minY, maxY, minZ, maxZ;
};

#endif // BOUNDINGSPHERE_H
