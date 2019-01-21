#include "texturehandler.h"

#include <memory>

Texture TextureHandler::createTexture()
{
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, texture.getTexture());
    glBindTexture(GL_TEXTURE_2D, *texture.getTexture());
    return texture;
}

void TextureHandler::deleteTexture()
{
    glDeleteTextures(1, texture.getTexture());
}



// Procedura �aduje plik o podanej nazwie
// wype�nia podan� struktur� TARGAINFO
// oraz zwraca adres bufora z pikselami (je�li nie by�o b��du)
// Je�li by� b��d - zwraca NULL
GLubyte *TextureHandler::LoadTGAImage(char *filename, TARGAINFO *info)
{
    GLubyte	TGAHeader[12]={0,0,2,0,0,0,0,0,0,0,0,0};	// Nag��wek TGA bez kompresji
    GLubyte	TGACompare[12];			// Tu si� za�aduje dane z pliku
    GLubyte	Header[6];			// Pierwsze potrzebne 6 bajt�w z pliku
    GLubyte *Bits = NULL;	// Wska�nik na bufor z danymi pikseli

    FILE *plik = fopen(filename, "rb");	// Pr�ba otwarcia do odczytu
    if(plik)
    {
        fread(TGACompare, 1, sizeof(TGACompare), plik);	// Odczytanie nag��wka pliku
        if(memcmp(TGAHeader, TGACompare, sizeof(TGAHeader)) == 0)	// Nag��wek identyczny?
        {
            fread(Header, 1, sizeof(Header), plik);	// Odczyt u�ytecznych danych

            // Wy�uskanie informacji o rozmiarach
            info->width  = Header[1] * 256 + Header[0];
            info->height = Header[3] * 256 + Header[2];
            info->bpp = Header[4];

            // Sprawdzenie czy rozmiary > 0 oraz czy bitmapa 24 lub 32-bitowa
            if(info->width>0 && info->height>0 && (info->bpp==24 || info->bpp==32))
            {
                long ImageSize = info->height * info->width * info->bpp / 8;	// Obliczenie ilo�ci danych
                Bits = (GLubyte*)malloc(ImageSize);	// Alokacja pami�ci na dane

                if(Bits)
                {
                    fread(Bits, 1, ImageSize, plik);	// Odczyt w�a�ciwych danych pikseli z pliku

                    // Konwersja BGR -> RGB
                    int i;
                    GLubyte tmp;	// Miejsce przechowania jednej warto�ci koloru

                    for(i=0;i < ImageSize;i += info->bpp / 8)	// Wszystkie warto�ci RGB lub RGBA
                    {
                        tmp = Bits[i];
                        Bits[i] = Bits[i+2];
                        Bits[i+2] = tmp;
                    }
                }
            }
        }

        fclose(plik);
    }

    return(Bits);
}

///////////////////////////////////////////////////////////////////////////////
// Procedury na podstawie przekazanych danych �aduj�
// i tworz� tekstur� lub tekstur� z Mip-Map'ami
bool TextureHandler::LoadTGATexture(char *filename)
{
    TARGAINFO info;	// Dane o bitmapie
    GLubyte *bits;	// Dane o pikselach

    // ladowanie pliku
    bits = LoadTGAImage(filename, &info);	// Pr�ba wczytania tekstury
    if (bits == nullptr)	return false;	// ERROR

    // Ustawienie parametr�w tekstury
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    if(info.bpp == 24)	// Bitmapa z danymi RGB
        glTexImage2D(GL_TEXTURE_2D, 0, 3, info.width, info.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bits);
    else	// Bitmapa z danymi RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, 4, info.width, info.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);

    free(bits);
    return true;
}

