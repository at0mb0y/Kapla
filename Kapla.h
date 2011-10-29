#ifndef DEF_KAPLA
#define DEF_KAPLA
#include "btBulletDynamicsCommon.h"
//réunis tous les objets bullet nécéssaire pour faire la simulation d'un Kapla
// l'objet est ajouter au World quand la touche espace est relachée. Les coordonés de chute sont récupéré au curseur.
//le constructeur envoi les coordonées à la structure


class Kapla
{
	public:
    Kapla();
    Kapla(int x, int y, int z, int ori, int sens);
    ~Kapla(); //destructeur nécessaire car déclaration de pointeur
    void initiate(int x, int y, int z);
	void dropKapla(btDiscreteDynamicsWorld &myWorld);
	void recordAction();
    void getCoordinate();
    void delKapla(btDiscreteDynamicsWorld &myWorld);
    void affiche();


	private:
    int m_id;
    float angl;
    int longeur;
    int largeur;
    int profondeur;
    //btVector3;
    btScalar mass;
    // Position, orientation.
    btTransform m_Transform;

    // btDefaultMotionState fournit une implémentation pour synchroniser les transformations.
    btDefaultMotionState *m_MotionState;

    // Une matrice OpenGL, pour récupérer la position, rotation d'un objet.
    btScalar	matrix[16];

    // Le corps d'une boite et de notre sol.
    // btRigidBody est la classe principale des objets rigides
    btRigidBody *m_body;
	btCollisionShape *m_shape;

};

#endif