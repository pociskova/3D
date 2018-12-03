#include "camera.h"
void Camera::ustawWspolrzedne()
{

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
}

void Camera::ustawKamere()
{
    gluLookAt(player.pos.x,player.pos.y,player.pos.z,player.pos.x+player.dir.x,player.pos.y+player.dir.y,player.pos.z+player.dir.z,0,1,0);
}
