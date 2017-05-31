#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

//#define Rectangle MyRectangle

class Rectangle : public Forme {
	private :
		uint height;
		uint width;
		void ecrire (ostream &os) const override;

	public :
		Rectangle(ulong color, uint x, uint y, uint width, uint height);
		Rectangle(istream &is);
		~Rectangle();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		inline uint getWidth () const {return width;}
		inline void setWidth (uint _width) { width = _width; }
		inline uint getHeight () const { return height; }
		inline void setHeight (uint _height) { height = _height; }
		double perimetre () const override;
};
#endif
