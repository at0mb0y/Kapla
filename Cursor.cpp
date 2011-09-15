#include "Cursor.h"

Cursor::Cursor():m_x(0),m_y(0),m_z(0),m_ori(0),m_sens(0)
{
    
    
	

}

void Cursor::set(unsigned int MouseX, unsigned int MouseY)
{
    

    glTranslatef(MouseX, MouseY, 0.f);
    
}
	
//  Une fonction pour afficher une boite à l'aide d'OpenGL
void Cursor::drawKapla(unsigned int x, unsigned int y,unsigned int z)
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
    
	
