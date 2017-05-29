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



MyWindow::MyWindow(int w, int h,const char *name)
 : EZWindow(w,h,name),formes(200),pforme(nullptr)
{
    //pforme->infotime(pforme->getlog(), " - Création d'une fenêtre.");
    setDoubleBuffer(true);
}

MyWindow::~MyWindow()
{}

void MyWindow::expose()
{
    formes.dessiner(*this);
    if(pforme!=nullptr)
    {
    	if (pforme->getFill()==true)
      {
        pforme->dessiner(*this,true);
        cerr << " Etape 1";
      }
      else
      {
        pforme->dessiner(*this,false);
        cerr << " Etape 2";
      }
    }
    setColor(ez_black);
    drawText(EZAlign::TL,3,3,"h : affiche l'aide sur la console");
}

void MyWindow::buttonPress(int mouse_x,int mouse_y,int button)
{
  cerr << " BOUTON PRESSED";
    if(button==1)
	     pforme = formes.isOver(mouse_x,mouse_y);
}

// Deplacement de la souris :
void MyWindow::motionNotify(int mouse_x,int mouse_y,int button)
{
    Point p(mouse_x, mouse_y);
    if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
      pforme->setAnchor(p); // on la bouge.
    sendExpose(); // Force le rafraichissement du contenu de la fenetre
}

void MyWindow::buttonRelease(int mouse_x,int mouse_y,int button)
{
  cerr << " BOUTON REALEASE";
  Point p(mouse_x, mouse_y);
  if(button == 1 && pforme != nullptr) // Si on clique sur l'ancre d'une forme
    pforme->setAnchor(p);
  sendExpose(); // Force le rafraichissement du contenu de la fenetre
}

void MyWindow::keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
{
    switch (keysym)
    {
	case EZKeySym::Escape: case EZKeySym::q:
	{
	    //pforme->infotime(pforme->log, " - Arrêt de l'application.");
	    EZDraw::quit();
	    break;
	}
	case EZKeySym::E:
	{
	    //pforme->infotime(pforme->log, " - Affichage de la liste des formes sur la console.");
	    cout << formes;
	    break;
	}
	case EZKeySym::S:
	{
	    //pforme->infotime(pforme->log, " - Sauvegarde des formes dans le fichier 'Formes.txt'.");
	    ofstream f("Formes.txt");
	    formes.sauver(f);
	    break;
	}
	case EZKeySym::C:
	{
	    //pforme->infotime(pforme->log, " - Récupperation des formes depuis le fichier 'Formes.txt'.");
	    ifstream f("Formes.txt");
	    formes.charger(f);
	    break;
	}
	case EZKeySym::F:
	{
	    if (pforme->getFill()==true)
	    {
		//pforme->infotime(pforme->log, " - Déremplissage de la forme sélectionner.");
		    pforme->setFill(false);
        cerr << " F PRESSED GETFILL TRUE";
	    }
      else
      {
		//pforme->infotime(pforme->log, " - Remplissage de la forme sélectionné.");
		    pforme->setFill(true);
        cerr << " F PRESSED GETFILL FALSE";
	    }
	    break;
	}
	case EZKeySym::_0:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Noir'.");
		if(pforme)
		    pforme->setColor(ez_black);
	    break;
	}
	case EZKeySym::_1:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Gris'.");
	    if(pforme)
		pforme->setColor(ez_grey);
	    break;
	}
	case EZKeySym::_2:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Rouge'.");
	    if(pforme)
		pforme->setColor(ez_red);
	    break;
	}
	case EZKeySym::_3:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Vert'.");
	    if(pforme)
		pforme->setColor(ez_green);
	    break;
	}
	case EZKeySym::_4:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Bleu'.");
	    if(pforme)
		pforme->setColor(ez_blue);
	    break;
	}
	case EZKeySym::_5:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Jaune'.");
	    if(pforme)
		pforme->setColor(ez_yellow);
	    break;
	}
	case EZKeySym::_6:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Cyan'.");
	    if(pforme)
		pforme->setColor(ez_cyan);
	    break;
	}
	case EZKeySym::_7:
	{
	    //pforme->infotime(pforme->log, " - Selection de la couleur : 'Magenta'.");
	    if(pforme)
		pforme->setColor(ez_magenta);
	    break;
	}
	case EZKeySym::h:
	    cout << "q : quitter" << endl
		 << "h : cette aide" << endl
		 << "E : ecrire la liste des formes sur la console" << endl
		 << "S : sauve la liste des formes sur disque" << endl
		 << "C : charge la liste des formes depuis le disque" << endl
		 << "F : Active/déactive le remplissage" << endl
		 << "+ : augmente l'épaisseur" << endl
		 << "- : diminue l'épaisseur" << endl
		 << "0 : met en noir la forme" << endl
		 << "1 : met en gris la forme" << endl
		 << "2 : met en rouge la forme" << endl
		 << "3 : met en vert la forme" << endl
		 << "4 : met en bleu la forme" << endl
		 << "5 : met en jaune la forme" << endl
		 << "6 : met en cyan la forme" << endl
		 << "7 : met en magenta la forme" << endl
		 << "r : crée un rectangle" << endl
		 << "e : crée une ellipse" << endl
		 << "s : crée un carré" << endl
		 << "c : crée un cercle" << endl
		 << "t : crée un triangle" << endl;
	    break;
	case EZKeySym::r:
	{
	    //pforme->infotime(pforme->log, " - Ajout d'un Rectangle.");
	    formes.ajouter(new Rectangle(ez_black,getWidth()/2-25,getHeight()/2-25,getWidth()/2+25,getHeight()/2+25));
	    break;
	}
	case EZKeySym::e:
	{
	    //pforme->infotime(pforme->log, " - Ajout d'une Ellipse.");
	    formes.ajouter(new Ellipse(ez_black,getWidth()/2-25,getHeight()/2-15,50,30));
	    break;
	}
	case EZKeySym::c:
	{
	    //pforme->infotime(pforme->log, " - Ajout d'un Carré.");
	    formes.ajouter(new Carre(ez_black,getWidth()/2-25,getHeight()/2-25,50));
	    break;
	}
	case EZKeySym::s:
	{
	    //pforme->infotime(pforme->log, " - Ajout d'un Cercle.");
	    formes.ajouter(new Cercle(ez_black,getWidth()/2-25,getHeight()/2-25,50));
	    break;
	}
	case EZKeySym::t:
	{
	    //pforme->infotime(pforme->log, " - Ajout d'un Triangle.");
	    formes.ajouter(new Triangle(ez_black,getWidth()/2-25,getHeight()/2-25,getWidth()/2+25,getHeight()/2+25));
	    break;
	}
	default:
	    break;
    }
    sendExpose(); // Force le rafraichissement du contenu de la fenetre
}
