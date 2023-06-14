#ifndef FINALZONE_H
#define FINALZONE_H

#include "3DCube.h"

class FinalZone
{
public:
    FinalZone(float x, float y, float z);
  
    
    bool CheckCollision(const Cube3D& cube) ;

    void Draw(float red, float green, float blue) const;
    bool collision;
    bool collisionHandled;
private:
    float x, y, z;


   
};

#endif // FINALZONE_H