#include "key.h"


void Key::OnKeyPress(unsigned char key, int x, int y)
{
    keystate [key] = true;
}
void Key::OnKeyUp(unsigned char key, int x, int y)
{
    keystate[key] = false;
}
