#include "Kapla.h"

Kapla::Kapla():m_id(0),mass(0),m_body(0),m_shape(0),m_MotionState(0),longeur(10),largeur(0),profondeur(10)
{
    Kapla::initiate(0,0,0);
}

Kapla::Kapla (int x, int y, int z, int ori, int sens):m_id(0),mass(0.5f),m_body(0),m_shape(0),m_MotionState(0),angl(0),longeur(3),largeur(1),profondeur(15)
    {
        
        Kapla::initiate(x,y,z);
            
    }
//Kapla::Kapla(Kapla const& KaplaCopy):

Kapla::~Kapla()
{
    //pour éviter les fuites de mémoire je détruits les objets créer par référence et pas directement "inclu" dans l'objet Kapla
    delete m_body;
    delete m_shape;
    delete m_MotionState;
}
void Kapla::initiate(int x, int y, int z)
{
    m_shape = new btBoxShape( btVector3(longeur,largeur,profondeur) );
    m_Transform.setIdentity();
    
    m_Transform.setOrigin( btVector3(x,y,z) );
    
    btVector3 localInertia(0,0,0);
    
    
    
    m_shape->calculateLocalInertia( mass, localInertia );
    
    //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
    m_MotionState = new btDefaultMotionState(m_Transform);
    btRigidBody::btRigidBodyConstructionInfo m_BoxRigidBodyConstructionInfo( mass, m_MotionState, m_shape, localInertia );
    m_body = new btRigidBody(m_BoxRigidBodyConstructionInfo);
    
    //fait "tomber" le Kapla c'est à dire l'ajoute au monde bullet, à partir de là il interagit avec les autre Kaplas

}
    //methode
void Kapla::dropKapla(btDiscreteDynamicsWorld &m_World)
    
    {
        
        //add the body to the dynamics world
        //soit je l'envoi à my world, soit cette fonction est directement appelé ici...
        m_World.addRigidBody(m_body);           
    }
    //donne la position du Kapla par un matrice[16] pour que openGL puisse s'en servir
void Kapla:: getCoordinate()
    {
       // return m_MotionState; PAS de return car void ?
        
    }
    //commande pour retirer du monde un Kapla, cette commande est appelée par actionrecord lorsqu'une action est suprimée, le kapla est retirée du monde
void Kapla::delKapla(btDiscreteDynamicsWorld &m_World)
    {
        m_World.removeRigidBody(m_body);
    }

    


   
   



