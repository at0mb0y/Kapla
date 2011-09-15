#ifndef DEF_CURSOR
#define DEF_CURSOR
#include "btBulletDynamicsCommon.h"
#include <SFML/Window.hpp>

//dessine le kapla en ghost, reçoit les input du clavier et met à jour
//
class Cursor

{
	public:
    Cursor();
    void drawKapla(unsigned int x, unsigned int y, unsigned int z);
    void set(unsigned int MouseX, unsigned int MouseY);
private:
    int m_x;
    int m_y;
    int m_z;
    int m_ori;
    int m_sens;
	
};


#endif