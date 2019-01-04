#include <GL/glut.h>
#include <stdlib.h>
#include "engine.h"

void displayFuncWrapper();
void reshapeFuncWrapper(int width, int height);
void keyboardFuncWrapper( unsigned char key, int x, int y );
void mouseButtonFuncWrapper( int button, int state, int x, int y );
void mouseMotionFuncWrapper(int x, int y );
void specialKeysFuncWrapper(int key, int x, int y );
void menuHandlerFuncWrapper(int opt);
void OneKeyPressFuncWrapper(unsigned char key, int x, int y);
void OneKeyUpFuncWrapper(unsigned char key, int x, int y);

Engine e; // obiekt globalny z powodu niekompatybilnosci interfejsow - nie ma mozliwosci rzutowania wskaznika na metode obiektu &Foo::memberFnc, do wskaznika na funkcje statyczna void(*)()
          // jednym z mozliwych rozwiazan bylo uzycie obiektu globalnego i napisanie wrapperow jako funkcji do ktorych mamy staly adres w pamieci

int main( int argc, char * argv[] )
{

    e.Init(argc,argv,"3D",300,300,600,600);
    e.set(menuHandlerFuncWrapper);

    // dołączenie funkcji generującej scenę 3D
    glutDisplayFunc( displayFuncWrapper);

    // dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
    glutReshapeFunc(reshapeFuncWrapper);

    // dołączenie funkcji obsługi klawiatury
    glutKeyboardFunc(keyboardFuncWrapper);

    // dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
    glutSpecialFunc( specialKeysFuncWrapper);

    // obsługa przycisków myszki
    glutMouseFunc( mouseButtonFuncWrapper  );

    // obsługa ruchu kursora myszki

    glutMotionFunc(mouseMotionFuncWrapper);

         glutKeyboardFunc( OneKeyPressFuncWrapper);
         glutKeyboardUpFunc(OneKeyUpFuncWrapper);




             e.c.ustawWspolrzedne();


    // wprowadzenie programu do obsługi pętli komunikatów
    glutMainLoop();
    return 0;
}

void OneKeyPressFuncWrapper(unsigned char key, int x, int y)
{
    e.k.OnKeyPress(key,  x, y);
}

void OneKeyUpFuncWrapper(unsigned char key, int x, int y)
{
     e.k.OnKeyUp(key,  x, y);
}

void displayFuncWrapper()
{
    e.glutDisplay();
}

void reshapeFuncWrapper(int width, int height)
{
    e.Reshape(width, height);
}


void keyboardFuncWrapper( unsigned char key, int x, int y )
{
    e.Keyboard(key, x, y);
}

void mouseButtonFuncWrapper( int button, int state, int x, int y )
{
    e.MouseButton(button, state, x, y);
}

void mouseMotionFuncWrapper(int x, int y )
{
    e.MouseMotion(x, y);
}

void specialKeysFuncWrapper(int key, int x, int y )
{
    e.SpecialKeys(key, x, y);
}

void menuHandlerFuncWrapper(int opt)
{
    e.Menu(opt);
}

