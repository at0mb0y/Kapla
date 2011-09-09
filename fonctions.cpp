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
