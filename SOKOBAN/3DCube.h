#ifndef CUBE3D_H
#define CUBE3D_H

class Cube3D
{
public:
    Cube3D();
    void SetPosition(float x, float y);
    void Draw(float x, float y, float z);
    float GetX() const;
    void CubeCollision(float &cubeX, float &cubeY);
    float GetY() const;
private:
    float positionX;
    float positionY;
};

#endif  // CUBE3D_H