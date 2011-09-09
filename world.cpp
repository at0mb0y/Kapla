
#include "world.h"



World::World():m_World(0),m_Broadphase(0),m_Dispatcher(0),m_CollisionConfiguration(0),m_SequentialImpulseConstraintSolver(0)

{

    ///collision configuration contains default setup for memory, collision setup
	m_CollisionConfiguration = new btDefaultCollisionConfiguration();
	
	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	m_Dispatcher = new	btCollisionDispatcher(m_CollisionConfiguration);
	
	m_Broadphase = new btDbvtBroadphase();
	
	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	m_SequentialImpulseConstraintSolver = new btSequentialImpulseConstraintSolver;	
    // initialisation du monde bullet
	m_World = new btDiscreteDynamicsWorld(m_Dispatcher,m_Broadphase,m_SequentialImpulseConstraintSolver,m_CollisionConfiguration);
	
	// On définit la gravité, de façon à ce que les objets tombent vers le bas (-Y).
	m_World->setGravity( btVector3(0,-10,0) );
    
    //créer un kapla spécial par une extension du Kapla
    //sol= new kapla(sol);


}

