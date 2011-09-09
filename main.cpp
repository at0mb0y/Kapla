/*
 Le code source présent sur cette page est utilisable à volonté, même pour utilisation commerciale.
 La reproduction de l'article est autorisée avec l'accord de l'auteur.
 */


//#include "main.h"
#include "fonctions.h"


// Notre application SFML
sf::Window	Application;




KaplaList *kapla = NULL;
// référence vers l'entrée associée à une fenêtre (pour récupérer les donnés clavier en temps réel
const sf::Input& Input = App.GetInput();

int main ( int argc, char **argv )
{
	// On crée notre fenâtre grâce à SFML
	Application.Create( sf::VideoMode( 800, 500, 32 ), "SFML : Bullet physics", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close );
	
	bool run = 1; // Tant que run vaut 1, l'application s'exécutera
	KaplaList kapla;
    initialiserKaplaList(&kapla);
	/// Initialisation d'OpenGL
	
	// On active la lumière 0
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
	
	// Quelques autres options OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR);
	
	// Couleur de fond d'écran
    glClearColor(0.7,0.7,0.7,0);
	
	// l'espace d'affichage
	glViewport( 0, 0, 800, 500 );
	

	

	
	// Notre boucle d'affichage
	while( run )
	{
		// Clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// Mode perspective
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective( 45.0f, 800.0/500.0, 0.1f, 1000.0f );
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
        sf::Event Event;
        while (Application.GetEvent(Event))
        {
            
            // Fenêtre fermée
            if (Event.Type == sf::Event::Closed)
                Application.Close();
            
            // Touche 'echap' appuyée
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                Application.Close();
            //Utilise les flêche pour déplacer le Kapla qui va être laché
            if ((Event.Type == sf::Event::KeyPressed) &&(Event.Key.Code== sf::Key:: ))
                Application.Close();

        }
		// Update dynamics
		if (myWorld)
		{
			myWorld->stepSimulation( 0.0001 );
		}
		
		// Semblant de caméra
		glTranslatef( 0,0,-20);
		glRotatef(40,1,0,0);
		
		// On recupère la matrice OpenGL transformée par Bullet qu'on appliquera à notre boite
		myMotionState->m_graphicsWorldTrans.getOpenGLMatrix( matrix );
		
		// On affiche notre boite avec les transformations applqiuées grâce à la matrice
		glPushMatrix();
		glMultMatrixf( matrix );
		myBox(3,1,15);
		glPopMatrix();
		
		// On a	ffiche le sol;
		myBox(10,1,10);
		
		// swap buffers, etc
		Application.Display();
	}
}
