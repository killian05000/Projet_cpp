// MyWindow.cpp
#include <iostream>
#include <string>

using namespace std;

#include "ez-draw++.hpp"
#include "MyWindow.hpp"

#include "Point.hpp"   // Uniquement pour le constructeur qui peuple la fenêtre
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
#include "Ellipse.hpp"
#include "Triangle.hpp"
#include <sstream>


//Création d'une fenêtre
MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),formes(200),pforme(nullptr), souris(false), dx(0), dy(0)
{
    setDoubleBuffer(true);
    quadriActive=false;
}

MyWindow::~MyWindow()
{}

void MyWindow::quadrillage()const // dessine un quadrillage pour permettree un agencement des formes facile
{
	stringstream y;
	stringstream x;

	for (uint i=0; i < getHeight(); i+=50)
	{
		if (i>0)
		{
			y.str("");
			y << i;
			drawText(EZAlign::TL,3,i-5, y.str());
			drawLine(30,i, getWidth(), i);
		}
	}

	for (uint i=50; i < getWidth(); i+=50)
	{
		x.str("");
		x << i;

		if(i < 100)
			drawText(EZAlign::TL,i-5,20, x.str());
		else if (i <1000)
			drawText(EZAlign::TL,i-8,20, x.str());
		else
			drawText(EZAlign::TL,i-11,20, x.str());

		drawLine(i,40, i, getHeight());
	}
}

void MyWindow::expose()
{
	if (quadriActive)
	{
		setColor(ez_grey);
		quadrillage();
	}
    formes.dessiner(*this);
    setColor(ez_black);
    drawText(EZAlign::TL,3,3,"h : affiche l'aide sur la console");
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
    if(button==1 and souris)
	{
	    setColor(ez_grey);
	    drawPoint(mouse_x, mouse_y);
	    dx = mouse_x; dy = mouse_y;
	}

  if (button==1)
    pforme = formes.isOver(mouse_x,mouse_y);

}

// Déplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
    if(button == 1 && pforme != nullptr && !souris)
    { // Si on clique sur l'ancre d'une forme
		  pforme->setAnchor(mouse_x, mouse_y); // on la bouge (l'ancre).
    }

    if(button==1 and souris)
  	{
      drawLine(mouse_x, mouse_y, dx, dy);
      dx = mouse_x; dy = mouse_y;
    }
    if (!souris)
	   sendExpose(); // Force le rafraichissement du contenu de la fenêtre
}


void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
    //Point p(mouse_x, mouse_y);
    if(button == 1 && pforme != nullptr && !souris) // Si on clique sur l'ancre d'une forme
    {
      pforme->setAnchor(mouse_x,mouse_y);
    }
    sendExpose(); // Force le rafraichissement du contenu de la fenêtre
}