bool TextureHandler::LoadTGAMipmap(char *filename)
{
    TARGAINFO info;	// Dane o bitmapie
    GLubyte *bits;	// Dane o pikselach

    // �adowanie pliku
    bits = LoadTGAImage(filename, &info);	// Pr�ba wczytania tekstury
    if(bits == NULL)	return(false);	// ERROR

    // Ustawienie parametr�w tekstury
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    if(info.bpp == 24)	// Bitmapa z danymi RGB
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, info.width, info.height, GL_RGB, GL_UNSIGNED_BYTE, bits);
    else	// Bitmapa z danymi RGBA
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, info.width, info.height, GL_RGBA, GL_UNSIGNED_BYTE, bits);

    free(bits);
    return(true);
}








// int TextureHandler::imageLoad(const char *filename, image *image){
//   FILE *file;
//   unsigned long size;//rozmiar pliku w bajtach
//   unsigned long i;//typ licznika
//   unsigned short int planes;//numer plaszczyzny obrazka(musi byc 1)
//   unsigned short int bpp;//przechowywanie tymczasowego koloru po konwersji bgr-rgb
//   char temp;

//   //sprawdzanie czy plik istnieje
//   if((file = fopen(filename, "rb")) == NULL){
//     printf("plik nie istnieje : %s\n", filename);
//     return 0;
//   }

//   //ustawiamy pozycje wskaznika w pliku
//   fseek(file, 18, SEEK_CUR);

//   //czytamy wysokosc
//   if((i = fread(&image->sizeX, 4, 1, file)) != 1){
//     printf("blad czytania wysokosci z pliku: %s\n", filename);
//     return 0;
//   }
//   printf("wysokosc obrazka %s: %lu\n", filename, image->sizeX);

//  //czytamy szerokosc
//   if((i = fread(&image->sizeY, 4, 1, file)) != 1){
//     printf("blad czytania szerokosci z pliku: %s\n", filename);
//     return 0;
//   }
//   printf("szerokosc obrazka %s: %lu\n", filename, image->sizeY);

//   //liczymy rozmiar(zakladamy 24 bity lub 3 bajty na pixel)
//   size = image->sizeX * image->sizeY * 3;

//   //kopiujemy 1 element pliku do tablicy
//   if((fread(&planes, 2, 1, file)) != 1){
//     printf("blad czytania plaszczyzny pliku %s.\n", filename);
//     return 0;
//   }

//   if(planes != 1){
//     printf("plaszczyzna z pliku %s nie jest 1: %u\n", filename, planes);
//     return 0;
//   }



//   //czytanie bpp
//   if((i = fread(&bpp, 2, 1, file)) != 1){
//     printf("blad czytania bpp z pliku %s.\n", filename);
//     return 0;
//   }
//   if(bpp != 24){
//     printf("Bpp z pliku %s nie jest 24: %u\n", filename, bpp);
//     return 0;
//   }

//   // seek past the rest of the bitmap header.
//   fseek(file, 24, SEEK_CUR);

//   //czytanie danych
//   image->data = (char *) malloc(size);
//   if(image->data == NULL){
//     printf("blad allokacji pamieci z poprawionych kolorow danych obrazka\n");
//     return 0;
//   }

//   if((i = fread(image->data, size, 1, file)) != 1){
//     printf("blad czytania danych obrazka z pliku %s.\n", filename);
//     return 0;
//   }

//   for(i=0;i<size;i+=3){ // odwrocenie wszystkich kolorow (bgr -> rgb)
//     temp = image->data[i];
//     image->data[i] = image->data[i+2];
//     image->data[i+2] = temp;
//   }


//   // koniec
//   return 1;
// }


// void TextureHandler::loadGLTextures(const char *filename){
//   //ladowanie tekstury
//   image *image1;

//   //allokacja przestrzeni dla tekstury
//   image1 = (image *) malloc(sizeof(image));
//   if(image1 == NULL){
//     printf("blad allokacji pamieci dla obrazka\n");
//     exit(0);
//   }

//   if(!imageLoad(filename, image1)){
//     exit(1);
//   }

//   //tworzenie tekstury
//   glGenTextures(1, texture.getTexture());
//   glBindTexture(GL_TEXTURE_2D, texture.getTexture()[0]);   // 2d texture (x and y size)

//   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
//   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

//   // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image,
//   // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
//   glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
//   free(image1);
// }
