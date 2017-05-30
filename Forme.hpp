#ifndef FORME_HPP
#define FORME_HPP

#include <ctime>
#include <fstream>
#include "Point.hpp"

class Forme {

	private :
		ulong color;
		Point anchor;
		bool selected;
		bool fill = false;
		uint thickness = 1;
		std::ofstream log;

	public :
		Forme (ulong color, uint x, uint y);
		Forme (const Forme &orig);
		Forme (istream &is);
		virtual ~Forme();
		inline ulong getColor() const {return color;}
		inline void setColor(unsigned long _Color) {color= _Color;}
		inline bool getFill() const {return fill;}
		inline void setFill(bool _fill) {fill = _fill;}
		inline uint getThickness() const {return thickness;}
		inline void increaseThickness() {thickness++;}
		inline void decreaseThickness() { if (thickness >1) thickness--;}
		inline const Point &getAnchor() const {return anchor;}
		void setAnchor(Point p);
		bool isOver(uint x, uint y);
		virtual void dessiner(EZWindow &fenetre, bool active = false) const;
		virtual double perimetre () const = 0;
		friend ostream &operator<<(ostream &os, const Forme &forme);
		virtual void ecrire(ostream &os) const = 0;
		static Forme* charger(istream &is);
		static void infotime(ostream &os, string message = "");
		//inline ofstream getlog() const {return log("Session.log");}
};

#endif
