#include "engine.h"

#include "key.h"
#include "camera.h"

template <typename E>
constexpr  typename std::underlying_type<E>::type underlying_cast(E e)
{
   return static_cast<typename std::underlying_type<E>::type>(e);
}


void Engine::Init(int argc, char * argv[],const char* name, int wx, int wy, int width, int height)
{
    // inicjalizacja biblioteki GLUT
    glutInit(&argc,argv);
    // kolory podawane jako składowe RGB,
    // okno z podwójnym buforowaniem
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    // rozmiar okna 300x300 punktów
    glutInitWindowSize(width,height);
    // początkowe położenie okna
    glutInitWindowPosition(wx,wy);
    // otwarcie okna
    glutCreateWindow(name);

    w=width;
    h=height;
    // ustawienie wartości jakimi będą wypełniane
    // bufory kolorów w trakcie czyszczenia
    glClearColor(0,0,0,0);

}

void Engine::errorHandling(const char * errorLocation)
{
    unsigned int gle = glGetError();

    if (gle != GL_NO_ERROR)
    {
        cout << "GL Error discovered from caller " << errorLocation << ": ";

        switch (gle)
        {
        case GL_INVALID_ENUM:
            cout << "Invalid enum." << endl;
            break;

        case GL_INVALID_VALUE:
            cout << "Invalid value.\n";
            break;

        case GL_INVALID_OPERATION:
            cout << "Invalid Operation.\n";
            break;

        case GL_STACK_OVERFLOW:
            cout << "Stack overflow.\n";
            break;

        case GL_STACK_UNDERFLOW:
            cout << "Stack underflow.\n";
            break;

        case GL_OUT_OF_MEMORY:
            cout << "Out of memory.\n";
            break;
        default:
            cout << "Unknown error! Enum code is: " << gle << endl;
            break;

        } // End of switch

    } // End of if error detected

} // End of chechGLError function


