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


void Engine::display(Shape shape)
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
        glTranslatef( translatex, translatey, 0.0 );

        // skalowanie obiektu - klawisze "+" i "-"
        glScalef( scale, scale, scale );

        // obroty obiektu - klawisze kursora
        glRotatef( rotatex, 1.0, 0, 0 );
        glRotatef( rotatey, 0, 1.0, 0 );

        // kolor krawędzi obieusing namespace std;ktu
        glColor3f( 0.0, 0.0, 0.0 );
        c.ustawKamere();
        // rysowanie obiektu
        switch( shape )
        {
            // kula
        case Shape::WIRE_SPHERE:
            glutWireSphere( 1.0, 200, 100 );
            break;

            // stożek
        case Shape::WIRE_CONE:
            glutWireCone( 1.0, 2.0, 20, 10 );
            break;

            // sześcian
        case Shape::WIRE_CUBE:
            glutWireCube( 1.0 );
            break;

            // torus
        case Shape::WIRE_TORUS:
            glutWireTorus( 0.2, 1, 10, 20 );
            break;

            // dwunastościan
        case Shape::WIRE_DODECAHEDRON:
            glutWireDodecahedron();
            break;

            // czajnik
        case Shape::WIRE_TEAPOT:
            glutWireTeapot( 1.0 );
            break;

            // ośmiościan
        case Shape::WIRE_OCTAHEDRON:
            glutWireOctahedron();
            break;

            // czworościan
        case Shape::WIRE_TETRAHEDRON:
            glutWireTetrahedron();
            break;

            // dwudziestościan
        case Shape::WIRE_ICOSAHEDRON:
            glutWireIcosahedron();
            break;

            //KULA
        case Shape::SOLID_SPHERE:
            glutSolidSphere( 1.0, 20, 10 );
            break;

            // stożek
        case Shape::SOLID_CONE:
            glutSolidCone( 1.0, 2.0, 20, 10 );
            break;

            // sześcian
        case Shape::SOLID_CUBE:
            glutSolidCube( 1.0 );
            break;

            // torus
        case Shape::SOLID_TORUS:
            glutSolidTorus( 0.2, 1, 10, 20 );
            break;

            // dwunastościan
        case Shape::SOLID_DODECAHEDRON:
            glutSolidDodecahedron();
            break;

            // czajnik
        case Shape::SOLID_TEAPOT:
            glutSolidTeapot( 1.0 );
            break;

            // ośmiościan
        case Shape::SOLID_OCTAHEDRON:
            glutSolidOctahedron();
            break;

            // czworościan
        case Shape::SOLID_TETRAHEDRON:
            glutSolidTetrahedron();
            break;

            // dwudziestościan
        case Shape::SOLID_ICOSAHEDRON:
            glutSolidIcosahedron();
            break;
        case Shape::LAST:
            exit(-1);
        }


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
    display(currentShape);
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
    display(currentShape);
}
void Engine::skalowanie(int s, int w)
{
    // zestaw funkcji ustalających sposób rzutowania,
    // zakresy współrzędnych x,y widocznych w oknie
    // oraz zerujących macierze przekształceń
    glViewport(0,0,s,w);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (s<=w) glOrtho(-1000,1000,-1000*(w/s),1000*(w/s),-1000,1000);
    else glOrtho(-1000*(s/w),1000*(s/w),-1000,1000,-1000,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Engine::obroty(void)
{
    // zwiększenie kąta o 5 stopni po wykryciu
    // bezczynności systemu
    if (kat==360) kat=0;
    kat+=5;
    // wymuszenie ponownego przerysowania okna
    glutPostRedisplay();
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
        display(currentShape);
    }
    else
    {
        handleOption(static_cast<Settings>(value));
    }
}
void Engine::Keyboard( unsigned char key, int x, int y )
{
    // klawisz +
    if( key == '+' )
         scale += 0.1;
    else

    // klawisz -
    if( key == '-' && scale > 0.1 )
         scale -= 0.1;
//    switch (key)
//    {
//    case 'd' :
//        c.angle -= 0.01f;
//        c.lx = sin(c.angle);
//        c.lz = -cos(c.angle);
//        break;
//    case 'a' :
//        c.angle += 0.01f;
//        c.lx = sin(c.angle);
//        c.lz = -cos(c.angle);
//        break;
//    case 'w' :
//        c.x += c.lx * 0.1f;
//        c.z += c.lz * 0.1f;
//        break;
//    case 's' :
//        c.x -= c.lx * 0.1f;
//        c.z -= c.lz * 0.1f;
//        break;
//       }

    // odrysowanie okna
    Reshape( glutGet( GLUT_WINDOW_WIDTH ), glutGet( GLUT_WINDOW_HEIGHT ) );

}

void Engine::glutDisplay()
{
    display(currentShape);
}

// obsługa klawiszy funkcyjnych i klawiszy kursora

void Engine::SpecialKeys( int key, int x, int y )
{
    switch( key )
    {
        // kursor w lewo
    case GLUT_KEY_LEFT:
        rotatey -= 1;
        break;

        // kursor w górę
    case GLUT_KEY_UP:
        rotatex -= 1;
        break;

        // kursor w prawo
    case GLUT_KEY_RIGHT:
        rotatey += 1;
        break;

        // kursor w dół
    case GLUT_KEY_DOWN:
        rotatex += 1;
        break;


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
        translatex += 1.1 *( right - left ) / glutGet( GLUT_WINDOW_WIDTH ) *( x - button_x );
        button_x = x;
        translatey += 1.1 *( top - bottom ) / glutGet( GLUT_WINDOW_HEIGHT ) *( button_y - y );
        button_y = y;
        glutPostRedisplay();
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
    far = 70.0;
    scale = 1.0;

    // kąty obrotu i przesuniecie
    rotatex = 0.0;
    rotatey = 0.0;
    translatex = 0.0;
    translatey = 0.0;

   // wskaźnik naciśnięcia lewego przycisku myszki
    button_state = GLUT_UP;

    auto menuAspect = glutCreateMenu( menuHandler );
    glutAddMenuEntry( "1x1", underlying_cast(Settings::ASPECT_1_1) );
    glutAddMenuEntry( "fullscreen", underlying_cast(Settings::FULL_WINDOW) );

    //utworzenie podmenu rzutowanina
    auto menuPerspetive = glutCreateMenu( menuHandler );
    glutAddMenuEntry( "perspektywistyczne", underlying_cast(Settings::PERSPECTIVE) );
    glutAddMenuEntry( "ortogonalne", underlying_cast(Settings::ORTHO) );
   // utworzenie podmenu - obiekty wire
    auto menuObjectWire = glutCreateMenu( menuHandler );
    glutAddMenuEntry( "Kula", underlying_cast(Shape::WIRE_SPHERE) );
    glutAddMenuEntry( "Stozek", underlying_cast(Shape::WIRE_CONE) );
    glutAddMenuEntry( "Szescian", underlying_cast(Shape::WIRE_CUBE) );
    glutAddMenuEntry( "Torus", underlying_cast(Shape::WIRE_TORUS) );
    glutAddMenuEntry( "Dwunastoscian", underlying_cast(Shape::WIRE_DODECAHEDRON) );
    glutAddMenuEntry( "Czajnik", underlying_cast(Shape::WIRE_TEAPOT) );
    glutAddMenuEntry( "Osmioscian", underlying_cast(Shape::WIRE_OCTAHEDRON) );
    glutAddMenuEntry( "Czworoscian", underlying_cast(Shape::WIRE_TETRAHEDRON) );
    glutAddMenuEntry( "Dwudziestoscian", underlying_cast(Shape::WIRE_ICOSAHEDRON) );


  // utworzenie podmenu - obiekty solid
    auto menuObjectSolid = glutCreateMenu( menuHandler );
    glutAddMenuEntry( "Kula", underlying_cast(Shape::SOLID_SPHERE) );
    glutAddMenuEntry( "Stozek", underlying_cast(Shape::SOLID_CONE) );
    glutAddMenuEntry( "Szescian", underlying_cast(Shape::SOLID_CUBE) );
    glutAddMenuEntry( "Torus", underlying_cast(Shape::SOLID_TORUS) );
    glutAddMenuEntry( "Dwunastoscian", underlying_cast(Shape::SOLID_DODECAHEDRON) );
    glutAddMenuEntry( "Czajnik", underlying_cast(Shape::SOLID_TEAPOT) );
    glutAddMenuEntry( "Osmioscian", underlying_cast(Shape::SOLID_OCTAHEDRON) );
    glutAddMenuEntry( "Czworoscian", underlying_cast(Shape::SOLID_TETRAHEDRON) );
    glutAddMenuEntry( "Dwudziestoscian", underlying_cast(Shape::SOLID_ICOSAHEDRON) );

    // menu główne
    glutCreateMenu(menuHandler );
    glutAddSubMenu( "Aspekt obrazu", menuAspect );
   // glutAddSubMenu( "Rzutowanie", menuPerspetive );
    glutAddSubMenu( "Szkieletowy", menuObjectWire );
    glutAddSubMenu( "Wypelniony", menuObjectSolid );
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
