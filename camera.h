#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include <iostream>
using namespace std;
#include "key.h"

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

class Camera{
public:
    void ustawWspolrzedne();
    void ustawKamere();
    Key k;
 private:
    SCameraState player;

};
#endif // CAMERA_H
