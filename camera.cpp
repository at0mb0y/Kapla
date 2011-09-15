#include "camera.h"
#include <math.h>

Camera::Camera():sceneBoxX(10), sceneBoxY(10), sceneBoxZ(10),sceneBoxCenterX(0),sceneBoxCenterY(0), sceneBoxCenterZ(0)
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Mode perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0f, 800.0/500.0, 0.1f, 1000.0f );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    

    

}

void Camera::set(unsigned int deltaX, unsigned int deltaY)
{

    
    sceneBoxCenterX = sceneBoxX/2;
    sceneBoxCenterY = sceneBoxY/2;
    
gluLookAt((cos(deltaX/100)*sceneBoxX),sin(deltaX/100)*sceneBoxY,(sin(deltaY/100)*sceneBoxZ),sceneBoxCenterX,sceneBoxCenterY,sceneBoxCenterZ,0,0,1);


}
void Camera::extendScene(float nX,float mX, float nY, float mY)
{
    
}