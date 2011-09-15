  #include "fonctions.h"

// fonction Kapla


void dropKapla(int x, int y, int z, btScalar& mass)
{
   	
    mass = 0.5f;
	
	
}
void initialiserKaplaList (KaplaList* kapla)
{
    (*kapla).x=0; 
    (*kapla).y=0;
    (*kapla).z=0;
    (*kapla).ori=0;
    (*kapla).sens=0; 
}
void box(int x, int y,int z)
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
