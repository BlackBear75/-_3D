#include "3DCube.h"
#include"gl/glut.h"
Cube3D::Cube3D() : positionX(0), positionY(0)
{
}

void Cube3D::SetPosition(float x, float y)
{
    positionX = x;
    positionY = y;
}

void Cube3D::Draw(float x,float y,float z )
{
    // Розміри куба
    float size = 1.5f;
    glEnable(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glTranslatef(x, y, z);
    glScalef(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    // Передня грань
    glVertex3f(positionX - size, positionY - size, 0.0f);
    glVertex3f(positionX + size, positionY - size, 0.0f);
    glVertex3f(positionX + size, positionY + size, 0.0f);
    glVertex3f(positionX - size, positionY + size, 0.0f);

    // Ліва грань
    glVertex3f(positionX - size, positionY - size, 0.0f);
    glVertex3f(positionX - size, positionY + size, 0.0f);
    glVertex3f(positionX - size, positionY + size, size * 2);
    glVertex3f(positionX - size, positionY - size, size * 2);

    // Задня грань
    glVertex3f(positionX + size, positionY - size, size * 2);
    glVertex3f(positionX - size, positionY - size, size * 2);
    glVertex3f(positionX - size, positionY + size, size * 2);
    glVertex3f(positionX + size, positionY + size, size * 2);

    // Права грань
    glVertex3f(positionX + size, positionY - size, 0.0f);
    glVertex3f(positionX + size, positionY + size, 0.0f);
    glVertex3f(positionX + size, positionY + size, size * 2);
    glVertex3f(positionX + size, positionY - size, size * 2);

    // Верхня грань
    glVertex3f(positionX - size, positionY + size, 0.0f);
    glVertex3f(positionX + size, positionY + size, 0.0f);
    glVertex3f(positionX + size, positionY + size, size * 2);
    glVertex3f(positionX - size, positionY + size, size * 2);

    // Нижня грань
    glVertex3f(positionX - size, positionY - size, 0.0f);
    glVertex3f(positionX + size, positionY - size, 0.0f);
    glVertex3f(positionX + size, positionY - size, size * 2);
    glVertex3f(positionX - size, positionY - size, size * 2);

    glEnd();
}
float Cube3D::GetX() const
{
    return positionX;
}

float Cube3D::GetY() const
{
    return positionY;
}


void Cube3D::CubeCollision( float &cubeX,float &cubeY)
{
    
    
    if (cubeX >= -5.2 && cubeX < 15.5 && cubeY <= 8.5 && cubeY >= 5.5)
    {

        cubeY -= 0.01f;

    }
    if (cubeX > -5.2 && cubeX < 15.5 && cubeY <= 8.6 && cubeY >= 6.6)
    {

        cubeY += 0.01f;

    }
    ////
    if (cubeY < 17 && cubeY > 6.3 && cubeX <= -5.6 && cubeX >= -6.6)
    {

        cubeX -= 0.01f;

    }
    if (cubeY < 17 && cubeY > 6.6 && cubeX <= -3.5 && cubeX >= -5.0)
    {

        cubeX += 0.01f;

    }
    /// //
    if (cubeX <= -4.6 && cubeX > -16 && cubeY <= 17.5 && cubeY >= 15.5)
    {

        cubeY -= 0.01f;

    }
    if (cubeX < -4.6 && cubeX > -16 && cubeY <= 18.6 && cubeY >= 15.6)
    {

        cubeY += 0.01f;

    }
    //////
    if (cubeY < 7.3 && cubeY > -7.3 && cubeX >= 13.5 && cubeX <= 14.8)
    {

        cubeX -= 0.01f;

    }
    if (cubeY < 7.3 && cubeY> -7.3 && cubeX >= 14.2 && cubeX <= 16.5)
    {

        cubeX += 0.01f;

    }
    ////////
    if (cubeX >= 14.8 && cubeX < 24 && cubeY <= -6.7 && cubeY >= -8.5)
    {

        cubeY -= 0.01f;

    }
    if (cubeX >= 14.8 && cubeX < 24 && cubeY <= -5.4 && cubeY >= -7.4)
    {

        cubeY += 0.01f;

    }
    //////2
    if (cubeX >= -15.5 && cubeX < 6.4 && cubeY >= -8.5 && cubeY <= -6.2)
    {

        cubeY -= 0.01f;

    }
    if (cubeX > -15.5 && cubeX < 6.4 && cubeY >= -6.7 && cubeY <= -5.4)
    {

        cubeY += 0.01f;

    }
    //
    if (cubeY < -6 && cubeY > -18 && cubeX >= 3.5 && cubeX <= 4.8)
    {

        cubeX -= 0.01f;

    }
    if (cubeY < -6 && cubeY > -18 && cubeX >= 4.8 && cubeX <= 6.5)
    {

        cubeX += 0.01f;

    }
    ////
    if (cubeY < -6 && cubeY > -24 && cubeX <= -15.6 && cubeX >= -16.5)
    {

        cubeX -= 0.01f;

    }
    if (cubeY < -6 && cubeY > -24 && cubeX <= -13.5 && cubeX >= -15.0)
    {

        cubeX += 0.01f;

    }

}