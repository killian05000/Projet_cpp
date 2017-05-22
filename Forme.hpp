#ifndef FORME_HPP
#define FORME_HPP

#include "Point.hpp"

class Forme {
	
	private :
		ulong color;
		Point anchor;
		bool selected;
	
	public :
		Forme (ulong color, uint x, uint y);
		Forme (const Forme &orig);
		Forme (istream &is);
		virtual ~Forme();
		inline ulong getColor() const {return color;}
		inline void setColor(unsigned long _Color) {color= _Color;}
		inline const Point &getAnchor() const {return anchor;}
		void setAnchor(Point p);
		bool isOver(uint x, uint y);
		virtual void dessiner(EZWindow &fenetre, bool active = false) const;
		virtual double perimetre () const = 0;
		friend ostream &operator<<(ostream &os, const Forme &forme);
		virtual void ecrire(ostream &os) const = 0;
		static Forme* charger(istream &is);
};

#endif
