#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(ulong color, uint x, uint y, uint _height, uint _width)
 : Forme(color, x, y), height(_height), width(_width)
{
    Forme::infotime("Construction d'un Rectangle");
    cerr << "Construction d'un rectangle " << perimetre() << endl;
}

Rectangle::Rectangle(istream &is)
 : Forme(is), height(0), width(0)
{
    Forme::infotime("Construction d'un Rectangle depuis l'entrée standard ('Formes.txt')");
    bool fillsave = false;
	uint thicknesssave = 0;
    is >> height >> width >> fillsave >> thicknesssave;
	setThickness(thicknesssave);
    setFill(fillsave);
}

Rectangle::~Rectangle()
{
    Forme::infotime("Destruction de Rectangle");
}

double Rectangle::perimetre() const
{
    return ((height+width)*2);
}

void Rectangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
    w.setThick(getThickness());
    if (isActive)
	//w.fillRectangle((Forme::getAnchor().getx()-width/2), (Forme::getAnchor().gety()-height/2), (Forme::getAnchor().getx()+width/2), (Forme::getAnchor().gety()+height/2));
	w.fillRectangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width), (Forme::getAnchor().gety()+height));
    else
	w.drawRectangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()+width), (Forme::getAnchor().gety()+height));
}

void Rectangle::ecrire(ostream &os) const
{
    Forme::infotime("Sauvegarde de Rectangle depuis la sortie standard ('Formes.txt')");
    os << "Rectangle    " << getColor() << "       " << getAnchor().getx() << "      " << getAnchor().gety() << "      " << height << "      " << width;
}
