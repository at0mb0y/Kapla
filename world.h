#ifndef DEF_WORLD
#define DEF_WORLD
#include "btBulletDynamicsCommon.h"
//automatise et réunis les différentes classes pour générer un Worls Bullet
class World
{
    public:
    World();
    ~World();
    void simuStep();

    private:

    // btCollisionConfiguration permet de configurer les allocataires de mémoire.
    btDefaultCollisionConfiguration *m_CollisionConfiguration;
    // Ensuite on déclare le nom du monde physique
    btDiscreteDynamicsWorld *m_World;

    // La classe btBroadphaseInterface fournit une interface pour détecter les objets où leurs AABB se chevauchent.
    btBroadphaseInterface	*m_Broadphase;

    // btCollisionDispatcher supporte des algorithmes qui peuvent gérer des pairs de collisions ConvexConvex et ConvexConcave. Temps de l'impact, le point le plus proche et pénétration de profondeur.
    btCollisionDispatcher	*m_Dispatcher;



    // btSequentialImpulseConstraintSolver est une implémentation SIMD rapide de la méthode Projected Gauss Seidel (iterative LCP).
    btSequentialImpulseConstraintSolver *m_SequentialImpulseConstraintSolver;










};

#endif