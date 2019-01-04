#ifndef KEY_H
#define KEY_H
#include <GL/glut.h>
#include <iostream>
using namespace std;


     class Key{
     public:
         bool keystate [256];
         void OnKeyPress(unsigned char key, int x, int y);
         void OnKeyUp(unsigned char key, int x, int y);

     };




#endif // KEY_H
