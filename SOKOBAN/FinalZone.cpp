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
 
    // �������� ���������� �� ������ ����
    float cubeX = cube.GetX();
    float cubeY = cube.GetY();
    float cubeSize = 1.5;
   
    // ����������, �� ����������� ��� � ����� �������� ����
    if (cubeX >= x - cubeSize && cubeX <= x + cubeSize &&
        cubeY >= y - cubeSize && cubeY <= y + cubeSize)
    {
        collision = true;
        return collision;
    }
    else
    {
        collision = false; // ������ �������� ���糿, ���� ��� ������� ����
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

    // ������������ �������
    glColor3f(red, green, blue);

    // ����� ����������
    float size = 3;

    // ������������ ��������� �� ������ ����������
    float left = x - size;
    float right = x + size;
    float bottom = y - size;
    float top = y + size;

    // ��������� ����������
    glBegin(GL_QUADS);
    glVertex3f(left, bottom, z);
    glVertex3f(right, bottom, z);
    glVertex3f(right, top, z);
    glVertex3f(left, top, z);
    glEnd();
}