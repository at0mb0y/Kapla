/*
 Le code source présent sur cette page est utilisable à volonté, même pour utilisation commerciale.
 La reproduction de l'article est autorisée avec l'accord de l'auteur.
 */


//#include "main.h"
#include "fonctions.h"


// Notre application SFML
sf::Window	Application;



int main ( int argc, char **argv )
{
	// On crée notre fenâtre grâce à SFML
	Application.Create( sf::VideoMode( 800, 500, 32 ), "SFML : Bullet physics", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close );
	
    //Variable pour calculer le delta de déplacement de la souris quand les clicks droit et gauche de la souris sont enfoncé pour manipuler la caméra
    unsigned int previousX, previousY;
    // Pour déclancher la chute d'un seul kapla quand la touche Espace est relachée
	bool trigger = 0; 
    double deltaX = 0;
    double deltaY = 0;
	
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
    //On initialise une caméra qui sera placé par défaut par le constructeur
    Camera camcam;
    
	// l'espace d'affichage
	glViewport( 0, 0, 800, 500 );
    
    // une instance de curseur en forme de kapla qui se déplace au dessus de la construction, il peut être retourné pour avoir une des 3 surfaces différentes face au sol. On peut orienter l'angle du kapla dans le plan du sol
	Cursor cursor;
    //crée un "monde" Bullet, nécessaire pour mettre les kaplas et les faire intéragir. Pour fonctionner plusieur doivent être créés pour que "btDiscreteDynamicWorld" crée un objet world dans lequel ajouter les objets Kapla.
    //pour simplifier l'initialisation, j'ai pensé réunir la création des différents objets nécessaire dans un class world
    
    //problème pour initialiser le monde, il y a divers objet à générer pour le mettre en place mais ca ne semble pas marcher 
    World monde;
    // déclaration d'un conteneur pour les objet de type Kapla
    std::vector<Kapla> keva;
    
    

 // pour avoir les infos clavier en temps réel
	const sf::Input& Input = Application.GetInput();
	// Notre boucle d'affichage
	while(Application.IsOpened() )
	{

        // référence vers l'entrée associée à une fenêtre (pour récupérer les donnés clavier en temps réel
        
        sf::Event Event;
        while (Application.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Resized)
                glViewport(0, 0, Event.Size.Width, Event.Size.Height);
            // Fenêtre fermée
            if (Event.Type == sf::Event::Closed)
                Application.Close();
            
            // Touche 'echap' appuyée
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                Application.Close();
        }
            //Utilise les flêche pour déplacer le Kapla qui va être laché
            // Get some useless input states, just to illustrate the tutorial
            bool         LeftKeyDown     = Input.IsKeyDown(sf::Key::Left);
            bool         RightKeyDown     = Input.IsKeyDown(sf::Key::Right);
            bool         UpKeyDown     = Input.IsKeyDown(sf::Key::Up);
            bool         DownKeyDown     = Input.IsKeyDown(sf::Key::Down);
            bool         RightButtonDown = Input.IsMouseButtonDown(sf::Mouse::Right);
            bool         LeftButtonDown = Input.IsMouseButtonDown(sf::Mouse::Left);
            bool         Espace     = Input.IsKeyDown(sf::Key::Space);

            unsigned int MouseX          = Input.GetMouseX();
            unsigned int MouseY          = Input.GetMouseY();
        
       // en approchant le curseur Kapla du bord la caméra dézoom pour laisser voir tous les Kapla (je présume que la souris est en coordonée absolue par rapport à la fenêtre avec le 0 en haut à gauche.
        if (MouseX<20) {

            camcam.extendScene(MouseX,0.0,0.0,0.0);
        }
        else if (MouseX > (Event.Size.Width - 20)) {
            camcam.extendScene(0.0,(MouseX-(Event.Size.Width - 20)),0.0,0.0);
        }
        
        
        if (MouseY<20) {
            
            camcam.extendScene(0.0, 0.0,MouseX,0.0);
        }else if (MouseY > (Event.Size.Height - 20)) {
            camcam.extendScene(0.0,0.0,0.0,(MouseY-(Event.Size.Height - 20)));
        }
        
        //Tant que la souris bouge la souris bouge
        
        while ((previousY=!MouseY)||(previousX=!MouseX))
        {
            //si les deux boutons sont enfoncés
            if ((RightButtonDown)&&(LeftButtonDown))
            {

                //utiliser le delta de déplacement pour déplacer la caméra autour de la scène 
            deltaX = MouseX - previousX;
            deltaY = MouseY - previousY;
            
            camcam.set(deltaX,deltaY);
            }
            
        }
        //NEED convertiseur coord souris -> coord du plan visible par la caméra
        // le déplacement sur le plan de la fenêtre est proportionel à celui du plan de construction
        cursor.set(MouseX, MouseY);
        // dessin  le curseur
        cursor.drawKapla(5,15,1); 
        
        
        //touche espace enfoncée et relachée
        if ((trigger)&&!(Espace))
        {
            // ajoute un kapla dans le monde au coordonée et orientation et direction du curseur.
            keva.push_back(Kapla());
        
            trigger=0;
        }else if ((Espace)&&!(trigger))
        {
            trigger=1;
        }                
                                     
            previousX=MouseX;
            previousY=MouseY; 

        
		// Update dynamics

		        monde.simuStep();

		
		// On a	ffiche le sol;
		box(10,1,10);
		

		
		// swap buffers, etc
		Application.Display();
	}
}
