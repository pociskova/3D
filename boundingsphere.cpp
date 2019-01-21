#include "boundingsphere.h"

//BoundingSphere::BoundingSphere(vector<Point3D> points)
//{
//    findMin(points);
//    findMax(points);

//    centerPoint.setX(minX+maxX/2);
//    centerPoint.setY(minY+maxY/2);
//    centerPoint.setZ(minY+maxY/2);
//}

void BoundingSphere::setSphere(vector<Point3D> points)
{
    findMin(points);
    findMax(points);

    centerPoint.setX(minX+maxX/2);
    centerPoint.setY(minY+maxY/2);
    centerPoint.setZ(minY+maxY/2);
}

void BoundingSphere::findMin(vector<Point3D> points)
{
    minX=points[0].getX();
    minY=points[0].getY();
    minZ=points[0].getZ();
    for(unsigned int i=1 ; i < points.size() ; i++)
    {
        if(points[i].getX() < minX)
            minX=points[i].getX();

        if(points[i].getY() < minY)
            minY=points[i].getY();

        if(points[i].getZ() < minZ)
            minZ=points[i].getZ();
    }
}

void BoundingSphere::findMax(vector<Point3D> points)
{
    maxX=points[0].getX();
    maxY=points[0].getY();
    maxZ=points[0].getZ();
    for(unsigned int i=1 ; i < points.size() ; i++)
    {
        if(points[i].getX() < maxX)
            maxX=points[i].getX();

        if(points[i].getY() < maxY)
            maxY=points[i].getY();

        if(points[i].getZ() < maxZ)
            maxZ=points[i].getZ();
    }
}
