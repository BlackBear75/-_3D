#include "FinalZone.h"
#include "gl/glut.h"
#include<iostream>
FinalZone::FinalZone(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->collision = false;
}

bool FinalZone::CheckCollision(const Cube3D& cube) 
{
 
    // Отримуємо координати та розміри куба
    float cubeX = cube.GetX();
    float cubeY = cube.GetY();
    float cubeSize = 1.5;
   
    // Перевіряємо, чи знаходиться куб у межах фінальної зони
    if (cubeX >= x - cubeSize && cubeX <= x + cubeSize &&
        cubeY >= y - cubeSize && cubeY <= y + cubeSize)
    {
        collision = true;
        return collision;
    }
    else
    {
        collision = false; // Знімаємо позначку колізії, якщо куб покинув зону
        return collision;
    }
}
void FinalZone::Draw(float red, float green, float blue) const
{

    if (collision)
    {
        red = 0;
        green = 1.0f;
       blue = 0;
    }

    // Встановлення кольору
    glColor3f(red, green, blue);

    // Розмір квадратика
    float size = 3;

    // Встановлення положення та розміру квадратика
    float left = x - size;
    float right = x + size;
    float bottom = y - size;
    float top = y + size;

    // Малювання квадратика
    glBegin(GL_QUADS);
    glVertex3f(left, bottom, z);
    glVertex3f(right, bottom, z);
    glVertex3f(right, top, z);
    glVertex3f(left, top, z);
    glEnd();
}