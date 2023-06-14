#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "STB_IMAGE/stb_image.h"  // Додали заголовочний файл для бібліотеки stb_image

unsigned int TextureWall::GettextureID()
{
    return textureID;
}

TextureWall::TextureWall() {
    // Ініціалізуємо ID текстури
    textureID = 0;
}

void TextureWall::LoadTexture(const char* filename) {
    int width, height, channels;

    // Завантажуємо зображення з файлу за допомогою бібліотеки stb_image
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (!image) {
        // Обробка помилки завантаження зображення
        // Можна вивести повідомлення про помилку або зупинити програму
        return;
    }

    // Генеруємо ID текстури
    glGenTextures(1, &textureID);

    // Задаємо параметри текстури
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Завантажуємо дані зображення у текстуру
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    // Звільняємо пам'ять, виділену під зображення
    stbi_image_free(image);
}


void TextureWall::DrawWall(float x,float y,float wigth,float ugol) {

  
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textureID);
    glColor4f(1.0f, 1.0f, 1.0f, 1);
    glTranslatef(x, y, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(ugol, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, 0.0f, -wigth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-5.0f, 0.0f, wigth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 0.0f, wigth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f, 0.0f, -wigth);
    glEnd();
    glPopMatrix();
}


void TextureWall::CreationWall(GLuint texture, GLuint texturepool, GLuint texturesky)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw left wall
    glPushMatrix();
    glTranslatef(-24.0f, 0.0f, 8.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -10.0f, -24.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -10.0f, 24.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 10.0f, 24.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 10.0f, -24.0f);
    glEnd();
    glPopMatrix();

    // Draw right wall
    glPushMatrix();
    glTranslatef(23.0f, 0.0f, 8.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -10.0f, -24.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -10.0f, 24.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 10.0f, 24.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 10.0f, -24.0f);
    glEnd();
    glPopMatrix();

    // Draw bottom wall
    glPushMatrix();
    glTranslatef(0.0f, -23.0f, 8.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f, -24.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f, 24.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 0.0f, 24.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 0.0f, -24.0f);
    glEnd();
    glPopMatrix();

    // Draw top wall

    glPushMatrix();
    glTranslatef(0.0f, 23.0f, 8.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f, -24.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f, 24.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 0.0f, 24.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 0.0f, -24.0f);
    glEnd();
    glPopMatrix();
    // Draw низ wall
    glBindTexture(GL_TEXTURE_2D, texturepool);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -2.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-40, 0.0f, -40);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-40, 0.0f, 40);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(40, 0.0f, 40);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(40, 0.0f, -40);
    glEnd();
    glPopMatrix();
    // Draw небо wall
    glBindTexture(GL_TEXTURE_2D, texturesky);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 24.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-40, 0.0f, -40);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-40, 0.0f, 40);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(40, 0.0f, 40);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(40, 0.0f, -40);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
