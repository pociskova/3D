#include "texture.h"

GLuint* Texture::getTexture()
{
    return text;
}

void Texture::textureFilter(int param, GLfloat value)
{
        switch(param)
        {
            case MIN_FILTER:
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                break;
            case MAG_FILTER:
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                break;
            case WRAP_S:
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                break;
            case WRAP_T:
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                break;
            case BORDER_COLOR:
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, value);
                break;
            case PRIORITY:
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_PRIORITY, value);
                break;
            default:
                break;
        }
}
