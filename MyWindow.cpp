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


//Création d'une fenêtre
MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),formes(200),pforme(nullptr)
{
    setDoubleBuffer(true);
}

MyWindow::~MyWindow()
{}

void MyWindow::expose()
{
    formes.dessiner(*this);
    setColor(ez_black);
    drawText(EZAlign::TL,3,3,"h : affiche l'aide sur la console");
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
    if(button==1)
	     pforme = formes.isOver(mouse_x,mouse_y);
}

// Déplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
    Point p(mouse_x, mouse_y);
    if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
	pforme->setAnchor(p); // on la bouge (l'ancre).
    sendExpose(); // Force le rafraichissement du contenu de la fenêtre
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
    Point p(mouse_x, mouse_y);
    if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
	pforme->setAnchor(p);
    sendExpose(); // Force le rafraichissement du contenu de la fenêtre
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier à été enfoncée ou relachée
{
    switch (keysym)
    {
	case EZKeySym::Escape: case EZKeySym::q:
	{
	    //Arrêt de l'application
	    EZDraw::quit();
	    break;
	}
	case EZKeySym::E:
	{
	    //Affichage de la liste des formes sur la console
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
	    if (pforme->getFill()==true)
		pforme->setFill(false); //Déremplissage de la forme sélectionnée
	    else
		pforme->setFill(true); //Remplissage de la forme sélectionnée
	    break;
	}
	case EZKeySym::plus:
	{
	    pforme->increaseThickness(); // Augmenter l'épaisseur de la forme sélectionnée
	    break;
	}
	case EZKeySym::minus:
	{
	    pforme->decreaseThickness(); // Diminuer l'épaisseur de la forme sélectionnée
	    break;
	}
	case EZKeySym::R:
	{
	    pforme->~Forme(); // Destruction de la forme sélectionnée
	    break;
	}
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
	case EZKeySym::h:
	    //Affichage du menu dans le terminal
	    cout << "q : Quitter" << endl
		 << "h : Cette aide" << endl
		 << "E : Ecrire la liste des formes sur la console" << endl
		 << "S : Sauve la liste des formes sur le disque" << endl
		 << "C : Charge la liste des formes depuis le disque" << endl
		 << "F : Active/déactive le remplissage" << endl
		 << "p : Augmente l'épaisseur" << endl
		 << "m : Diminue l'épaisseur" << endl
		 << "R : Supprime la forme" << endl
		 << "0 : Met en noir la forme" << endl
		 << "1 : Met en gris la forme" << endl
		 << "2 : Met en rouge la forme" << endl
		 << "3 : Met en vert la forme" << endl
		 << "4 : Met en bleu la forme" << endl
		 << "5 : Met en jaune la forme" << endl
		 << "6 : Met en cyan la forme" << endl
		 << "7 : Met en magenta la forme" << endl
		 << "r : Crée un rectangle" << endl
		 << "e : Crée une ellipse" << endl
		 << "s : Crée un carré" << endl
		 << "c : Crée un cercle" << endl
		 << "t : Crée un triangle" << endl;
	    break;
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
	    formes.ajouter(new Cercle(ez_black,getWidth()/2.28,getHeight()/2.2,50));
	    break;
	}
	case EZKeySym::t:
	{
	    //Dessinage de Triangle
	    formes.ajouter(new Triangle(ez_black,getWidth()/2,getHeight()/3.35,getWidth()/4,getHeight()/4));
	    break;
	}
	default:
	    break;
    }
    sendExpose(); // Force le rafraichissement du contenu de la fenêtre
}
