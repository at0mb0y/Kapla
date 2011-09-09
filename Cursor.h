#ifndef DEF_CURSOR
#define DEF_CURSOR
#include "btBulletDynamicsCommon.h"

//dessine le kapla en ghost, reçoit les input du clavier et met à jour
//
class Cursor

{
	public:
    Cursor(int x, int y, int z, int ori, int sens);
    void drawKapla(int x, int y, int z);
    void set();
private:
    int x;
    int y;
    int z;
    int ori;
    int sens;
	
};


#endif