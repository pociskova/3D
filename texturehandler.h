#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <GL/glut.h>
#include <iostream>

//#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "texture.h"
using namespace std;

//struct image{
//  unsigned long sizeX;
//  unsigned long sizeY;
//  char *data;
//};

typedef struct {
    GLuint bpp;		// iloć bitów na piksel
    GLuint width;	// rozmiary w pikselach
    GLuint height;
} TARGAINFO;

class TextureHandler{
public:
    Texture createTexture();
    void deleteTexture();
//     int imageLoad(const char *filename, image *image);
//      void loadGLTextures(const char *filename);

    GLubyte *LoadTGAImage(char *filename, TARGAINFO *info);
    bool LoadTGATexture(char *filename);
    bool LoadTGAMipmap(char *filename);

    Texture texture;

};

#endif // TEXTUREHANDLER_H
