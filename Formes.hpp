#ifndef FORMES_HPP
#define FORMES_HPP

#include "Forme.hpp"

class Formes {
	private :
		const size_t maxformes;
		size_t nbformes;
		Forme **formes;

	public :
		Formes(size_t taille = 200);
		~Formes();
		void ajouter (Forme *forme);
		Forme* isOver (uint x, uint y);
		Forme* isOverTP2 (uint x, uint y);
		Forme* isOverTP3 (uint x, uint y);
		void dessiner (EZWindow &fenetre);
		friend ostream &operator<< (ostream &os, const Formes &f);
		void sauver(ostream &os) const;
		void charger(istream &is);
};

#endif