void Engine::display()
{

    // kolor tła - zawartość bufora koloru
        glClearColor( 1.0, 1.0, 1.0, 1.0 );

        // czyszczenie bufora koloru
        glClear( GL_COLOR_BUFFER_BIT );




        // wybór macierzy modelowania
        glMatrixMode( GL_MODELVIEW );


        // macierz modelowania = macierz jednostkowa
        glLoadIdentity();

        // przesunięcie układu współrzędnych obiektu do środka bryły odcinania
        glTranslatef( 0, 0, -( near + far ) / 2 );

        // przesunięcie obiektu - ruch myszką
        glTranslatef( translatex, translatey, translatez );

        // skalowanie obiektu - klawisze "+" i "-"
       // glScalef( scale, scale, scale );

        // obroty obiektu - klawisze kursora
        //glRotatef( rotatex, 1.0, 0, 0 );
        //glRotatef( rotatey, 0, 1.0, 0 );

        // kolor krawędzi obieusing namespace std;ktu
        glColor3f( 0.0, 0.0, 0.0 );

           c.ustawKamere();


        auto myTexture = textureFactory.createTexture();
        textureFactory.LoadTGATexture("/home/ola/Pulpit/tex0.tga");

        float xPlane[] = {1.0f, 0.0f, 0.0f, 0.0f};
        float yPlane[] = {0.0f, 1.0f, 0.0f, 0.0f};
        float zPlane[] = {0.0f, 0.0f, 1.0f, 0.0f};

        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
        glTexGeni(GL_R, GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);

        glTexGenfv(GL_S,GL_OBJECT_PLANE,xPlane);
        glTexGenfv(GL_T,GL_OBJECT_PLANE,yPlane);
        glTexGenfv(GL_R,GL_OBJECT_PLANE,zPlane);pp

        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
 //       glScale(0.5f,0.5f,0.5f);
      //  glTranslate(0.5f,0.5f,0.5f);




        // rysowanie obiektu
     //   glutSolidCone( 1.0, 2.0, 10, 10 );
        glutSolidCube(2.0);
//        glBegin(GL_TRIANGLES);
//        glTexCoord2f(0.1f, 0.0f);
//        glVertex3f(0.0f,0.0f,0.0f);
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(2.0f,0.0f,0.0f);
//        glTexCoord2f(0.1f, 1.0f);
//        glVertex3f(0.0f,-2.0f,0.0f);
//        glEnd();


        // skierowanie poleceń do wykonania
        glFlush();

        // zamiana buforów koloru
        glutSwapBuffers();

}
void Engine::Reshape( int width, int height )
{

    // obszar renderingu - całe okno
    glViewport( 0, 0, width, height );

    // wybór macierzy rzutowania
    glMatrixMode( GL_PROJECTION );

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity();

    // parametry bryły obcinania
    if( aspect == Settings::ASPECT_1_1 )
    {
        // wysokość okna większa od szerokości okna
        if( width < height && width > 0 )
             glFrustum( left, right, bottom * height / width, top * height / width, near, far );
        else

        // szerokość okna większa lub równa wysokości okna
        if( width >= height && height > 0 )
             glFrustum( left * width / height, right * width / height, bottom, top, near, far );

    }
    else
    {
         glFrustum( left, right, bottom, top, near, far );
    }
    // generowanie sceny 3d
    display();
}
void Engine::ortho(int width, int height)
{
    glOrtho( left * width / height, right * width / height, bottom, top, near, far );

}
void Engine::perspective(int width, int height)
{
   glFrustum( left * width / height, right * width / height, bottom, top, near, far );

}
void Engine::ReshapeOrtho( int width, int height )
{

    // obszar renderingu - całe okno
    glViewport( 0, 0, width, height );

    // wybór macierzy rzutowania
    glMatrixMode( GL_PROJECTION );

    // macierz rzutowania = macierz jednostkowa
    glLoadIdentity();

    // parametry bryły obcinania
    if( aspect == Settings::ASPECT_1_1 )
    {
        // wysokość okna większa od szerokości okna
        if( width < height && width > 0 )
             glOrtho( left, right, bottom * height / width, top * height / width, near, far );
        else

        // szerokość okna większa lub równa wysokości okna
        if( width >= height && height > 0 )
             glOrtho( left * width / height, right * width / height, bottom, top, near, far );

    }
    else
    {
         glOrtho( left, right, bottom, top, near, far );
    }
    // generowanie sceny 3D
    c.refresh();
    display();
}



void Engine::handleOption(const Settings currentOption)
{
    aspect = currentOption;
    switch( currentOption )
    {
        // obszar renderingu - całe okno
      case Settings::FULL_WINDOW:
         glutFullScreen();
        Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );
        break;

   // obszar renderingu - aspekt 1:1
      case Settings::ASPECT_1_1:
        glutReshapeWindow(w,h);

        Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );
        break;
    case Settings::PERSPECTIVE:
     Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ));
      break;

    case Settings::ORTHO:
      ReshapeOrtho( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ));
      break;
        // wyjście
       case Settings::EXIT:
        exit( 0 );
    }
}


void Engine::Menu( int value )
{
    currentShape = static_cast<Shape>(value);
    if (currentShape < Shape::LAST)
    {
       glShadeModel( GL_SMOOTH);
        display();
    }
    else
    {
        handleOption(static_cast<Settings>(value));
    }
}
void Engine::Keyboard( unsigned char key, int x, int y )
{
    cout<<"obsluguje klawiature"<<endl;
   switch (key)
    {
    case '+' :
        scale += 0.1;
        break;
    case '-' :
        if(scale > 0.1 )
             scale -= 0.1;
        break;
    case 'w' :
        translatey += 1.0;
        cout<<"naciskam x"<<translatey<<endl;
        break;
    case 's' :
        if(translatey > 1.0)
             translatey -=1.0;
        break;
    case 'd' :
        translatex += 1.0;
        break;
    case 'a' :
        if(translatex > 1.0)
             translatex -=1.0;
        break;
    }

    // odrysowanie okna
    Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );
}



// obsługa klawiszy funkcyjnych i klawiszy kursora