void MyWindow::timerNotify()
{
  if (pforme->getColorChanging()==true)
  {
    if (numColor==0)
    {
      pforme->setColor(ez_black);
      cerr << "noir" << endl;
    }
    else if (numColor==1)
    {
      pforme->setColor(ez_grey);
      cerr <<"gris" << endl;
    }
    else if (numColor==2)
    {
      pforme->setColor(ez_red);
      cerr << "rouge" << endl;
    }
    else if (numColor==3)
    {
      pforme->setColor(ez_green);
      cerr << "vert" << endl;
    }
    else if (numColor==4)
    {
      pforme->setColor(ez_blue);
      cerr << "bleue" << endl;
    }
    else if (numColor==5)
    {
      pforme->setColor(ez_yellow);
      cerr << "jaune" << endl;
    }
    else if (numColor==6)
    {
      pforme->setColor(ez_cyan);
      cerr << "cyan" << endl;
    }
    else if (numColor==7)
    {
      pforme->setColor(ez_magenta);
      cerr << "magenta" << endl;
    }
    numColor++;
    if (numColor>7)
      numColor=0;
    expose();
    if (pforme->getColorChanging()==true)
      startTimer(500);
    else
      pforme->setColor(ez_black);
  }

  if (pforme->getFlashActive()==true)
  {
    // if (pforme->getFill()==true)
    //   pforme->setFill(false); //Déremplissage de la forme sélectionnée
    // else
    if (pforme->getFill()==true)
    {
      pforme->setFill(false);
    }
    else
      pforme->setFill(true); //Remplissage de la forme sélectionnée

    sendExpose();
    if (pforme->getFlashActive()==true)
      startTimer(500);
  }
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier à été enfoncée ou relachée
{
    switch (keysym)
    {
    	case EZKeySym::h:
    	    //Affichage du menu dans le terminal
    		cout << "q : Quitter" << endl
    			 << "h : Cette aide" << endl
    			 << "E : Ecrire la liste des formes sur la console" << endl
    			 << "S : Sauve la liste des formes sur le disque" << endl
    			 << "C : Charge la liste des formes depuis le disque" << endl
    			 << "F : Active/déactive le remplissage" << endl
		       << "O : Affiche le quadrillage" << endl
    			 << "+ : Augmente l'épaisseur" << endl
    			 << "- : Diminue l'épaisseur" << endl
    			 //<< "R : Supprime la forme" << endl
    			 << "0 : Met en noir la forme" << endl
    			 << "1 : Met en gris la forme" << endl
    			 << "2 : Met en rouge la forme" << endl
    			 << "3 : Met en vert la forme" << endl
    			 << "4 : Met en bleu la forme" << endl
    			 << "5 : Met en jaune la forme" << endl
    			 << "6 : Met en cyan la forme" << endl
    			 << "7 : Met en magenta la forme" << endl
           << "M : Animation multicolore" << endl
           << "P : Animation remplissage clignotant" << endl
    			 << "r : Crée un rectangle" << endl
    			 << "e : Crée une ellipse" << endl
    			 << "s : Crée un carré" << endl
    			 << "c : Crée un cercle" << endl
    			 << "t : Crée un triangle" << endl
    			 << "p : Creé un polynome" << endl
    			 << "m : tracer à la souris" << endl;
    	    break;
    	case EZKeySym::Escape: case EZKeySym::q:
    	{
    	    //Arrêt de l'application
    	    EZDraw::quit();
    	    break;
    	}
      case EZKeySym::M:
      {
        if (pforme != nullptr)
        {
          if (pforme->getColorChanging()==true)
            pforme->setColorChanging(false);
          else
            pforme->setColorChanging(true);

          startTimer(500);
        }
        break;
      }
      case EZKeySym::P:
      {
        if (pforme != nullptr)
        {
          if (pforme->getFlashActive())
            pforme->setFlashActive(false);
          else
            pforme->setFlashActive(true);

          startTimer(500);
        }
        break;
      }
      case EZKeySym::I:
      {
        cout << "veuillez saisir le chemin d'accés :" << endl;
        cin >> imagePath;
        //EZImage(imagePath);

      }
    	case EZKeySym::E:
    	{
    	    //Affichage de la liste des formes sur la console
    		    cout << "  Nom     Couleur  Ancre x  Ancre y  Hauteur  Largeur" << endl;
    	    cout << formes;
    	    break;
    	}
    	case EZKeySym::S:
    	{
    	    //Sauvegarde des formes dans le fichier 'Formes.txt'
    	    ofstream f("Formes.txt");
    	    formes.sauver(f);
    	    break;
    	}
    	case EZKeySym::C:
    	{
    	    //Récupperation des formes depuis le fichier 'Formes.txt'
    	    ifstream f("Formes.txt");
    	    formes.charger(f);
    	    break;
    	}
    	case EZKeySym::F:
    	{
        if (pforme != nullptr)
        {
    	    if (pforme->getFill()==true)
    		pforme->setFill(false); //Déremplissage de la forme sélectionnée
    	    else
    		pforme->setFill(true); //Remplissage de la forme sélectionnée
        }
    	    break;
    	}
    	case EZKeySym::plus:
    	{
        if (pforme != nullptr)
        {
    	    pforme->increaseThickness(); // Augmenter l'épaisseur de la forme sélectionnée
        }
  	    break;
    	}
    	case EZKeySym::minus:
    	{
        if (pforme != nullptr)
        {
    	    pforme->decreaseThickness(); // Diminuer l'épaisseur de la forme sélectionnée
        }
  	    break;
    	}
    	// case EZKeySym::R:
    	// {
      //     preBouncing(mouse_x, mouse_y, getHeight());
    	//     break;
    	// }
    	case EZKeySym::_0:
    	{
    	    //Sélection de la couleur : 'Noir'
    	    if(pforme)
    		pforme->setColor(ez_black);
    	    break;
    	}
    	case EZKeySym::_1:
    	{
    	    //Sélection de la couleur : 'Gris'
    	    if(pforme)
    		pforme->setColor(ez_grey);
    	    break;
    	}
    	case EZKeySym::_2:
    	{
    	    //Sélection de la couleur : 'Rouge'
    	    if(pforme)
    		pforme->setColor(ez_red);
    	    break;
    	}
    	case EZKeySym::_3:
    	{
    	    //Sélection de la couleur : 'Vert'
    	    if(pforme)
    		pforme->setColor(ez_green);
    	    break;
    	}
    	case EZKeySym::_4:
    	{
    	    //Sélection de la couleur : 'Bleu'
    	    if(pforme)
    		pforme->setColor(ez_blue);
    	    break;
    	}
    	case EZKeySym::_5:
    	{
    	    //Sélection de la couleur : 'Jaune'
    	    if(pforme)
    		pforme->setColor(ez_yellow);
    	    break;
    	}
    	case EZKeySym::_6:
    	{
    	    //Sélection de la couleur : 'Cyan'
    	    if(pforme)
    		pforme->setColor(ez_cyan);
    	    break;
    	}
    	case EZKeySym::_7:
    	{
    	    //Sélection de la couleur : 'Magenta'
    	    if(pforme)
    		pforme->setColor(ez_magenta);
    	    break;
    	}
    	case EZKeySym::r:
    	{
    	    //Dessinage de Rectangle
    	    formes.ajouter(new Rectangle(ez_black,getWidth()/2.46,getHeight()/4,250,150));
    	    break;
    	}
    	case EZKeySym::e:
    	{
    	    //Dessinage de Ellipse
    	    formes.ajouter(new Ellipse(ez_black,getWidth()/2.13,getHeight()/2.2,100,50));
    	    break;
    	}
    	case EZKeySym::c:
    	{
    	    //Dessinage de Carré
    	    formes.ajouter(new Carre(ez_black,getWidth()/2.28,getHeight()/2.2,100));
    	    break;
    	}
    	case EZKeySym::s:
    	{
    	    //Dessinage de Cercle
    	    formes.ajouter(new Cercle(ez_black,getWidth()/2.28,getHeight()/2.2,100));
    	    break;
    	}
    	case EZKeySym::t:
    	{
    	    //Dessinage de Triangle
    	    formes.ajouter(new Triangle(ez_black,getWidth()/2,getHeight()/3.35,200,250,200,250));
  		    //formes.ajouter(new Triangle(ez_black, 320, 110, 380, 120, 350, 150));
    	    break;
    	}
	// case EZKeySym::p:
	//     uint i;
	//     cerr << "Veuillez saisir le nombre de sommet de votre polygone (3 min - 10 max) : ";
	//     cin >> i;
	//     if (i==3)
	// 	formes.ajouter(new Triangle(ez_black,getWidth()/2,getHeight()/4,150,175,0,350));
	//     else if (i==4)
	// 	formes.ajouter(new Polygone(ez_black,getWidth()/2,getHeight()/4,100, 300, 25, 50, 400, 20));
  //   	case EZKeySym::m:
	// 	{
  //   		//Dessinage à la main
  //   	    if (souris)
  //     			souris = false;
  //   	    else
	// 		      souris = true;
	// 		break;
	// 	 }
		 case EZKeySym::O:
		 {
			 if (quadriActive)
				 quadriActive=false;
			 else
				 quadriActive=true;

			 break;
		  }
      default:
		  break;
      }
    sendExpose(); // Force le rafraichissement du contenu de la fenêtre
}
