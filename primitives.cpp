#include "primitives.h"

void Primitives::line(std::vector <Point3D> points)
{
    glBegin(GL_POINTS);
    for(int i=0; i< points.size();i++)
    {
        glVertex3f(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    glEnd();
}
void Primitives::brokenLine(std::vector<Point3D> points)
{
    glBegin(GL_LINE_STRIP);
    for(int i=0; i< points.size();i++)
    {
        glVertex3f(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    glEnd();
}
void Primitives::triangle(std::vector<Point3D> points)
{
    glBegin(GL_TRIANGLES);
    for(int i=0; i< points.size();i++)
    {
        glVertex3f(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    glEnd();
}
void Primitives::triangleStrip(std::vector<Point3D> points)
{
    glBegin(GL_TRIANGLE_STRIP);
    for(int i=0; i< points.size();i++)
    {
        glVertex3f(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    glEnd();
}
void Primitives::closeBrokenLine(std::vector<Point3D> points)
{
    glBegin(GL_LINE_LOOP);
    for(int i=0; i< points.size();i++)
    {
        glVertex3f(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    glEnd();
}

void  Primitives::wireSphere(GLdouble radius, GLint slices, GLint stacks)
{
    glutWireSphere( radius, slices, stacks);
 }


void Primitives::wireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks)
{
    glutWireCone( base, height,  slices, stacks );
}

void Primitives::wireCube(GLdouble size)
{
    glutWireCube( size);
}


void Primitives::wireTorus(GLdouble innerRadius,GLdouble outerRadius, GLint nsides, GLint rings)
{
    glutWireTorus( innerRadius, outerRadius, nsides, rings );
}

void Primitives::wireDodecahedron()
{
    glutWireDodecahedron();
}

void Primitives::wireTeapot(GLdouble size)
{
    glutWireTeapot( size );
}

void Primitives::wireOctahedron()
{
    glutWireOctahedron();
}
void Primitives::wireTetrahedron()
{
    glutWireTetrahedron();
}
void Primitives::wireIcosahedron()
{
    glutWireIcosahedron();
}

 void Primitives::solidSphere(GLdouble radius, GLint slices, GLint stacks)
 {
       glutSolidSphere( radius, slices, stacks);
 }


                  void Primitives::solidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks)
                  {
                        glutSolidCone( base, height,  slices, stacks );
                  }

                    void Primitives::solidCube(GLdouble size)
                    {
                        glutSolidCube( size);
                    }


                    void Primitives::solidTorus(GLdouble innerRadius,GLdouble outerRadius, GLint nsides, GLint rings)
                    {
                        glutSolidTorus( innerRadius, outerRadius, nsides, rings );
                    }

                    void Primitives::solidDodecahedron()
                    {
                        glutSolidDodecahedron();
                    }

                    void Primitives::solidTeapot(GLdouble size)
                    {
                        glutSolidTeapot( size );
                    }

                    void Primitives::solidOctahedron()
                    {
                        glutSolidOctahedron();
                    }
                    void Primitives::solidTetrahedron()
                    {
                        glutSolidTetrahedron();
                    }
                    void Primitives::solidIcosahedron()
                    {
                        glutSolidIcosahedron();
                    }