void Engine::SpecialKeys( int key, int x, int y )
{
    switch( key )
    {
        // kursor w lewo
//    case GLUT_KEY_LEFT:
//        rotatey -= 1;
//        break;
//        // kursor w górę
//    case GLUT_KEY_UP:
//        rotatex -= 1;
//        break;
//        // kursor w prawo
//    case GLUT_KEY_RIGHT:
//        rotatey += 1;
//        break;
//        // kursor w dół
//    case GLUT_KEY_DOWN:
//        rotatex += 1;
//        break;
    case GLUT_KEY_UP :
        translatey += 0.1;

        break;
    case  GLUT_KEY_DOWN :
        translatey -=0.1;
        break;
    case GLUT_KEY_RIGHT :
        translatex += 0.1;
        break;
    case GLUT_KEY_LEFT :
        translatex -=0.1;
    case GLUT_KEY_F1 :
        c.angle -= 0.01f;
        c.lx = sin(c.angle);
        c.lz = -cos(c.angle);
        break;
    case GLUT_KEY_F2 :
        c.angle += 0.01f;
        c.lx = sin(c.angle);
        c.lz = -cos(c.angle);
        break;
    case GLUT_KEY_F3 :
        c.x += c.lx * 0.1f;
        c.z += c.lz * 0.1f;
        break;
    case GLUT_KEY_F4 :
        c.x -= c.lx * 0.1f;
        c.z -= c.lz * 0.1f;
        break;
    case GLUT_KEY_F11 :
        scale += 0.1;
        break;
    case GLUT_KEY_F12 :
        if(scale > 0.1 )
             scale -= 0.1;
        break;
    }

    // odrysowanie okna
    Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );
}

// obsługa przycisków myszki

void Engine::MouseButton( int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON )
    {
        // zapamiętanie stanu lewego przycisku myszki
        button_state = state;

        // zapamiętanie położenia kursora myszki
        if( state == GLUT_DOWN )
        {
            button_x = x;
            button_y = y;
        }
    }
}

// obsługa ruchu kursora myszki

void Engine::MouseMotion( int x, int y )
{
    if( button_state == GLUT_DOWN )
    {
//        translatex += 1.1 *( right - left ) / glutGet( GLUT_WINDOW_WIDTH ) *( x - button_x );
//        button_x = x;
//        translatey += 1.1 *( top - bottom ) / glutGet( GLUT_WINDOW_HEIGHT ) *( button_y - y );
//        button_y = y;

                translatez += 1.1 *( right - left ) / glutGet( GLUT_WINDOW_WIDTH ) *( x - button_x );
                button_x = x;
                translatez += 1.1 *( top - bottom ) / glutGet( GLUT_WINDOW_HEIGHT ) *( button_y - y );
                button_y = y;
        glutPostRedisplay();
        Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );
    }
}
void Engine::set(void (* menuHandler)( int menu ))
{

    top = 10.0;
    left = - 10.0;
    right = 10.0;
    bottom = - 10.0;

    // rozmiary bryły obcinania
    near = 50.0;
    far = 120.0;
    scale = 1.0;

    // kąty obrotu i przesuniecie
    rotatex = 0.0;
    rotatey = 0.0;
    translatex = 0.0;
    translatey = 0.0;

   // wskaźnik naciśnięcia lewego przycisku myszki
    button_state = GLUT_UP;

   // utworzenie podmenu
    //auto menuObjectWire = glutCreateMenu( menuHandler );
    //glutAddMenuEntry( "Kula", underlying_cast(Shape::WIRE_SPHERE) );

    // menu główne
    glutCreateMenu(menuHandler );
   // glutAddSubMenu( "Operacja", menuObjectWire );
    glutAddMenuEntry( "Wyjscie", underlying_cast(Settings::EXIT) );
    // określenie przycisku myszki obsługującego menu podręczne
    glutAttachMenu( GLUT_RIGHT_BUTTON );
}

void Engine::cleanColor()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::cleanDepth()
{
     glClear(GL_DEPTH_BUFFER_BIT);
}

void Engine::cleanAccum()
{
     glClear(GL_ACCUM_BUFFER_BIT);
}
void Engine::cleanStencil()
{
     glClear(GL_STENCIL_BUFFER_BIT);
}
