#ifndef DEF_ACTIONRECORD
#define DEF_ACTIONRECORD
#include "btBulletDynamicsCommon.h"

//produit un objet qui permet de gérer une stucture contenant les actions enregistrée par l'utilisateur.

class ActionRecord
{

	public:

    ActionRecord();
	//ajoute un kapla dans la structure
	void play();
	//rejoue la struct à partir d'un point
	void dell();
	//retire l'action
	void afficheRecordBar();
	private:





};

#endif