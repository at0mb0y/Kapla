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
    Camera(float eyeRadius, float radianXY,float radianZ);
    void set();
    void set(double fromX, double fromY,double fromZ);
    void setByPolar(float eyeRadius, float radianXY, float radianZ);
    void display();

    //idéalement il faudrait que en fonction du point de vue de la caméra elle zoom et dézome pour voir l'ensemble des kapla

    //en fonction du point de vue il ya un plan invisible sur lequel se dépace le curseur
    void extendScene(float nX,float mX, float nY, float mY);
    void updateProjection();
    void zoom(float dt);
    void tumble( float dtRadianXY,  float dtRadianZ);
    void projectionMode(int mode);
private:
    float m_eyeRadius,m_radianXY,m_radianZ;
    float m_fromX,m_fromY, m_fromZ;
    float m_toX,m_toY,m_toZ;
    double sceneBoxX;
    double sceneBoxY;
    double sceneBoxZ;
    double sceneBoxCenterX;
    double sceneBoxCenterY;
    double sceneBoxCenterZ;
    double pointPrince;
    double pointOeil;
    double dist;
    const float PI;
    int m_upX,m_upY,m_upZ;



};



#endif // CAMERA_INCLUDED