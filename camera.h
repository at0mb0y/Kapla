#ifndef CAMERA_INCLUDED

#define CAMERA_INCLUDED
// header SFML
#include <SFML/Window.hpp>

// header Bullet physics
#include "btBulletDynamicsCommon.h"
#include "Kapla.h"
#include "Cursor.h"

class Camera

{
    public:
    Camera();
    void set(unsigned int deltaX, unsigned int deltaY);
    
    //idéalement il faudrait que en fonction du point de vue de la caméra elle zoom et dézome pour voir l'ensemble des kapla
    
    //en fonction du point de vue il ya un plan invisible sur lequel se dépace le curseur
    void extendScene(float nX,float mX, float nY, float mY);
private:
    double sceneBoxX;
    double sceneBoxY;
    double sceneBoxZ;
    double sceneBoxCenterX;
    double sceneBoxCenterY;
    double sceneBoxCenterZ;
    
};

    

#endif // CAMERA_INCLUDED