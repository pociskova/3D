#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include <iostream>
using namespace std;
#include "point3d.h"
#include "key.h"
#include <cmath>

struct vec3
{
    float x, y, z;
};
struct SCameraState
{
    vec3 pos; //pozycja
    vec3 dir;  //kierunek widzenia
    float speed;
};

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const GLfloat YAW        = -90.0f;
const GLfloat PITCH      =  0.0f;
const GLfloat SPEED      =  3.0f;
const GLfloat SENSITIVTY =  0.05f;
const GLfloat ZOOM       =  45.0f;

class Camera{
public:
    void ustawWspolrzedne();
    void ustawKamere();
    void processSpecialKeys(int key, int xx, int yy);
    void refresh();

    Key k;

    SCameraState player;
    // angle of rotation for the camera direction
    float angle=0.0;
    // actual vector representing the camera's direction
    float lx=0.0f,lz=-1.0f;
    // XZ position of the camera
    float x=0.0f,z=5.0f;


};
#endif // CAMERA_H
