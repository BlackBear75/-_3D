#ifndef TEXTUREWALL_H
#define TEXTUREWALL_H
#include "gl/glut.h"


class TextureWall {
public:
    TextureWall();

    void LoadTexture(const char* filename);  // Завантажує текстуру з файлу


    void DrawWall(float x, float y,float wigth, float ugol);
    
    void CreationWall(GLuint texture, GLuint texturepool, GLuint texturesky);

    unsigned int GettextureID();
   


private:
    unsigned int textureID;  // ID текстури
    
};


#endif