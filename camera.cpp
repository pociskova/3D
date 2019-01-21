#include "camera.h"
void Camera::ustawWspolrzedne()
{
    player.pos={0.0f, 0.0f, 0.0f};
    player.dir={0.0f, 1.0f, 0.0f};

if(k.keystate ['w']) {
player.pos.x += player.dir.x * player.speed;
player.pos.y += player.dir.y * player.speed;
player.pos.z += player.dir.z * player.speed;
}
if(k.keystate ['s']) {
player.pos.x -= player.dir.x * player.speed;
player.pos.y -= player.dir.y * player.speed;
player.pos.z -= player.dir.z * player.speed;
}
if(k.keystate ['d']) {
player.pos.x += (-player.dir.z)* player.speed;
player.pos.y += 0* player.speed;
player.pos.z += player.dir.x * player.speed;
}
if(k.keystate ['a']) {
player.pos.x -=  (-player.dir.z)* player.speed;
player.pos.y -= 0* player.speed;
player.pos.z -= player.dir.x * player.speed;
}
ustawKamere();
}

void Camera::ustawKamere()
{
    //gluLookAt(player.pos.x,player.pos.y,player.pos.z,player.pos.x+player.dir.x,player.pos.y+player.dir.y,player.pos.z+player.dir.z,0,1,0);
    gluLookAt(	x, 1.0f, z,
                x+lx, 1.0f,  z+lz,
                0.0f, 1.0f,  0.0f);
}

  void Camera::refresh()
  {
      angle=0.0;
          // actual vector representing the camera's direction
          lx=0.0f;
          lz=-1.0f;
          // XZ position of the camera
          x=0.0f;
          z=5.0f;
  }

void Camera::processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_F1 :
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_F2 :
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_F3 :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_F4 :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }
}
