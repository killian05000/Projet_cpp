#include <iostream>
#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(ulong color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3)
	: Forme(color, _x1, _y1, _x2, _y2, _x3, _y3), x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), anchor2((_x1-_x2),(_y1+_y2)), anchor3((_x1+_x3),(_y1+_y3))
{
	Forme::infotime("Construction d'un Triangle");
	cerr << "Construction d'un triangle " << perimetre() << endl;

	setNomForme("triangle");
}

Triangle::Triangle(istream &is)
 : Forme(is), x1(0), y1(0), x2(0), y2(0), x3(0), y3(0),anchor2(50,50), anchor3(70,70)
{
    Forme::infotime("Construction du Triangle à partir de l'entrée standard ('Formes.txt')");
    bool fillsave = false;
	uint thicknesssave = 0;
    is >> x2 >> y2 >> x3 >> y3 >> fillsave >> thicknesssave;
	setThickness(thicknesssave);
    setFill(fillsave);
}

Triangle::~Triangle()
{
    Forme::infotime("Destruction de Triangle");
}

double Triangle::perimetre() const
{
	int AB = (sqrt( ((getx1()-getx2())*(getx1()-getx2())) + ((gety1()-gety2()) * (gety1()-gety2())) ) );
	int AC = (sqrt( ((getx1()-getx3())*(getx1()-getx3())) + ((gety1()-gety3()) * (gety1()-gety3())) ) );
	int BC = (sqrt( ((getx2()-getx3())*(getx2()-getx3())) + ((gety2()-gety3()) * (gety2()-gety3())) ) );

	return (AB + AC + BC);
}

void Triangle::dessiner(EZWindow &w, bool isActive) const
{
    Forme::dessiner(w);
	if (isActive)
		w.fillTriangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()-x2), (Forme::getAnchor().gety()+y2), (Forme::getAnchor().getx()+x3), (Forme::getAnchor().gety()+y3));
	else
		w.drawTriangle(Forme::getAnchor().getx(), Forme::getAnchor().gety(), (Forme::getAnchor().getx()-x2), (Forme::getAnchor().gety()+y2), (Forme::getAnchor().getx()+x3), (Forme::getAnchor().gety()+y3));
	anchor2.dessiner(w, isActive);
	anchor3.dessiner(w, isActive);
}

bool Triangle::isOver(uint x, uint y)
{
    //permet de vérifier si l'utilisateur clique sur l'ancre ou pas
		if (anchor.isOver(x,y)==true)
		{
			setAnchor1Focused(true);
			setAnchor2Focused(false);
			setAnchor3Focused(false);
			return anchor.isOver(x,y);
		}
		else if (anchor2.isOver(x,y)==true)
		{
			setAnchor2Focused(true);
			setAnchor1Focused(false);
			setAnchor3Focused(false);
			return anchor2.isOver(x,y);
		}
		else if (anchor3.isOver(x,y)==true)
		{
			setAnchor3Focused(true);
			setAnchor1Focused(false);
			setAnchor2Focused(false);
			return anchor3.isOver(x,y);
		}
		else
			return false;
}

void Triangle::setAnchor(uint x, uint y)
{
    //Déclaration d'une ancre comme un point
		if (anchor1Focused)
		{
    	Forme::setAnchor(x,y);
			x1=x;
			y1=y;
			anchor2.setxy((x1-x2),(y1+y2));
			anchor3.setxy((x1+x3),(y1+y3));
		}
		if (anchor2Focused)
		{
			x2=x;
			y2=y-y1;
			anchor2.setxy((x1-x2),(y1+y2));
			anchor3Focused = false;
		}
		if (anchor3Focused)
		{
			x3=x-x1;
			y3=y-y1;
			//anchor3.setxy((anchor.getx()+x),(anchor.gety()+y));
			std::cerr << "Je suis dans le 3" << '\n';

    	anchor3.setxy((x1+x3),(y1+y3));
			anchor2Focused = false;
		}
}

void Triangle::ecrire(ostream &os) const
{
	Forme::infotime("Sauvegarde du Triangle sur la sortie standard ('Formes.txt')");
	os << "Triangle " << getColor() << " " << getAnchor().getx() << " " << getAnchor().gety() << " " << x2 << " " << y2 << " " << x3 << " " << y3;
}
