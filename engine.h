#pragma once

#include <GL/glut.h>
#include <iostream>
using namespace std;
#include "key.h"
#include "camera.h"

enum class Shape : int
{
    WIRE_SPHERE , // kula
    WIRE_CONE, // stożek
    WIRE_CUBE, // sześcian
    WIRE_TORUS, // torus
    WIRE_DODECAHEDRON, // dwunastościan
    WIRE_TEAPOT, // czajnik
    WIRE_OCTAHEDRON, // ośmiościan
    WIRE_TETRAHEDRON, // czworościan
    WIRE_ICOSAHEDRON, // dwudziestościan
    LAST
};

enum class Settings : int
{
    FULL_WINDOW = 100, // aspekt obrazu - całe okno
    ASPECT_1_1, // aspekt obrazu 1:1
    EXIT   // wyjście
 };

//struct vec3
//{
//    float x, y, z;
//};

class Engine{
public:

void Init(int argc, char * argv[],const char* name, int wx, int wy, int width, int height);
void display(Shape shape);
void Reshape( int width, int height );
void skalowanie(int s, int w);
void obroty(void);
void set(void (* menuHandler)( int menu ));
void Menu( int value );
void MouseMotion( int x, int y );
void MouseButton( int button, int state, int x, int y );
void SpecialKeys( int key, int x, int y );
void Keyboard( unsigned char key, int x, int y );
void glutDisplay();


 float kat;
 Settings aspect = Settings::FULL_WINDOW;

// rodzaj obiektu
 Shape currentShape = Shape::WIRE_CONE;

// rozmiary bryły obcinania

 GLdouble left ;
 GLdouble right ;
 GLdouble bottom ;
 GLdouble top ;
 GLdouble near;
 GLdouble far;

// współczynnik skalowania

GLfloat scale;

// kąty obrotu

GLfloat rotatex ;
GLfloat rotatey ;

// przesunięcie

GLfloat translatex;
GLfloat translatey ;

// wskaźnik naciśnięcia lewego przycisku myszki

int button_state ;

// położenie kursora myszki

int button_x, button_y;


private:
void handleOption(const Settings currentOption);
};

