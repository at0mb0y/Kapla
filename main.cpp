/*
 Le code source pr�sent sur cette page est utilisable � volont�, m�me pour utilisation commerciale.
 La reproduction de l'article est autoris�e avec l'accord de l'auteur.
 */


//#include "main.h"
#include "fonctions.h"


// Notre application SFML
sf::Window	Application;


using namespace std;

int main ( int argc, char **argv )
{
	// On cr�e notre fen�tre gr�ce � SFML
	Application.Create( sf::VideoMode( 800, 500, 32 ), "SFML : Bullet physics", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close );

	// Create a clock for measuring time elapsed
    sf::Clock montre;

	// Pour d�clancher la chute d'un seul kapla quand la touche Espace est relach�e
	bool trigger = 0;

	unsigned int windowsWidth = Application.GetWidth();
    unsigned int windowsHeight = Application.GetHeight();


    int startPointX(0),startPointY(0);
    float deltaX(0),deltaY(0),prevDeltaX(1),prevDeltaY(1);
    int   MouseX(0);
    int   MouseY(0);
    bool show = true;


    //On initialise une cam�ra qui sera plac� par d�faut par le constructeur
    Camera camcam(110,60.0,60.0);
    Cursor cursor;
	bool test = false;

    float time;

	// pour avoir les infos clavier en temps r�el
	const sf::Input& Input = Application.GetInput();
	//cr�e un "monde" Bullet, n�cessaire pour mettre les kaplas et les faire int�ragir. Pour fonctionner plusieur doivent �tre cr��s pour que "btDiscreteDynamicWorld" cr�e un objet world dans lequel ajouter les objets Kapla.
    //pour simplifier l'initialisation, j'ai pens� r�unir la cr�ation des diff�rents objets n�cessaire dans un class world

    //probl�me pour initialiser le monde, il y a divers objet � g�n�rer pour le mettre en place mais ca ne semble pas marcher
    //World monde;
    // d�claration d'un conteneur pour les objet de type Kapla
    //std::vector<Kapla> keva;



 // pour avoir les infos clavier en temps r�el

	// Notre boucle d'affichage
	while(Application.IsOpened() )
	{
        Application.ShowMouseCursor (false);
        // r�f�rence vers l'entr�e associ�e � une fen�tre (pour r�cup�rer les donn�s clavier en temps r�el

        sf::Event Event;
        //Utilise les fl�che pour d�placer le Kapla qui va �tre lach�
        // Get some useless input states, just to illustrate the tutorial
        bool         LeftKeyDown     = Input.IsKeyDown(sf::Key::Left);
        bool         RightKeyDown     = Input.IsKeyDown(sf::Key::Right);
        bool         UpKeyDown     = Input.IsKeyDown(sf::Key::Up);
        bool         DownKeyDown     = Input.IsKeyDown(sf::Key::Down);

        bool         RightButtonDown = Input.IsMouseButtonDown(sf::Mouse::Right);
        bool         LeftButtonDown = Input.IsMouseButtonDown(sf::Mouse::Left);
        bool         Espace     = Input.IsKeyDown(sf::Key::Space);
        bool         Shift     = Input.IsKeyDown(sf::Key::LShift);
        MouseX  =   Input.GetMouseX() ;
        MouseY  =   Input.GetMouseY() ;

        if (LeftButtonDown)
        {
			if (show )
			{
				montre.Reset();
				startPointY = MouseY;
				startPointX = MouseX;
                //cout<< "start point" <<startPointX<< endl;

				show = false;
			}
			time = montre.GetElapsedTime();
            //cout<< time << endl;

			if (time > 0.02)
			{

				deltaX = ((MouseX-startPointX)/50);

				deltaY = ((MouseY-startPointY)/50);
				//show = true;
                cout<< deltaX<< endl;
				if ((prevDeltaX != deltaX)||(prevDeltaY != deltaY)) {
					camcam.tumble(deltaX/50,deltaY/50);
					montre.Reset();
					prevDeltaX = deltaX;
					prevDeltaY = deltaY;

				}
            }

        }else
        {
            show = true;
            cursor.set((MouseX - windowsWidth/2), (MouseY - windowsHeight/2));
        }

        if (Shift) {
            test=true;
        }else{
            test=false;
        }



        if (LeftKeyDown) {
            camcam.tumble(0.005, 0);
            LeftKeyDown = false;
        }
        if (RightKeyDown) {
            camcam.tumble(-0.005, 0);
            RightKeyDown = false;
        }
        if (UpKeyDown) {
            camcam.tumble(0, 0.005);
        }
        if (DownKeyDown) {
            camcam.tumble(0, -0.005);
        }
        //unsigned int delta =mouseT3 - mouseT1;
        //cout << delta<< endl;




        while (Application.GetEvent(Event))
        {

            if (Event.Type == sf::Event::Resized)
                glViewport(0, 0, Event.Size.Width, Event.Size.Height);
            // Fen�tre ferm�e
            if (Event.Type == sf::Event::Closed)
                Application.Close();

            // Touche 'echap' appuy�e
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                Application.Close();
        }

        Application.SetActive();



        //touche espace enfonc�e et relach�e
        if ((trigger)&&!(Espace))
        {
            // ajoute un kapla dans le monde au coordon�e et orientation et direction du curseur.
            //keva.push_back(Kapla());

            trigger=false;
        }else if ((Espace)&&!(trigger))
        {
            trigger=true;
        }




		// Update dynamics

		        //monde.simuStep();


		camcam.display();

        cursor.drawKapla(15, 3, 1);

        glPushMatrix();
		glTranslatef(20, 0, 0);
		box(1,1,1);
		glPopMatrix();

		// On a	ffiche le sol;
        if (test==true)
        {
			box(100,100,1);
        }




		// swap buffers, etc
		Application.Display();
	}
}
