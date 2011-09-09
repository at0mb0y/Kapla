#ifndef FONCTION_H_INCLUDED

#define FONCTION_H_INCLUDED
// header SFML
#include <SFML/Window.hpp>

// header Bullet physics
#include "btBulletDynamicsCommon.h"
#include "Kapla.h"
#include "Cursor"


void dropKapla(int x, int y, int z, btScalar& mass);
/**
 * \brief Fonction qui ajoute un Kapla dans le monde
 * \param nombreRecu  des coordonés W,Y
 * \return btRigid body
 */

void myBox(float x, float y, float z);

/**
 * \brief Fonction qui dessine une boite
 * \param dimension X,YZ
 * \return rien
 */

typedef struct KaplaList KaplaList;
struct KaplaList{
    
    int x,y,z;
    int ori;
    int sens;
    
};

void initialiserKaplaList (KaplaList* kapla);
#endif // FONCTION_H_INCLUDED