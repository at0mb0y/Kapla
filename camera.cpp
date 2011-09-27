#include "camera.h"
#include <math.h>

Camera::Camera(float eyeRadius, float radianXY,float radianZ):m_eyeRadius(eyeRadius), m_radianXY(radianXY),m_radianZ(radianZ), sceneBoxX(10), sceneBoxY(10), sceneBoxZ(10),sceneBoxCenterX(0),sceneBoxCenterY(0), sceneBoxCenterZ(0),m_fromX(0),m_fromY(10),m_fromZ(0),m_toX(0),m_toY(0),m_toZ(0),PI(3.14),m_upX(0.0),m_upY(0),m_upZ(0),pointPrince(sqrt(pow(m_fromX,2)+pow(m_fromY,2)+pow(m_fromZ,2))), pointOeil(sqrt((pow(m_toX,2)+pow(m_toY,2)+pow(m_toZ,2)))),dist  (sqrt((pow(pointPrince,2)+(pow(pointOeil,2)))))

{
    /// Initialisation d'OpenGL
	
    // Set color and depth clear value
    //glClearDepth(1.f);
	
    //glDepthMask(GL_TRUE);
    // On active la lumière 0
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
	
	// Quelques autres options OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR);
	
    glClearColor(0.7,0.7,0.7,0.f);
    glViewport( 0, 0, 800, 500 );
	
	using namespace std;
	updateProjection();
	
    
	
}

void Camera::set()
{
    m_fromX = 0;
    m_fromY = 0;
    m_fromZ = 0;
    
}

void Camera::set(double fromX, double fromY, double fromZ)
{
	
    
    m_fromX += fromX ;
    m_fromY += fromY;
    m_fromZ += fromZ;
    sceneBoxCenterX = sceneBoxX/2;
    sceneBoxCenterY = sceneBoxY/2;
    
	
	
	
	
}
void Camera::setByPolar(float eyeRadius, float radianXY , float radianZ)

{
    m_eyeRadius = eyeRadius;
    m_radianXY = radianXY;
    m_radianZ = radianZ;
    updateProjection();
}
void Camera::display()
{
    
    if (m_radianXY<0)
    {
        m_radianXY+=2*PI;
    } else if(m_radianXY>=2*PI)
    {
        m_radianXY-=2*PI;
    }
    /* check radianZ (0.0<=radianZ<=PI/2.0) */
    
    /*if(m_radianZ <= 0.0){
	 m_radianXY = 90.0;
	 m_radianZ = 0.0;
	 }else if(m_radianZ >= PI/2.0){
	 m_radianZ = PI/2.0;
	 }
     */
    /*
	 if(m_radianZ==0.0){
	 m_upX=0;
	 m_upY=1;
	 m_upZ=0;
	 }else{
	 m_upX=0;
	 m_upY=0;
	 m_upZ=-1;
	 } */
	
    m_upX=0;
    m_upY=0;
    m_upZ=-1;
    /* look at */
    m_fromX =m_eyeRadius*sin(m_radianZ)*cos(m_radianXY);
    m_fromY =m_eyeRadius*sin(m_radianZ)*sin(m_radianXY);  
    m_fromZ =m_eyeRadius*cos(m_radianZ);  
    m_toX=0.0;  
    m_toY=0.0;  
    m_toZ=0.0; 
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( m_eyeRadius, 800.0/500.0, 0.1f, 1000.0f );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    pointPrince = sqrt(pow(m_fromX,2)+pow(m_fromY,2)+pow(m_fromZ,2));
    pointOeil = sqrt((pow(m_toX,2)+pow(m_toY,2)+pow(m_toZ,2)));
    dist = sqrt((pow(pointPrince,2)+(pow(pointOeil,2))));
    
    
    gluLookAt(m_fromX,m_fromY,m_fromZ,m_toX,m_toY,m_toZ,m_upX,m_upY,m_upZ);
    
}
void Camera::extendScene(float nX,float mX, float nY, float mY)
{
    
}
void Camera::tumble( float dtRadianXY, float dtRadianZ)
{
    m_radianXY += dtRadianXY/dist;
    m_radianZ += -dtRadianZ/dist;
	
}

void Camera::zoom (float dt)
{
	//m_eyeRadius += dt;
    
}
void Camera::updateProjection()
{
	
	
    
}
