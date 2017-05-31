#include <iostream>
#include "Formes.hpp"

Formes::Formes(size_t taille)
 : maxformes(taille), nbformes(0), formes(nullptr)
{
    formes = new Forme *[maxformes];
}

Formes::~Formes()
{
    //Destruction de toute les formes
    for (size_t i=0; i < nbformes; i++)
    {
	delete formes[i];
    }
    delete []formes;
}

void Formes::ajouter(Forme *forme)
{

    if (nbformes+1 > maxformes)
    {
	throw std::runtime_error("Trop de Formes");
    }
    formes[nbformes++] = forme;
}

void Formes::dessiner(EZWindow &w)
{
    for (size_t i=0; i < nbformes; ++i)
    {
	formes[i] -> dessiner(w, formes[i]->getFill());
    }
}

Forme *Formes::isOver(uint x, uint y)
{
    for (size_t i=0; i < nbformes; ++i)
	if (formes[i] -> isOver(x, y))
	    return formes[i];
    return nullptr;
}

void Formes::sauver(ostream &os) const
{
    //Sauvegarde des formes, via la sortie standard, dans le fichier 'Formes.txt'
    os << nbformes << endl;
    for (size_t i=0; i < nbformes; i++)
       os << *formes[i] << " " << formes[i]->getFill() << endl;

}

ostream &operator<<(ostream &os, const Formes &f)
{
    for (uint i=0; i < f.nbformes; i++)
	os << *f.formes[i] << endl;
    return os;
}

void Formes::charger(istream &is)
{
    //Chargement des formes, par l'entrée standard, depuis le fichier 'Formes.txt'
    for (size_t i=0; i < nbformes; i++)
	delete formes[i];
    nbformes=0;
    size_t combien = 0;
    is >> combien;
    if (combien < maxformes)
	for (size_t i=0; i < combien; i++)
	    ajouter(Forme::charger(is));
}
