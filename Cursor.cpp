#include "Cursor.h"

Cursor::Cursor(int x, int y, int z, int ori, int sens)
{
    
    
	

}

void Cursor::set()
{
    
}
	
//  Une fonction pour afficher une boite à l'aide d'OpenGL
void Cursor::drawKapla(float x, float y, float z)
{
glPushMatrix();
glScalef(x,y,z);
glBegin (GL_QUADS);
//face 1
glNormal3i(-1, 1,-1);
glVertex3i(-1, 1,-1); glVertex3i( 1, 1,-1);
glVertex3i( 1,-1,-1); glVertex3i(-1,-1,-1);
//face 2
glNormal3i(-1,-1,-1);
glVertex3i(-1,-1,-1); glVertex3i( 1,-1,-1);
glVertex3i( 1,-1, 1); glVertex3i(-1,-1, 1);
// face 3
glNormal3i( 1,-1, 1);
glVertex3i( 1,-1, 1); glVertex3i( 1,-1,-1);
glVertex3i( 1, 1,-1); glVertex3i( 1, 1, 1);
//face 4
glNormal3i( 1, 1,-1);
glVertex3i( 1, 1,-1); glVertex3i(-1, 1,-1);
glVertex3i(-1, 1, 1); glVertex3i( 1, 1, 1);
//face 5
glNormal3i(-1, 1, 1);
glVertex3i(-1, 1, 1); glVertex3i(-1, 1,-1);
glVertex3i(-1,-1,-1); glVertex3i(-1,-1, 1);
//face 6
glNormal3i( 1,-1, 1);
glVertex3i( 1,-1, 1); glVertex3i( 1, 1, 1);
glVertex3i(-1, 1, 1); glVertex3i(-1,-1, 1);
glEnd();
glPopMatrix();
}
    
	
