#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include "Forme.hpp"

class Polygone : public Forme {
    private :
	uint x1; // change rien ici
	uint y1;
	uint x2; // enfait le x du point 2 c'est x1-x2
	uint y2; // enfait le y du point 2 c'est y1-y2
	uint x3;
	uint y3; // y1 y est ajouté
	uint x4; // change rien ici
	uint y4;
	uint x5; // enfait le x du point 2 c'est x1-x2
	uint y5; // enfait le y du point 2 c'est y1-y2
	uint x6;
	uint y6;
	uint x7;
	uint y7;
	uint x8;
	uint y8;
	uint x9;
	uint y9;
	uint x10;
	uint y10;
	void ecrire (ostream &os) const override;

    public :
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4);
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4, uint x5, uint y5);
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4, uint x5, uint y5, uint x6, uint y6);
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4, uint x5, uint y5, uint x6, uint y6, uint x7, uint y7);
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4, uint x5, uint y5, uint x6, uint y6, uint x7, uint y7, uint x8, uint y8);
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4, uint x5, uint y5, uint x6, uint y6, uint x7, uint y7, uint x8, uint y8, uint x9, uint y9);
	Polygone(ulong color, uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4, uint x5, uint y5, uint x6, uint y6, uint x7, uint y7, uint x8, uint y8, uint x9, uint y9, uint x10, uint y10);
	Polygone(istream &is);
	~Polygone();
	virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
	double perimetre () const override;
};


//= classe MyWindow2 ==========================================================
class MyWindow2 : public EZWindow
{
	string tampon = "";
public:
	MyWindow2(int w, int h, const char *name)
		: EZWindow(w, h, name)
	{
		//construction de la fentre pour saisit nb sommet par l'utilisateur
	}
	~MyWindow2() { /*destruction de la fenêtre pour saisit nb sommet par l'utilisateur */ }
	void expose()
	{
		EZWindow::setColor(ez_black);
		drawText(EZAlign::TL, 10, 10, "Veuillez saisir le nombre de sommet pour le polygone : " + tampon + "_");
	}

	int saisie_texte(EZKeySym key_sym, string& /*s*/)
	{
		switch (key_sym) {

		case EZKeySym::BackSpace:                /* Touche backspace */
			if (tampon.length() == 0) break;
			tampon.resize(tampon.length() - 1);
			sendExpose();
			break;

			//case EZKeySym::Return: Polygone::setsommet(1);         /* Renvoie 1 si touche Entree */

		default:                                 /* Insertion d'un caractere */
			if (currentEvent().keyCount() != 1) break;
			tampon.push_back(currentEvent().keyString()[0]);
			sendExpose();
			break;
		}
		return 0;
	}

	//uint getSommet() const { /*return tampon.c_str();*/ }

	void close() { EZDraw::quit(); }
};

#endif // POLYGONE_HPP
