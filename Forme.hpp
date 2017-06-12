#ifndef FORME_HPP
#define FORME_HPP

#include <ctime>
#include <fstream>
#include "Point.hpp"

class Forme {

	protected :
		ulong color;
		Point anchor;
		bool selected;
		bool anchor1Focused;
		bool anchor2Focused;
		bool anchor3Focused;
		bool isBoucing = false;
		bool fill = false;
		uint thickness = 1;
		string nomForme;
		std::ofstream log;
		uint x1; // change rien ici
		uint y1;
		uint x2; // enfait le x du point 2 c'est x1-x2
		uint y2; // enfait le y du point 2 c'est y1-y2
		uint x3;
		uint y3; // y1 y est ajouté

	public :
		Forme (ulong color, uint x, uint y);
		Forme (ulong _color, uint _x1, uint _y1, uint _x2, uint _y2, uint _x3, uint _y3);
		Forme (const Forme &orig);
		Forme (istream &is);
		virtual ~Forme();
		inline ulong getColor() const {return color;}
		inline void setColor(unsigned long _Color) {color= _Color;}
		inline bool getFill() const {return fill;}
		inline void setFill(bool _fill) {fill = _fill;}
		inline uint getThickness() const {return thickness;}
		inline void setThickness(uint _thickness) { thickness = _thickness; }
		inline void increaseThickness() { if (thickness <5 && !getFill()) thickness++;}
		inline void decreaseThickness() { if (thickness >1 && !getFill()) thickness--;}
		inline string getNomForme() const {return nomForme;}
		inline void setNomForme(string  _nomForme) {nomForme = _nomForme;}
		inline const Point &getAnchor() const { return anchor; }

		inline bool getAnchor1Focused() const {return anchor1Focused;}
		inline void setAnchor1Focused(bool _anchor1Focused) {anchor1Focused = _anchor1Focused;}

		inline bool getAnchor2Focused() const {return anchor2Focused;}
		inline void setAnchor2Focused(bool _anchor2Focused) {anchor2Focused = _anchor2Focused;}

		inline bool getAnchor3Focused() const {return anchor3Focused;}
		inline void setAnchor3Focused(bool _anchor3Focused) {anchor3Focused = _anchor3Focused;}

		virtual inline uint getx1() const { return x1; }
		virtual inline uint getx2() const { return x2; }
		virtual inline uint getx3() const { return x3; }
		virtual inline uint gety1() const { return y1; }
		virtual inline uint gety2() const { return y2; }
		virtual inline uint gety3() const { return y3; }

		void bouncing(int x, int y, int h);
		inline void setIsBoucing(bool _isBoucing) {isBoucing = _isBoucing;}
		virtual void setAnchor(uint x, uint y);
		virtual bool isOver(uint x, uint y);
		virtual void dessiner(EZWindow &fenetre, bool active = false) const;
		virtual double perimetre () const = 0;
		friend ostream &operator<<(ostream &os, const Forme &forme);
		virtual void ecrire(ostream &os) const = 0;
		static Forme* charger(istream &is);
		virtual void infotime(string message = "") const;
		inline void fileclose() { log.close(); }
};

#endif
